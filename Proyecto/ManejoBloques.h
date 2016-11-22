#ifndef MANEJOBLOQUES_H
#define MANEJOBLOQUES_H
#define TRUE    1
#define FALSE   0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bloques.h"
#include "BloquesTablas.h"

/** -------------------- Funciones ---------------------- **/
_listaBloques* inicializarListaBloque();
_listaBloqueTablas* inicializarListaTablaEnBloque();
void agregarTablaEnBloque(char* nombreTabla, _listaBloques* listaBloques, _listaBloqueTablas* listaBloqueTablas);
/** -------------------- Funciones ---------------------- **/

_listaBloques* inicializarListaBloque()
{
    return nuevaListaBloques();
}

_listaBloqueTablas* inicializarListaTablaEnBloque()
{
    return nuevaListaBloqueTablas();
}

void agregarTablaEnBloque(char* nombreTabla, _listaBloques* listaBloques, _listaBloqueTablas* listaBloqueTablas)
{
    _bloque* bloque = getUltimoBloque(listaBloques);
    _bloqueTablas* bloqueTablas;

    if(bloque == NULL)
    {
        agregarBloque(listaBloques, -1, 1, 4);
        agregarTablaBloque(nombreTabla, listaBloqueTablas, -1, -1);
        bloque = getUltimoBloque(listaBloques);
        setListaBloqueTablas(listaBloques, listaBloqueTablas);
    }
    else{
        if(getSizeListaBloqueTablas(bloque->ptrListaBloqueTablas) < bloque->cantTablasEnBloque)
        {
            agregarTablaBloque(nombreTabla, listaBloqueTablas, -1, -1);
        }
        else{
            listaBloqueTablas = vaciarBloqueTablas(listaBloqueTablas);
            agregarBloque(listaBloques, -1, 1, 4);
            agregarTablaBloque(nombreTabla, listaBloqueTablas, -1, -1);
            bloque = getUltimoBloque(listaBloques);
            setListaBloqueTablas(listaBloques, listaBloqueTablas);
        }
    }
}

#endif // MANEJOBLOQUES_H
