#include <stdlib.h>
#include <stdio.h>


typedef struct Nodo {

        char item;
        struct Nodo* next;

} tNodo;


typedef struct Cabecera {

       tNodo* first;
       tNodo* last; 

} tCabecera;

void Inicializar ( tCabecera* c ) {

    (*c).first = NULL;
    (*c).last = NULL;

}

int isEmptyQueue( tCabecera c ) {

    return c.first == NULL;
}

void enqueue ( tCabecera* c, char d ) {

    tNodo* N = NULL;
    N = malloc(sizeof(tNodo));

    N->item = d;
    N->next = NULL;

    if ( isEmptyQueue(*c) ) {

        (*c).first = N;
        (*c).last = N;

    }

    else {

        (*c).last->next = N;
        (*c).last = N;
    }
}   

char dequeue ( tCabecera* c ) {
    
    char enqueue;
    tNodo* aux;
    if( !isEmptyQueue(*c) ) {
        enqueue = (*c).first->item;
        aux = (*c).first;
        (*c).first = (*c).first->next;
        free(aux);
    }
    else Inicializar(c);

    return enqueue ;

    
}