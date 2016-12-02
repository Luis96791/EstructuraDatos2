#ifndef BLOQUETABLAS_H
#define BLOQUETABLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"
#include "BloqueCampos.h"
#include "BloqueRegistros.h"

typedef struct BloqueTablas _bloqueTablas;
typedef struct ListaBloqueTablas _listaBloqueTablas;

struct BloqueTablas
{
    int bloque_anterior;
    int bloque_siguiente;
    int cantidad_tablas;
    _bloqueTablas* siguiente;
    _listaTablas* listaTablas;
};

struct ListaBloqueTablas
{
    _bloqueTablas* inicio;
};

_listaBloqueTablas* nuevaListaBloqueTablas();
void nuevoBloqueTablas(int bloque_anterior, int bloque_siguiente, int cantidad_tablas, _listaBloqueTablas* listaBloqueTablas, _tabla* tabla);
void agregarNuevoBloqueTablasLista(_listaBloqueTablas* listaBloqueTablas, _bloqueTablas* bloqueTablas, _tabla* tabla);
void agregarTablaEnBloqueExistente(_bloqueTablas* bloqueTablas, _tabla* tabla);
void listarBloqueTablas(_listaBloqueTablas* listaBloqueTablas);
int getCantidadDeTablasEnBloque(_bloqueTablas* bloqueTablas);
_bloqueTablas* getUltimoBloqueTablas(_listaBloqueTablas* listaBloqueTablas);
void agregarTablaEnBloqueTablas(_tabla* tabla, _listaBloqueTablas* listaBloqueTablas, int bloque_anterior, int bloque_siguiente, int cantidad_tablas);

_listaBloqueTablas* nuevaListaBloqueTablas()
{
    _listaBloqueTablas* listaBloqueTablas;

    listaBloqueTablas = (_listaBloqueTablas *)malloc(sizeof(_listaBloqueTablas));
    listaBloqueTablas->inicio = NULL;
    return listaBloqueTablas;
}

void nuevoBloqueTablas(int bloque_anterior, int bloque_siguiente, int cantidad_tablas, _listaBloqueTablas* listaBloqueTablas, _tabla* tabla)
{
    _bloqueTablas* bloqueTablas;

    bloqueTablas = (_bloqueTablas *)malloc(sizeof(_bloqueTablas));
    bloqueTablas->bloque_anterior = bloque_anterior;
    bloqueTablas->bloque_siguiente = bloque_siguiente;
    bloqueTablas->cantidad_tablas = cantidad_tablas;
    bloqueTablas->listaTablas = nuevaListaTablas();
    bloqueTablas->siguiente = NULL;

    agregarNuevoBloqueTablasLista(listaBloqueTablas, bloqueTablas, tabla);
}

void agregarNuevoBloqueTablasLista(_listaBloqueTablas* listaBloqueTablas, _bloqueTablas* bloqueTablas, _tabla* tabla)
{
    _bloqueTablas* temporal;

    if(listaBloqueTablas->inicio == NULL)
    {
        listaBloqueTablas->inicio = bloqueTablas;
        agregarTabla(tabla->nombreTabla, bloqueTablas->listaTablas, tabla->primerBloqueCampos, tabla->primerBloqueRegistros);
        return;
    }
    temporal = listaBloqueTablas->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = bloqueTablas;
    agregarTabla(tabla->nombreTabla, bloqueTablas->listaTablas, tabla->primerBloqueCampos, tabla->primerBloqueRegistros);
}

void agregarTablaEnBloqueExistente(_bloqueTablas* bloqueTablas, _tabla* tabla)
{
    agregarTabla(tabla->nombreTabla, bloqueTablas->listaTablas, tabla->primerBloqueCampos, tabla->primerBloqueRegistros);
}

void listarBloqueTablas(_listaBloqueTablas* listaBloqueTablas)
{
    _bloqueTablas* temporal = listaBloqueTablas->inicio;

    while(temporal != NULL)
    {
        printf("%d %d %d \n", temporal->bloque_anterior, temporal->bloque_siguiente, temporal->cantidad_tablas);
        listarTablas(temporal->listaTablas);
        temporal = temporal->siguiente;
    }
}

_bloqueTablas* getUltimoBloqueTablas(_listaBloqueTablas* listaBloqueTablas)
{
    _bloqueTablas* temporal = listaBloqueTablas->inicio;

    while( 1 )
    {
        if(temporal->siguiente == NULL)
            return temporal;
        else
            temporal = temporal->siguiente;
    }
    return NULL;
}

int getCantidadDeTablasEnBloque(_bloqueTablas* bloqueTablas)
{
    int contador = 0;
    _tabla* temporal = bloqueTablas->listaTablas->inicio;

    if(temporal == NULL)
        return contador;

    while(temporal != NULL)
    {
        temporal = temporal->siguiente;
        contador++;
    }

    return contador;
}

void agregarTablaEnBloqueTablas(_tabla* tabla, _listaBloqueTablas* listaBloqueTablas, int bloque_anterior, int bloque_siguiente, int cantidad_tablas)
{

    if(listaBloqueTablas->inicio == NULL)
    {
        nuevoBloqueTablas(bloque_anterior, bloque_siguiente, cantidad_tablas, listaBloqueTablas, tabla);
        return;
    }

     _bloqueTablas* ultimoBloqueListaTablas = getUltimoBloqueTablas(listaBloqueTablas);

    if(getCantidadDeTablasEnBloque(ultimoBloqueListaTablas) < ultimoBloqueListaTablas->cantidad_tablas)
    {
        agregarTablaEnBloqueExistente(ultimoBloqueListaTablas, tabla);
    }
    else{
        nuevoBloqueTablas(bloque_anterior, bloque_siguiente, cantidad_tablas, listaBloqueTablas, tabla);
    }
}

#endif // BLOQUETABLAS_H
