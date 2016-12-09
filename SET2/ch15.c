#include <stdio.h>
#include <stdlib.h>



int pkcs7_validate (char *buf,int len)
(
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
) 