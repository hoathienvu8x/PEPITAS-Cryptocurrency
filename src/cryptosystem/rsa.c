#include "core/cryptosystem/rsa.h"
#include "core/blockchain/wallet.h"
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>

// PUBLIC KEY : (n, e)
// PRIVATE KEY: (n, d)
void generate_key()
{
    RSA *keypair = RSA_generate_key(2048, 3, NULL, NULL);

    struct stat st = {0};

    if (stat(".keys", &st) == -1)
    {
        mkdir(".keys", 0700);
    }

    if (!(access(".keys/rsa.pub", F_OK) == 0 && access(".keys/rsa", F_OK) == 0))
    {
        // If there is no key
        FILE *rsa_public_file = fopen("./.keys/rsa.pub","wb");
        FILE *rsa_private_file = fopen("./.keys/rsa","wb");

        if (!rsa_private_file || !rsa_public_file)
            err(errno, "Impossible to write '.keys/rsa.pub' and .keys/rsa files");

        if (PEM_write_RSAPrivateKey(rsa_private_file, keypair, NULL, NULL, 0, NULL, NULL) == -1)
            err(errno,"Impossible to write data in '.keys/rsa'");
        fclose(rsa_private_file);
        
        if (PEM_write_RSAPublicKey(rsa_public_file, keypair) ==-1) 
            err(errno,"Impossible to write data in '.keys/rsa.pub'");
        fclose(rsa_public_file);
    }

    Wallet *wallet = get_my_wallet();
    wallet->priv_key = keypair;
    wallet->pub_key = keypair;
}

void get_keys() {
    if (!access(".keys/rsa.pub", F_OK) == 0 && access(".keys/rsa", F_OK) == 0)
        return generate_key();
    

    FILE *rsa_public_file = fopen("./.keys/rsa.pub","rb");
    FILE *rsa_private_file = fopen("./.keys/rsa","rb");

    Wallet *wallet = get_my_wallet();
    wallet->priv_key = PEM_read_RSAPrivateKey(rsa_private_file, NULL,NULL,NULL);
    wallet->pub_key = PEM_read_RSA_PUBKEY(rsa_public_file, NULL,NULL,NULL);
    
}