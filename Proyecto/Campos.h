#ifndef CAMPOS_H
#define CAMPOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef struct Campo _campo;
typedef struct ListaCampos _listaCampos;

struct Campo
{
    char* nombre_campo;
    char* tipo_campo;
    _campo* siguiente;
};

struct ListaCampos
{
    _campo *inicio;
};

/* -------------- Funciones ---------------*/

/**
    \brief Crea un espacio en memoria para una lista de Campos.
    \return Devuelve una lista de campos.
*/
_listaCampos* nuevaListaCampos();
/**
    \brief Crea un espacio en memoria para un Campo.
    \param Lista de Campos
    \param Nombre Campo
    \param Tipo Campo
*/
_campo* agregarCampo(_listaCampos* listaCampos, char* nombre_campo, char* tipo_campo);
/**
    \brief Agrega un nuevo campo a la Lista de Campos
    \param Campo
    \param Lista de Campos
*/
void agregarCamposLista(_campo* campo, _listaCampos* listaCampos);
/**
    \brief Muestra en pantalla los campos de la Lista de Campos
    \param Lista de Campos
*/
void listarCampos(_listaCampos* listaCampos);

/* -------------- Funciones ---------------*/

_listaCampos* nuevaListaCampos()
{
    _listaCampos* listaCampos;

    listaCampos = (_listaCampos *)malloc(sizeof(_listaCampos));
    listaCampos->inicio = NULL;
    return listaCampos;
}

_campo* agregarCampo(_listaCampos* listaCampos, char* nombre_campo, char* tipo_campo)
{
    _campo* campo;

    campo = (_campo *)malloc(sizeof(_campo));
    campo->nombre_campo = nombre_campo;
    campo->tipo_campo = tipo_campo;
    campo->siguiente = NULL;

    agregarCamposLista(campo, listaCampos);
    return campo;
}

void agregarCamposLista(_campo* campo, _listaCampos* listaCampos)
{
    _campo* temporal;

    if(listaCampos->inicio == NULL)
    {
        listaCampos->inicio = campo;
        return;
    }
    temporal = listaCampos->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = campo;
}

void listarCampos(_listaCampos* listaCampos)
{
    _campo* temporal = listaCampos->inicio;

    while(temporal != NULL)
    {
        printf("%s\t, %s\n", temporal->nombre_campo, temporal->tipo_campo);
        temporal = temporal->siguiente;
    }
}

#endif // CAMPOS_H
