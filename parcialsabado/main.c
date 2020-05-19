#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#include "tipo.h"
#include "color.h"
#include "bicicleta.h"

#define TAM 5
#define TAMT 4
#define TAMC 5
#define TAMHARD 4
int main()
{
    char respuesta;
    char seguir = 's';

    eBicicleta bicis[TAM];
    eTipo tipos[TAMT]={{1000,"Rutera"},{1001,"Carrera"},{1002,"Mountain"},{1003,"BMX"}};
    eColor colores[TAMC]={{5000,"Gris"},{5001,"Negro"},{5002,"Blanco"},{5003,"Azul"},{5004,"Rojo"}};
    inicializarBicicletas(bicis,TAM);
    hardcoreo(bicis,TAMHARD);
     do
    {

        switch(menuOpciones())
        {
        case 'a':
            altaBicicleta(bicis,TAM);
            break;
        case 'b':
            modificarBicicleta(bicis,TAM,tipos,TAMT,colores,TAMC);
            break;
        case 'c':
            bajaBicicleta(bicis,TAM,tipos,TAMT,colores,TAMC);
            break;
        case 'd':
            mostrarBicis(bicis,TAM,tipos,TAMT,colores,TAMC);
            break;
        case 'e':
            system("cls");
            listarTipos(tipos,TAMT);
            break;
        case 'f':
            system("cls");
            listarColores(colores,TAMC);
            break;
        case 'g':

            break;
        case 'h':

            break;
        case 'i':
            printf("\nSeguro que desea salir?s/n: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                seguir='n';
            }
            break;
        }
        system("pause");
    }
    while(seguir == 's');
    return 0;

    return 0;
}
