#ifndef REGISTROS_H
#define REGISTROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef struct Registro _registro;
typedef struct ListaRegistros _listaRegistros;

struct Registro
{
    char* dato_registro;
    _registro* siguiente;
};

struct ListaRegistros
{
    _registro* inicio;
};

_listaRegistros* nuevoRegistro();
void insertarRegistros(_listaRegistros* ptr, _listaDescCampos* ptrListaDesCampo);
void listarRegistros(_listaRegistros* inicio);


_listaRegistros* nuevoRegistro()
{
    _listaRegistros* listaRegistros;

    listaRegistros = (_listaRegistros *)malloc(sizeof(_listaRegistros));
    listaRegistros->inicio = NULL;
    return ptr;
}

void insertarRegistros(_listaRegistros* ptr, _listaDescCampos* ptrListaDesCampo)
{
    _nodoRegistro *temp;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoRegistro *)malloc(sizeof(_nodoRegistro));
        ptr->inicio->siguiente = NULL;
        ptr->inicio->ptrListaDescCampos = ptrListaDesCampo;
        return;
    }
    temp = ptr->inicio;

    while(temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = (_nodoRegistro *)malloc(sizeof(_nodoRegistro));
    temp->siguiente->siguiente = NULL;
    temp->siguiente->ptrListaDescCampos = ptrListaDesCampo;
}

void listarRegistros(_listaRegistros* inicio)
{
    _nodoRegistro* temporal = inicio;

    while(temporal != NULL)
    {
        listarDescCampos(temporal->ptrListaDescCampos->inicio);
        temporal = temporal->siguiente;
    }
}

#endif // REGISTROS_H
