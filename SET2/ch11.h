#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch10.h"

unsigned int keysize=16;
unsigned char pre[64];
unsigned char randokey[16];
unsigned char post[64];
unsigned char ciphertext[1024];
unsigned char temp[1024];
int selection;
int r1;
int r2;


unsigned int rand_array(int n, char *buf)  //Generate array of random bytes size n
{
    for (int i=0;i<n;i++){
        unsigned char r = rand();  // GEN RANDOM BYTE
        buf[i]=r;                 //FILL BUF WITH RANDOM BYTES
    }
}   



int encryption_oracle(char *input)  
{
    int ptsize = strlen(input);   //get size of input
    memset(temp, 0, 1024);        //zero out temp and ciphertext arrays
    memset(ciphertext, 0, 1024);

    memcpy(temp,pre,r1);          // pad random stuff before and aft all to temp
    strcpy(temp+r1,input);
    memcpy(temp+r1+ptsize,post,r2);  

    int lentemp = r1+ptsize+r2;   //get new size
    if (selection ==0){          // randomly encrypt either ECB or CBC
        //encrypt ECB
        int ctsize = AES128_ECB_enc(temp, randokey, ciphertext, keysize, lentemp);
        return ctsize;
    }
    else{
        unsigned char IV[keysize];
        rand_array(keysize,IV);  //Generate random IV
        //encrypte CBC
        int ctsize = AES128_CBC_enc(temp, randokey, IV, ciphertext, keysize, lentemp);
        return ctsize;
    }

}


void det_block_cipher()      //function to detect blocksize / block cipher mode
{ 
    int mode;
    int init;
    int size;
    int bs = 0; 
    printf("\nDetecting block ciper mode...\n");
    char testinput[1024]="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; //some test input
    int len = strlen(testinput);
    
    for (int i = (strlen(testinput)-1); i>=0; i--){   //feed test input to encryption oracle a byte at a time
        size =encryption_oracle(testinput+i);         //get size
        if ((strlen(testinput+i))==1){   //if feeding 1 byte
            init=size;                  //grab initial size
        }

        if (size > init){               // when size changes from initial, record the jump, this is blocksize
            bs = size-init;
            printf("\nblocksize is %d bytes\n", bs);
            break;
        }
    }
   
    //now detect block cipher mode              
    printf("detecting block cipher mode\n");
    size = encryption_oracle(testinput);  // feed whole test input

    for (int j=0; j<size-bs; j+=bs){          ///iterate through blocks of ciphertext
        int test =0;
        mode=0;
        test = memcmp(ciphertext+j, ciphertext+j+bs, bs); //test for repeating blocks with memcmp

            if (test ==0){                              // if you have a match, increment mode
                mode+=1;
                break;
            }
    }
        
    if (mode>0){            // test if mode was incremented for ECB
        puts("ECB\n");
    }        
    else {
        puts("CBC\n");    // if not it was CBC
    }
}



