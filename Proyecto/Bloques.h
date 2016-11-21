#ifndef BLOQUE_H
#define BLOQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BloquesTablas.h"

typedef struct Bloque _bloque;
typedef struct ListaBloques _listaBloques;


struct Bloque
{
    int bloqueAnterior;
    int bloqueSiguiente;
    int cantTablasEnBloque;
    _listaBloqueTablas* ptrListaBloqueTablas;
    _bloque* siguiente;
};

struct ListaBloques
{
    _bloque* inicio;
};

/** -------------------- Funciones ---------------------- **/
_listaBloques* nuevaListaBloques();
void agregarBloque(_listaBloques* listaBloques, int bloqueAnterior, int bloqueSiguiente, int cantTablas);
void listarBloques(_listaBloques* listaBloques);
void setListaBloqueTablas(_bloque* bloque, _listaBloqueTablas* listaBloqueTablas);
_bloque* getUltimoBloque(_listaBloques* listaBloques);
/** -------------------- Funciones ---------------------- **/

_listaBloques* nuevaListaBloques()
{
    _listaBloques* listaBloques;

    listaBloques = (_listaBloques* )malloc(sizeof(_listaBloques));
    listaBloques->inicio = NULL;

    return listaBloques;
}

void agregarBloque(_listaBloques* listaBloques, int bloqueAnterior, int bloqueSiguiente, int cantTablas)
{
    _bloque* temporal;

    if(listaBloques->inicio == NULL)
    {
        listaBloques->inicio = (_bloque *)malloc(sizeof(_bloque));
        listaBloques->inicio->bloqueAnterior = bloqueAnterior;
        listaBloques->inicio->bloqueSiguiente = bloqueSiguiente;
        listaBloques->inicio->cantTablasEnBloque = cantTablas;
        listaBloques->inicio->ptrListaBloqueTablas = NULL;
        listaBloques->inicio->siguiente = NULL;
    }
    else{
        temporal = listaBloques->inicio;

        while(temporal->siguiente != NULL)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = (_bloque *)malloc(sizeof(_bloque));
        temporal->siguiente->bloqueAnterior = bloqueAnterior;
        temporal->siguiente->bloqueSiguiente = bloqueSiguiente;
        temporal->siguiente->cantTablasEnBloque = cantTablas;
        temporal->siguiente->ptrListaBloqueTablas = NULL;
        temporal->siguiente->siguiente = NULL;
    }
}

void listarBloques(_listaBloques* listaBloques)
{
    _bloque* temporal = listaBloques->inicio;

    while(temporal != NULL)
    {
        printf("%d, %d, %d", temporal->bloqueAnterior, temporal->bloqueSiguiente, temporal->cantTablasEnBloque);
        temporal = temporal->siguiente;
    }
}

void setListaBloqueTablas(_bloque* bloque, _listaBloqueTablas* listaBloqueTablas)
{
    bloque->ptrListaBloqueTablas = listaBloqueTablas;
}

_bloque* getUltimoBloque(_listaBloques* listaBloques)
{
    _bloque* temporal = listaBloques->inicio;

    if(temporal == NULL)
    {
        return NULL;
    }
    else{
        while( 1 )
        {
            if(temporal->siguiente == NULL)
            {
                return temporal;
            }
            else{
                temporal = temporal->siguiente;
            }
        }
    }
}

#endif // BLOQUE_H
