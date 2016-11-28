#ifndef REGISTROS_H
#define REGISTROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CampoDato.h"

#define TRUE    1
#define FALSE   0


typedef struct Registro _registro;
typedef struct ListaRegistros _listaRegistros;

struct Registro
{
    int numero_registro;
    _listaCampoDatos* listaCampoDatos;
    _registro* siguiente;
};

struct ListaRegistros
{
    _registro* inicio;
};

_listaRegistros* nuevaListaRegistros();
_registro* agregarRegistro(_listaRegistros* listaRegistros, int numero_registro);
_registro* agregarRegistrosLista(_registro* registro, _listaRegistros* listaRegistros);
void listarRegistros(_listaRegistros* listaRegistros);


_listaRegistros* nuevaListaRegistros()
{
    _listaRegistros* listaRegistros;

    listaRegistros = (_listaRegistros *)malloc(sizeof(_listaRegistros));
    listaRegistros->inicio = NULL;
    return listaRegistros;
}

_registro* agregarRegistro(_listaRegistros* listaRegistros, int numero_registro)
{
    _registro* registro;

    registro = (_registro *)malloc(sizeof(_registro));
    registro->numero_registro = numero_registro;
    registro->listaCampoDatos = nuevaListaCampoDatos();
    registro->siguiente = NULL;

    return agregarRegistrosLista(registro, listaRegistros);
}

_registro* agregarRegistrosLista(_registro* registro, _listaRegistros* listaRegistros)
{
    _registro* temporal;

    if(listaRegistros->inicio == NULL)
    {
        listaRegistros->inicio = registro;
        return registro;
    }
    temporal = listaRegistros->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = registro;
    return registro;
}

void listarRegistros(_listaRegistros* listaRegistros)
{
    _registro* temporal = listaRegistros->inicio;

    while(temporal != NULL)
    {
        printf("Registro %d\n", temporal->numero_registro);
        listarCampoDatos(temporal->listaCampoDatos);
        temporal = temporal->siguiente;
    }
}

#endif // REGISTROS_H
