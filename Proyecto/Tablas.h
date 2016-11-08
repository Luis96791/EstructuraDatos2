#ifndef TABLAS_H
#define TABLAS_H
#include "Campos.h"
#include "Registros.h"
#include "Utilidades.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef struct NodoTabla _nodoTabla;
typedef struct ListaTabla _listaTabla;

struct NodoTabla
{
    int id_tabla;
    char* nombre_tabla;
    _listaRegistros* ptrListaRegistro;
    _nodoTabla *siguiente;
    _listaCampos *ptrListaCampo;
    int primerBloqueCampos;
    int primerBloqueRegistros;

};

struct ListaTabla
{
    _nodoTabla *inicio;
};

_listaTabla* nuevaTabla();
void insertarTablas(_listaTabla* ptr, int id, char* nombre, _listaCampos* ptrListaCampos);
void listarTablas(_listaTabla* ptr);
_nodoTabla* buscarTabla(_listaTabla* ptr, char* nombre);
void modificarRegistroATabla(_listaTabla* ptr, _listaRegistros* ptrListaRegistros, char* cadena);
void agregarCamposTabla(_nodoTabla* nodoTabla, _listaCampos* listaCampos);

_listaTabla* nuevaTabla()
{
    _listaTabla* ptr;
    ptr = (_listaTabla *)malloc(sizeof(_listaTabla));
    ptr->inicio = NULL;
    return ptr;
}

void insertarTablas(_listaTabla* ptr, int id, char* nombre, _listaCampos* ptrListaCampos)
{
    _nodoTabla *temp;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoTabla *)malloc(sizeof(_nodoTabla));
        ptr->inicio->id_tabla = id;
        ptr->inicio->nombre_tabla = nombre;
        ptr->inicio->siguiente = NULL;
        ptr->inicio->ptrListaCampo = ptrListaCampos;
        ptr->inicio->ptrListaRegistro = NULL;
        ptr->inicio->primerBloqueCampos = -1;
        ptr->inicio->primerBloqueRegistros = -1;
        return;
    }
    temp = ptr->inicio;

    while(temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = (_nodoTabla *)malloc(sizeof(_nodoTabla));
    temp->siguiente->siguiente = NULL;
    temp->siguiente->nombre_tabla = nombre;
    temp->siguiente->id_tabla = id;
    temp->siguiente->ptrListaCampo = ptrListaCampos;
    temp->siguiente->ptrListaRegistro = NULL;
    temp->siguiente->primerBloqueCampos = -1;
    temp->siguiente->primerBloqueRegistros = -1;

}

void listarTablas(_listaTabla* ptr)
{
    _nodoTabla* temporal = ptr->inicio;

    while(temporal != NULL)
    {
        printf("%d , %s\n", temporal->id_tabla, temporal->nombre_tabla);
        temporal = temporal->siguiente;
    }
}

_nodoTabla* buscarTabla(_listaTabla* ptr, char* nombre)
{
    _nodoTabla* temporal = ptr->inicio;

    while(temporal != NULL)
    {
        if(compareTo(temporal->nombre_tabla, nombre))
        {
            return temporal;
        }
        temporal = temporal->siguiente;
    }
    printf("Esta tabla no existe!\n");
    return  NULL;
}

void modificarRegistroATabla(_listaTabla* ptr, _listaRegistros* ptrListaRegistros, char* cadena)
{
    _nodoTabla* temporal = ptr->inicio;

    while(temporal != NULL)
    {
        if(compareTo(temporal->nombre_tabla, cadena))
        {
            temporal->ptrListaRegistro = ptrListaRegistros;
            return;
        }
        temporal = temporal->siguiente;
    }
}

void agregarCamposTabla(_nodoTabla* nodoTabla, _listaCampos* listaCampos)
{
    nodoTabla->ptrListaCampo = listaCampos;
}

#endif // TABLAS_H
