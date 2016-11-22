#ifndef BLOQUESTABLAS_H
#define BLOQUESTABLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BloqueTablas _bloqueTablas;
typedef struct ListaBloqueTablas _listaBloqueTablas;

struct BloqueTablas
{
    char* nombreTabla;
    int primerBloqueCampos;
    int primerBloqueRegistros;
    _bloqueTablas* siguiente;
};

struct ListaBloqueTablas
{
    _bloqueTablas* inicio;
};

/** -------------------- Funciones ---------------------- **/
_listaBloqueTablas* nuevaListaBloqueTablas();
void agregarTablaBloque(char* nombreTabla, _listaBloqueTablas* listaBloqueTablas, int pBC, int pBR);
void listarBloqueTablas(_listaBloqueTablas* listaBloqueTablas);
int getSizeListaBloqueTablas(_listaBloqueTablas* listaBloqueTablas);
_listaBloqueTablas* vaciarBloqueTablas(_listaBloqueTablas* listaBloqueTablas);
_bloqueTablas* getUltimoBloqueTablas(_listaBloqueTablas* listaBloqueTablas);
/** -------------------- Funciones ---------------------- **/

_listaBloqueTablas* nuevaListaBloqueTablas()
{
    _listaBloqueTablas* listaBloqueTablas;

    listaBloqueTablas = (_listaBloqueTablas *)malloc(sizeof(_listaBloqueTablas));
    listaBloqueTablas->inicio = NULL;

    return listaBloqueTablas;
}

void agregarTablaBloque(char* nombreTabla, _listaBloqueTablas* listaBloqueTablas, int pBC, int pBR)
{
    _bloqueTablas* temporal;

    if(listaBloqueTablas->inicio == NULL)
    {
        listaBloqueTablas->inicio = (_bloqueTablas *)malloc(sizeof(_bloqueTablas));
        listaBloqueTablas->inicio->nombreTabla = nombreTabla;
        listaBloqueTablas->inicio->primerBloqueCampos = pBC;
        listaBloqueTablas->inicio->primerBloqueRegistros = pBR;
        listaBloqueTablas->inicio->siguiente = NULL;
    }
    else{
        temporal = listaBloqueTablas->inicio;

        while(temporal->siguiente != NULL)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = (_bloqueTablas *)malloc(sizeof(_bloqueTablas));
        temporal->siguiente->nombreTabla = nombreTabla;
        temporal->siguiente->primerBloqueCampos = pBC;
        temporal->siguiente->primerBloqueRegistros = pBR;
        temporal->siguiente->siguiente = NULL;
    }
}

void listarBloqueTablas(_listaBloqueTablas* listaBloqueTablas)
{
    _bloqueTablas* temporal = listaBloqueTablas->inicio;

    while(temporal != NULL)
    {
        printf("%s\n", temporal->nombreTabla);
        temporal = temporal->siguiente;
    }
}

int getSizeListaBloqueTablas(_listaBloqueTablas* listaBloqueTablas)
{
    int contador = 0;
    _bloqueTablas* temporal = listaBloqueTablas->inicio;

    if(temporal == NULL)
    {
        return contador;
    }
    else{
        while(temporal != NULL)
        {
            contador++;
            temporal = temporal->siguiente;
        }
    }
    return contador;
}

_listaBloqueTablas* vaciarBloqueTablas(_listaBloqueTablas* listaBloqueTablas)
{
   listaBloqueTablas->inicio = NULL;
   return listaBloqueTablas;
}

_bloqueTablas* getUltimoBloqueTablas(_listaBloqueTablas* listaBloqueTablas)
{
    _bloqueTablas* temporal = listaBloqueTablas->inicio;

    if(temporal == NULL)
    {
        return NULL;
    }
    else{
        while( 1 )
        {
            if(temporal->siguiente == NULL)
            {
                return temporal;
            }
            else{
                temporal = temporal->siguiente;
            }
        }
    }
}

#endif // BLOQUESTABLAS_H
