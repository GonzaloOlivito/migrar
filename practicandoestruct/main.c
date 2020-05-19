#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"
#include "utn.h"
#include "empleados.h"
#include "sectores.h"
#define TAM 7
#define CANTHARD 7
#define TAMSEC 5

typedef struct
{
    int idSector;
    char descripcion[20];
}eSector;

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

int menu();
int subMenu();
int hardCodeo(eEmployee vec[], int cantHard);

void menuSectores();
int cargarDescripcionSector(char descripcion[],int idSector, eSector sectores[], int tamsec);

int inicializarEmpleados(eEmployee vec[], int tam);
int buscarLibre(eEmployee vec[], int tam);
int altaEmpleado(int id, eEmployee vec[], int tam);
void mostrarEmpleado(eEmployee emp, eSector sectores[], int tamsec);
void mostrarEmpleados(eEmployee vec[], int tam, eSector sectores[], int tamsec);
int modificarEmpleado(int id, eEmployee vec[], int tam, eSector sectores[], int tamsec);
int bajaEmpleado(int id, eEmployee vec[], int tam, eSector sectores[], int tamsec);
int buscarEmpleado(int id, eEmployee vec[], int tam);

int menuModificar();

int main()
{
    int flag=0;
    int id=1000;
    char seguir = 's';
char confirma;
    eEmployee lista[TAM];
    eSector sectores[TAMSEC];
    inicializarEmpleados(lista,TAM);
    /*f(hardCodeo(lista,CANTHARD)== 1)
    {
        flag=1;
    }*/
    id=CANTHARD+id;
    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
           if(altaEmpleado(id,lista,TAM))
           {
               id++;
               flag=1;
           }
            break;
        case 2:
            if(flag==1)
            {
                modificarEmpleado(id,lista,TAM,sectores,TAMSEC);
            } else
            {
                printf("Primero tiene que dar de alta un empleado\n");
            }

            break;
        case 3:
              if(flag==1)
            {
                bajaEmpleado(id,lista,TAM,sectores,TAMSEC);
            } else
            {
                printf("Primero tiene que dar de alta un empleado\n");
            }


            break;
        case 4:
             if(flag==1)
            {
                mostrarEmpleados(lista,TAM, sectores, TAMSEC);
            } else
            {
                printf("Primero tiene que dar de alta un empleado\n");
            }

            break;
        case 5:
            printf("Confirma salir s/n:");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
        system("pause");

    }while(seguir == 's');

    return 0;
}
int menu()
{
    int opcion;

    printf("****MENU EMPLEADOS****\n\n");
    printf("1. Alta empleado\n");
    printf("2. Modificar empleado\n");
    printf("3. Baja empleado\n");
    printf("4. Informes\n");
    printf("5. Salir\n");
    printf("Seleccione la opcion deseada: ");
    scanf("%d", &opcion);

    return opcion;
}
int subMenu()
{
    int opcion;
    system("cls");
    printf("**Menu informes**\n\n");
    printf("1. Ordenar empleados alfabeticamente por apellidos y sector\n");
    printf("2. Informar total y promedio de los salarios y empleados que superen la media\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int hardCodeo(eEmployee vec[], int cantHard)
{
    int todoOk=1;
    for(int i=0;i<cantHard;i++)
    {
        vec[i].id=ids[i];
        strcpy(vec[i].name,nombres[i]);
        strcpy(vec[i].lastName,apellidos[i]);
        vec[i].salary=sueldos[i];
        vec[i].sector=idsSector[i];
        vec[i].isEmpty=0;
    }
    return todoOk;
}

void menuSectores()
{

    printf("1. Sistemas\n");
    printf("2. RRHH\n");
    printf("3. Compras\n");
    printf("4. Ventas\n");
    printf("5. Administracion\n");
}

int cargarDescripcionSector(char descripcion[],int id, eSector sectores[], int tamsec)
{
      int todoOk=0;
    for(int i=0;i<tamsec;i++)
    {
        if(sectores[i].idSector == id)
        {
            strcpy(descripcion,sectores[i].descripcion);
            todoOk=1;
        }
    }

return todoOk;

}




int inicializarEmpleados (eEmployee vec[], int tam)
{
    for(int i=0;i<tam;i++){
        vec[i].isEmpty=1;
    }
    return 0;
}

int altaEmpleado(int id, eEmployee vec[], int tam)
{
    system("cls");
    printf("\n***ALTA EMPLEADO***\n\n");
    int retorno=-1;
    int libre;
    libre=buscarLibre(vec,tam);
    if(libre==-1)
    {
        printf("\n No hay mas lugar! \n");
    }else
    {
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(vec[libre].name);

    printf("Ingrese el apellido: ");
    fflush(stdin);
    gets(vec[libre].lastName);

    printf("Ingrese el sueldo: ");
    scanf("%f", &vec[libre].salary);

    menuSectores();
    printf("Ingrese el sector: ");
    scanf("%d", &vec[libre].sector);

    vec[libre].id = id;

    vec[libre].isEmpty=0;

    retorno = 1;
    }

    return retorno;
}

int buscarLibre(eEmployee vec[], int tam)
{
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==1)
        {
            retorno = i;
            break;
        }
    }
return retorno;
}

void mostrarEmpleado(eEmployee emp, eSector sectores[], int tamsec)
{
    char descripcion[20];

    cargarDescripcionSector(descripcion,emp.sector,sectores,tamsec);



    printf("\n %d   %10s %10s  %.2f %10s",emp.id, emp.name, emp.lastName,emp.salary,descripcion);
}

void mostrarEmpleados(eEmployee vec[], int tam, eSector sectores[], int tamsec)
{
    int flag=0;

    printf("\n     **** LISTA DE EMPLEADOS **** \n");
    printf("\n   ID     NOMBRE     APELLIDO   SUELDO   SECTOR " );
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
        mostrarEmpleado(vec[i],sectores,tamsec);
        flag=1;
        }

    }
    printf("\n");
    if(flag==0)
    {
        printf("No hay empleados que listar");
    }
}


int buscarEmpleado(int id, eEmployee vec[], int tam)
{
    int retorno = -1;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].id == id)
        {
            retorno = i;

        }
    }
    return retorno;
}
int modificarEmpleado(int id, eEmployee vec[], int tam, eSector sectores[], int tamsec)
{
    int eleccion;
    int esta;

    system("cls");

    printf("     ***MODIFICAR EMPLEADO***\n\n");
    mostrarEmpleados(vec,tam,sectores,tamsec);
    printf("Ingrese ID a modificar: ");
    scanf("%d", &eleccion);
    esta = buscarEmpleado(eleccion,vec,tam);
    if(esta==-1)
    {
        printf("No se encontro el id, reintente");
    }else
    {
    system("cls");
    printf("\n   ID     NOMBRE     APELLIDO   SUELDO " );
       mostrarEmpleado(vec[esta],sectores,tamsec);
        switch(menuModificar()){
         case 1:
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(vec[esta].name);
        break;
    case 2:
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(vec[esta].lastName);
        break;
    case 3:
        printf("Ingrese sueldo: ");
        scanf("%f", &vec[esta].salary);
        break;
    case 4:
        break;
        }

    }
return 0;
}


int bajaEmpleado(int id, eEmployee vec[], int tam, eSector sectores[], int tamsec)
{
    int idIngresado;
    int esta;
    char  respuesta;
    system("cls");
    printf("*********BAJA EMPLEADO***********\n");

    mostrarEmpleados(vec,tam,sectores,tamsec);

    printf("Seleccione el id a dar de baja: ");
    scanf("%d", &idIngresado);

    esta=buscarEmpleado(idIngresado,vec,tam);
    if(vec[esta].isEmpty == 0 && vec[esta].id == idIngresado)
    {
        printf("\n   ID     NOMBRE     APELLIDO   SUELDO " );
        mostrarEmpleado(vec[esta],sectores,tamsec);
        printf("\nConfirma la baja? s/n: ");
        fflush(stdin);
        scanf("%c", &respuesta);
        if(respuesta == 's')
        {
            vec[esta].isEmpty=1;
            printf("\nBaja realizada con exito\n");
        }else
        {
            printf("Baja anulada\n");
        }
    }else
    {
        printf("No se encuentra el empleado con el id %d\n", idIngresado);
    }
    return 0;
}

int menuModificar()
{
    int opcion;
    printf("\n1. Modificar nombre\n");
    printf("2. Modificar apellido\n");
    printf("3. Modificar sueldo\n");
    printf("4. Anular operacion\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
