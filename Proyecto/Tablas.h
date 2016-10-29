#ifndef TABLAS_H
#define TABLAS_H
#include "Campos.h"
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
    _nodoTabla *siguiente;
    _nodoCampo *ptrCampo;

};

struct ListaTabla
{
    _nodoTabla *inicio;
};

_listaTabla* nuevaTabla();
void insertarTablas(_listaTabla* ptr, int id, char* nombre);
void listarTablas(_listaTabla* inicio);
_nodoTabla* buscarTabla(_listaTabla* ptr, char* nombre);

_listaTabla* nuevaTabla()
{
    _listaTabla* ptr;
    ptr = (_listaTabla *)malloc(sizeof(_listaTabla));
    ptr->inicio = NULL;
    return ptr;
}

void insertarTablas(_listaTabla* ptr, int id, char* nombre)
{
    _nodoTabla *temp, *temp1;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoTabla *)malloc(sizeof(_nodoTabla));
        ptr->inicio->id_tabla = id;
        ptr->inicio->nombre_tabla = nombre;
        ptr->inicio->siguiente = NULL;
        ptr->inicio->ptrCampo = NULL;
        return;
    }
    temp = ptr->inicio;

    while(temp != NULL)
    {
        temp1 = temp;
        temp = temp->siguiente;
    }
    temp1->siguiente = (_nodoTabla *)malloc(sizeof(_nodoTabla));
    temp1->siguiente->siguiente = NULL;
    temp1->siguiente->nombre_tabla = nombre;
    temp1->siguiente->id_tabla = id;
    temp1->siguiente->ptrCampo = NULL;

}

void listarTablas(_listaTabla* inicio)
{
    _nodoTabla* temporal = inicio;

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
        temporal = temporal->siguiente;
        if(compareTo(temporal->nombre_tabla, nombre))
        {
            return temporal;
        }
    }

    return  NULL;
}

#endif // TABLAS_H
