#ifndef ARBOL_B_H
#define ARBOL_B_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE    1
#define FALSE   0
#define NUMERO_LLAVES 4

typedef struct NodoArbolB _nodoArbolB;

struct NodoArbolB
{
    int es_hoja;
    int numero_llaves;
    int llaves[NUMERO_LLAVES];
    _nodoArbolB* hijos[NUMERO_LLAVES + 1];
};

_nodoArbolB* crearArbolB();
void agregarNodoEnArbolB(_nodoArbolB* nodoArbolB, int llave);
_nodoArbolB* agregarLlaveEnNodo(_nodoArbolB* nodoArbolB, int llave, int centro);
int buscarEnArbol(_nodoArbolB* nodoArbolB, int llave);
int buscarLlave(int numero_llaves, int* llaves, int llave);

_nodoArbolB* crearArbolB()
{
    _nodoArbolB* nodoArbolB;

    nodoArbolB = (_nodoArbolB *)malloc(sizeof(_nodoArbolB));
    nodoArbolB->es_hoja = TRUE;
    nodoArbolB->numero_llaves = 0;

    return nodoArbolB;
}

void agregarNodoEnArbolB(_nodoArbolB* nodoArbolB, int llave)
{
    _nodoArbolB* bloqueHijoIzq;
    _nodoArbolB* bloqueHijoDer;
    int centro = -1;

    bloqueHijoDer = agregarLlaveEnNodo(nodoArbolB, llave, centro);

    if(bloqueHijoDer != NULL)
    {
        bloqueHijoIzq = (_nodoArbolB *)malloc(sizeof(_nodoArbolB));
        memmove(bloqueHijoIzq, nodoArbolB, sizeof(*nodoArbolB));

        nodoArbolB->numero_llaves = 1;
        nodoArbolB->es_hoja = FALSE;
        nodoArbolB->llaves[0] = centro;
        nodoArbolB->hijos[0] = bloqueHijoIzq;
        nodoArbolB->hijos[1] = bloqueHijoDer;
    }
}

_nodoArbolB* agregarLlaveEnNodo(_nodoArbolB* nodoArbolB, int llave, int centro)
{
    int posicion;
    int enMedio = -1;
    _nodoArbolB* bloqueHijoDer;

    posicion = buscarLlave(nodoArbolB->numero_llaves, nodoArbolB->llaves, centro);

    if(posicion < nodoArbolB->numero_llaves && nodoArbolB->llaves[posicion] == llave)
    {
        return NULL;
    }

    if(nodoArbolB->es_hoja)
    {
        memmove(&nodoArbolB->llaves[posicion+1], &nodoArbolB->llaves[posicion], sizeof(* (nodoArbolB->llaves))*(nodoArbolB->numero_llaves - posicion));
        nodoArbolB->llaves[posicion] = llave;
        nodoArbolB->numero_llaves++;
    }
    else{
        bloqueHijoDer = agregarLlaveEnNodo(nodoArbolB->hijos[posicion], llave, enMedio);

        if(bloqueHijoDer != NULL)
        {
            memmove(&nodoArbolB->llaves[posicion+1], &nodoArbolB->llaves[posicion], sizeof(* (nodoArbolB->llaves))*(nodoArbolB->numero_llaves - posicion));
            memmove(&nodoArbolB->llaves[posicion+2], &nodoArbolB->llaves[posicion+1], sizeof(* (nodoArbolB->llaves))*(nodoArbolB->numero_llaves - posicion));

            nodoArbolB->llaves[posicion] = enMedio;
            nodoArbolB->hijos[posicion+1] = bloqueHijoDer;
            nodoArbolB->numero_llaves++;
        }
    }

    if(nodoArbolB->numero_llaves >= NUMERO_LLAVES)
    {
        enMedio = nodoArbolB->numero_llaves/2;
        centro = nodoArbolB->llaves[enMedio];
        bloqueHijoDer = malloc(sizeof(_nodoArbolB));

        bloqueHijoDer->numero_llaves = nodoArbolB->numero_llaves - enMedio - 1;
        bloqueHijoDer->es_hoja = nodoArbolB->es_hoja;

        memmove(bloqueHijoDer->llaves, &nodoArbolB->llaves[enMedio+1], sizeof(* (nodoArbolB->llaves)) * bloqueHijoDer->numero_llaves);

        if(!nodoArbolB->es_hoja)
        {
            memmove(bloqueHijoDer->hijos, &nodoArbolB->llaves[enMedio+1], sizeof(* (nodoArbolB->hijos)) * (bloqueHijoDer->numero_llaves + 1));
        }
        nodoArbolB->numero_llaves = enMedio;
        return bloqueHijoDer;
    }
    else{
        return NULL;
    }
}

void eliminarNodo(_nodoArbolB* nodoArbolB, int llave)
{
    _nodoArbolB* nodoActual = buscarEnArbol(nodoArbolB, llave);

    if(nodoActual == NULL)
    {
        return;
    }

    if(nodoActual->es_hoja && nodoActual->numero_llaves == 1)
    {
        nodoActual == NULL;
    }
    else{
        eliminarNodoLlave(nodoActual, llave);
    }

    if(nodoActual->hijos[0]->numero_llaves+1 < nodoActual->hijos[1]->numero_llaves)
    {
        eliminarNodoLlave(nodoActual, llave);
        eliminarNodo(nodoActual, llave);
    }

    if(nodoActual->hijos[1]->numero_llaves+1 < nodoActual->hijos[0]->numero_llaves)
    {
        eliminarNodoLlave(nodoActual, llave);
        eliminarNodo(nodoActual, llave);
    }
}

void eliminarNodoLlave(_nodoArbolB* NodoArbolB, int llave)
{
    int x = 0, j;
    for(; x < NodoArbolB->numero_llaves; x++)
    {
        if(NodoArbolB->hijos[x] == llave)
        {
            for(j = x; j < NodoArbolB->numero_llaves; j++)
            {
                NodoArbolB->hijos[j] = NodoArbolB->hijos[j+1];
            }
        }
    }
}

int buscarLlave(int numero_llaves, int* llaves, int llave)
{
    int longitud = -1;
    int tamanio = numero_llaves;
    int centro;

    while(longitud + 1 < tamanio)
    {
        centro = (longitud+tamanio)/2;
        if(llaves[centro] == llave)
            return centro;
        else if(llaves[centro] < llave)
            longitud = centro;
        else
            tamanio = centro;
    }
    return tamanio;
}

int buscarEnArbol(_nodoArbolB* nodoArbolB, int llave)
{
    int posicion;

    if(nodoArbolB->numero_llaves == 0)
        return FALSE;

    posicion = buscarLlave(nodoArbolB->numero_llaves, nodoArbolB->llaves, llave);

    if(posicion < nodoArbolB->numero_llaves && nodoArbolB->llaves[posicion] == llave)
    {
        return TRUE;
    }
    else{
        return !nodoArbolB->es_hoja && buscarEnArbol(nodoArbolB->hijos[posicion], llave);
    }
}

#endif // ARBOL_B_H
