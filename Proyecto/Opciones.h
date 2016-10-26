#ifndef OPCIONES_H
#define OPCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef struct Opciones _nodoOpciones;
typedef struct ListaOpciones _listaOpciones;

struct Opciones
{
    char* titulo_opcion;
    int id_opcion;
    int orden_opcion;
    _nodoOpciones* subOpciones;
    _nodoOpciones* siguiente;
};

struct ListaOpciones
{
    _nodoOpciones* inicio;
};

//_listaTabla* nuevaTabla();
//void insertarTablas(_listaTabla* ptr, int id, char* nombre);
//void listarTablas(_listaTabla* inicio);

_listaOpciones* nuevaOpcion();
void insertarOpciones(_listaOpciones* ptr, char* titulo, int id, int orden, _nodoOpciones* subOpciones);
void listarOpciones(_nodoOpciones* inicio);

_listaOpciones* nuevaOpcion()
{
    _listaOpciones* ptr;
    ptr = (_listaOpciones *)malloc(sizeof(_listaOpciones));
    ptr->inicio = NULL;
    return ptr;
}

void insertarOpciones(_listaOpciones* ptr, char* titulo, int id, int orden, _nodoOpciones* subOpciones)
{
    _nodoOpciones *temp, *temp1;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoOpciones *)malloc(sizeof(_nodoOpciones));
        ptr->inicio->titulo_opcion = titulo;
        ptr->inicio->id_opcion = id;
        ptr->inicio->orden_opcion = orden;
        ptr->inicio->subOpciones = subOpciones;
        ptr->inicio->siguiente = NULL;
        return;
    }
    temp = ptr->inicio;

    while(temp != NULL)
    {
        temp1 = temp;
        temp = temp->siguiente;
    }
    temp1->siguiente = (_nodoOpciones *)malloc(sizeof(_nodoOpciones));
    temp1->siguiente->titulo_opcion = titulo;
    temp1->siguiente->id_opcion = id;
    temp1->siguiente->orden_opcion = orden;
    temp1->siguiente->subOpciones = subOpciones;
    temp1->siguiente->siguiente = NULL;
}

void listarOpciones(_nodoOpciones* inicio)
{
    _nodoOpciones *temp = inicio;

    while(temp != NULL)
    {
        printf("%d , %s\n", temp->id_opcion, temp->titulo_opcion);
        temp = temp->siguiente;
    }
}

#endif // OPCIONES_H
