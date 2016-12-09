#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch10.h"
#include "base64.h"

unsigned int keysize=16;
unsigned char randokey[16];
unsigned char ciphertext[2048];
unsigned char decoded[2048];
unsigned char pre[8];

char b64d[2048]="Um9sbGluJyBpbiBteSA1LjAKV2l0aCBteSByYWctdG9wIGRvd24gc28gbXkgaGF"
                "pciBjYW4gYmxvdwpUaGUgZ2lybGllcyBvbiBzdGFuZGJ5IHdhdmluZyBqdXN0IH"
                "RvIHNheSBoaQpEaWQgeW91IHN0b3A/IE5vLCBJIGp1c3QgZHJvdmUgYnkK";
char unb64d[2048];

unsigned int rand_array(int n, char *buf)  //Generate array of random bytes size n
{
    for (int i=0;i<n;i++){
        unsigned char r = rand();  // GEN RANDOM BYTE
        buf[i]=r;                 //FILL BUF WITH RANDOM BYTES
    }
}  

int encryption_oracle(char *input, char *output)    //ENCRYPT AS ECB with random key
{
    int ptsize = strlen(input);   //get size of input
    unsigned char temp[1028];
    memset(temp, 0, 1028);        //zero out temp and ciphertext arrays
    memset(ciphertext, 0, 2048);
    //base64 decode pre
    //get length of pre
    
    strcpy(temp,input);  //copy input into temp
    memcpy(temp+ptsize,unb64d,strlen(unb64d));          // add mysterydata after input in temp
    int lentemp = ptsize+strlen(unb64d);   //get new size
    //encrypt ECB
    int ctsize = AES128_ECB_enc(temp, randokey, output, keysize, lentemp);
    return ctsize;
}

void bat_ecb_decrypt()      //function to detect blocksize / block cipher mode // decrypt
{ 
    int mode;
    int mysterysize;
    int init;
    int size;
    int bs = 0; 
    unsigned char temp1[1028];
    unsigned char temp2[1028];
    printf("\nDetecting block ciper mode...\n");
    char testinput[1024]="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; //some test input
    int len = strlen(testinput);
    
    for (int i = (strlen(testinput)-1); i>=0; i--){   //feed test input to encryption oracle a byte at a time
        size =encryption_oracle(testinput+i, temp1);         //get size
        if ((strlen(testinput+i))==1){   //if feeding 1 byte
            init=size;                  //grab initial size
        }

        if (size > init){               // when size changes from initial, record the jump, this is blocksize
            bs = size-init;
            mysterysize=(init+1)-strlen(testinput+i);
            printf("mysterystring is %d\n" ,mysterysize) ;
            break;
        }
    }
   
    //now detect block cipher mode

    printf("detecting block cipher mode\n");
    memset(testinput,0,1024); //ZERO OUT testinput
    for (int i=0;i<5;i++){
        memset(testinput,0x61,i); //fill test input with i*"a"s
        //puts(testinput);
        //puts("\n");
        size = encryption_oracle(testinput, temp1);  // feed current test input
        //puts(temp1);
        for (int j=0; j<size-bs; j+=bs){         ///iterate through blocks of ciphertext
            int test =0;
            mode=0;
            test = memcmp(ciphertext+j, ciphertext+j+bs, bs); //test for repeating blocks with memcmp

            if (test ==0){                              // if you have a match, increment mode
                mode+=1;
                //printf("repeat detected input size %d",i);
                //printf("in block %d",j);
                break;
            }
        }
    }   
    if (mode>0){            // test if mode was incremented for ECB
        puts("ECB\n");
    }        
    else {
        puts("CBC\n");    // if not it was CBC
    }
    
    //feed enc oracle input one byte less than blocksize
    int z =0;
    
    unsigned char test1[1024];
    unsigned char test2[1024];
    memset(test1,0,1024); //ZERO OUT test1
    memset(test2,0,1024); //ZERO OUT test2
    memset(test2,0x61,bs); // fill test2 with (blocksize)*"a"
    memset(temp1,0x0,bs);
    memset(temp2,0x0,bs);
    int start = (bs)-1; //31
    memset(test1,0x61,start); // start test1 with 1 byte short input
    printf("BS%d",bs);
    int ret=0;
    int b=0;
    printf("\n");
    for (int j=0;j<(mysterysize);j++){  // for each byte of mysterytext
        if (j%bs==0){
        b++;
        }  
        size = encryption_oracle(test1+(j%bs),temp1);  // TEMP1 holds ecrypted one byte short input then 2 bytes short, then 3 bytes short ...
        for (int i=1;i<=255;i++){  //for all ascii
           (test2+j)[(bs)-1]=i;    //change last char of test2 to every ascii char
            size = encryption_oracle(test2+(j%bs),temp2);  //encrypt it 
            ret = memcmp(temp1, temp2,(bs*b)); // compare temp / temp2 until you find match of last char
            if (ret==0){
               
                (test2+j)[bs*b-1]=i; //set that char of test2 to the winning character
                decoded[z++]=i;
                break;
                
            }
        }

           
    }
    
    
}



int main()
{
    Base64decode(unb64d, b64d);
    //generate random stuff 
    srand(time(NULL));
    rand_array(keysize,randokey); //generate random key
    rand_array(8,pre); //generate random key
    
    //call detection function
    bat_ecb_decrypt();   
    puts(decoded);
    //}
}