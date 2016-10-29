#ifndef DESCRIPCIONCAMPOS_H
#define DESCRIPCIONCAMPOS_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE    1
#define FALSE   0

typedef struct DescripcionCampos _nodoDescCampos;
typedef struct ListaDescripcionCampos _listDesCampos;

struct DescripcionCampos
{
    void* dato;
    _nodoDescCampos* siguiente;
};

struct ListaDescripcionCampos
{
    _nodoDescCampos *inicio;
};

_listDesCampos* nuevaDesCampos();
void insertarDesCampos(_listDesCampos* ptr, void* dato);

_listDesCampos* nuevaDesCampos()
{
    _listDesCampos* ptr;

    ptr = (_listDesCampos *)malloc(sizeof(_listDesCampos));
    ptr->inicio = NULL;
    return ptr;
}

void insertarDesCampos(_listDesCampos* ptr, void* dato)
{
    _nodoDescCampos *temp, *temp1;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoDescCampos *)malloc(sizeof(_nodoDescCampos));
        ptr->inicio->dato = dato;
        ptr->inicio->siguiente = NULL;
        return;
    }
    temp = ptr->inicio;

    while(temp != NULL)
    {
        temp1 = temp;
        temp = temp->siguiente;
    }
    temp1->siguiente = (_nodoDescCampos *)malloc(sizeof(_nodoDescCampos));
    temp1->siguiente->dato = dato;
    temp1->siguiente->siguiente = NULL;
}

#endif // DESCRIPCIONCAMPOS_H
