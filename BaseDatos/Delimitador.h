#ifndef DELIMITADOR_H
#define DELIMITADOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tablas.h"

char* convertirAcadena(_listaTabla* LT);

char* convertirAcadena(_listaTabla* LT)
{
    _nodoTabla* temp = LT->inicio;
    char* cadena = malloc(200);
    char caracter;

    while(temp != NULL)
    {
        temp = temp->siguiente;
    }

    return cadena;
}

#endif // DELIMITADOR_H
