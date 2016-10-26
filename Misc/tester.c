#include <stdio.h>
//test endianess
void main(){

int x;
char *ptr;

x=0x12345678; 

ptr = &x;  //ptr = reference x (now equals mem location)

printf ("loc = %x\n", ptr);
printf ("value = %x\n", *ptr); //deref pointer

if (*ptr == 0x78){
    printf("little endian son\n");
}
else{
printf("big endian dog\n");
}
}