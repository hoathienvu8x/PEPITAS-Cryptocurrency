#include "network/server.h"
#include "network/client.h"
#include "network/network.h"
#include "misc/safe.h"

void *accept_connection(void *arg)
{
    int clientfd = *((int *)arg);

    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    if (getpeername(clientfd, (struct sockaddr * restrict) & client_addr, &client_addr_len) == -1)
        err(EXIT_FAILURE, "Failed to recover client IP address\n");

    char ip_str[INET_ADDRSTRLEN];
    if (inet_ntop(AF_INET, &(client_addr.sin_addr), ip_str, INET_ADDRSTRLEN) == NULL)
        err(EXIT_FAILURE, "Failed to convert client IP address to string\n");

    printf("New connection: '%s'\n", ip_str);

    send_client_list(clientfd);

    close(clientfd);
    free(arg);

    return NULL;
}
int init_server()
{
    // Try to connect to the peer-to-peer network

    struct addrinfo hints = {0}; //
    struct addrinfo *result;     //
    struct addrinfo *rp;         //
    int addrinfo_error;
    int sockfd; //File Descriptor of the socket

    hints.ai_family = AF_UNSPEC;     //IPV4 only
    hints.ai_socktype = SOCK_STREAM; //TCP
    hints.ai_flags = AI_PASSIVE;     //Server

    // Get info
    addrinfo_error = getaddrinfo(NULL, STATIC_PORT, &hints, &result);

    // Error management
    if (addrinfo_error != 0)
    {
        errx(EXIT_FAILURE, "Fail getting address on port %s: %s",
             STATIC_PORT, gai_strerror(addrinfo_error));
    }

    // result points to a linked list
    // try yo connect for each result
    for (rp = result; rp != NULL; rp = rp->ai_next)
    {
        sockfd = socket(rp->ai_family, rp->ai_socktype, 0);
        if (sockfd == -1)
            continue; // The socket is not created

        int chezpas = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &chezpas, sizeof(int));

        // Try to connect
        if (bind(sockfd, rp->ai_addr, rp->ai_addrlen) == -1)
        {
            close(sockfd);
            continue;
        }
        break;
    }

    free(result);

    if (rp == NULL)
    { /* No address succeeded */
        fprintf(stderr, "Could not bind\n");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    while (1)
    {
        int *clientfd = malloc(sizeof(int));
        *clientfd = accept(sockfd, rp->ai_addr, &rp->ai_addrlen);
        if (*clientfd != -1)
        {
            pthread_t thread;
            pthread_create(&thread, NULL, accept_connection, clientfd);
        }
    }

    return sockfd;
}

int ping_server(size_t neighbour_id)
{
    if (send(
            get_my_node()->neighbours[neighbour_id].server_sockfd,
            HD_PING,
            sizeof(HD_PING), 0
            ) != -1)
        return 0;
    else 
        return -1;
}