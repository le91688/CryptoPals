#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch10.h"
#include "base64.h"

unsigned int keysize=16;
unsigned char randokey[16];
unsigned char ciphertext[2048];
unsigned char decoded[2048];
unsigned char pre[11]="1234";

char post[2048]="TESTMEYO THIS IS SOME STUFF TO DECRYPT";
                


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
    memcpy(temp,pre,4);
    strcpy(temp+4,input);  //copy input into temp
    memcpy(temp+ptsize+4,post,strlen(post));          // add mysterydata after input in temp
    int lentemp = ptsize+strlen(post);   //get new size
    int ctsize = AES128_ECB_enc(temp, randokey, output, keysize, lentemp);
    return ctsize;
}

void bat_ecb_decrypt()      //function to detect blocksize / block cipher mode // decrypt
{ 
    int mode;
    int mysterysize;
    int inputsize;
    int init;
    int repeat;
    int size;
    int presize;
    int bs = 0; 
    char testme[1028]="aaaaaaaaaaaaaaa";
    unsigned char temp1[1028];
    unsigned char temp2[1028];
    //printf("\nDetecting block ciper mode...\n");
    char testinput[1024]="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; //some test input
    int len = strlen(testinput);
    ///////////get blocksize 
    for (int i = (strlen(testinput)-1); i>=0; i--){   //feed test input to encryption oracle a byte at a time
        size =encryption_oracle(testinput+i, temp1);         //get size
        if ((strlen(testinput+i))==1){   //if feeding 1 byte
            init=size;                  //grab initial size
        }

        if (size > init){               // when size changes from initial, record the jump, this is blocksize
            bs = size-init;
            break;
        }
        
    }

    printf("detecting block cipher mode\n");
    memset(testinput,0,1024); //ZERO OUT testinput
    int dablock;
    for (int i=0;i<100;i++){   // for all inputs upto 60
        memset(testinput,0x61,i); //fill test input with i*"a"s
        size = encryption_oracle(testinput, temp1);  // feed current test input to oracle
        for (int j=0; j<size-bs; j+=bs){         ///iterate through blocks of ciphertext
            int test =0;
            mode=0;
            test = memcmp(temp1+j, temp1+j+bs, bs); //test for repeating blocks with memcmp
            
            if (test ==0){    
                mode+=1;
         
                dablock=((j+bs)/bs);
                break;
            }
        }
        
        if (mode>0){                              // if you have a match, increment mode
            repeat=i;
            mysterysize = size - i;
            break;
        }
    }
    
    
    int z =0;
    unsigned char test1[1024];
    unsigned char test2[1024];
    //memset(test1,0,1024); //ZERO OUT testinput
    //memset(test2,0,1024); //ZERO OUT testinput
    memset(test2,0x61,repeat); // fill test2 with repeat*"a"
    //memset(temp1,0x0,bs*4);  //4 blocks big
    //memset(temp2,0x0,bs*4); //4 blocks big
    memset(test1,0x61,(repeat-1)); // start test1 with 1 byte short of repeat
    //rintf("BS%d",bs);
    int ret=0;
    int b=dablock+1;
    //printf("print dablock : %d\n", b );
    //printf("\n");
    
    for (int j=0;j<mysterysize;j++){  // for each byte of mysterydata

        size = encryption_oracle((test1+j),temp1);  // temp is your different inputs
        for (int i=1;i<=255;i++){  //for all ascii
           (test2+j)[repeat-1]=i;    //change last char of testinput to test

            size = encryption_oracle(test2+j,temp2);  //encrypt it
            ret = memcmp(temp1,temp2,(bs*3)); // compare temp / temp2 for 3 blocks 

            if (ret==0){
                (test2+j)[repeat-1]=i;
                decoded[z++]=i;
                break;
            }
        }

           
    }
    
    
}



int main()
{
    //generate random stuff 
    srand(time(NULL));
    rand_array(keysize,randokey); //generate random key
    
    //call detection function
    bat_ecb_decrypt();   
    puts(decoded);
    //}
}