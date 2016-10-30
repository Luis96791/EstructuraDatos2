#ifndef DESCRIPCIONCAMPOS_H
#define DESCRIPCIONCAMPOS_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE    1
#define FALSE   0

typedef struct DescripcionCampos _nodoDescCampos;
typedef struct ListaDescripcionCampos _listaDescCampos;

struct DescripcionCampos
{
    char* datoChar;
    int datoInt;
    _nodoDescCampos* siguiente;
};

struct ListaDescripcionCampos
{
    _nodoDescCampos *inicio;
};

_listaDescCampos* nuevaDesCampos();
void insertarDesCampos(_listaDescCampos* ptr, char* dato, _nodoCampo* ptrNodoCampo);
void listarDescCampos(_listaDescCampos* inicio, _nodoCampo* ptrNodoCampo);
int getPosicionDescCampo(_listaDescCampos* inicio);

_listaDescCampos* nuevaDesCampos()
{
    _listaDescCampos* ptr;

    ptr = (_listaDescCampos *)malloc(sizeof(_listaDescCampos));
    ptr->inicio = NULL;
    return ptr;
}

void insertarDesCampos(_listaDescCampos* ptr, char* dato, _nodoCampo* ptrNodoCampo)
{
    _nodoDescCampos *temp, *temp1;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoDescCampos *)malloc(sizeof(_nodoDescCampos));
        if(ptrNodoCampo->tipo == "entero")
        {
            ptr->inicio->datoInt = (int)dato;
            ptr->inicio->datoChar = NULL;
        }
        else{
            ptr->inicio->datoChar = dato;
            ptr->inicio->datoInt = NULL;
        }
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
    if(ptrNodoCampo->tipo == "entero")
    {
        temp1->siguiente->datoInt = (int)dato;
        temp1->siguiente->datoChar = NULL;
    }
    else{
        temp1->siguiente->datoChar = dato;
        temp1->siguiente->datoInt = NULL;
    }
    temp1->siguiente->siguiente = NULL;
}

void listarDescCampos(_listaDescCampos* inicio, _nodoCampo* ptrNodoCampo)
{
    _nodoDescCampos* temporal = inicio;

    while(temporal != NULL)
    {
        if(ptrNodoCampo->tipo == "entero")
        {
            printf("%d \n", temporal->datoInt);
        }
        else{
            printf("%c \n", temporal->datoChar);
        }
        temporal = temporal->siguiente;
    }
}

int getPosicionDescCampo(_listaDescCampos* inicio)
{
    _nodoDescCampos* temporal = inicio;
    int posicion = 0;

    while(temporal != NULL)
    {
        temporal = temporal->siguiente;
        posicion++;
    }
    return posicion;
}


#endif // DESCRIPCIONCAMPOS_H
