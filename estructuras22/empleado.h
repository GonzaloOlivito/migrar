#include "sector.h"
#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
    float sueldo;
    eFecha fechaIngreso;
    int isEmpty;
    int idSector;
} eEmpleado;


#endif // EMPLEADO_H_INCLUDED
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int altaEmpleado(int id, eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamsec);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
int menuOpciones();
void hardcodearEmpleados(eEmpleado vec[], int cant);
int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tamsec);
int minimenu();
int cargarNombreEmpleado(char descripcion[], int id, eEmpleado empleados[], int tam);
