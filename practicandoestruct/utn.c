#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#define TRUE 1
#define FALSE 0


//----------------------------------------------------------------------------------------------------------------------------
int getString(int longMax, int intentos, char* mensaje, char* dondeAsignar)
{
    int todoOk = 1;
    char aux[longMax];
int i;
    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);

    for(i=0; i<strlen(aux); i++)
    {
        while((isalpha(aux[i])==0) || strlen(aux) > longMax)
        {
            intentos--;
            if(intentos == 0)
            {
                todoOk=0;
                break;
            }
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    strlwr(aux);
    aux[0]=toupper(aux[0]);

    if(intentos != 0)
    {
        strcpy(dondeAsignar, aux);
    }


    return todoOk;
}
//----------------------------------------------------------------------------------------------------------------------------

void getFloat(float min, float max, float* dondeAsignar, char* mensaje)
{
    float auxFloat;
    char aux[20];
int i;
    printf("%s",mensaje);
    gets(aux);

    for(i=0; i<strlen(aux); i++)
    {
        while((isdigit(aux[i])==0))
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    auxFloat=atoi(aux);


    while(auxFloat < min || auxFloat > max)
    {
        printf("Error. %s",mensaje);
        scanf("%f",&auxFloat);
    }

        *dondeAsignar = auxFloat;

}

void getInt(int min, int max, int* dondeAsignar, char* mensaje)
{
    int auxInt;
    char aux[20];
int i;
    printf("%s",mensaje);
    gets(aux);

    for(i=0; i<strlen(aux); i++)
    {
        while((isdigit(aux[i])==0))
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    auxInt=atoi(aux);


    while(auxInt < min || auxInt > max)
    {
        printf("Error. %s",mensaje);
        scanf("%d",&auxInt);
    }

        *dondeAsignar = auxInt;

}
