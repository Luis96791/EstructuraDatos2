#ifndef TABLAS_H
#define TABLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Campos.h"
#include "Registros.h"
#include "BloqueCampos.h"
#include "BloqueRegistros.h"
#include "Utilidades.h"

#define DECIMAL     10
#define COMA        44

typedef struct Tabla _tabla;
typedef struct ListaTablas _listaTablas;

struct Tabla
{
    char* nombreTabla;
    int primerBloqueCampos;
    int primerBloqueRegistros;
    _listaCampos* listaCampos;
    _listaRegistros* listaRegistros;
    _listaBloqueCampos* listaBloqueCampos;
    _listaBloqueRegistros* listaBloqueRegistros;
    _tabla* siguiente;
};

struct ListaTablas
{
    _tabla* inicio;
};

/* -------------------- Funciones ---------------------- */

/**
    \brief Crea un nuevo espacio en memoria para almacenar tablas en una lista
    \return Lista de Tablas.
*/
_listaTablas* nuevaListaTablas();
/**
    \brief Crea un nuevo espacio en memoria para una Tabla.
    \param Nombre Tabla.
    \param Lista de Tablas.
    \param Primer Bloque de Campos.
    \param Primer Bloque de Registros.
*/
_tabla* agregarTabla(char* nombreTabla, _listaTablas* listaTablas, int pBC, int pBR);
/**
    \brief Agrega una tabla a la lista de tablas.
    \param Tabla.
    \param Lista de Tablas.
*/
void agregarTablaLista(_tabla* tabla, _listaTablas* listaTablas);
/**
    \brief Muestra en pantalla todas las tablas que hay en la lista.
    \param Lista de Tablas.
*/
void listarTablas(_listaTablas* listaTablas);
/**
    \brief Obtiene la cantidad de tablas que hay en la lista.
    \param Lista de Tablas.
    \return Retorna la cantidad de tablas que hay en la lista.
*/
int getSizeListaTablas(_listaTablas* listaTablas);
/**
    \brief Busca una tabla en una lista de tablas.
    \param Nombre de la tabla a buscar
    \param Lista de Tablas
    \return Devuelve la tabla buscada.
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

_tabla* agregarTabla(char* nombreTabla, _listaTablas* listaTablas, int pBC, int pBR)
{
    _tabla* tabla;

    tabla = (_tabla *)malloc(sizeof(_tabla));
    tabla->nombreTabla = nombreTabla;
    tabla->primerBloqueCampos = pBC;
    tabla->primerBloqueRegistros = pBR;
    tabla->listaCampos = nuevaListaCampos();
    tabla->listaRegistros = nuevaListaRegistros();
    tabla->listaBloqueCampos = nuevaListaBloqueCampos();
    tabla->listaBloqueRegistros = nuevaListaBloqueRegistros();
    tabla->siguiente = NULL;

    agregarTablaLista(tabla, listaTablas);
    return tabla;
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

void escribirTablaEnArchivo(_tabla* tabla)
{
    FILE* file;
    char* bufferTemp = malloc(sizeof(char)*12);

    file = abrirArchivo("a");

    fputs("T,", file);
    if(file != NULL)
    {
        fputs(tabla->nombreTabla, file);
        fputc(COMA, file);
    }
    fclose(file);
    free(bufferTemp);
}

char* leerTabla(_listaTablas* listaTablas, int posBuffer)
{
    FILE* file;
    char* buffer = (char *)malloc(sizeof(char)*1000);

    file = abrirArchivo("r");
    fgets(buffer, 1000, file);

    fclose(file);

    printf("%s", buffer);

    char* copiaBuffer = (char *)malloc(sizeof(char)*20);
    int posCopiaBuffer = 0;

    while(buffer[posBuffer] != ',')
    {
        copiaBuffer[posCopiaBuffer] = buffer[posBuffer];
        posBuffer++;
        posCopiaBuffer++;
    }

    agregarTabla(copiaBuffer, listaTablas, 0, 0);
}

#endif // TABLAS_H
