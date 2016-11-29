#ifndef MENULISTA_H
#define MENULISTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NodoMenu _nodoMenu;
typedef struct ListaMenu _listaMenu;

struct NodoMenu
{
    int id;
    char* titulo;
    char* grado;
    _nodoMenu* siguiente;
};

struct ListaMenu
{
    _nodoMenu* inicio;
};

/*------------ Funciones ----------------*/
_listaMenu* nuevaListaMenu();
void agregarNodoMenu(_listaMenu* listaMenu, int id, char* titulo, char* grado);
void agregarListaMenu(_nodoMenu* nodoMenu, _listaMenu* listaMenu);
void listarNodosMenu(_listaMenu* listaMenu);
/*------------ Funciones ----------------*/

_listaMenu* nuevaListaMenu()
{
    _listaMenu* listaMenu;

    listaMenu = (_listaMenu *)malloc(sizeof(_listaMenu));
    listaMenu->inicio = NULL;
    return listaMenu;
}

void agregarNodoMenu(_listaMenu* listaMenu, int id, char* titulo, char* grado)
{
    _nodoMenu* nodoMenu;

    nodoMenu = (_nodoMenu *)malloc(sizeof(_nodoMenu));
    nodoMenu->id = id;
    nodoMenu->titulo = titulo;
    nodoMenu->grado = grado;
    nodoMenu->siguiente = NULL;

    agregarListaMenu(nodoMenu, listaMenu);
}

void agregarListaMenu(_nodoMenu* nodoMenu, _listaMenu* listaMenu)
{
    _nodoMenu* temporal;

    if(listaMenu->inicio == NULL)
    {
        listaMenu->inicio = nodoMenu;
        return;
    }

    temporal = listaMenu->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = nodoMenu;
}

void listarNodosMenu(_listaMenu* listaMenu)
{
    _nodoMenu* temporal = listaMenu->inicio;

    while(temporal != NULL)
    {
        printf("%d, %s, %s\n", temporal->id, temporal->titulo, temporal->grado);
        temporal = temporal->siguiente;
    }
}

#endif // MENULISTA_H
