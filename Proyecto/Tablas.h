#ifndef TABLAS_H
#define TABLAS_H
#include "Campos.h"

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
};

struct ListaTabla
{
    _nodoTabla *inicio;
};

_listaTabla* nuevaTabla();
void insertarTablas(_listaTabla* ptr, int id, char* nombre);
void listarTablas(_listaTabla* inicio);

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


#endif // TABLAS_H
