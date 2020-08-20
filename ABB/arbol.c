typedef struct Arbol{
    int dato;
    struct Arbol *izq;
    struct Arbol *der;
}tarbol;
//---------------------------------------------------
void Carga(tarbol **A,int X){
    if (*A==NULL){
        *A=malloc(sizeof(tarbol));
        (*A)->dato=X;
        (*A)->izq=NULL;
        (*A)->der=NULL;
    }
    else if  ((*A)->dato > X)
        Carga(&(*A)->izq,X);
    else
        Carga(&(*A)->der,X);
}

int CantidadPares( tarbol* A ) {
    
    int result = 0 ;
    if( A != NULL ){

        CantidadPares(A->izq);
        if ( A->dato % 2 == 0 ) result++;
        CantidadPares(A->der);

    }

}
//----------------------------------------------------
void MuestraIn(tarbol *A){

    if (A!=NULL){
    MuestraIn(A->izq);
    printf("[ %d ]",A->dato);
    MuestraIn(A->der);
    }
}



//----------------------------------------------------
void MuestraPre(tarbol *A){
    if (A!=NULL){
        printf("[ %d ]",A->dato);
        MuestraIn(A->izq);
        MuestraIn(A->der);
    }
}
//----------------------------------------------------
void MuestraPos(tarbol *A){
    if (A!=NULL){
        MuestraIn(A->izq);
        MuestraIn(A->der);
        printf("[ %d ]",A->dato);
    }
}   

//--------------------------------------------------
int CantNodos(tarbol *A){

    if (A==NULL) return(0);
    else return(1+(CantNodos(A->izq)+CantNodos(A->der)));

}
//-----------------------------------------------------------------------------
void menor (arbol *a, int *e) {

    if (a->izq==NULL) *e=a->info;
    else menor(a->izq,e);
}
//------------------------------------------------------------------------------
void inicializar (arbol **a) {
        *a=NULL;
}
//--------------------------------------------------------------------------------------
void buscar (arbol *a, int c, int *enc) {
if (a!=NULL)
    {
    if ( a->info == c )
        *enc=1;
    else if (a->info>c)
            buscar(a->izq,c,enc);
    else
        buscar(a->der,c,enc);
    }
    else
        *enc=0;
}
//--------------------------------------------------------------------------------------
int Altura(tarbol *A){
    if (A==NULL)   return(0);
    else if ((Altura(A->der)) > (Altura(A->izq)))  return(1+Altura(A->der));
    else return(1+Altura(A->izq));
}
//----------------------------------------------------------------------
int Altura1(tarbol *A){
    int hd,hi;
    if (A==NULL) return(0);
    
    else    {
        hd=Altura1(A->der);
        hi=Altura1(A->izq);
    if (hd>hi) return (hd+1);

    else return(hi+1);
    }
}
//*******************************************************************
include <stdio.h>
#include <stdlib.h>
#include "LibArbol.h"
int menu();
void Carga(tarbol **A,int X);
void MuestraIn(tarbol *A);
//void Profundidad(tarbol *A,int &I, int &D, int &M);
int CantNodos(tarbol *A);
int Altura(tarbol *A);
int Altura1(tarbol *A);
int main()
{ char car;
int X;
int op,res,iz=1,de=1,Max=0;
tarbol *Ar=NULL;
printf("Programa que maneja Arboles!\n");
do{
op = menu();
switch (op){
case 1:printf("\nInvocamos a ARMAR y Cargamos un Arbol\n");
printf("\nIngrese valor Entero\n");fflush(stdin);
scanf("%d",&X);
Carga(&Ar,X);
break;

case 2:printf("\nMostramos el Arbol\n");
MuestraIn(Ar);
break;
case 3:printf("\nInvocamos a cantidad de nodos de un Arbol\n");
printf("\nCantidad es.....%d\n",CantNodos(Ar));
break;
case 4:printf("\nInvocamos a altura de un Arbol\n");
//Profundidad(Ar,&Iz,&De,&Max);
printf("\nLa Altura es.....%d\n",Altura(Ar));
break;
case 5:printf("\nInvocamos a profundidad de un Arbol\n");
//Profundidad(Ar,*iz,*de,*Max);
printf("\nLa Profundidad es.....%d\n",Max);
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
printf("\n0. Fin programa\n");
fflush(stdin);
scanf("%d",&auxi);
}
while (auxi<0 || auxi>5);
return (auxi);
}
//*********************************************************************

int CantidadPares(tarbol *A) {

    int result = 0;
    if (A != NULL)
    {

        CantidadPares(A->izq);
        if (A->dato % 2 == 0)
            result++;
        CantidadPares(A->der);
    }
}