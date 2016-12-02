#ifndef CAMPODATO_H
#define CAMPODATO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Campos.h"

typedef struct CampoDato _campoDato;
typedef struct ListaCampoDatos _listaCampoDatos;

struct CampoDato
{
    _campo* campo;
    char* datoCampo;
    _campoDato* siguiente;
};

struct ListaCampoDatos
{
    _campoDato* inicio;
};

_listaCampoDatos* nuevaListaCampoDatos();
void agregarCampoDato(_listaCampoDatos* listaCampoDatos, char* datoCampo, _campo* campo);
void agregarCampoDatosLista(_campoDato* campoDato, _listaCampoDatos* listaCampoDatos);
void listarCampoDatos(_listaCampoDatos* listaCampoDatos);

_listaCampoDatos* nuevaListaCampoDatos()
{
    _listaCampoDatos* listaCampoDatos;

    listaCampoDatos = (_listaCampoDatos *)malloc(sizeof(_listaCampoDatos));
    listaCampoDatos->inicio = NULL;
    return listaCampoDatos;
}

void agregarCampoDato(_listaCampoDatos* listaCampoDatos, char* datoCampo, _campo* campo)
{
    _campoDato* campoDato;

    campoDato = (_campoDato *)malloc(sizeof(_campoDato));
    campoDato->datoCampo = datoCampo;
    campoDato->campo = campo;
    campoDato->siguiente = NULL;

    agregarCampoDatosLista(campoDato, listaCampoDatos);
}

void agregarCampoDatosLista(_campoDato* campoDato, _listaCampoDatos* listaCampoDatos)
{
    _campoDato* temporal;

    if(listaCampoDatos->inicio == NULL)
    {
        listaCampoDatos->inicio = campoDato;
        return;
    }
    temporal = listaCampoDatos->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = campoDato;
}

void listarCampoDatos(_listaCampoDatos* listaCampoDatos)
{
    _campoDato* temporal = listaCampoDatos->inicio;

    while(temporal != NULL)
    {
        printf("\t%s: %s", temporal->campo->nombre_campo, temporal->datoCampo);
        temporal = temporal->siguiente;
    }
    printf("\n");
}

#endif // CAMPODATO_H
