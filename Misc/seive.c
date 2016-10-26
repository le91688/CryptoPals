#include <stdio.h>
#include <math.h>

int main(){
    int n = 100;
    int x =2;
    int list[n];
    
    //generate list of numbers in array 
    for (int i=0;i<n-1;i++){
        list[i]=x++;
        }
    
    //sieve 
   for (int i=0;i<sqrt(n);i++){  
       for (int j=i+1;j<n-1;j++){ 
            if (list[i]!=0 && list[j]%list[i]==0){
                list[j]=0;
            }
           }
        }
    //print primes
    printf("primes are\n");
    for (int i=0;i<n-1;i++){
        if (list[i]!=0){
       printf("%d\n",list[i]);
        }
        }
}