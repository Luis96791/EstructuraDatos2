#ifndef BLOQUE_H
#define BLOQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"
#include "Campos.h"

typedef struct Bloque _bloque;
typedef struct ListaBloques _listaBloques;


struct Bloque
{
    int bloqueAnterior;
    int bloqueSiguiente;
    int cantTablasEnBloque;
    int cantCamposEnBloque;
    int cantRegistrosEnBloque;
    _listaTablas* ptrlistaTablas;
    _listaCampos* ptrListaCampos;
    _bloque* siguiente;
};

struct ListaBloques
{
    _bloque* inicio;
};

/* -------------------- Funciones ---------------------- */

/**
    Crea un nuevo espacio en memoria para almacenar bloques en una lista
    @return Retorna una lista de bloques.
*/
_listaBloques* nuevaListaBloques();
/**
    Agrega una tabla a un bloque especifico, maneja los bloques.
    @param Nombre de tabla a agregar.
    @param Lista de Bloques.
    @param Primer Bloque de Campos.
    @param Primer Bloque de Registros.
    @param Cantidad de Tablas que soporta el bloque.
*/
void agregarTabla_ABloque(char* nombreTabla, _listaBloques* listaBloques, int pBC, int pBR, int cantTablas);
/**
    Crea el espacio de memoria para agregar un nuevo bloque a la lista de bloques.
    @param Lista de Bloques.
    @param Cantidad de tablas que soporta el bloque.
*/
void agregarBloqueTabla(_listaBloques* listaBloques, int cantTablas);
/**
    Agreaga un nuevo bloque al final de la lista de bloques.
    @param Bloque.
    @param Lista de Bloques.
*/
void agregarBloqueLista(_bloque* bloque, _listaBloques* listaBloques);
/**
   Muestra en pantalla los bloques que hay en la lista de bloques.
   @param Lista de Bloques.
*/
void listarBloques(_listaBloques* listaBloques);
/**
    Busca un bloque que aun no este ocupado por completo
    @param Lista de Bloques.
    @return Retorna un bloque.
*/
_bloque* getBloqueTablasDisponble(_listaBloques* listaBloques);
/**
    @return Retorna la cantidad de tablas que hay en un bloque.
    @param Bloque.
*/
int cantidadTablasPorBloque(_bloque* bloque);

void agregarBloqueCampo(_listaBloques* listaBloques, int cantCampos);
int cantidadCamposPorBloque(_bloque* bloque);
void agregarCampo_ABloque(char* nombreCampo, char* tipoCampo, _listaBloques* listaBloques, int cantCampos);
_bloque* getBloqueCamposDisponble(_listaBloques* listaBloques);
/* -------------------- Funciones ---------------------- */

_listaBloques* nuevaListaBloques()
{
    _listaBloques* listaBloques;

    listaBloques = (_listaBloques* )malloc(sizeof(_listaBloques));
    listaBloques->inicio = NULL;

    return listaBloques;
}

void agregarBloqueTabla(_listaBloques* listaBloques, int cantTablas)
{
    _bloque* bloque;

    bloque = (_bloque *)malloc(sizeof(_bloque));
    bloque->bloqueAnterior = -1;
    bloque->bloqueSiguiente = -1;
    bloque->cantTablasEnBloque = cantTablas;
    bloque->ptrlistaTablas = (_listaTablas *)malloc(sizeof(_listaTablas));
    bloque->ptrlistaTablas = nuevaListaTablas();
    bloque->ptrListaCampos = NULL;
    bloque->siguiente = NULL;

    agregarBloqueLista(bloque, listaBloques);
}

void agregarBloqueCampo(_listaBloques* listaBloques, int cantCampos)
{
    _bloque* bloque;

    bloque = (_bloque *)malloc(sizeof(_bloque));
    bloque->bloqueAnterior = -1;
    bloque->bloqueSiguiente = -1;
    bloque->cantCamposEnBloque = cantCampos;
    bloque->ptrlistaTablas = NULL;
    bloque->ptrListaCampos = (_listaCampos *)malloc(sizeof(_listaCampos));
    bloque->ptrListaCampos = nuevaListaCampos();
    bloque->siguiente = NULL;

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
        if(temporal->ptrlistaTablas != NULL)
        {
            printf("%d, %d, %d\n", temporal->bloqueAnterior, temporal->bloqueSiguiente, temporal->cantTablasEnBloque);
            listarTablas(temporal->ptrlistaTablas);
        }

        if(temporal->ptrListaCampos != NULL)
        {
            printf("%d, %d, %d\n", temporal->bloqueAnterior, temporal->bloqueSiguiente, temporal->cantCamposEnBloque);
            listarCampos(temporal->ptrListaCampos);
        }
        temporal = temporal->siguiente;
    }
}

void agregarTabla_ABloque(char* nombreTabla, _listaBloques* listaBloques, int pBC, int pBR, int cantTablas)
{
    _bloque* bloque;

    if(listaBloques->inicio == NULL)
    {
        agregarBloqueTabla(listaBloques, cantTablas);
        bloque = getBloqueTablasDisponble(listaBloques);
        agregarTabla(nombreTabla, bloque->ptrlistaTablas, pBC, pBR);
        return;
    }

    bloque = getBloqueTablasDisponble(listaBloques);

    if(bloque == NULL)
    {
        agregarBloqueTabla(listaBloques, cantTablas);
        bloque = getBloqueTablasDisponble(listaBloques);
        agregarTabla(nombreTabla, bloque->ptrlistaTablas, pBC, pBR);
    }
    else{
        agregarTabla(nombreTabla, bloque->ptrlistaTablas, pBC, pBR);
    }
}

void agregarCampo_ABloque(char* nombreCampo, char* tipoCampo, _listaBloques* listaBloques, int cantCampos)
{
    _bloque* bloque = getBloqueCamposDisponble(listaBloques);

    if(bloque == NULL)
    {
        agregarBloqueCampo(listaBloques, cantCampos);
        bloque = getBloqueCamposDisponble(listaBloques);
        agregarCampo(bloque->ptrListaCampos, nombreCampo, tipoCampo);
    }
    else{
        agregarCampo(bloque->ptrListaCampos, nombreCampo, tipoCampo);
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

int cantidadCamposPorBloque(_bloque* bloque)
{
    _campo* campo = bloque->ptrListaCampos->inicio;
    int contador = 0;

    if(campo == NULL)
    {
        return contador;
    }
    while(campo != NULL)
    {
        contador++;
        campo = campo->siguiente;
    }
    return contador;
}

_bloque* getBloqueTablasDisponble(_listaBloques* listaBloques)
{
    _bloque* temporal = listaBloques->inicio;

    if(temporal == NULL)
    {
        return NULL;
    }

    while(temporal != NULL)
    {
        if(temporal->ptrlistaTablas != NULL)
        {
            if(temporal->cantTablasEnBloque > cantidadTablasPorBloque(temporal))
            {
                return temporal;
            }
        }
        temporal = temporal->siguiente;
    }
    return NULL;
}

_bloque* getBloqueCamposDisponble(_listaBloques* listaBloques)
{
    _bloque* temporal = listaBloques->inicio;

    if(temporal == NULL)
    {
        return NULL;
    }

    while(temporal != NULL)
    {
        if(temporal->ptrListaCampos != NULL)
        {
            if(temporal->cantCamposEnBloque > cantidadCamposPorBloque(temporal))
            {
                return temporal;
            }
        }
        temporal = temporal->siguiente;
    }
    return NULL;
}

#endif // BLOQUE_H
