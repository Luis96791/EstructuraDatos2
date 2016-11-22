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
void agregarTablaCampos(char* nombreCampo, char* tipoCampo, _listaBloquesCampos* listaBloquesCampos);
void listarBloqueCampos(_listaBloquesCampos* listaBloquesCampos);
/** ------------------FUNCIONES------------------ **/

_listaBloquesCampos* nuevalistaBloqueCampos()
{
    _listaBloquesCampos* listaBloquesCampos;
    listaBloquesCampos = (_listaBloquesCampos *)malloc(sizeof(_listaBloquesCampos));
    listaBloquesCampos->inicio = NULL;
    return listaBloquesCampos;
}

void agregarTablaCampos(char* nombreCampo, char* tipoCampo, _listaBloquesCampos* listaBloquesCampos)
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

#endif // BLOQUESCAMPOS_H
