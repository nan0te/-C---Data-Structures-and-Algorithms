#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListStudent {
   
    unsigned int matricula;
    unsigned int calificacion;
    char name[30];
    struct ListStudent* next;
    struct ListStudent* prev;

} ListaEstudiantes ;

typedef struct Cabecera
{

    ListaEstudiantes *first;
    ListaEstudiantes *last;

} tCabecera;

typedef ListaEstudiantes* tLista;

tLista GenerarNodo(unsigned int matricula, unsigned int calificacion, char name[30])
{
    
    tLista nuevo;
    nuevo = (tLista)malloc(sizeof(ListaEstudiantes));
    nuevo->matricula = matricula;
    nuevo->calificacion = calificacion;
    strcpy(nuevo->name,name);
     //   nuevo->name = name;
    nuevo->next = nuevo->prev = NULL;
    return nuevo;
}

void Insertar ( tCabecera* cabeza, unsigned int matricula, unsigned int calificacion, char name[30] ) {
    

    tLista nuevo;
    tLista act;
    tLista aux;

    nuevo = GenerarNodo(matricula,calificacion,name);

    if ( cabeza->first == NULL  ) {

        cabeza->first = nuevo; // si el primer item esta vacio 
        cabeza->last = nuevo;
      
        }

    else if ( matricula < cabeza->first->matricula ) {
        //agregar al inicio
        // correr el primero
        cabeza->first->prev = nuevo;
        nuevo->prev = NULL;
        nuevo = cabeza->first;
        cabeza->first = nuevo;
        
    }

    else if ( matricula > cabeza->last->matricula ) {
                                //agrego al final
                                //apunto nuevo->prev a cabecera->last y cabezacera->last nuevo
        cabeza->last->next = nuevo;
        nuevo->prev = cabeza->last;
        nuevo->next = NULL;
        cabeza->last = nuevo;
    
    }

    else {

            act = cabeza->first->next;
            tLista prev;

            while ( act->matricula < nuevo->matricula ) {

                    prev = act->prev;    
                    act = act->next;

            }

            act->prev = nuevo;
            nuevo->prev = prev;
            nuevo->next = act;
            prev->next = nuevo;

    }
 
}

void EliminarItem( tCabecera* cabeza, char name[30] ) {

        tLista act;
        tLista prev;

        if( strcmp( cabeza->first->name,name ) == 0 ) {
            act = cabeza->first;
            cabeza->first = act->next;
            cabeza->first->prev = NULL;
            free(act);
        }

        else if ( strcmp( cabeza->last->name, name) == 0 ) {
            act = cabeza->last;
            cabeza->last = act->prev;
            cabeza->last->next = NULL;
            free(act);    
        }

        else {
            act = cabeza->first->next;
            tLista aux;
            while (act->name != NULL && (strcmp(act->name,name) != 0) ) {
                   prev = act ; 
                   act = act->next;
            }

            if ( strcmp( act->name, name ) == 0 ) {
                aux = act;
                prev->next = act->next;
                act = act->next;
                act->prev = prev;
                free(aux);
            }

            else printf("\n Element does not exist");
        }
}


void Modificar( tCabecera* cabeza, char name[30], unsigned int calificacion ) {

    tLista act;

    if ( strcmp(cabeza->first->name,name) == 0 ) {
        act = cabeza->first;
        act->calificacion = calificacion;
    }

    else if (strcmp(cabeza->last->name, name) == 0 ) {
        act = cabeza->last;
        act->calificacion = calificacion;
    }

    else {
            act = cabeza->first->next;

            while ( act != NULL && strcmp(act->name,name) != 0 ) {
                act = act->next;
            }

            if (strcmp(act->name, name) == 0 )  act->calificacion = calificacion;
            else printf("\n Element does not exist");
    }
}

void ImprimirItem( tCabecera* cabeza, char name[30] ) {
   
  
    tLista act;
    act = cabeza->first;
   

    while (act != NULL && (strcmp(act->name, name) != 0) ) {
        
        act = act->next;
      
    }

    if (strcmp(act->name, name) == 0) {
        printf("\n Matricula: %d ", act->matricula);
        printf("\n Matricula: %s ", act->name);
        printf("\n Matricula: %d \n", act->calificacion);
    }
        
    else
        printf("\n Element does not exist");
    
}
