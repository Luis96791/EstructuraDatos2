#ifndef REGISTROS_H
#define REGISTROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef struct Registros _nodoRegistro;
typedef struct ListaRegistros _listaRegistros;

struct Registros
{
    int dato_int;
    double dato_double;
    char dato_char;
    char* dato_string;
    int dato_bool;
    _nodoRegistro* siguiente;
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
    /**concretar idea para este TDA**/
}

#endif // REGISTROS_H
