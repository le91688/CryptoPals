#include <stdio.h>

void myatoi(char *string){
    int x = 0;
    while (*string!=0x00){
        if (*string>0x29 && *string<0x30)
        {
            x+=*string;
        }
                         }
    printf("result = %d",x);
}
void main(){
myatoi("123test");
}
