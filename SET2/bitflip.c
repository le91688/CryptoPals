#include <stdio.h>

#include "base64.h"
#include <string.h>


char b64d[2048]="6obi67W57jYVxJyh3vyTp7l31dHghJSWP117i+wqTa4=";
unsigned char unb64d[2048];
char *user1="qwerty";
char *user2="david";

int main()
{
    Base64decode(unb64d, b64d);


    for (int i=0;i<strlen(user1);i++){   
      unb64d[i]=unb64d[i]^user1[i]^user2[i]; 
      }
    

    printf("\nmodded\n");
    Base64encode(b64d, unb64d,32);

    printf("%s",b64d);

}