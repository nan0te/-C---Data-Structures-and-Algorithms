#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arbol{
    int data;
    struct Arbol *izq;
    struct Arbol *der;
}tarbol;

//---------------------------------------------------

void Carga(tarbol **A,int X){
    if (*A == NULL){
        *A = malloc(sizeof(tarbol));
        (*A)->data = X;
        (*A)->izq = NULL;
        (*A)->der = NULL;
    }
    else if  ((*A)->data > X)
        Carga(&(*A)->izq, X);
    else
        Carga(&(*A)->der, X);
}

void CantidadPares( tarbol* A , int* count) {
        
    if( A != NULL ){

        CantidadPares(A->izq,count);
        if ( A->data % 2 == 0 )  (*count) = (*count) + 1 ;
        CantidadPares(A->der,count);

    }

}

void printfNodosGradoDos ( tarbol* root ) {

    tarbol* left;
    tarbol* right;

    if (root != NULL) {
        if (root->izq != NULL) left = root->izq;
        else if (root->der != NULL) right = root->der;
    }

    if  (left->izq != NULL)      printf("\n Nodo menor izq grado 2 : %d \n", left->izq->data);
    else if (left->der != NULL)  printf("\n Nodo menor der grado 2: %d \n", left->der->data);

    else if (right->izq != NULL) printf("\n Nodo mayor der grado 2: %d \n", right->izq->data);
    else if (right->der != NULL) printf("\n Nodo mayor der grado 2: %d \n", right->der->data);
    
}

void InOrderSearch (tarbol* root, int item, int* result) {

    if (root != NULL && (*result) == 0) {
        InOrderSearch(root->izq, item, result);
        if ( root->data == item ) (*result) = 1;
        InOrderSearch(root->der, item, result);
    }
}

void InsertWithoutRepeats (tarbol** root, int item) {

        int result = 0 ;
        InOrderSearch(*root,item,&result);

        if (result == 0) Carga(root,item);
        else printf("\n No se puede instertar el Item. Ya existe en el Arbol\n"); 

}

void StackAscendente( pStack stack, tarbol* root ) {

         if (root != NULL) {
            StackAscendente(stack, root->izq);
            push(&stack, root->data);
            InOrderSearch(stack, root->der);
       }

}

void ContarItemMayoresYMenoresQue ( tarbol* root, int menor, int mayor, int* count ) {

            if (root != NULL) {
            ContarItemMayoresYMenoresQue(root->izq, menor, mayor, count);
            if ( root->data > menor && root->data < mayor ) (*count) = (*count) + 1 ;
            ContarItemMayoresYMenoresQue(root->der, menor, mayor, count);
       }

}

void InOrderSearchItem (tarbol* root, int item, int* encontrado ) {

    if (root != NULL && (*encontrado) == 0) {
        InOrderSearchItem(root->izq, item, encontrado);
        if ( root->data == item ) {
            printf("\nEl item %d se encuentra en el arbol.\n" );
            (*encontrado) = 1 ;
        }
        InOrderSearchItem(root->der, item, encontrado);
    }
}

//----------------------------------------------------
void MuestraIn(tarbol* root) {

    if (root!=NULL){
        MuestraIn(root->izq);
        printf("[ %d ]", root->data);
        MuestraIn(root->der);
    }
}



//----------------------------------------------------
void MuestraPre(tarbol* root) {
    if (root!=NULL){
        printf("[ %d ]", root->data);
        MuestraIn(root->izq);
        MuestraIn(root->der);
    }
}
//----------------------------------------------------
void MuestraPos(tarbol* root) {
    if (root!=NULL){
        MuestraIn(root->izq);
        MuestraIn(root->der);
        printf("[ %d ]", root->data);
    }
}   

//--------------------------------------------------
int CantNodos(tarbol *A){

    if (A==NULL) return(0);
    else return(1+(CantNodos(A->izq)+CantNodos(A->der)));

}
//-----------------------------------------------------------------------------
void menor (tarbol *a, int *e) {

    if (a->izq==NULL) *e = a->data;
    else menor(a->izq, e);
}
//------------------------------------------------------------------------------
void inicializar (tarbol** a) {
        *a = NULL;
}
//--------------------------------------------------------------------------------------
void buscar (tarbol *a, int c, int *enc) {
if (a!=NULL)
    {
    if (a->data == c)
        *enc=1;
    else if (a->data>c)
            buscar(a->izq, c, enc);
    else
        buscar(a->der, c, enc);
    }
    else
        *enc=0;
}
//--------------------------------------------------------------------------------------
int Altura(tarbol *A) {
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
