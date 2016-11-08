#ifndef BLOQUETABLAS_H
#define BLOQUETABLAS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Tablas.h"

typedef struct EncabezadoBloqueTablas _encabezadoBloqueTablas;
typedef struct BloqueTablas _bloqueTablas;

struct EncabezadoBloqueTablas
{
    int anterior;
    int siguiente;
    int cantidadTablas;
    _bloqueTablas* ptrBloqueTablas;
};

char* escribirEncabezadoTablas(char* cadena, _encabezadoBloqueTablas* temp, int seek);
char* escribirTablasEnBloque(char* cadena, _listaTabla* temp, _encabezadoBloqueTablas* encabezado, int seek);
char* escribirNodoEnTabla(char* cadena, _nodoTabla* temp, int seek);

char* escribirEncabezadoTablas(char* cadena, _encabezadoBloqueTablas* temp, int seek)
{
    /**Si imprime el encabezado de bloque lo que significa que si esta leyendo con memcpy**/

//------------->> ASI NO FUNCIONA---->PROBADO DE DIFERENTES MANERAS
//    memcpy(&(cadena[seek]), itoa(temp->anterior, &(cadena[seek]), 10), (strlen(cadena)+1-seek));
//    seek += (strlen(cadena)+1-seek);
//    memcpy(&(cadena[seek]), itoa(temp->siguiente, &(cadena[seek]), 10), (strlen(cadena)+1-seek));
//    seek += (strlen(cadena)+1-seek);
//    memcpy(&(cadena[seek]), itoa(temp->cantidadTablas, &(cadena[seek]), 10), (strlen(cadena)+1-seek));
//    seek += (strlen(cadena)+1-seek);


//-------------->> SOLO ASI DE PATITO SE LOGRA CONCATENAR LA STRING
//------------>> Le mando 2 de parametro por que creo que esto: itoa(temp->anterior, &(cadena[seek]), lo convierte a char
    memcpy(&(cadena[seek]), itoa(temp->anterior, &(cadena[seek]), 10), 2);
    seek += 2;
    memcpy(&(cadena[seek]), itoa(temp->siguiente, &(cadena[seek]), 10), 2);
    seek += 2;
    memcpy(&(cadena[seek]), itoa(temp->cantidadTablas, &(cadena[seek]), 10), 2);
    seek += 2;

    return cadena;
}

char* escribirTablasEnBloque(char* cadena, _listaTabla* temp, _encabezadoBloqueTablas* encabezado, int seek)
{
    _nodoTabla* NT;
    char* cadenaTemp;

    int i = 0;

    for(NT = temp->inicio; NT != NULL; NT = NT->siguiente, i++)
    {
        if(i < encabezado->cantidadTablas)
        {
            memcpy(&(cadena[seek]), NT->nombre_tabla, strlen(NT->nombre_tabla)+1);
            seek += strlen(NT->nombre_tabla);
            memcpy(&(cadena[seek]), itoa(NT->primerBloqueCampos, &(cadena[seek]), 10), 2);
            seek += 2;
            memcpy(&(cadena[seek]), itoa(NT->primerBloqueRegistros, &(cadena[seek]), 10), 2);
            seek += 2;
        }
    }
    return cadena;
}

#endif // BLOQUETABLAS_H
