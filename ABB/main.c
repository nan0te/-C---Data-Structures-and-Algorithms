#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int menu();
void Carga(tarbol **A,int X);
void MuestraIn(tarbol *A);
//void Profundidad(tarbol *A,int &I, int &D, int &M);
int CantNodos(tarbol *A);
int Altura(tarbol *A);
int Altura1(tarbol *A);


int main() {
    

int X;
int op,res,Max=0;
int count = 0 ;
int encontrado = 0 ;

tarbol *Ar=NULL;
printf("Programa que maneja Arboles!\n");

do{

op = menu();

switch (op){

    case 1: printf("\nInvocamos a ARMAR y Cargamos un Arbol\n");
            printf("\nIngrese valor Entero\n");fflush(stdin);
            scanf("%d",&X);
            Carga(&Ar,X);
    break;

    case 2: printf("\nMostramos el Arbol\n");
            MuestraIn(Ar);
    break;

    case 3: printf("\nInvocamos a cantidad de nodos de un Arbol\n");
             printf("\nCantidad es.....%d\n",CantNodos(Ar));
    break;

    case 4: printf("\nInvocamos a altura de un Arbol\n");
            //Profundidad(Ar,&Iz,&De,&Max);
            printf("\nLa Altura es.....%d\n",Altura(Ar));
    break;

    case 5: printf("\nInvocamos a profundidad de un Arbol\n");
            //Profundidad(Ar,*iz,*de,*Max);
            printf("\nLa Profundidad es.....%d\n",Max);
    break;

    case 6: printf("\nInvocamos a cantidad numeros pares \n");
             
            CantidadPares(Ar,&count);
            printf("\nCantidad de pares: %d", count);
    break;

    case 7: printf("\nInvocamos printfNodosGradoDos \n");
            printfNodosGradoDos(Ar);
    break;

    case 8: printf("\nInvocamos Insertar sin Repetidos \n");
            printf("\nIngrese valor Entero\n"); fflush(stdin);
            scanf("%d",&X);
            InsertWithoutRepeats(&Ar,X);
    break;

    case 8: printf("\nInvocamos Buscar Item \n");
            printf("\nIngrese valor item \n"); fflush(stdin);
            scanf("%d",&X);
            InsertWithoutRepeats(&Ar,X);
            InOrderSearchItem (&Ar, X, encontrado);
    break;
    }
printf("\nContinua operando con Arboles?? 1 = SI...0 = Fin\n");
fflush(stdin);
scanf("%d",&res);

}

while (res!=0);

}

int menu(){
int auxi;

do{
system("cls");
    printf("\nSeleccione una opcion\n");
    printf("\n---------------------\n");
    printf("\n1. Cargar un Arbol\n");
    printf("\n2. Mostrar el Arbol\n");
    printf("\n3. Contar nodos del Arbol\n");
    printf("\n4. Calcular altura del Arbol\n");
    printf("\n5. Calcular Profundidad del Arbol\n");
    printf("\n6. Contar nodos pares\n");
    printf("\n7. Imprimir Nodos Grado dos\n");
    printf("\n8. Insertar sin repetir\n");
    printf("\n9. Buscar Item en el arbol\n");
    printf("\n0. Fin programa\n");
    fflush(stdin);
    scanf("%d",&auxi);

   

}
while (auxi<0 || auxi>9);




return (auxi);

}
//*********************************************************************
/*
int CantidadPares(tarbol *A, int count) {

    
    if (A != NULL)
    {

        CantidadPares(A->izq);
        if (A->dato % 2 == 0)
            count++;
        CantidadPares(A->der);
    }
}

*/