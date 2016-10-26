#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch10.h"


unsigned int rand_array(int n, char *buf)  //Generate array of random bytes size n
{
    for (int i=0;i<n;i++){
        unsigned char r = rand();  // GEN RANDOM BYTE
        buf[i]=r;                 //FILL BUF WITH RANDOM BYTES
    }
}   




