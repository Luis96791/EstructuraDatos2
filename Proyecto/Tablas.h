#ifndef TABLAS_H
#define TABLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Campos.h"
#include "Utilidades.h"

typedef struct Tabla _tabla;
typedef struct ListaTablas _listaTablas;

struct Tabla
{
    char* nombreTabla;
    int primerBloqueCampos;
    int primerBloqueRegistros;
    _listaCampos* listaCampos;
    _tabla* siguiente;
};

struct ListaTablas
{
    _tabla* inicio;
};

/* -------------------- Funciones ---------------------- */

/**
    Crea un nuevo espacio en memoria para almacenar tablas en una lista
    @return Lista de Tablas.
*/
_listaTablas* nuevaListaTablas();
/**
    Crea un nuevo espacio en memoria para una Tabla.
    @param Nombre Tabla.
    @param Lista de Tablas.
    @param Primer Bloque de Campos.
    @param Primer Bloque de Registros.
*/
void agregarTabla(char* nombreTabla, _listaTablas* listaTablas, int pBC, int pBR);
/**
    Agrega una tabla a la lista de tablas.
    @param Tabla.
    @param Lista de Tablas.
*/
void agregarTablaLista(_tabla* tabla, _listaTablas* listaTablas);
/**
    Muestra en pantalla todas las tablas que hay en la lista.
    @param Lista de Tablas.
*/
void listarTablas(_listaTablas* listaTablas);
/**
    @param Lista de Tablas.
    @return Retorna la cantidad de tablas que hay en la lista.
*/
int getSizeListaTablas(_listaTablas* listaTablas);
/**
    Busca una tabla en una lista de tablas.
    @param Nombre de la tabla a buscar
    @param Lista de Tablas
    @return Devuelve la tabla buscada.
*/
_tabla* buscarTabla(char* nombre_tabla, _listaTablas* listaTablas);
/* -------------------- Funciones ---------------------- */



_listaTablas* nuevaListaTablas()
{
    _listaTablas* listaTablas;

    listaTablas = (_listaTablas *)malloc(sizeof(_listaTablas));
    listaTablas->inicio = NULL;

    return listaTablas;
}

void agregarTabla(char* nombreTabla, _listaTablas* listaTablas, int pBC, int pBR)
{
    _tabla* tabla;

    tabla = (_tabla *)malloc(sizeof(_tabla));
    tabla->nombreTabla = nombreTabla;
    tabla->primerBloqueCampos = pBC;
    tabla->primerBloqueRegistros = pBR;
    tabla->listaCampos = (_listaCampos *)malloc(sizeof(_listaCampos));
    tabla->listaCampos = nuevaListaCampos();
    tabla->siguiente = NULL;

    agregarTablaLista(tabla, listaTablas);
}

void agregarTablaLista(_tabla* tabla, _listaTablas* listaTablas)
{
    _tabla* temporal;

    if(listaTablas->inicio == NULL)
    {
        listaTablas->inicio = tabla;
        return;
    }
    temporal = listaTablas->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = tabla;
}

void listarTablas(_listaTablas* listaTablas)
{
    _tabla* temporal = listaTablas->inicio;

    while(temporal != NULL)
    {
        printf("%s , %d , %d\n", temporal->nombreTabla, temporal->primerBloqueCampos, temporal->primerBloqueRegistros);
        temporal = temporal->siguiente;
    }
}

int getSizeListaTablas(_listaTablas* listaTablas)
{
    int contador = 0;
    _tabla* temporal = listaTablas->inicio;

    if(temporal == NULL)
    {
        return contador;
    }
    else
    {
        while(temporal != NULL)
        {
            contador++;
            temporal = temporal->siguiente;
        }
    }
    return contador;
}

_tabla* buscarTabla(char* nombre_tabla, _listaTablas* listaTablas)
{
    _tabla* tabla = listaTablas->inicio;

    while(tabla != NULL)
    {
        if(compareTo(tabla->nombreTabla, nombre_tabla))
        {
            return tabla;
        }
        tabla = tabla->siguiente;
    }
    printf("La Tabla %s No Existe!\n", nombre_tabla);
    return NULL;
}

#endif // TABLAS_H
