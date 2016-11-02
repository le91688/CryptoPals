//crypto pals set 2 challenge 13

//ecb cut and paste

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ch11.h"





char input[1024]="\x61\x64\x6d\x69\x6e\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b\x0b" //admin+(0xb*11)
                 "\x61\x61\x61\x61\x61\x61\x61\x61\x61\x61\x61\x61\x61\x61\x61\x61"//16 a's
                 "\x61\x61\x61";  //3 a's   // special input breaks the encoded data into blocks the right way
                 
                 
char output[1024];
unsigned char ct[1024];
//unsigned int keysize=16;
unsigned char randokey[16];


void profilefor(char *input)            /// make an encoded output (//email=foo@bar.com&uid=10&role=user)
                                        //for a user input and encrypt it with ecb
{
    int i=0;
    while(input[i]!=0x00){
        if (input[i]==0x26||input[i]==0x3d){   //catch any illegal characters
            printf("Illegal character entered!\n");
            return;
        }
        else{
        output[i]=input[i];
        i++;
        }
    }
   
    strcpy(output+i,"&uid=10&role=user");  //17
    puts("data to be encrypted:\n");
    puts(output);
    int len = strlen(output);
    int ctsize = AES128_ECB_enc(output, randokey, ct, keysize, len);
    puts("cookie:\n");
    printf("size=%d\n",ctsize);
    for (int i=0;i<ctsize;i++){  //print ct
        if (i%16==0){
            puts("\n");
        }
        printf("%02x.",ct[i]);
    }
    
}

int main()
{
    srand(time(NULL));
    rand_array(keysize,randokey); //generate random key
    profilefor(input);
    
    det_block_cipher(ciphertext); //get block size etc.
    
    printf("heres an admin cookie busta\n");   //since we gave it admin with correct padding for first block, that becomes our new
                                            // last block
    for (int i=16;i<48;i++){
        printf("%02x",ct[i]);
    }
    for (int i=0;i<16;i++){
        printf("%02x",ct[i]);
    }
}


