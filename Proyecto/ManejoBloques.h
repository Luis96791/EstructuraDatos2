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
void agregarCampoEnBloque(char* nombreCampo, char* tipoCampo, _listaBloques* listaBloques, _listaBloquesCampos* listaBloquesCampos);
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

void agregarCampoEnBloque(char* nombreCampo, char* tipoCampo, _listaBloques* listaBloques, _listaBloquesCampos* listaBloquesCampos)
{
    _bloque* bloque = getUltimoBloque(listaBloques);
    _bloqueCampos* bloqueCampos;

    if(bloque == NULL)
    {
        agregarBloque(listaBloques, -1, 1, 4);
        agregarCampos(nombreCampo, tipoCampo, listaBloquesCampos);
        bloque = getUltimoBloque(listaBloques);
        setListaBloqueCampos(listaBloques, listaBloquesCampos);
    }
    else{
        if(getSizeListaBloqueCampos(bloque->ptrListaBLoquesCampos) < bloque->cantTablasEnBloque)//hay que cambiarle nombre a este atributo
        {
            agregarCampos(nombreCampo, tipoCampo, listaBloquesCampos);
        }
        else{
            listaBloquesCampos = vaciarBloquesCampos(listaBloquesCampos);
            agregarBloque(listaBloques, -1, 1, 4);
            agregarCampos(nombreCampo, tipoCampo, listaBloquesCampos);
            bloque = getUltimoBloque(listaBloques);
            setListaBloqueCampos(listaBloques, listaBloquesCampos);
        }
    }
}

#endif // MANEJOBLOQUES_H
