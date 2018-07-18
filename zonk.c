#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function to roll a die
int roll(){
    int die = 1 + (int)rand() % 6; 
    return die;
}


int main(){
    srand(time(NULL));
    int i,k;
    for(i = 0; i < 6;++k){
        k = 1 + (int)rand() % 6;
        printf("k is %d",k);
    }
}