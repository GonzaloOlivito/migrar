#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "utn.h"
#include "tipo.h"
#include "color.h"
#include "datawarehouse.h"

char menuOpciones()
{
    char opcion;
    system("cls");

    printf("BIENVENIDO \n\n");
    printf("A.Alta bicicleta\n");
    printf("B.Modificar bicicleta\n");
    printf("C.Baja bicicleta\n");
    printf("D.Lista bicicletas\n");
    printf("E.Listar tipos\n");
    printf("F.Listar colores\n");
    printf("G.Listar Servicios\n");
    printf("H.Alta trabajo\n");
    printf("I. Salir\n");
    printf("Ingrese la opcion deseada: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

void inicializarBicicletas(eBicicleta vec[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].isEmpty=1;
    }
}

int buscarLibre(eBicicleta vec[], int tam)
{
    int retorno = -1;
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
int buscarBicicleta(int id, eBicicleta vec[], int tam)
{

    int retorno = -1;
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0 && vec[i].id == id)
        {
        retorno = i;
        break;
    }

    }
    return retorno;
}

int altaBicicleta(eBicicleta vec[], int tam)
{
    system("cls");
    printf("**ALTA BICICLETA**\n\n");
    int todoOk=0;
    int libre=buscarLibre(vec,tam);
    int esta;
    int id;
    if(libre==-1)
    {
        printf("No hay lugar\n");
    }else
    {
        getIntRange(&id,0,99999,"Ingrese id: ");
        esta=buscarBicicleta(id,vec,tam);
        if(esta==-1)
        {
            vec[libre].id=id;
            getStringAlpha(20,"Ingrese la marca: ", vec[libre].marca);
            listarTipos();
            getIntRange(&vec[libre].idTipo,1000,1003,"Ingrese el id tipo: ");
            listarColores();
            getIntRange(&vec[libre].idColor,5000,5003,"Ingrese el id color: ");
            getFloatRange(0,999,&vec[libre].rodado,"Ingrese el rodado: ");
            vec[libre].isEmpty=0;
            todoOk=1;
            printf("\nAlta exitosa! \n");
        }else{
        printf("El id ya esta registrado, reintente.\n");
        }
    }

    return todoOk;
}

void mostrarBici (eBicicleta bici, int tam, eTipo tipoBici[], int tamTipo, eColor colorBici[], int tamColor)
{
    char tipoDes[20];
    char colorDes[20];
    cargarDescripcionTipo(tipoDes,tipoBici,tamTipo,bici.idTipo);
    cargarDescripcionColor(bici.idColor,colorDes,colorBici,tamColor);
    printf("%d   %5s    %8s %8s    %.2f\n", bici.id,bici.marca,tipoDes,colorDes,bici.rodado);
}

void mostrarBicis (eBicicleta vec[], int tam, eTipo tipoBici[], int tamTipo, eColor colorBici[], int tamColor)
{
    system("cls");
    printf("** LISTADO BICIS ** \n\n");
    printf("ID     MARCA       TIPO     COLOR   RODADO \n");
    int flag=-1;
    for(int i =0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarBici(vec[i],tam,tipoBici,tamTipo,colorBici,tamColor);
            flag=1;
        }
    }
    if(flag==-1)
    {
        printf("No hay bicis que mostrar\n\n");
    }
}

void hardcoreo(eBicicleta vec[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        vec[i].id=ids[i];
        vec[i].idColor=idsColor[i];
        vec[i].idTipo=idsTipo[i];
        strcpy(vec[i].marca,marcas[i]);
        vec[i].rodado=rodados[i];
        vec[i].isEmpty=0;

    }
}

int modificarBicicleta(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc)
{
    int id;
    int eleccion;
    int retorno=-1;
    int esta;
    system("cls");
    printf("***MENU MODIFICACION***\n\n");
    mostrarBicis(vec,tam,tipo,tam,color,tamc);

    getIntRange(&id,0,9999,"Ingrese el id a modificar: ");
    esta=buscarBicicleta(id,vec,tam);
    if(esta== -1)
    {
        printf("Id mal ingresado, reintente.");
    } else
    {
        printf("1. Modificar tipo\n");
        printf("2. Modificar rodado\n");
        getIntRange(&eleccion,1,2,"Ingrese la opcion a modificar: ");
        switch(eleccion)
        {
        case 1:
        listarTipos();
        getIntRange(&vec[esta].idTipo,1000,1004, "Ingrese el nuevo tipo: ");
        break;
        case 2:
        getFloatRange(0,999,&vec[esta].rodado,"Ingrese el nuevo rodado: ");
        break;
        retorno = 1;
        }
    }

    return retorno;
}

int bajaBicicleta(eBicicleta vec[], int tam, eTipo tipo[], int tamt, eColor color[], int tamc)
{
    int id;
    char eleccion;
    int retorno=-1;
    int esta;
    system("cls");
    printf("***MENU BAJA***\n\n");
    mostrarBicis(vec,tam,tipo,tam,color,tamc);

    getIntRange(&id,0,9999,"Ingrese el id a dar de baja: ");
    esta=buscarBicicleta(id,vec,tam);
    if(esta== -1)
    {
        printf("Id mal ingresado, reintente.");
    } else
    {
        getChar(3,&eleccion,"Confirma baja? s/n");
        if(eleccion == 's')
        {
            vec[esta].isEmpty=1;
            printf("Baja realizada con exito");
            retorno = 1;
        }
        }
    return retorno;
    }

