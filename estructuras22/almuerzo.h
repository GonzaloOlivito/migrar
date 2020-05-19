#include "empleado.h"
#include "comida.h"
#include "empleado.h"
#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED


typedef struct{
int id;
int idComida;
int idEmpleado;
eFecha fecha;
int isEmpty;

}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED

void inicializarAlmuerzo(eAlmuerzo almuerzos[], int tam);
void mostrarAlmuerzo(eAlmuerzo almuerzo, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamcom );
void mostrarAlmuerzos(eAlmuerzo almuerzos[],int tama, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamcom);
int altaAlmuerzo(int idAlmuerzo,eAlmuerzo almuerzos[],int tama, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamcom, eSector sectores[], int tamsec);
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam);
