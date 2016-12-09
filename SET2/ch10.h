#include <stdio.h>
#include <string.h>
#include "ch9.h"
#include "aes.h"
#include "aes.c"
void xorfunc(char *input1, char *input2, char *output, int blocksize)
{
    for (int i=0;i<blocksize;i++){
        output[i]=input1[i]^input2[i];
    }
}
//my AES CBC encrypt function
int AES128_CBC_enc(unsigned char *input, unsigned char *key,char *IV, unsigned char *output,int blocksize,int ptsize)
{
    //Pad plaintext returns new length of padded pt
    int newlen = PKCS7(input,blocksize,ptsize);
    unsigned char temp[16];
    unsigned char temp2[2048];

    //encrypt with AES128 on each block
    int blocknum = newlen/blocksize; //get number of blocks
    for (int i=0;i<blocknum;i++){  //iterate through each block
        if (i ==0){ //for first block
            xorfunc(input, IV, temp, blocksize); //XOR b0 PT ^ IV into temp 
            AES128_ECB_encrypt(temp, key, temp2); //encrypt temp into b0 output
        }  
        else{ //all other blocks
            xorfunc(input+(i*blocksize), temp2+((i-1)*blocksize), temp, blocksize); //input block2 ^ output block1, to temp
            AES128_ECB_encrypt(temp, key, temp2+(i*blocksize)); // aes temp b1 with key to output b1
        }
    }
    memcpy(output,IV,blocksize);
    memcpy(output+blocksize,temp2,newlen);
    return newlen+blocksize;
} 

//my AES CBC decrypt function
int AES128_CBC_dec(unsigned char *input, unsigned char *key, unsigned char *output,int blocksize,int ctsize)
{
    unsigned char temp[16];
    unsigned char temp2[2048];
    unsigned char IV[16];
    int newlen;
    int blocknum = ctsize/blocksize; //get number of blocks
    memcpy(IV,input,blocksize);
    for (int i=0;i<blocknum;i++){  //iterate through each block
        if (i ==0){ //for first block
            AES128_ECB_decrypt(input, key, temp); //aes first block of ct into temp
            xorfunc(temp, IV, temp2, blocksize); //temp ^ IV into first block output
            }  
        else{ //for the rest
            AES128_ECB_decrypt(input+(i*blocksize), key, temp); // aes current block CT with key into temp
            xorfunc(temp,input+((i-1)*blocksize),temp2+(i*blocksize), blocksize); // temp^prev CT block -> current block of output
        }
    }
    memcpy(output,temp2+blocksize,ctsize);
    newlen = ctsize-blocksize;
    return newlen;
}  

//my AES ECB encrypt function
int AES128_ECB_enc(unsigned char *input, unsigned char *key, unsigned char *output,int blocksize,int ptsize)
{
    //Pad plaintext returns new length of padded pt
    int newlen = PKCS7(input,blocksize,ptsize);
    int blocknum = newlen/blocksize;
    for (int i=0;i<blocknum;i++){
        AES128_ECB_encrypt(input + (i*blocksize), key, output+(i*blocksize));
        }
    return newlen;

} 
//my AES ECB decrypt function
int AES128_ECB_dec(unsigned char *input, unsigned char *key, unsigned char *output,int blocksize,int ctsize)
{
    //decrypt with AES128 ECB
    int blocknum = ctsize/blocksize;
    for (int i=0;i<blocknum;i++){
        AES128_ECB_decrypt(input + (i*blocksize), key, output+(i*blocksize));
    }
    return ctsize;
}
