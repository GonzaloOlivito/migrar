#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"

void informes(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    char respuesta;
    char seguir='s';
    do
    {
        switch(menuInformes())
        {
        case 'a':
            listarEmpleadosXanio(vec,tam,sectores,tamsec);
            break;
        case 'b':
            listarEmpleadas(vec,tam,sectores,tamsec);
            break;
        case 'c':
            informarTotalSueldos(vec,tam);
            break;
        case 'd':
            informarEmpleadosDeSector(vec,tam,sectores,tamsec);
            break;
        case 'e':
            informarEmpleadoXSector(vec,tam,sectores,tamsec);
            break;
        case 'f':
            informarMayorSueldoSector(vec,tam,sectores,tamsec);
            break;
            case 'h':
           empleadoJovenSector(sectores,tamsec,vec,tam);
            break;
        case 'g':
            printf("Confirma salir: s/n: ");
            fflush(stdin);
            scanf("%c",&respuesta);
            if(respuesta=='s')
            {
                seguir='n';
                break;
            }
            break;
        }
        system("pause");
    }
    while(seguir == 's');


}

char menuInformes()
{
    char opcion;
    system("cls");
    printf("\n*** Informe Empleados ***\n\n");
    printf("A. Informe empleados por anio\n");
    printf("B. Informe empleadas mujeres\n");
    printf("C. Informe total sueldos\n");
    printf("D. Informe empleados por sector\n");
    printf("E. Informe de empleados por sectores\n");
    printf("F. Informar mayor sueldo\n");
    printf("H. Empleado mas joven del sector\n");
    printf("G. Salir\n");

    printf("Ingrese una respuesta: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}

void listarEmpleadosXanio(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{

    int anio;
    int flag=0;
    system("cls");
    printf("***LISTADO DE EMPLEADOS POR ANIO DE INGRESO***\n\n\n");
    printf("Ingrese el anio que desea buscar: ");
    scanf("%d", &anio);

    printf(" Id      Nombre  Sexo  Edad   Sueldo    FechaIngreso\n");
    for(int i = 0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].fechaIngreso.anio == anio)
        {
            mostrarEmpleado(vec[i],sectores,tamsec);
            flag=1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay empleados que hayan ingresado ese año\n");
    }
}

void listarEmpleadas(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int flag=0;
    system("cls");
    printf("***LISTADO DE EMPLEADAS MUJERES***\n\n");
    printf(" Id      Nombre  Sexo  Edad   Sueldo    FechaIngreso\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].sexo=='f' && vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i],sectores,tamsec);
            flag=1;
        }

    }
    if(flag==0)
    {
        printf("No existen empleadas mujeres, machista");
    }
}

void informarTotalSueldos(eEmpleado vec[], int tam)
{
    float acumulador=0;
    system("cls");
    printf("***Informe total sueldos*** \n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            acumulador=vec[i].sueldo+acumulador;
        }
    }
    printf("El importe total de los sueldos es: %.2f\n\n", acumulador);
}
void informarEmpleadosDeSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int eleccion;
    char descripcion[20];
    int flag=0;
    system("cls");
    printf("***Listado de empleados por un sector***\n\n");

    listarSectores(sectores,tamsec);

    printf("Ingrese sector: ");
    scanf("%d", &eleccion);

    cargarDescripcionSector(descripcion,eleccion,sectores,tamsec);
    printf("\n Empleados sector %s \n\n", descripcion);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].idSector==eleccion)
        {

            mostrarEmpleado(vec[i],sectores,tamsec);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay empleados en el sector ");
    }


}

void informarEmpleadoXSector (eEmpleado vec[], int tam, eSector sectores [], int tamsec)
{
    int flag = 0;
    system("cls");
    printf("Lista de empleados por sectores \n\n");
    for(int s=0; s<tamsec; s++)
    {
        printf("Lista de empleados en el sector %s: \n", sectores[s].descripcion);
        for(int e=0; e<tam; e++)
        {
            if(vec[e].isEmpty == 0 && vec[e].idSector == sectores[s].id)
            {
                mostrarEmpleado(vec[e],sectores,tamsec);
                flag = 1;
            }

        }
    }
    if(flag==0)
    {
        printf("No hay empleados en este sector");
    }
}

void informarMayorSueldoSector (eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int eleccion;
    float max=0;
    system("cls");

    printf("  **Informe de mayor sueldo del sector\n\n**");
    listarSectores(sectores,tamsec);

    printf("Ingrese el sector: ");
    scanf("%d", &eleccion);
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idSector == eleccion)
        {
            max=vec[0].sueldo;
            if(vec[i].sueldo > max)
            {
                max=vec[i].sueldo;
            }

        }
    }

    printf("El mayor sueldo es %f", max);
}

void empleadoJovenSector(eSector sectores[], int tamsec, eEmpleado vec[], int tam)
{
    eEmpleado emp;
    system("cls");
    int eleccion;
    int joven;
    printf("Informar empleado mas joven\n");
    listarSectores(sectores,tamsec);
    printf("Ingrese el sector al que desea consultar el empleado mas joven: ");
    scanf("%d", &eleccion);
    for(int i=0; i<tamsec; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].idSector == eleccion)
        {
            joven=vec[0].edad;
            if(vec[i].edad < joven)
            {
                joven=vec[i].edad;
            }
        }
    if(vec[i].isEmpty == 0 && vec[i].edad == joven)
    {
        mostrarEmpleado(emp,sectores,tamsec);
    }
    }


}
