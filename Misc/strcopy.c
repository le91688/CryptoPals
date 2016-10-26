#include <stdio.h>



void stringcopy(char *dest, char *source)

{
    
    while (*source!=0x00){
        *dest++ = *source++;
    }
    
}

int main (){
    char buf[128]="this is a test";
    char buf2[128]={0};
    stringcopy(buf2,buf);
    
    puts(buf2);
}





