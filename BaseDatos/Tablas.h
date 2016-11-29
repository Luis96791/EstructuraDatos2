#ifndef TABLAS_H
#define TABLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoTabla _nodoTabla;
typedef struct ListaTablas _listaTabla;

struct NodoTabla
{
    int id_tabla;
    char* nombre_tabla;
    _nodoTabla *siguiente;
};

struct ListaTablas
{
    _nodoTabla *inicio;
};

_listaTabla* nuevaTabla();
void insertarTablas(_listaTabla* ptr, int id, char* nombre);
void listarTablas(_listaTabla* ptr);

_listaTabla* nuevaTabla()
{
    _listaTabla* ptr;
    ptr = (_listaTabla *)malloc(sizeof(_listaTabla));
    ptr->inicio = NULL;
    return ptr;
}

void insertarTablas(_listaTabla* ptr, int id, char* nombre)
{
    _nodoTabla *temp;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoTabla *)malloc(sizeof(_nodoTabla));
        ptr->inicio->id_tabla = id;
        ptr->inicio->nombre_tabla = nombre;
        ptr->inicio->siguiente = NULL;
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
}


void listarTablas(_listaTabla* ptr)
{
    _nodoTabla* temp = ptr->inicio;

    while(temp != NULL)
    {
        printf("ID: %d, Nombre: %s\n", temp->id_tabla, temp->nombre_tabla);
        temp = temp->siguiente;
    }
}

#endif // TABLAS_H
