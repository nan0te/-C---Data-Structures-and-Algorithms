#include <stdio.h>
#include <stdlib.h>
#include "ListStudent.h"

int main() {


    tCabecera Estudiante ;

    Insertar(&Estudiante,3,7,"nobile");
    
    ImprimirItem(&Estudiante,"nobile");
    system("pause");

    return 0;
}