#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"

#define TAM 10
#define CANTHARDCODE 9
#define TAMSECTOR 5
#define TAMC 5
#define TAMA 100


int main()
{

    int idIncrementado=1000;
    int idAlmuerzo=20000;
    char respuesta;
    char seguir = 's';
    eEmpleado lista[TAM];
    eSector sectores[TAMSECTOR] = {{1,"Informatica"},{2,"RRHH"},{3,"Compras"},{4,"Ventas"},{5,"Contable"}};
    eComida comidas[TAMC] = {{100,"Milanesa", 150},{101,"Ensalada", 170},{103,"Fideos",120},{104,"Sopa",110},{105,"Pizza",125}};
    eAlmuerzo almuerzos[TAMA];
    inicializarEmpleados(lista,TAM);
    inicializarAlmuerzo(almuerzos,TAMA);

    hardcodearEmpleados(lista,CANTHARDCODE);
    idIncrementado +=CANTHARDCODE;

    do
    {

        switch(menuOpciones())
        {
        case 1:
            if(altaEmpleado(idIncrementado,lista,TAM,sectores,TAMSECTOR))
            {
                idIncrementado++;
            }

            break;
        case 2:
            modificarEmpleado(lista,TAM,sectores,TAMSECTOR);
            break;
        case 3:
            bajaEmpleado(lista,TAM,sectores,TAMSECTOR);
            break;
        case 4:
            printf("Ordenar empleado");
            break;
        case 5:
            mostrarEmpleados(lista,TAM,sectores,TAMSECTOR);
            break;
        case 6:
            informes(lista,TAM,sectores,TAMSECTOR);
            break;
        case 7:
            mostrarAlmuerzos(almuerzos,TAMA,lista,TAM,comidas,TAMC);
            break;
        case 8:
            if(altaAlmuerzo(idIncrementado,almuerzos,TAMA,lista,TAM,comidas,TAMC,sectores,TAMSECTOR))
            {
                idAlmuerzo++;
            }
            break;

            case 10:
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
}

