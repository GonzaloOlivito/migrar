#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "datawarehouse.h"

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

int menuOpciones()
{
    int opcion;
    system("cls");

    printf("BIENVENIDO AL AMB\n\n");
    printf("1.Alta empleado\n");
    printf("2.Modificar empleado\n");
    printf("3.Baja empleado\n");
    printf("4.Ordenar empleados\n");
    printf("5.Listar empleados\n");
    printf("6.Informes\n");
    printf("7.Mostrar almuerzos\n");
    printf("8.Alta almuerzo\n");
    printf("10.Salir");
    printf("Ingrese la opcion deseada: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado vec[], int tam)
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

int altaEmpleado(int id, eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int todoOk=0;
    int libre=buscarLibre(vec,tam);
    printf("***ALTA EMPLEADO***\n\n");

    if(libre == -1)
    {
        printf("No hay lugar");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(vec[libre].nombre);

        printf("Ingrese edad: ");
        scanf("%d", &vec[libre].edad);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &vec[libre].sexo);

        printf("Ingrese sueldo: ");
        scanf("%f", &vec[libre].sueldo);

        printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d",&vec[libre].fechaIngreso.dia,&vec[libre].fechaIngreso.mes,&vec[libre].fechaIngreso.anio);

        listarSectores(sectores,tamsec);
        printf("Ingrese sector: ");
        scanf("%d", &vec[libre].idSector);

        vec[libre].id=id;

        vec[libre].isEmpty=0;

        todoOk=1;

        printf("Alta exitosa..\n\n");



    }

    return todoOk;
}
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamsec)
{
    char descripcion[20];

    cargarDescripcionSector(descripcion,emp.idSector,sectores,tamsec);

    printf("%d%10s   %c     %d    %.2f    %.2d/%.2d/%.2d      %10s \n", emp.id, emp.nombre,emp.sexo,emp.edad,emp.sueldo,emp.fechaIngreso.dia,emp.fechaIngreso.mes,emp.fechaIngreso.anio,descripcion );


}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int flag=0;
    system("cls");
    printf("****Listado Empleados****\n\n");
    printf(" Id      Nombre  Sexo  Edad   Sueldo    FechaIngreso  Sector\n");
    for(int i = 0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i],sectores,tamsec);
            flag=1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay empleados que listar\n");
    }
}

int buscarEmpleado(int id,eEmpleado vec[], int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(id==vec[i].id && vec[i].isEmpty == 0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int eleccion;
    char confirmacion;
    int esta;
    system("cls");
    printf("****BAJA EMPLEADO****\n\n");

    mostrarEmpleados(vec,tam,sectores,tamsec);

    printf("Ingrese id a dar de baja: ");
    scanf("%d", &eleccion);

    esta=buscarEmpleado(eleccion,vec,tam);
    if(esta==-1)
    {
        printf("Ingreso mal ID");
    }
    else
    {

        mostrarEmpleado(vec[esta],sectores,tamsec);
        printf("\n\nEsta seguro que desea dar de baja? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmacion);
        if(confirmacion == 's')
        {
            vec[esta].isEmpty=1;
            printf("\n\nBaja realizada con exito");
        }
        else
        {
            printf("\nBaja anulada");
        }

    }


}

void hardcodearEmpleados(eEmpleado vec[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        vec[i].id= ids[i];
        strcpy(vec[i].nombre,nombres[i]);
        vec[i].sexo = sexos[i];
        vec[i].edad =edades[i];
        vec[i].sueldo= sueldos[i];
        vec[i].fechaIngreso.dia=dias[i];
        vec[i].fechaIngreso.mes=meses[i];
        vec[i].fechaIngreso.anio=anios[i];
       vec[i].idSector=idsSector[i];
        vec[i].isEmpty=0;

    }
}

void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    int id;
    int esta;
    system("cls");
    printf("*****MODIFICAR EMPLEADO*****\n\n");
    mostrarEmpleados(vec,tam,sectores,tamsec);
    printf("Ingrese id a modificar: ");
    scanf("%d", &id);
    esta=buscarEmpleado(id,vec,tam);
    if(esta==-1)
    {
        printf("No se encontro al empleado con id: %d Reintente.\n\n", id);
    }
    else
    {
        printf("\nModificar al empleado: \n");
        mostrarEmpleado(vec[esta],sectores,tamsec);
        switch(minimenu())
        {
        case 1:
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[esta].nombre);
            break;
        case 2:
            printf("Ingrese edad: ");
            scanf("%d", &vec[esta].edad);
            break;
        case 3:
            printf("Ingrese sexo: ");
            scanf("%c", &vec[esta].sexo);
            break;
        case 4:
            printf("Ingrese sueldo: ");
            scanf("%f", &vec[esta].sueldo);
            break;
        case 5:
            printf("Ingrese fecha de ingreso: dd/mm/aaaa");
            scanf("%d/%d/%d", &vec[esta].fechaIngreso.dia, &vec[esta].fechaIngreso.mes, &vec[esta].fechaIngreso.anio);
        case 6:
            printf("Operacion cancelada! \n\n");
            break;

        }
        mostrarEmpleado(vec[esta],sectores,tamsec);
    }
}


int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tamsec)
{
    int todoOk=0;
    for(int i=0;i<tamsec;i++)
    {
        if(sectores[i].id == id)
        {
            strcpy(descripcion,sectores[i].descripcion);
            todoOk=1;
        }
    }

return todoOk;
}

int minimenu()
{
    int opcion;
    printf("\n1. Modificar nombre\n");
    printf("2. Modificar edad\n");
    printf("3. Modificar sexo\n");
    printf("4. Modificar sueldo\n");
    printf("5. Modificar fecha ingreso\n");
    printf("6. Cancelar operacion\n\n");
    printf("Ingrese una respuesta: ");
    scanf("%d",&opcion);

    return opcion;
}

int cargarNombreEmpleado(char descripcion[], int id, eEmpleado empleados[], int tam)
{
    int todoOk=0;
    for(int i=0;i<tam;i++)
    {
        if(empleados[i].id == id)
        {
            strcpy(descripcion,empleados[i].nombre);
            todoOk=1;
        }
    }

return todoOk;
}
