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
void insertarDesCampos(_listaDescCampos* ptr, char* dato);
void listarDescCampos(_listaDescCampos* inicio);
int getPosicionDescCampo(_listaDescCampos* inicio);

_listaDescCampos* nuevaDesCampos()
{
    _listaDescCampos* ptr;

    ptr = (_listaDescCampos *)malloc(sizeof(_listaDescCampos));
    ptr->inicio = NULL;
    return ptr;
}

void insertarDesCampos(_listaDescCampos* ptr, char* dato)
{
    _nodoDescCampos *temp, *temp1;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoDescCampos *)malloc(sizeof(_nodoDescCampos));
        ptr->inicio->datoChar = dato;
        ptr->inicio->datoInt = 0;
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
    temp1->siguiente->datoChar = dato;
    temp1->siguiente->datoInt = 0;
    temp1->siguiente->siguiente = NULL;
}

void listarDescCampos(_listaDescCampos* inicio)
{
    _nodoDescCampos* temporal = inicio;

    while(temporal != NULL)
    {
        printf("%s\t",temporal->datoChar);
        temporal = temporal->siguiente;
    }
    printf("\n");
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
