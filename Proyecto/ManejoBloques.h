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
    //El parametro listaBloqueTablas se debera estar vaciando en algun lugar fuera de esta funcion cuando su SIZE
    //sea 4
    //por el momento lo que interesa es hacer que esta funcion este haciendo las cosas correctamente.


    _bloque* bloque = getUltimoBloque(listaBloques);
    //Esto es en caso de que la listaBloques este vacia

    if(bloque == NULL)
    {
        agregarBloque(listaBloques, -1, 1, 4);//listabloques, anterior, siguiente, cantTablas
        agregarTablaBloque(nombreTabla, listaBloqueTablas, -1, -1);
        setListaBloqueTablas(getUltimoBloque(listaBloques), listaBloqueTablas);
        //se llama la funcion getUltimoBloque para que setee el ultimo bloque que en este caso seria el primero ingresado
        //y que ponga la lista de tablas en ese bloque.
    }
    else{
        if(getSizeListaBloqueTablas(bloque->ptrListaBloqueTablas) <= bloque->cantTablasEnBloque)
        {
            agregarTablaBloque(nombreTabla, listaBloqueTablas, -1, -1);
        }
        else{
            agregarBloque(listaBloques, -1, 1, 4);
            agregarTablaBloque(nombreTabla, listaBloqueTablas, -1, -1);
            setListaBloqueTablas(getUltimoBloque(listaBloques), listaBloqueTablas);
        }
    }
}

#endif // MANEJOBLOQUES_H
