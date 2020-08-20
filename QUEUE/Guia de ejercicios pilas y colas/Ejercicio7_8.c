#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "Stack.h"
#include "StackChar.h"

// void EjercicioSiete( pStack* stack, pStack* aux, int acumulador, int cantidadItems, float promedio );

int main () {


/*  ----------------------------- EJERCICIO 7 ------------------------
pStack stack = NULL;
pStack aux = NULL;

push(&stack,4);
push(&stack,6);
push(&stack,8);
push(&stack,10);
push(&stack,2);

int acumulador = 0 ;
int cantidadItems = 0;
float promedio = 0 ;

EjercicioSiete(&stack,&aux,acumulador,cantidadItems,promedio);

*/


// ------------------------------ EJERCICIO 8 -----------------------

pStack A = NULL;
pStackChar B = NULL;
tCabecera C;

push(&A,2);
push(&A,2);
push(&A,-1);
push(&A,-1);
push(&A,1);

pushChar(&B,'A');
pushChar(&B,'B');
pushChar(&B,'C');
pushChar(&B,'D');
pushChar(&B,'F');






    return 0;
}

/*
void EjercicioSiete( pStack* stack, pStack* aux, int acumulador, int cantidadItems, float promedio ) {

        if ( isEmpty(*stack) ) exit(EXIT_FAILURE);

        else {

            acumulador += pop(stack);
            push(aux,acumulador);
            EjercicioSiete(stack,aux,acumulador,cantidadItems+1, acumulador/cantidadItems);
      
        }

} */


void EjercicioOcho(pStack* A, pStackChar* b, tCabecera* C) {

        int count = 0 ;
        int _pop = 0 ;
        char _popChar = 0 ;
        char _enqueue = 0 ;
        
        while ( !isEmpty(*A) ) {

          _pop = pop(A);

            if ( _pop > 0 ) {
                    
                    while ( count <= _pop  ) {

                        _popChar = popChar(b);
                        enqueue(C,_popChar);
                        pushChar(b,_popChar);
                        count++;

                    }

                    _popChar = popChar(b);
                    count = 0 ;

                }

                else if ( _pop < 0 ) {

                    while ( count <= _pop && (!isEmptyQueue(*C))  ) {

                        _enqueue = dequeue(C);
                        count++;

                    }

                    count = 0 ;
                }

                else if ( _pop == 0 ) {

                    _popChar = popChar(b);

                }
        }

} 