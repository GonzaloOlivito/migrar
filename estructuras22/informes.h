#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

void informes(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
char menuInformes();
void listarEmpleadosXanio(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void listarEmpleadas(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void informarTotalSueldos(eEmpleado vec[], int tam);
void informarEmpleadosDeSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void informarEmpleadoXSector (eEmpleado vec[], int tam, eSector sectores [], int tamsec);
void informarMayorSueldoSector (eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void empleadoJovenSector(eSector sectores[], int tamsec, eEmpleado vec[], int tam);
