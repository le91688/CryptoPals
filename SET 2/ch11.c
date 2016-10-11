#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch9.h"
unsigned int keysize;
unsigned char pre[64];
unsigned char post[64];
//generate array of random bytes (size n)
void gen_rando(int n, char *buf){
srand(time(NULL));
for (int i=0;i<n;i++){
unsigned char r = rand(); 
buf[i]=r;
}
}

//encryption oracle func
void encryption_oracle(char *input);

int main(){
keysize = 16;
unsigned char randokey[keysize];
gen_rando(keysize,randokey);
gen_rando(5,pre);
gen_rando(5,post);

printf("%d",rand(5));



}