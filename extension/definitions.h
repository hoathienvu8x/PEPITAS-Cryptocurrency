#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define MAX_TRANSACTIONS_PER_BLOCK 4
#define UID_LENGTH 32
#define PTR_CHECK(ptr, msg) if (!ptr) { perror(msg); exit(EXIT_FAILURE); }

#endif /* DEFINITIONS_H */
