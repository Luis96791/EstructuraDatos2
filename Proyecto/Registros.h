#ifndef REGISTROS_H
#define REGISTROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DescripcionCampos.h"

#define TRUE    1
#define FALSE   0

typedef struct Registros _nodoRegistro;
typedef struct ListaRegistros _listaRegistros;

struct Registros
{
    _nodoRegistro* siguiente;
    _nodoDescCampos* ptrNodoDescCampos;
};

struct ListaRegistros
{
    _nodoRegistro* inicio;
};

_listaRegistros* nuevoRegistro();


_listaRegistros* nuevoRegistro()
{
    _listaRegistros *ptr;

    ptr = (_listaRegistros *)malloc(sizeof(_listaRegistros));
    ptr->inicio = NULL;
    return ptr;
}

void insertarRegistros(_listaRegistros* ptr)
{
    _nodoRegistro *temp, *temp1;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoRegistro *)malloc(sizeof(_nodoRegistro));
        ptr->inicio->siguiente = NULL;
        ptr->inicio->ptrNodoDescCampos = NULL;
        return;
    }
    temp = ptr->inicio;

    while(temp != NULL)
    {
        temp1 = temp;
        temp = temp->siguiente;
    }
    temp1->siguiente = (_nodoRegistro *)malloc(sizeof(_nodoRegistro));
    temp1->siguiente->siguiente = NULL;
    temp1->siguiente->ptrNodoDescCampos = NULL;
}

#endif // REGISTROS_H
