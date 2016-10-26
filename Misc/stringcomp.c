

int stringcomp(char *dest, char *source){
    int test=0;
    while (*source){
        if (*dest++!=*source++){
            test+=1;
        }
    return test;    
    }
    
}