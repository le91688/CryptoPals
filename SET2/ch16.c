#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ch10.h"

unsigned int blocksize=16;
unsigned char key[16]="YELLOW SUBMARINE";  
unsigned char IV[16]={0};
unsigned char pre[32]="comment1=cooking%20MCs;userdata=";
unsigned char post[42]=";comment2=%20like%20a%20pound%20of%20bacon";
unsigned char input[1024]="aaaaaaaaaaaaaaaa";
unsigned char ct[2048];


int gen_cookie(char *input, char *output)    //ENCRYPT AS ECB with random key
{
    int input_size = 0; 
    unsigned char temp[2048];             
    memcpy(temp,pre,32);
    char *p = temp+32;
    //sanitize input by removing = and : characters and copy to temp
    while(*input!=0x00){ 
        
        if (*input!=0x3a && *input!=0x3d){  
            *p++ =*input++; 
            input_size++;
            }
        else{
            *input++;
            }
        }
    printf("input size %d\n", input_size);
    memcpy(p,post,42);      // add mysterydata after input in temp
    int lentemp =input_size+74 ; //get new size
    int ctsize=AES128_CBC_enc(temp, key,IV, ct,blocksize,lentemp);
    
    return ctsize;
}
int read_cookie(char *input, int ctsize)
{   
    int test;
    char admintest[12]=";admin=true;";
    unsigned char pt[2048];
    AES128_CBC_dec(input, key, IV, pt, blocksize, ctsize);
    printf("decrypted cookie and checking for admin\n");
    printf("%s\n",pt);
    char *p = pt;
    int c = 0;
    while (*p!=0x0){
        c++;
        test = memcmp(p,admintest,12);
        *p++;
        if (test==0){
            
            return 1;
            }
        }
    return 0;
    
}

int main()
{
    int c_size = gen_cookie(input,ct);
    printf("\nciphertext size = %d\n", c_size);
    for (int i=0; i<c_size; i++){
        printf("|%02x", ct[i]);
        }
    puts("\n");
    //modify ciphertext   yes i know this is a bad way to do this and i will update later ;)   
    ct[17]=ct[17]^0x61;   //zero out 12 bytes
    ct[18]=ct[18]^0x61;
    ct[19]=ct[19]^0x61;
    ct[20]=ct[20]^0x61;
    ct[21]=ct[21]^0x61;
    ct[22]=ct[22]^0x61;
    ct[23]=ct[23]^0x61;
    ct[24]=ct[24]^0x61;
    ct[25]=ct[25]^0x61;
    ct[26]=ct[26]^0x61;
    ct[27]=ct[27]^0x61;
    ct[28]=ct[28]^0x61;
    
    
    ct[17]=ct[17]^0x3b;  //make 12 bytes = ;admin=true;
    ct[18]=ct[18]^0x61;
    ct[19]=ct[19]^0x64;
    ct[20]=ct[20]^0x6d;
    ct[21]=ct[21]^0x69;
    ct[22]=ct[22]^0x6e;
    ct[23]=ct[23]^0x3d;
    ct[24]=ct[24]^0x74;
    ct[25]=ct[25]^0x72;
    ct[26]=ct[26]^0x75;
    ct[27]=ct[27]^0x65;
    ct[28]=ct[28]^0x3b;

//decrypt and check for admin
    int isadmin = read_cookie(ct, c_size);
    printf("\nis admin? %d\n", isadmin);
    
}