#ifndef BLOQUEREGISTROS_H
#define BLOQUEREGISTROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Registros.h"
#include "CampoDato.h"

typedef struct BloqueRegistros _bloqueRegistros;
typedef struct ListaBloqueRegistros _listaBloqueRegistros;

struct BloqueRegistros
{
    int bloque_anterior;
    int bloque_siguiente;
    int cantidad_registros;
    _bloqueRegistros* siguiente;
    _listaRegistros* listaRegistros;
};

struct ListaBloqueRegistros
{
    _bloqueRegistros* inicio;
};

_listaBloqueRegistros* nuevaListaBloqueRegistros();
void nuevoBloqueRegistros(int bloque_anterior, int bloque_siguiente, int cantidad_registros, _listaBloqueRegistros* listaBloqueRegistros, _registro* registro);
void agregarNuevoBloqueRegistrosLista(_listaBloqueRegistros* listaBloqueRegistros, _bloqueRegistros* bloqueRegistros, _registro* registro);
void agregarRegistroEnBloqueExistente(_bloqueRegistros* bloqueRegistros, _registro* registro);
void listarBloqueRegistros(_listaBloqueRegistros* listaBloqueRegistros);
_bloqueRegistros* getUltimoBloqueRegistros(_listaBloqueRegistros* listaBloqueRegistros);
int getCantidadDeRegistrosEnBloque(_bloqueRegistros* bloqueRegistros);
void agregarRegistroEnBloqueRegistros(_registro* registro, _listaBloqueRegistros* listaBloqueRegistros, int bloque_anterior, int bloque_siguiente, int cantidad_registros);

_listaBloqueRegistros* nuevaListaBloqueRegistros()
{
    _listaBloqueRegistros* listaBloqueRegistros;

    listaBloqueRegistros = (_listaBloqueRegistros *)malloc(sizeof(_listaBloqueRegistros));
    listaBloqueRegistros->inicio = NULL;
    return listaBloqueRegistros;
}

void nuevoBloqueRegistros(int bloque_anterior, int bloque_siguiente, int cantidad_registros, _listaBloqueRegistros* listaBloqueRegistros, _registro* registro)
{
    _bloqueRegistros* bloqueRegistros;

    bloqueRegistros = (_bloqueRegistros *)malloc(sizeof(_bloqueRegistros));
    bloqueRegistros->bloque_anterior = bloque_anterior;
    bloqueRegistros->bloque_siguiente = bloque_siguiente;
    bloqueRegistros->cantidad_registros = cantidad_registros;
    bloqueRegistros->listaRegistros = nuevaListaRegistros();
    bloqueRegistros->siguiente = NULL;

    agregarNuevoBloqueRegistrosLista(listaBloqueRegistros, bloqueRegistros, registro);
}

void agregarNuevoBloqueRegistrosLista(_listaBloqueRegistros* listaBloqueRegistros, _bloqueRegistros* bloqueRegistros, _registro* registro)
{
    _bloqueRegistros* temporal;

    if(listaBloqueRegistros->inicio == NULL)
    {
        listaBloqueRegistros->inicio = bloqueRegistros;
        agregarRegistro(bloqueRegistros->listaRegistros, 0);
        return;
    }
    temporal = listaBloqueRegistros->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = bloqueRegistros;
    agregarRegistro(bloqueRegistros->listaRegistros, 0);
}

void agregarRegistroEnBloqueExistente(_bloqueRegistros* bloqueRegistros, _registro* registro)
{
    agregarRegistro(bloqueRegistros->listaRegistros, 0);
}

void listarBloqueRegistros(_listaBloqueRegistros* listaBloqueRegistros)
{
    printf("\n--Listando Los Bloque de Registros--\n\n");
    _bloqueRegistros* temporal = listaBloqueRegistros->inicio;

    while(temporal != NULL)
    {
        printf("%d %d %d \n", temporal->bloque_anterior, temporal->bloque_siguiente, temporal->cantidad_registros);
        listarRegistros(temporal->listaRegistros);
        temporal = temporal->siguiente;
    }
}

_bloqueRegistros* getUltimoBloqueRegistros(_listaBloqueRegistros* listaBloqueRegistros)
{
     _bloqueRegistros* temporal = listaBloqueRegistros->inicio;

    while( 1 )
    {
        if(temporal->siguiente == NULL)
            return temporal;
        else
            temporal = temporal->siguiente;
    }
    return NULL;
}

int getCantidadDeRegistrosEnBloque(_bloqueRegistros* bloqueRegistros)
{
     int contador = 0;
    _registro* temporal = bloqueRegistros->listaRegistros->inicio;

    if(temporal == NULL)
        return contador;

    while(temporal != NULL)
    {
        temporal = temporal->siguiente;
        contador++;
    }

    return contador;
}

void agregarRegistroEnBloqueRegistros(_registro* registro, _listaBloqueRegistros* listaBloqueRegistros, int bloque_anterior, int bloque_siguiente, int cantidad_registros)
{
    if(listaBloqueRegistros->inicio == NULL)
    {
        nuevoBloqueRegistros(bloque_anterior, bloque_siguiente, cantidad_registros, listaBloqueRegistros, registro);
        return;
    }

     _bloqueRegistros* ultimoBloqueListaRegistros = getUltimoBloqueRegistros(listaBloqueRegistros);

    if(getCantidadDeRegistrosEnBloque(ultimoBloqueListaRegistros) < ultimoBloqueListaRegistros->cantidad_registros)
    {
        agregarRegistroEnBloqueExistente(ultimoBloqueListaRegistros, registro);
    }
    else{
        nuevoBloqueRegistros(bloque_anterior, bloque_siguiente, cantidad_registros, listaBloqueRegistros, registro);
    }
}

#endif // BLOQUEREGISTROS_H
