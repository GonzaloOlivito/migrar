#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"


void listarSectores(eSector sectores[], int tamsec)
{

    printf("****Listado sectores****\n\n");
    printf(" Id    Sector\n");
    for(int i = 0; i<tamsec; i++)
    {

    printf("%d      %10s\n", sectores[i].id, sectores[i].descripcion);

    }
    printf("\n\n");

}

