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
    _listaTablas* ptrlistaTablas;
    _bloque* siguiente;
};

struct ListaBloques
{
    _bloque* inicio;
};

/** -------------------- Funciones ---------------------- **/
_listaBloques* nuevaListaBloques();
void agregarTabla_ABloque(char* nombreTabla, _listaBloques* listaBloques);
void agregarBloque(_listaBloques* listaBloques, int cantTablas);
void agregarBloqueLista(_bloque* bloque, _listaBloques* listaBloques);
void listarBloques(_listaBloques* listaBloques);
_bloque* getUltimoBloque(_listaBloques* listaBloques);
int cantidadTablasPorBloque(_bloque* bloque);
/** -------------------- Funciones ---------------------- **/

_listaBloques* nuevaListaBloques()
{
    _listaBloques* listaBloques;

    listaBloques = (_listaBloques* )malloc(sizeof(_listaBloques));
    listaBloques->inicio = NULL;

    return listaBloques;
}

void agregarBloque(_listaBloques* listaBloques, int cantTablas)
{
    _bloque* bloque;

    bloque = (_bloque *)malloc(sizeof(_bloque));
    bloque->bloqueAnterior = -1;
    bloque->bloqueSiguiente = -1;
    bloque->cantTablasEnBloque = cantTablas;
    bloque->ptrlistaTablas = NULL;

    agregarBloqueLista(bloque, listaBloques);
}

void agregarBloqueLista(_bloque* bloque, _listaBloques* listaBloques)
{
    _bloque* temporal;

    if(listaBloques->inicio == NULL)
    {
        listaBloques->inicio = bloque;
        return;
    }

    temporal = listaBloques->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = bloque;
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

void agregarTabla_ABloque(char* nombreTabla, _listaBloques* listaBloques)
{
    _bloque* bloque = getUltimoBloque(listaBloques);

    if(bloque->cantTablasEnBloque < cantidadTablasPorBloque(bloque))
    {
        /**WORKING HERE**/
    }
}

_bloque* getUltimoBloque(_listaBloques* listaBloques)
{
    _bloque* bloque = listaBloques->inicio;

    if(listaBloques->inicio == NULL)
    {
        return NULL;
    }

    while( 1 )
    {
        if(bloque->siguiente == NULL)
        {
            return bloque;
        }
        else{
            bloque = bloque->siguiente;
        }
    }
}

int cantidadTablasPorBloque(_bloque* bloque)
{
    _tabla* tabla = bloque->ptrlistaTablas->inicio;
    int contador = 0;

    if(bloque->ptrlistaTablas->inicio == NULL)
    {
        return contador;
    }
    while(tabla != NULL)
    {
        contador++;
        tabla = tabla->siguiente;
    }
    return contador;
}

//
//void setListaBloqueTablas(_listaBloques* listaBloques, _listaBloqueTablas* listaBloqueTablas)
//{
//    getUltimoBloque(listaBloques)->ptrListaBloqueTablas = listaBloqueTablas;
//}
//
//void setListaBloqueCampos(_listaBloques* listaBloques, _listaBloquesCampos* listaBloquesCampos)
//{
//    getUltimoBloque(listaBloques)->ptrListaBLoquesCampos = listaBloquesCampos;
//}
//
//_bloque* getUltimoBloque(_listaBloques* listaBloques)
//{
//    _bloque* temporal = listaBloques->inicio;
//
//    if(temporal == NULL)
//    {
//        return NULL;
//    }
//    else{
//        while( 1 )
//        {
//            if(temporal->siguiente == NULL)
//            {
//                return temporal;
//            }
//            else{
//                temporal = temporal->siguiente;
//            }
//        }
//    }
//}

#endif // BLOQUE_H
