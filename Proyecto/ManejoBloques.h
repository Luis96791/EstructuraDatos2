#ifndef MANEJOBLOQUES_H
#define MANEJOBLOQUES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BloqueTablas.h"
#include "Tablas.h"

#define TRUE    1
#define FALSE   0

void agregarTablaEnBloque(char* nombreTabla, _listaBloques* listaBloques, _listaBloqueTablas* listaBloqueTablas);
int hayEspacioDisponible(_bloque* bloque);
_bloque* getUltimoBloque(_listaBloques* listaBloques);

_bloque* getUltimoBloque(_listaBloques* listaBloques)
{
    _bloque* temporal = listaBloques->inicio;

    if(temporal == NULL)
    {
        return NULL;
    }

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    return temporal;
}

void agregarTablaEnBloque(char* nombreTabla, _listaBloques* listaBloques, _listaBloqueTablas* listaBloqueTablas)//lo que no puedo manejar es esta lista quiero hacerla
//que sea para cada bloque por que asi como esta es para todos los bloques seria la misma lista de tablas
{
    _bloque* bloque = getUltimoBloque(listaBloques);

    //Esto es para cuando la lista bloques este vacia
    if(bloque == NULL)
    {
        insertarBloque(listaBloques, -1, -1, 4);
        bloque = getUltimoBloque(listaBloques);
        insertarTablasEnBloque(listaBloqueTablas, nombreTabla, bloque);
    }
    else{
        bloque = getUltimoBloque(listaBloques);
        if(hayEspacioDisponible(bloque))
        {
            insertarTablasEnBloque(listaBloqueTablas, nombreTabla, bloque);
        }
        else{
            //NO SE QUE PONER EN ESTE ELSE
        }
    }
}

int hayEspacioDisponible(_bloque* bloque)
{
    if(getSizeListaBloqueTablas(bloque->ptrListaBloqueTablas) < bloque->cantidadTablas)
    {
        return TRUE;
    }
    return FALSE;
}

#endif // MANEJOBLOQUES_H
