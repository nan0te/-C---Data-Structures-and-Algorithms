#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListStudent {
   
    unsigned int matricula;
    unsigned int calificacion;
    char name[30];
    struct ListStudent* next;
    
} ListaEstudiantes ;


typedef ListaEstudiantes* tLista;

tLista GenerarNodo (void) {
    
    tLista aux;
    aux = malloc (sizeof(tLista*));
    printf(" Ingrese matricula : ");
    scanf("%d",&aux->matricula);
    printf("\n Ingrese nombre y apellido : ");
    scanf("%s",&aux->name);
    printf(" Ingrese calificion : ");
    scanf("%d", &aux->calificacion);
    aux->next = NULL ;
    return aux;

}

void ImprimirNodos (tLista list) {

    while ( list != NULL ) {
        
        printf("%d \n", list->matricula);
        printf("%s \n", &list->name);
        printf("%d \n", list->calificacion);
        list = list->next;
       
    }

}   

void Generar ( tLista* list ) {

    tLista actual ;
    int res = 1 ;
    while ( res == 1 ) {
        actual = GenerarNodo() ;
        actual->next = *list ;
        *list = actual ;
        printf("Continuar ? : ") ;
        scanf("%d",&res) ;

    }
}

int charCompare(char ch1[30], char ch2[30])
{
    int len1 = strlen(ch1);
    int len2 = strlen(ch2);
    int result = 0 ;

    if ( len1 == len2 ) {

        for ( int i = 0 ; i < len1 ; i++ )  {

            if ( ch1[i] == ch2[i] )   result = 1 ;   
            
            else  result = 0 ;
              
        }

    }
    else  result = 0 ;
    

    return result ;
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
}