#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "base64.h"
#include "ch10.h"

unsigned int blocksize=16;
unsigned char *key="YELLOW SUBMARINE";  
char *IV= "0000000000000000";
//char *b64d="MDAwMDAxV2l0aCB0aGUgYmFzcyBraWNrZWQgaW4gYW5kIHRoZSBWZWdhJ3MgYXJlIHB1bXBpbic=";
unsigned char unb64d[2048];
unsigned char ct[2048];
unsigned char pt[2048];
unsigned char decrypted[2048];
unsigned char test[2048]= "DECRYPT DIS STUFF RIGHT HERE DAWGSON";

int pkcs7_validate (unsigned char *buf,int len)
{
    int j =0;
    char pad = buf[len-1];

    while(buf[len-j-1] == pad){ 
        j++; 
    } 
    if (j!= pad){
        return 0;
    }
    else{ 
        while(buf[len-j-1] !=0x0){
            buf[len-j-1]=0x0; 
            }
    return 1;
    }
} 

int encrypt(unsigned char *input, int size)
{
    //Base64decode(unb64d, input);  //decode b64
    puts(test);
    int ctsize=AES128_CBC_enc(test, key,IV, ct,blocksize,size);  //AES CBC encrypt
    printf("\nciphertext:\n");
    
    for (int i=0; i<ctsize; i++){
        printf("%02x", ct[i]);    //print 
        }
    printf("\nIV = %s\n", IV);
    return ctsize;   //return the size of the CT
}

int check_ct(char *input, int size)
{
    unsigned char temp[2048]={0};
    int ptsize =AES128_CBC_dec(input, key,temp,blocksize,size);   //CBC decrypt
    int test = pkcs7_validate(temp, ptsize);
    return test;
}

int main()
{
    int init_size= strlen(test);
    int size = encrypt(test,init_size); 
    printf("size = %d\n", size);
    //print ct
    printf("\nciphertext:\n");
    for (int i=0;i<size;i++){
        if (i%blocksize == 0){
            printf("\n");
        }
        printf("%02x|",ct[i]);
     }
     
    int offset= size-blocksize; 
    printf("\noffset = %d\n", offset);
    unsigned char r[2048]={0};
    unsigned char tmp [2048]={0};
    int padval =0;
    int b=0;
    int test;
    for (int i=0; i<offset;i++){
        memcpy(tmp,ct,size);
        //printf("i=%d\n",i);
        for(int x=0;x<i%16;x++){ //set previous bytes
            //printf("setting up prev bytes : tmp[%d]^=%x^%x\n",offset-x-(b*16)-1,r[offset-x-(b*16)-1],i%16+1);
            tmp[offset-x-(b*16)-1]^=r[offset-x-(b*16)-1]^i%16+1;
        }
        //printf("testing tmp[%d] for %x\n", offset-i-1,i%16+1);
  
        //printf("b=%d\n",b);
        for(int p=0x1;p<=0xff;p++){
            if(p!=i%16+1 || p==padval){
                //printf("testing tmp[%d]^=%x^%d\n",offset-i-1,p,i%16+1);
                tmp[offset-i-1]^=p^i%16+1;  //test for p
                test = check_ct(tmp,size-(b*16));
                if(test==1){
                    //printf("winning p @ %x\n", p);
                    //printf("saving p to r[%d]\n",offset-i-1);
                    r[offset-i-1]=p;  //save to r and break
                    if(i==1){
                        padval=p;
                    }
                    if(i%16==15){
                        //printf("inc b\n");
                        b++;
                        //printf("new submit size is %d\n",size-(b*16));
                    }
                    break;
                }
                else{
                    tmp[offset-i-1]^=p^i%16+1; //reset the byte 
                }
        
            }
            
        }
                        if (test==0){
                    printf("error no value for p\n");
                    return 0;
                }
    }

    printf("\ndecrypted:\n");
    for (int i=0;i<size-blocksize;i++){
        if (i%blocksize == 0){
            printf("\n");
        }
        printf("%02x|",r[i]);
     }

}

    


    
    
    
    
    
    
    