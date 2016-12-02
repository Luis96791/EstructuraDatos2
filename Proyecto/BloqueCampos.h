#ifndef BLOQUECAMPOS_H
#define BLOQUECAMPOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Campos.h"


typedef struct BloqueCampos _bloqueCampos;
typedef struct ListaBloqueCampos _listaBloqueCampos;

struct BloqueCampos
{
    int bloque_anterior;
    int bloque_siguiente;
    int cantidad_campos;
    _bloqueCampos* siguiente;
    _listaCampos* listaCampos;
};

struct ListaBloqueCampos
{
    _bloqueCampos* inicio;
};

_listaBloqueCampos* nuevaListaBloqueCampos();
void nuevoBloqueCampos(int bloque_anterior, int bloque_siguiente, int cantidad_campos, _listaBloqueCampos* listaBloqueCampos, _campo* campo);
void agregarNuevoBloqueCamposLista(_listaBloqueCampos* listaBloqueCampos, _bloqueCampos* bloqueCampos, _campo* campo);
void listarBloqueCampos(_listaBloqueCampos* listaBloqueCampos);
void agregarCampoEnBloqueExistente(_bloqueCampos* bloqueCampos, _campo* campo);
_bloqueCampos* getUltimoBloqueCampos(_listaBloqueCampos* listaBloqueCampos);
int getCantidadDeCamposEnBloque(_bloqueCampos* bloqueCampos);
void agregarCamposEnBloqueCampos(_campo* campo, _listaBloqueCampos* listaBloqueCampos, int bloque_anterior, int bloque_siguiente, int cantidad_campos);

_listaBloqueCampos* nuevaListaBloqueCampos()
{
    _listaBloqueCampos* listaBloqueCampos;

    listaBloqueCampos = (_listaBloqueCampos *)malloc(sizeof(_listaBloqueCampos));
    listaBloqueCampos->inicio = NULL;
    return listaBloqueCampos;
}

void nuevoBloqueCampos(int bloque_anterior, int bloque_siguiente, int cantidad_campos, _listaBloqueCampos* listaBloqueCampos, _campo* campo)
{
    _bloqueCampos* bloqueCampos;

    bloqueCampos = (_bloqueCampos *)malloc(sizeof(_bloqueCampos));
    bloqueCampos->bloque_anterior = bloque_anterior;
    bloqueCampos->bloque_siguiente = bloque_siguiente;
    bloqueCampos->cantidad_campos = cantidad_campos;
    bloqueCampos->listaCampos = nuevaListaCampos();
    bloqueCampos->siguiente = NULL;

    agregarNuevoBloqueCamposLista(listaBloqueCampos, bloqueCampos, campo);
}

void agregarNuevoBloqueCamposLista(_listaBloqueCampos* listaBloqueCampos, _bloqueCampos* bloqueCampos, _campo* campo)
{
    _bloqueCampos* temporal;

    if(listaBloqueCampos->inicio == NULL)
    {
        listaBloqueCampos->inicio = bloqueCampos;
        agregarCampo(bloqueCampos->listaCampos, campo->nombre_campo, campo->tipo_campo);
        return;
    }
    temporal = listaBloqueCampos->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = bloqueCampos;
    agregarCampo(bloqueCampos->listaCampos, campo->nombre_campo, campo->tipo_campo);
}

void agregarCampoEnBloqueExistente(_bloqueCampos* bloqueCampos, _campo* campo)
{
    agregarCampo(bloqueCampos->listaCampos, campo->nombre_campo, campo->tipo_campo);
}

void listarBloqueCampos(_listaBloqueCampos* listaBloqueCampos)
{
    printf("\n--Listando Los Bloque de Campos--\n\n");
    _bloqueCampos* temporal = listaBloqueCampos->inicio;

    while(temporal != NULL)
    {
        printf("%d %d %d \n", temporal->bloque_anterior, temporal->bloque_siguiente, temporal->cantidad_campos);
        listarCampos(temporal->listaCampos);
        temporal = temporal->siguiente;
    }
}

_bloqueCampos* getUltimoBloqueCampos(_listaBloqueCampos* listaBloqueCampos)
{
     _bloqueCampos* temporal = listaBloqueCampos->inicio;

    while( 1 )
    {
        if(temporal->siguiente == NULL)
            return temporal;
        else
            temporal = temporal->siguiente;
    }
    return NULL;
}

int getCantidadDeCamposEnBloque(_bloqueCampos* bloqueCampos)
{
     int contador = 0;
    _campo* temporal = bloqueCampos->listaCampos->inicio;

    if(temporal == NULL)
        return contador;

    while(temporal != NULL)
    {
        temporal = temporal->siguiente;
        contador++;
    }

    return contador;
}

void agregarCamposEnBloqueCampos(_campo* campo, _listaBloqueCampos* listaBloqueCampos, int bloque_anterior, int bloque_siguiente, int cantidad_campos)
{
    if(listaBloqueCampos->inicio == NULL)
    {
        nuevoBloqueCampos(bloque_anterior, bloque_siguiente, cantidad_campos, listaBloqueCampos, campo);
        return;
    }

     _bloqueCampos* ultimoBloqueListaCampos = getUltimoBloqueCampos(listaBloqueCampos);

    if(getCantidadDeCamposEnBloque(ultimoBloqueListaCampos) < ultimoBloqueListaCampos->cantidad_campos)
    {
        agregarCampoEnBloqueExistente(ultimoBloqueListaCampos, campo);
    }
    else{
        nuevoBloqueCampos(bloque_anterior, bloque_siguiente, cantidad_campos, listaBloqueCampos, campo);
    }
}

#endif // BLOQUECAMPOS_H
