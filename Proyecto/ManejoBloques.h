#ifndef MANEJOBLOQUES_H
#define MANEJOBLOQUES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BloqueTablas.h"
#include "Tablas.h"

#define TRUE    1
#define FALSE   0

void agregarTablaEnBloque(char* nombreTabla, _listaBloques* listaBloques, _listaBloqueTablas* listaBloqueTablas);
void administrarTablas(char* nombreTabla, char* data);
int hayEspacioDisponible(_bloque* bloque);
_bloque* getUltimoBloque(_listaBloques* listaBloques);
char* escribirBloqueTablas(char* cadena, _bloque* bloque, int seek);

_bloque* getUltimoBloque(_listaBloques* listaBloques)
{
    _bloque* temporal = listaBloques->inicio;

    if(temporal == NULL)
    {
        return NULL;
    }

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    return temporal;
}

void agregarTablaEnBloque(char* nombreTabla, _listaBloques* listaBloques, _listaBloqueTablas* listaBloqueTablas)
{
    _bloque* bloque = getUltimoBloque(listaBloques);

    if(bloque == NULL)
    {
        insertarBloque(listaBloques, -1, -1, 4);
        bloque = getUltimoBloque(listaBloques);
        insertarTablasEnBloque(listaBloqueTablas, nombreTabla, bloque);
    }
    else{
        bloque = getUltimoBloque(listaBloques);
        if(hayEspacioDisponible(bloque))
        {
            insertarTablasEnBloque(listaBloqueTablas, nombreTabla, bloque);
        }
        else{
            insertarBloque(listaBloques,-1,-1,4);
            agregarTablaEnBloque(nombreTabla,listaBloques,listaBloqueTablas);
        }
    }
}

int hayEspacioDisponible(_bloque* bloque)
{
    if(getSizeListaBloqueTablas(bloque->ptrListaBloqueTablas) < bloque->cantidadTablas)
    {
        return TRUE;
    }
    return FALSE;
}

void administrarTablas(char* nombreTabla, char* data)
{
    _listaBloques* listaBloques;
    listaBloques = nuevaListaBloques();
    _listaBloqueTablas* listaBloqueTablas;
    listaBloqueTablas = nuevaListaBloqueTablas();

    agregarTablaEnBloque(nombreTabla, listaBloques, listaBloqueTablas);
    escribirBloqueTablas(data, listaBloques->inicio, 0);
}

char* escribirBloqueTablas(char* cadena, _bloque* bloque, int seek)
{
    memcpy(&(cadena[seek]), itoa(bloque->posAnterior, &(cadena[seek]), 10), 2);
    seek += 2;
    memcpy(&(cadena[seek]), itoa(bloque->posSiguiente, &(cadena[seek]), 10), 2);
    seek += 2;
    memcpy(&(cadena[seek]), itoa(bloque->cantidadTablas, &(cadena[seek]), 10), 2);
    seek += 2;
    _bloqueTablas* bloqueTablas = bloque->ptrListaBloqueTablas->inicio;

    while(bloqueTablas != NULL)
    {
        memcpy(&(cadena[seek]), bloqueTablas->nombreTabla, strlen(bloqueTablas->nombreTabla));
        seek += strlen(bloqueTablas->nombreTabla);
        memcpy(&(cadena[seek]), itoa(bloqueTablas->posPrimerBloqueCampos, &(cadena[seek]), 10), 2);
        seek += 2;
        memcpy(&(cadena[seek]), itoa(bloqueTablas->posPrimerBloqueRegistros, &(cadena[seek]), 10), 2);
        seek += 2;
        bloqueTablas = bloqueTablas->siguiente;
    }

    return cadena;
}

#endif // MANEJOBLOQUES_H
