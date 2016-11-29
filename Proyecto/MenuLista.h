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
/**
    Asigna un nuevo espacio en memoria para una lista.
    @return Lista Menu vacia
*/
_listaMenu* nuevaListaMenu();
/**
    Agrega un un elemento a la Lista Menu
    (el nodo menu debe estar creado con todos sus atributos)
    @param Nodo Menu
    @param Lista Menu
*/
void agregarListaMenu(_nodoMenu* nodoMenu, _listaMenu* listaMenu);
/**
    Muestra en pantalla todos los elementos de la lista.
    @param Lista Menu
*/
void mostrarMenuEnPantalla(_listaMenu* listaMenu);
/*------------ Funciones ----------------*/

_listaMenu* nuevaListaMenu()
{
    _listaMenu* listaMenu;

    listaMenu = (_listaMenu *)malloc(sizeof(_listaMenu));
    listaMenu->inicio = NULL;
    return listaMenu;
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

void mostrarMenuEnPantalla(_listaMenu* listaMenu)
{
    _nodoMenu* temporal = listaMenu->inicio;

    while(temporal != NULL)
    {
        printf("\t  %s-. %s\n", temporal->grado, temporal->titulo);
        temporal = temporal->siguiente;
    }
}

#endif // MENULISTA_H
