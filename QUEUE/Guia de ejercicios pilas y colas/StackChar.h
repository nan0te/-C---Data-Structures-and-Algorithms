#include <stdio.h>
#include <stdlib.h>


typedef struct StackChar {

    char dato ;
    struct StackChar* next;

} StackChar;

typedef StackChar* pStackChar ;

 StackChar* GenerarNodoChar( char item ) {

     StackChar* aux ;
     aux = malloc ( sizeof(StackChar) ) ;
     aux->dato = item ;
     aux->next = NULL;
     return aux ;

}
int isEmptyStackChar ( StackChar* p ) {

    return p == NULL;

}

void pushChar( pStackChar* p, char item ) {

    StackChar* aux ;
    aux = GenerarNodoChar(item) ;
    aux->next = *p ;
    *p = aux ; 

}

char popChar( pStackChar* p ) {

    char pop = 0 ;
    StackChar* aux ;
     if ( !isEmptyStackChar(*p) ) {
         pop  = (*p)->dato;
         aux = *p ;
         *p = aux->next;
         free(aux);
     }
     //else printf("\n ESTA VACIA") ;

    return pop;
} 



