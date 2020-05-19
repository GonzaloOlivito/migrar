#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"
#include "comida.h"
#include "empleado.h"

void inicializarAlmuerzo(eAlmuerzo almuerzos[], int tam)
{
for(int i=0; i<tam; i++)
    {
        almuerzos[i].isEmpty=1;
    }
}
void mostrarAlmuerzo(eAlmuerzo almuerzo, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamcom )
{
    char nombreEmpleado[20];
    char nombreComida[20];
    cargarDescripcionComida(nombreComida,almuerzo.id,comidas,tamcom);
    cargarNombreEmpleado(nombreEmpleado,almuerzo.id,empleados,tamEmp);
    printf("    %d  %d  %s  %s %d/%d/%d\n", almuerzo.id,almuerzo.idEmpleado,nombreEmpleado,nombreComida,almuerzo.fecha.dia,almuerzo.fecha.mes,almuerzo.fecha.anio);
}
void mostrarAlmuerzos(eAlmuerzo almuerzos[],int tama, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamcom)
{
    int flag=0;
    system("cls");
    printf("**** LISTADO ALMUERZOS **** \n\n");
    printf(" Id     IdEmpleado   Nombre  Comidas   Fecha\n\n");
    for(int i=0;i<tama;i++)
    {
        if(almuerzos[i].isEmpty==0)
        {
            mostrarAlmuerzo(almuerzos[i],empleados,tamEmp,comidas,tamcom);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("No hay almuerzos");
    }

    printf("\n\n");
}

int altaAlmuerzo(int idAlmuerzo,eAlmuerzo almuerzos[],int tama, eEmpleado empleados[], int tamEmp, eComida comidas[], int tamcom, eSector sectores[], int tamsec)
{
    int retorno = 0;
    int indice;
    eAlmuerzo nuevoAlmuerzo;

    system("cls");

    printf("Alta almuerzo\n\n");

    indice = buscarLibreAlmuerzo(almuerzos,tama);

    if(indice == -1)
    {
        printf("No hay lugar para otro almuerzo");
    }else
    {
        mostrarEmpleados(empleados,tamEmp,sectores,tamsec);
        printf("Ingrese id empleado: ");
        scanf("%d",&nuevoAlmuerzo.idEmpleado);

        mostrarComidas(comidas,tamcom);
        printf("Ingrese id comida: ");
        scanf("%d", &nuevoAlmuerzo.idComida);

        printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d",&nuevoAlmuerzo.fecha.dia,&nuevoAlmuerzo.fecha.mes,nuevoAlmuerzo.fecha.anio);
        nuevoAlmuerzo.isEmpty= 0;
        nuevoAlmuerzo.id=idAlmuerzo;

        almuerzos[indice]=nuevoAlmuerzo;
        retorno = 1;
    }


    return retorno;
}

int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam)
{
    int retorno=-1;
    for(int i; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

