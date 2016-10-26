#include <stdio.h>
long long unsigned int i;
short int input1;
short int input2;
short int input3;
short int input4;
short int r4;
short int r6;



short int swapbytes(short int num) {
    short int swapped;
    swapped = ((num>>8 & 0xFF) + (num<<8 & 0xFF00));
    return swapped;
}
}

void main() 
{
for (i=0xFFFFFFFFFFF;i>0; --i ) #from
{

if (i%1000000000==0){
printf("number = %ld\n",i);
                    }
input1 = i&0xffff;
input2 = (i>>16)&0xffff;
input3 = i>>32;

r4=0;  //zero out r4 and r6 for each possible input
r6=0;
if (sizeof i<=2){
/* 1st iteration */
r4 = input1;
r4=swapbytes(r4);
r6=input1^r6;
r6=r6^r4;
r4=r4^r6;
r6=r6^r4;
    //check for win
    if (r4==0xFEB1 && r6==0x9298){  //check for win
    printf("winning input= %x%x%x\n",input3,input2,input1);
    }
//printf("r4= %x\n",r4);
//printf("r6= %x\n",r6);
}

else if (sizeof i>2 && sizeof i<5){  //3 or 4 byte long input
/* 1st iteration */
r4 = input2;
r4=swapbytes(r4);
r6=input2^r6;
r6=r6^r4;
r4=r4^r6;
r6=r6^r4;
/* second iteration */
r4 = r4+input1;
r4=swapbytes(r4);
r6=input1^r6;
r6=r6^r4;
r4=r4^r6;
r6=r6^r4;
    //check for win
    if (r4==0xFEB1 && r6==0x9298){ 
    printf("winning input= %x%x%x\n",input3,input2,input1);
    }
//printf("r4= %x\n",r4);
//printf("r6= %x\n",r6);
}

else if (sizeof i>4){ //if input size >4bytes
/* 1st iteration */

r4 = r4+ input3;

r4=swapbytes(r4);

r6=input3^r6;

r6=r6^r4;

r4=r4^r6;

r6=r6^r4;


/* second iteration */

r4 = r4+input2;

r4=swapbytes(r4);

r6=input2^r6;

r6=r6^r4;

r4=r4^r6;

r6=r6^r4;


/* 3rd iteration */

r4 = r4+input1;

r4=swapbytes(r4);

r6=input1^r6;

r6=r6^r4;

r4=r4^r6;

r6=r6^r4;


    //check for win
    if (r4==0xFEB1 && r6==0x9298){ 
    printf("winning input= %x%x%x\n",input3,input2,input1);
    }

}
}
}