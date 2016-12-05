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
    _registro* ultimo;
};

_listaRegistros* nuevaListaRegistros();
_registro* agregarRegistro(_listaRegistros* listaRegistros);
_registro* agregarRegistrosLista(_registro* registro, _listaRegistros* listaRegistros);
void listarRegistros(_listaRegistros* listaRegistros);


_listaRegistros* nuevaListaRegistros()
{
    _listaRegistros* listaRegistros;

    listaRegistros = (_listaRegistros *)malloc(sizeof(_listaRegistros));
    listaRegistros->inicio = NULL;
    return listaRegistros;
}

_registro* agregarRegistro(_listaRegistros* listaRegistros)
{
    _registro* registro;
    int numero_registro;

    if(listaRegistros->inicio == NULL)
        numero_registro = 1;
    else
        numero_registro = (listaRegistros->ultimo->numero_registro+1);

    registro = (_registro *)malloc(sizeof(_registro));
    registro->numero_registro = numero_registro;
    registro->listaCampoDatos = nuevaListaCampoDatos();

    return agregarRegistrosLista(registro, listaRegistros);
}

_registro* agregarRegistrosLista(_registro* registro, _listaRegistros* listaRegistros)
{
    if(listaRegistros->inicio == NULL)
    {
        listaRegistros->inicio = registro;
        listaRegistros->ultimo = registro;
        return registro;
    }

    listaRegistros->ultimo->siguiente = registro;
    listaRegistros->ultimo = registro;
    return registro;
}

void listarRegistros(_listaRegistros* listaRegistros)
{
    _registro* temporal = listaRegistros->inicio;

    while(temporal != NULL)
    {
        printf("Registro: %d", temporal->numero_registro);
        listarCampoDatos(temporal->listaCampoDatos);
        temporal = temporal->siguiente;
    }
}

#endif // REGISTROS_H
