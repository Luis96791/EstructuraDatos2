#ifndef BLOQUEREGISTROS_H
#define BLOQUEREGISTROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Registros.h"

typedef struct BloqueRegistros _bloqueRegistros;
typedef struct ListaBloqueRegistros _listaBloqueRegistros;

struct BloqueRegistros
{
    int bloque_anterior;
    int bloque_siguiente;
    int cantidad_registros;
    _bloqueRegistros* siguiente;
    _listaRegistros* listaRegistros;
};

struct ListaBloqueRegistros
{
    _bloqueRegistros* inicio;
};

_listaBloqueRegistros* nuevaListaBloqueRegistros();
void agregarBloqueRegistros(int anterior, int siguiente, int cantidad_registros, _listaRegistros* listaRegistros);

_listaBloqueRegistros* nuevaListaBloqueRegistros()
{
    _listaBloqueRegistros* listaBloqueRegistros;

    listaBloqueRegistros = (_listaBloqueRegistros *)malloc(sizeof(_listaBloqueRegistros));
    listaBloqueRegistros->inicio = NULL;
    return listaBloqueRegistros;
}

#endif // BLOQUEREGISTROS_H
