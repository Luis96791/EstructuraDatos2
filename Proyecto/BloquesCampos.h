#ifndef BLOQUESCAMPOS_H
#define BLOQUESCAMPOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BloqueCampos _bloqueCampos;
typedef struct ListaBloquesCampos _listaBloquesCampos;

struct BloqueCampos
{
    char* nombreCampo;
    char* tipoCampo;
    _bloqueCampos* siguiente;
};

struct ListaBloquesCampos
{
    _bloqueCampos* inicio;
};

/** ------------------FUNCIONES------------------ **/
_listaBloquesCampos* nuevaListaBloqueCampos();
void agregarCampos(char* nombreCampo, char* tipoCampo, _listaBloquesCampos* listaBloquesCampos);
void listarBloqueCampos(_listaBloquesCampos* listaBloquesCampos);
int getSizeListaBloqueCampos(_listaBloquesCampos* listaBloquesCampos);
_listaBloquesCampos* vaciarBloquesCampos(_listaBloquesCampos* listaBloquesCampos);
_bloqueCampos* getUltimoBloqueCampos(_listaBloquesCampos* listaBloquesCampos);
/** ------------------FUNCIONES------------------ **/

_listaBloquesCampos* nuevaListaBloqueCampos()
{
    _listaBloquesCampos* listaBloquesCampos;
    listaBloquesCampos = (_listaBloquesCampos *)malloc(sizeof(_listaBloquesCampos));
    listaBloquesCampos->inicio = NULL;
    return listaBloquesCampos;
}

void agregarCampos(char* nombreCampo, char* tipoCampo, _listaBloquesCampos* listaBloquesCampos)
{
    _bloqueCampos* temporal;

    if(listaBloquesCampos->inicio == NULL)
    {
        listaBloquesCampos->inicio = (_listaBloquesCampos *)malloc(sizeof(_listaBloquesCampos));
        listaBloquesCampos->inicio->nombreCampo = nombreCampo;
        listaBloquesCampos->inicio->tipoCampo = tipoCampo;
        listaBloquesCampos->inicio->siguiente = NULL;
    }
    else{
        temporal = listaBloquesCampos->inicio;

        while(temporal->siguiente != NULL)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = (_listaBloquesCampos *)malloc(sizeof(_listaBloquesCampos));
        temporal->siguiente->nombreCampo = nombreCampo;
        temporal->siguiente->tipoCampo = tipoCampo;
        temporal->siguiente->siguiente = NULL;
    }
}

void listarBloqueCampos(_listaBloquesCampos* listaBloquesCampos)
{
    _bloqueCampos* temporal = listaBloquesCampos->inicio;

    while(temporal != NULL)
    {
        printf("%s\n", temporal->nombreCampo);
        temporal = temporal->siguiente;
    }
}

int getSizeListaBloqueCampos(_listaBloquesCampos* listaBloquesCampos)
{
    int contador = 0;
    _bloqueCampos* temporal = listaBloquesCampos->inicio;

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

_bloqueCampos* getUltimoBloqueCampos(_listaBloquesCampos* listaBloquesCampos)
{
    _bloqueCampos* temporal = listaBloquesCampos->inicio;

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

_listaBloquesCampos* vaciarBloquesCampos(_listaBloquesCampos* listaBloquesCampos)
{
    _bloqueCampos* bloqueCampos = getUltimoBloqueCampos(listaBloquesCampos)->siguiente;
    listaBloquesCampos->inicio = NULL;
    listaBloquesCampos->inicio = bloqueCampos;
    return listaBloquesCampos;
}

#endif // BLOQUESCAMPOS_H
