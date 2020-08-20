#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int EjercicioCinco ( int  arr[], int n, int index, int mayor );
void EjercicioOnce(int arr[], int index, int n);
void EjercicioTrece(int num, int mod, int div, int aux );
void EjercicioQuince(char *palabra, char *palabra2, int len, int inicio, int final);

    int main()
{

    int arr[] = { 10, 2, 3, 5 , 7, 8, 9 , 20 } ;
    size_t N = sizeof(arr) / sizeof( arr[0]) ;
    int ejCinco = EjercicioCinco(arr,N,0,0) ;
    printf( "%d \n ", ejCinco) ;

    EjercicioOnce(arr,0,N);
    printf("\n");

    

  //  int n = 3871;
  //  int result = n % 100 ;
  //  printf( "%d ", result );
    
    EjercicioTrece(9641232,10,1,1);
    printf("\n");

    char* palabra = "neuquen";
    int len = strlen(palabra);
    printf("len = %d ", len ) ;
    EjercicioQuince(palabra,palabra,len,0,len) ;
        
        system("pause");
    return 0 ;
}

int EjercicioCinco(int arr[],int n, int index, int mayor) {

    if ( index < n ) {
        if (mayor < arr[index]) mayor = arr[index];
        index++;
        return EjercicioCinco(arr,n,index,mayor);
    }
    
    return mayor;
    
}

void EjercicioOnce ( int arr[], int index, int n ) {

    if ( index < n ) {
        
        printf ( " %d,", arr[index]) ;    
        index =index + 2;
        
      return EjercicioOnce (arr,index,n);
    }

}

  
 void EjercicioTrece(int num,int mod, int div, int aux) {

    if ( num > 0 ) {
         
        aux = (num % mod) / div ;
        
        if ( aux >= 1 ) {
            printf ( "%d \n", aux);
            return EjercicioTrece(num-aux,mod*10,div*10,aux);    
        }
    }
} 
void EjercicioQuince(char* palabra,char* palabra2, int len , int inicio, int final){

        if (  inicio < len  ) {

            printf("%c" , palabra[inicio]) ;
            if(  palabra[inicio] == palabra2[final] )
              EjercicioQuince(palabra,palabra2,len,inicio+1,final-1);
        }
        else if ( len == inicio ) {
            printf("TRUE \n");
        }
        else {
            printf("FALSE \n");
        }   
}