//cryptopals challenge 9
//larry espenshade
#include <stdio.h>
#include <string.h>

int PKCS7(char *input, int blocksize, int ptsize){
//printf( "current size %d\n", ptsize);
if (ptsize < blocksize){
    //printf ("\npt<bs\n");
    int newlen = blocksize;
    int dif = blocksize-ptsize;
    for (int i=ptsize;i<blocksize;i++){
        if (input[i]==0){
            input[i]=0x1*dif;
        } 
    }
        //printf( "padding %d\n", dif);
        //printf( "padded length %d\n", newlen);
    return newlen;
}
else if (ptsize > blocksize){
    //printf ("\npt>bs\n");
    int padlen = blocksize;
    while (padlen<ptsize){
        padlen+=blocksize;
    }
    //padlen+=blocksize;
    int dif = padlen - ptsize;
    int newlen = ptsize+dif;
 
        //printf( "padding %d\n", dif);
        //printf( "padded length %d\n", newlen);
    for (int i=ptsize;i<newlen;i++){
        if (input[i]==0){
            input[i]=0x1*dif;
        } 
    }
}
else {
    //printf ("\nSame\n");
    int newlen = blocksize+ptsize;
    int dif = blocksize;
    for (int i=ptsize;i<newlen;i++){
        if (input[i]==0){
            input[i]=0x1*dif;
        } 
    }
        //printf( "padding %d\n", dif);
        //printf( "padded length %d\n", newlen);
    return newlen;
    }
}


