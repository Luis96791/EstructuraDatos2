#ifndef BLOQUECAMPODATOS_H
#define BLOQUECAMPODATOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CampoDato.h"

typedef struct BloqueCampoDatos _bloqueCampoDatos;
typedef struct ListaBloqueCampoDatos _listaBloqueCampoDatos;

struct BloqueCampoDatos
{
    int bloque_anterior;
    int bloque_siguiente;
    int cantidad_campoDatos;
    _bloqueCampoDatos* siguiente;
    _listaCampoDatos* listaCampoDatos;
};

struct ListaBloqueCampoDatos
{
    _bloqueCampoDatos* inicio;
};

_listaBloqueCampoDatos* nuevaListaBloqueCampoDatos();
void nuevoBloqueCampoDatos(int bloque_anterior, int bloque_siguiente, int cantidad_campoDatos, _listaBloqueCampoDatos* listaBloqueCampoDatos, _campoDato* campoDato);
void agregarNuevoBloqueCampoDatosLista(_listaBloqueCampoDatos* listaBloqueCampoDatos, _bloqueCampoDatos* bloqueCampoDatos, _campoDato* campoDato);
void agregarCampoDatoEnBloqueExistente(_bloqueCampoDatos* bloqueCampoDatos, _campoDato* campoDato);
void listarBloqueCampoDatos(_listaBloqueCampoDatos* listaBloqueCampoDatos);
_bloqueCampoDatos* getUltimoBloqueCampoDatos(_listaBloqueCampoDatos* listaBloqueCampoDatos);
int getCantidadDeCampoDatosEnBloque(_bloqueCampoDatos* bloqueCampoDatos);
void agregarCampoDatoEnBloqueCampoDatos(_campoDato* campoDato, _listaBloqueCampoDatos* listaBloqueCampoDatos, int bloque_anterior, int bloque_siguiente, int cantidad_CampoDatos);


_listaBloqueCampoDatos* nuevaListaBloqueCampoDatos()
{
    _listaBloqueCampoDatos* listaBloqueCampoDatos;

    listaBloqueCampoDatos = (_listaBloqueCampoDatos *)malloc(sizeof(_listaBloqueCampoDatos));
    listaBloqueCampoDatos->inicio = NULL;
    return listaBloqueCampoDatos;
}

void nuevoBloqueCampoDatos(int bloque_anterior, int bloque_siguiente, int cantidad_campoDatos, _listaBloqueCampoDatos* listaBloqueCampoDatos, _campoDato* campoDato)
{
    _bloqueCampoDatos* bloqueCampoDatos;

    bloqueCampoDatos = (_bloqueCampoDatos *)malloc(sizeof(_bloqueCampoDatos));
    bloqueCampoDatos->bloque_anterior = bloque_anterior;
    bloqueCampoDatos->bloque_siguiente = bloque_siguiente;
    bloqueCampoDatos->cantidad_campoDatos = cantidad_campoDatos;
    bloqueCampoDatos->listaCampoDatos = nuevaListaCampoDatos();
    bloqueCampoDatos->siguiente = NULL;

    agregarNuevoBloqueCampoDatosLista(listaBloqueCampoDatos, bloqueCampoDatos, campoDato);
}

void agregarNuevoBloqueCampoDatosLista(_listaBloqueCampoDatos* listaBloqueCampoDatos, _bloqueCampoDatos* bloqueCampoDatos, _campoDato* campoDato)
{
    _bloqueCampoDatos* temporal;

    if(listaBloqueCampoDatos->inicio == NULL)
    {
        listaBloqueCampoDatos->inicio = bloqueCampoDatos;
        agregarCampoDato(bloqueCampoDatos->listaCampoDatos, campoDato->datoCampo, campoDato->campo);
        return;
    }
    temporal = listaBloqueCampoDatos->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = bloqueCampoDatos;
    agregarCampoDato(bloqueCampoDatos->listaCampoDatos, campoDato->datoCampo, campoDato->campo);
}

void agregarCampoDatoEnBloqueExistente(_bloqueCampoDatos* bloqueCampoDatos, _campoDato* campoDato)
{
    agregarCampoDato(bloqueCampoDatos->listaCampoDatos, campoDato->datoCampo, campoDato->campo);
}

void listarBloqueCampoDatos(_listaBloqueCampoDatos* listaBloqueCampoDatos)
{
    printf("\n\t--Listando Los Bloques de CampoDatos--\n\n");
    _bloqueCampoDatos* temporal = listaBloqueCampoDatos->inicio;

    while(temporal != NULL)
    {
        printf("\t%d %d %d \n", temporal->bloque_anterior, temporal->bloque_siguiente, temporal->cantidad_campoDatos);
        listarCampoDatos(temporal->listaCampoDatos);
        temporal = temporal->siguiente;
    }
}

_bloqueCampoDatos* getUltimoBloqueCampoDatos(_listaBloqueCampoDatos* listaBloqueCampoDatos)
{
     _bloqueCampoDatos* temporal = listaBloqueCampoDatos->inicio;

    while( 1 )
    {
        if(temporal->siguiente == NULL)
            return temporal;
        else
            temporal = temporal->siguiente;
    }
    return NULL;
}

int getCantidadDeCampoDatosEnBloque(_bloqueCampoDatos* bloqueCampoDatos)
{
     int contador = 0;
    _campoDato* temporal = bloqueCampoDatos->listaCampoDatos->inicio;

    if(temporal == NULL)
        return contador;

    while(temporal != NULL)
    {
        temporal = temporal->siguiente;
        contador++;
    }

    return contador;
}

void agregarCampoDatoEnBloqueCampoDatos(_campoDato* campoDato, _listaBloqueCampoDatos* listaBloqueCampoDatos, int bloque_anterior, int bloque_siguiente, int cantidad_CampoDatos)
{
    if(listaBloqueCampoDatos->inicio == NULL)
    {
        nuevoBloqueCampoDatos(bloque_anterior, bloque_siguiente, cantidad_CampoDatos, listaBloqueCampoDatos, campoDato);
        return;
    }

     _bloqueCampoDatos* ultimoBloqueListaCampoDatos = getUltimoBloqueCampoDatos(listaBloqueCampoDatos);

    if(getCantidadDeCampoDatosEnBloque(ultimoBloqueListaCampoDatos) < ultimoBloqueListaCampoDatos->cantidad_campoDatos)
    {
        agregarCampoDatoEnBloqueExistente(ultimoBloqueListaCampoDatos, campoDato);
    }
    else{
        nuevoBloqueCampoDatos(bloque_anterior, bloque_siguiente, cantidad_CampoDatos, listaBloqueCampoDatos, campoDato);
    }
}

#endif // BLOQUECAMPODATOS_H
