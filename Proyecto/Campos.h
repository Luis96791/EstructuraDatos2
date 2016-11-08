#ifndef CAMPOS_H
#define CAMPOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef struct Campos _nodoCampo;
typedef struct ListaCampos _listaCampos;

struct Campos
{
    char* nombre_campo;
    char* tipo;
    _nodoCampo* siguiente;
};

struct ListaCampos
{
    _nodoCampo *inicio;
};

_listaCampos* nuevoCampo();
void insertarCampos(_listaCampos* ptr, char* nombre_campo, char* tipo);
void listarCampos(_listaCampos* ptr);
_nodoCampo* buscarCampo(_listaCampos* ptr, char* nombre);

_listaCampos* nuevoCampo()
{
    _listaCampos* ptr;

    ptr = (_listaCampos *)malloc(sizeof(_listaCampos));
    ptr->inicio = NULL;
    return ptr;
}

void insertarCampos(_listaCampos* ptr, char* nombre_campo, char* tipo)
{
    _nodoCampo *temp;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoCampo *)malloc(sizeof(_nodoCampo));
        ptr->inicio->nombre_campo = nombre_campo;
        ptr->inicio->tipo = tipo;
        ptr->inicio->siguiente = NULL;
        return;
    }
    temp = ptr->inicio;

    while(temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = (_nodoCampo *)malloc(sizeof(_nodoCampo));
    temp->siguiente->nombre_campo = nombre_campo;
    temp->siguiente->tipo = tipo;
    temp->siguiente->siguiente = NULL;
}

void listarCampos(_listaCampos* ptr)
{
    _nodoCampo* temporal = ptr->inicio;

    while(temporal != NULL)
    {
        printf("%s , %s\n", temporal->nombre_campo, temporal->tipo);
        temporal = temporal->siguiente;
    }
}

_nodoCampo* buscarCampo(_listaCampos* ptr, char* nombre)
{
    _nodoCampo* temporal = ptr->inicio;


    while(temporal != NULL)
    {
        if(compareTo(temporal->nombre_campo, nombre))
        {
            printf("Encontrado\n");
            return temporal;
        }
        temporal = temporal->siguiente;
    }
    printf("NO encontrado\n");
    return  NULL;
}

#endif // CAMPOS_H
