#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

void listarTipos()
{
    printf(" ID  TIPO\n");
    printf("1000-Rutera\n");
    printf("1001-Carrera\n");
    printf("1002-Mountain\n");
    printf("1003-BMX\n");
}

int cargarDescripcionTipo(char descripcion[], eTipo tipos[], int tamt, int id)
{
    int retorno = -1;
    for(int i=0;i<tamt;i++)
    {
        if(tipos[i].id==id)
        {
            strcpy(descripcion,tipos[i].descripcion);
            retorno = 1;
        }
    }

    return retorno;
}
