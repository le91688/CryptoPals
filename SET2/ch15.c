#include <stdio.h>
#include <stdlib.h>



int pkcs7_validate (char *bufint len; 
 
char pad = buf[len-1];

while(buf[len-j-1] == pad){ 
    j++; 
    } 
 
if (j!= pad){
    printf ("not pkcs7")
    return 0;
    }
else{ 
    printf("pkcs7 detected")
    while(buf[len-j-1] !=0x0){
        buf[len-j-1]=0x0; 
        }
    return 1;
    }