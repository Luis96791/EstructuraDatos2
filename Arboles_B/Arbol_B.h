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
    _nodoArbolB* subArbolB[NUMERO_LLAVES + 1];
};

_nodoArbolB* crearArbolB();
void agregarBloqueEnArbolB(_nodoArbolB* nodoArbolB, int llave);
_nodoArbolB* agregarEnBloque_ArbolB(_nodoArbolB* nodoArbolB, int llave, int centro);

_nodoArbolB* crearArbolB()
{
    _nodoArbolB* nodoArbolB;

    nodoArbolB = (_nodoArbolB *)malloc(sizeof(_nodoArbolB));
    nodoArbolB->es_hoja = TRUE;
    nodoArbolB->numero_llaves = 0;

    return nodoArbolB;
}

void agregarBloqueEnArbolB(_nodoArbolB* nodoArbolB, int llave)
{
    _nodoArbolB* bloqueHijoIzq;
    _nodoArbolB* bloqueHijoDer;
    int centro;

    bloqueHijoDer = agregarEnBloque_ArbolB(nodoArbolB, llave, centro); //probablemente &centro

    if(bloqueHijoDer != NULL)
    {
        bloqueHijoIzq = (_nodoArbolB *)malloc(sizeof(_nodoArbolB));
        memmove(bloqueHijoIzq, nodoArbolB, sizeof(*nodoArbolB));

        nodoArbolB->numero_llaves = 1;
        nodoArbolB->es_hoja = FALSE;
        nodoArbolB->llaves[0] = centro;
        nodoArbolB->subArbolB[0] = bloqueHijoIzq;
        nodoArbolB->subArbolB[1] = bloqueHijoDer;
    }
}

_nodoArbolB* agregarEnBloque_ArbolB(_nodoArbolB* nodoArbolB, int llave, int centro)
{
    int posicion;
    int en_medio;
    _nodoArbolB* bloqueHijoDer;

    //AQUI posicion = buscarLLave

    if(posicion < nodoArbolB->numero_llaves && nodoArbolB->llaves[posicion] == llave)
    {
        return NULL;
    }

    if(nodoArbolB->es_hoja != NULL)
    {
        memmove(nodoArbolB->llaves[posicion+1], nodoArbolB->llaves[posicion], sizeof(* (nodoArbolB->llaves))*(nodoArbolB->numero_llaves - posicion));
        nodoArbolB->llaves[posicion] = llave;
        nodoArbolB->numero_llaves++;
    }
    else{
        bloqueHijoDer = agregarEnBloque_ArbolB(nodoArbolB->subArbolB[posicion], llave, en_medio); // chek si es &en_medio

        if(bloqueHijoDer != NULL)
        {
            memmove(nodoArbolB->llaves[posicion+1], nodoArbolB->llaves[posicion], sizeof(* (nodoArbolB->llaves))*(nodoArbolB->numero_llaves - posicion));
            memmove(nodoArbolB->llaves[posicion+2], nodoArbolB->llaves[posicion+1], sizeof(* (nodoArbolB->llaves))*(nodoArbolB->numero_llaves - posicion));

            nodoArbolB->llaves[posicion] = en_medio;
            nodoArbolB->subArbolB[posicion+1] = bloqueHijoDer;
            nodoArbolB->numero_llaves++;
        }
    }

    if(nodoArbolB->numero_llaves >= NUMERO_LLAVES)
    {
        en_medio = nodoArbolB->numero_llaves/2;
        centro = nodoArbolB->llaves[en_medio]; //chek si es *centro

        bloqueHijoDer = malloc(sizeof(_nodoArbolB));

        bloqueHijoDer->numero_llaves = nodoArbolB->numero_llaves - en_medio - 1;
        bloqueHijoDer->es_hoja = nodoArbolB->es_hoja;

        memmove(bloqueHijoDer->llaves, nodoArbolB->llaves[en_medio+1], sizeof(* (nodoArbolB->llaves)) * bloqueHijoDer->numero_llaves);//check &nodoArbolB->llaves[en_medio+1]

        if(!nodoArbolB->es_hoja)
        {
            memmove(bloqueHijoDer->subArbolB, nodoArbolB->llaves[en_medio+1], sizeof(* (nodoArbolB->subArbolB)) * (bloqueHijoDer->numero_llaves + 1));//check &nodoArbolB->llaves[en_medio+1]
        }
        nodoArbolB->numero_llaves = en_medio;
        return bloqueHijoDer;
    }
    else{
        return NULL;
    }
}

#endif // ARBOL_B_H
