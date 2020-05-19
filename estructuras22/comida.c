#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"

void mostrarComidas(eComida comidas[], int tam)
{
    printf("LISTADO DE COMIDAS\n\n");
    printf("   Id   Descipcion      Precio\n");
    for(int i=0;i<tam;i++)
    {
        printf(" %d  %10s   %5.2f\n",comidas[i].id,comidas[i].descripcion,comidas[i].precio);
    }
}

int cargarDescripcionComida(char descripcion[], int id, eComida comidas[], int tamcom)
{
    int todoOk=0;
    for(int i=0;i<tamcom;i++)
    {
        if(comidas[i].id == id)
        {
            strcpy(descripcion,comidas[i].descripcion);
            todoOk=1;
        }
    }

return todoOk;
}
