#include <stdio.h>
#include <stdlib.h>
#include "ListStudent.h"

int main() {


    tLista Estudiante, Estudiante2;
    Estudiante = NULL;
    Estudiante2 = NULL;
    Generar(&Estudiante);
   // ImprimirNodos(Estudiante);
    //ModificarCalificacion(&Estudiante,"nobile",9);
    EliminarEstudiante(&Estudiante,"nobile");
    //ImprimirNodos(Estudiante);
    system("pause");

    return 0;
}