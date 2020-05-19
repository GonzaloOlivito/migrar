#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 7
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
} eEmpleado;

void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);
void ordenarEmpleados(eEmpleado vec[], int tam);
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(int id,eEmpleado vec[], int tam);
void altaEmpleado(eEmpleado vec[], int tam);
void bajaempleado(eEmpleado vec[], int tam);
void modificarEmpleado(eEmpleado vec[], int tam);
int minimenu();
int menu();
int main()
{
    char seguir='s';
    char confirma;
    eEmpleado lista[TAM]= {{8921,"Julio",'m',30,34000.00,{12,12,2012}},
        {1234,"Ramon",'m',32,31000.00,{21,03,2015}},
        {3467,"Ana",'f',29,35400.00,{23,11,2019}},
        {1012,"Miguel",'m',34,49000.00,{23,11,2019}},
        {4534,"Daniela",'f',23,37400.00,{6,9,2019}}
    };
    // inicializarEmpleados(lista,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(lista,TAM);
            break;
        case 2:
            modificarEmpleado(lista,TAM);
            break;
        case 3:
            bajaempleado(lista, TAM);
            break;
        case 4:
            printf("Ordenar");
            break;
        case 5:
            mostrarEmpleados(lista,TAM);
            break;
        case 6:
            printf("Informes");
            break;
        case 7:
            printf("\nSeguro que desea salir?s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir='n';
            }
            break;
        }
        system("pause");
    }
    while(seguir == 's');

    return 0;
}
void mostrarEmpleado(eEmpleado emp)
{
    printf("%d%10s   %c     %d    %.2f    %d/%d/%d\n", emp.id, emp.nombre,emp.sexo,emp.edad,emp.sueldo,emp.fechaIngreso.dia,emp.fechaIngreso.mes,emp.fechaIngreso.anio );


}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int flag=0;
    printf("****Listado Empleados****\n\n");
    printf(" Id      Nombre  Sexo  Edad   Sueldo    FechaIngreso\n");
    for(int i = 0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i]);
            flag=1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay empleados que listar\n");
    }
}
void ordenarEmpleados(eEmpleado vec[], int tam)
{
    eEmpleado auxEmp;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i].sexo>vec[j].sexo)
            {
                auxEmp=vec[i];
                vec[i]=vec[j];
                vec[j]=auxEmp;
            }
            else if(vec[i].sexo == vec[j].sexo)
            {
                auxEmp=vec[i];
                vec[i]=vec[j];
                vec[j]=auxEmp;
            }
        }
    }
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int menu()
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
    printf("7.Salir\n");
    printf("Ingrese la opcion deseada: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(int id,eEmpleado vec[], int tam)
{
    int retorno=-1;
    for(int i; i<tam; i++)
    {
        if(vec[i].id==id && vec[i].isEmpty == 0)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}

void altaEmpleado(eEmpleado vec[], int tam)
{
    int libre=buscarLibre(vec,tam);
    int esta=buscarEmpleado(libre,vec,tam);
    int id;
    eEmpleado auxEmpleado;

    system("cls");
    printf("*****ALTA EMPLEADO*****\n\n");

    if(libre==-1 ) // hay lugar?
    {
        printf("No hay lugar!");
    }
    else
    {
        printf("Ingrese id: ");
        scanf("%d", &id);
        esta=buscarEmpleado(id,vec,tam);
        if(esta != -1)
        {
            printf("El id ya se encuentra cargado");
        }
        else
        {
            auxEmpleado.id=id;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &auxEmpleado.sexo);

            printf("Ingrese edad: ");
            scanf("%d", &auxEmpleado.edad);

            printf("Ingrese sueldo: ");
            scanf("%f", &auxEmpleado.sueldo);

            printf("Ingrese fecha ingreso dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxEmpleado.fechaIngreso.dia,&auxEmpleado.fechaIngreso.mes,&auxEmpleado.fechaIngreso.anio);

            auxEmpleado.isEmpty=0;

            vec[libre]=auxEmpleado;

        }
    }

}

void bajaempleado(eEmpleado vec[], int tam)
{
    int id;
    int esta;
    char respuesta;
    system("cls");
    printf("*****BAJA EMPLEADO*****\n\n");
    printf("Ingrese id a dar de baja: ");
    scanf("%d", &id);
    esta=buscarEmpleado(id,vec,tam);
    if(esta==-1)
    {
        printf("No se encontro al empleado con id: %d Reintente.\n\n", id);
    }
    else
    {
        printf("Baja al empleado: \n");
        mostrarEmpleado(vec[esta]);
        printf("Confirma baja s/n: ");
        fflush(stdin);
        scanf("%c", &respuesta);
        if(respuesta=='s')
        {
            vec[esta].isEmpty=1;
            printf("Baja realizada con exito.");
        }
        else
        {
            printf("Baja cancelada.");
        }
    }
}

void modificarEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int esta;
    system("cls");
    printf("*****MODIFICAR EMPLEADO*****\n\n");
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
        mostrarEmpleado(vec[esta]);
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
        mostrarEmpleado(vec[esta]);
    }
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
