#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    char string[10] = "hello";

    MD5((unsigned char*)&string, strlen(string), (unsigned char*)&digest);

    char mdString[33];

    for(int i = 0; i < 16; i++)
         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    printf("md5 digest: %s\n", mdString);

    return 0;
}
