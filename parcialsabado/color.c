#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

void listarColores()
{
    printf("ID   COLOR\n");
    printf("5000-Gris\n");
    printf("5001-Negro\n");
    printf("5002-Blanco\n");
    printf("5003-Azul\n");
    printf("5004-Rojo\n");
}
int cargarDescripcionColor(int id, char nombreColor[],eColor color[], int tamc)
{
    int retorno = -1;
    for(int i=0;i<tamc;i++)
    {
        if(color[i].id == id)
        {
            strcpy(nombreColor,color[i].nombreColor);
            retorno = 1;
        }
    }

    return retorno;
}
