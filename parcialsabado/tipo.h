
#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


typedef struct{
int id;
char descripcion[20];
}eTipo;


#endif // TIPO_H_INCLUDED

void listarTipos();
int cargarDescripcionTipo(char descripcion[], eTipo tipos[], int tamt, int id);
