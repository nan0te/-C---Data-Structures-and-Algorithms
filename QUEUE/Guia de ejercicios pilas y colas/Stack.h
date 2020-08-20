#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {

    int dato ;
    struct Stack* next;

} Stack;

typedef Stack* pStack ;

 Stack* GenerarNodo( int item ) {

     Stack* aux ;
     aux = malloc ( sizeof(Stack) ) ;
     aux->dato = item ;
     aux->next = NULL;
     return aux ;

}
int isEmpty ( Stack* p ) {

    return p == NULL;

}

void push( pStack* p, int item ) {

    Stack* aux ;
    aux = GenerarNodo(item) ;
    aux->next = *p ;
    *p = aux ; 

}

int pop( pStack* p ) {

    int pop = 0 ;
    Stack* aux ;
     if ( !isEmpty(*p) ) {
         pop  = (*p)->dato;
         aux = *p ;
         *p = aux->next;
         free(aux);
     }
     //else printf("\n ESTA VACIA") ;

    return pop;
} 



void Interseccion ( pStack* a, pStack* b, pStack* inter ) {

    pStack aux = NULL ;
    int item =0 ;int item2 = 0; int itemaux = 0;

    while ( !isEmpty(*a) )  {

        item = pop(a); // 9 - 6 -
        
        while (  !isEmpty(*b)  ) { // modicar condicion

            item2 = pop(b); // 9 -- 8 -

            if (item == item2) {
              
                printf("INTERSECCION\n");
                push(inter, item2);
            }

             else {

                push(&aux, item2);
               
            }
        }

        while (!isEmpty(aux))
        {
            itemaux = pop(&aux);
            push(b, itemaux);
        }
    }
                                        
}

void Union (pStack *a, pStack *b, pStack* u) {

    pStack aux = NULL;
    int item = 0;
    int item2 = 0;
    int itemaux = 0;

    while (!isEmpty(*a))  {

        item = pop(a); // 9 - 6 -
        push(u,item);

        while (!isEmpty(*b)) { // modicar condicion

            item2 = pop(b); // 9 -- 8 -

            if (item != item2)  push(&aux, item2); 

        }

        while (!isEmpty(aux)) {
            itemaux = pop(&aux);
            push(b, itemaux);
        }
    }

    while (!isEmpty(*b)) {
        int pop_b = 0;
        pop_b = pop(b);
        push(u,pop_b);
    }  
}
