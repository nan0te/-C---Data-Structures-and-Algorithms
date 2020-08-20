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

    if ( !cabeza->first  ) {

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
            aux = act;
            prev->next = act->next;
            act = act->next;
            act->prev = prev;
            free(aux);

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

            act->calificacion = calificacion;
    }
}

void ImprimirItem( tCabecera* cabeza, char name[30] ) {
   
  
    tLista act;
    act = cabeza->first;
    printf("asdasdqweqw");

    while (act != NULL && (strcmp(act->name, name) != 0) ) {
        
        act = act->next;
        printf("asdasdqweqw");
        
    }

        printf("\n Matricula: %d ", act->matricula);
        printf("\n Matricula: %s ", act->name);
        printf("\n Matricula: %d \n", act->calificacion);
}
/*void ImprimirNodos (tLista list) {

    while ( list != NULL ) {
        
        printf("%d \n", list->matricula);
        printf("%s \n", &list->name);
        printf("%d \n", list->calificacion);
        list = list->next;
       
    }

}   





void ModificarCalificacion(tLista* list, char nombre[30] , unsigned int ncalificacion ) {

    tLista actual = NULL;
    actual = *list;
    int fin = 0 ;

    while ( actual != NULL && fin == 0 ) {

                if (  charCompare(actual->name , nombre) != 0 ) {

                    printf("alumno encontrado");
                    actual->calificacion = ncalificacion ;
                    printf("\n se modifico");
                    printf("\n la calificacion ahora es de : %d ", actual->calificacion );

                    fin == 1 ;
                }
                actual = actual->next;
    }

}

void PrintAprobados (tLista list)
{

    while (list != NULL  )
    {
        if (list->calificacion >= 7) {
        printf("%d \n", list->matricula);
        printf("%s \n", &list->name);
        printf("%d \n", list->calificacion);
        }
        list = list->next;
    }
}


void CountDesaprobados ( tLista list) {

    int count = 0 ;

    while (list != NULL )
    {
        if (list->calificacion >= 7) count++;
         
        list = list->next;
    }

    printf(" \n Cantidad de desaprobados : %d " , count ) ;
}

void EliminarEstudiante(tLista *list, char nombre[30])
{

    tLista actual,anterior ;
    actual = *list; anterior = NULL;
    int fin = 0;

    while (actual != NULL && fin == 0)
    {

        if (charCompare(actual->name, nombre) != 0)
        {
            printf("\n estudiante encontrado : ");

            if ( actual == NULL )  {

                if( actual == *list) *list = actual->next ;
                else anterior->next = actual->next ;
                free(actual);
            }
               
            printf("\n estudiante eliminado : ");   
            fin == 1;
        }
        
        anterior = actual;
        actual = actual->next;
    }
}*/