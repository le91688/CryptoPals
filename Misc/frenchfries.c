#include <stdio.h>

int main(){

unsigned long long int n[100];

for (int i=0;i<100;i++){ //fill array n with 1-99
    n[i]=i+1;
    if (i>2){
        n[i]=n[i-1]+n[i-2];
            }
                        }

for (int i=0;i<100;i++){

    printf("%d\n",n[i]);
}

}

