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

int isEmpty( tCabecera c ) {

    return c.first == NULL;
}

void queue ( tCabecera* c, char d ) {

    tNodo* N = NULL;
    N = malloc(sizeof(tNodo));

    N->item = d;
    N->next = NULL;

    if ( isEmpty(*c) ) {

        (*c).first = N;
        (*c).last = N;

    }

    else {

        (*c).last->next = N;
        (*c).last = N;
    }
}   

char enqueue ( tCabecera* c ) {
    
    char enqueue;
    tNodo* aux;
    if( !isEmpty(*c) ) {
        enqueue = (*c).first;
        aux = (*c).first;
        (*c).first = (*c).first->next;
        free(aux);
    }
    else Inicializar(*c);

    return enqueue ;

    
}