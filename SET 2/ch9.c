//cryptopals challenge 9
//larry espenshade
#include <stdio.h>
#include <string.h>

char input[100];
int blocksize = 20;
int ptsize=16;
int i;

void PKCS7(char *input, int n, int ptsize){
int dif = n-ptsize;
for (i=ptsize;i<blocksize;i++){
   if (input[i]==0){
       input[i]=0x1*dif;
    } 
}
}

int main(){
    strcpy(input, "YELLOW SUBMARINE");
    PKCS7(input,blocksize,ptsize);
    for (i=0;i<blocksize;i++){
        printf("%02x\n",input[i]);
    }
}


