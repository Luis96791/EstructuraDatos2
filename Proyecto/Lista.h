#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#include "Nodo.h"

 typedef struct Lista
{
    struct mi_nodo* inicio;
}mi_lista;

int vacio(struct Nodo* nodo)
{
    return nodo == NULL;
}

void agregar(struct Nodo* nodo)
{
    if(vacio(nodo) == 0)
    {
        mi_lista* inicio = nodo;
        return;
    }
    mi_nodo* temp;
    temp = mi_lista* inicio;

}

#endif // LISTA_H
