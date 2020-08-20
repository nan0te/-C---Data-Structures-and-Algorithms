#include <stdio.h>
#include <stdlib.h> 
#include "Stack.h"

int main() {

    

    pStack A = NULL;
    pStack B = NULL;
    pStack C = NULL;
    pStack D = NULL;

    push(&A,10);
    push(&A,5);
    push(&A,7);
    push(&A,9);

     int pop_c = 0 ;
     int pop_d = 0 ;
    // value = pop(&A);
    // printf("%d -  \n", value);

    push(&B,10);
    push(&B,7);
    push(&B,8);
    push(&B,9);

    //Interseccion(&A,&B,&C);
    Union(&A,&B,&D);

    
    /*while ( !isEmpty(C)) {

        pop_c = pop(&C);
        printf("%d - ", pop_c);

    }*/
    printf(" \n ");
    while (!isEmpty(D))
    {

         pop_d = pop(&D);
         
         printf(" %d - ", pop_d);
    }

    return 0;
}