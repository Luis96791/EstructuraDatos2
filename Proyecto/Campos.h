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
    int id_campo;
    char* nombre_campo;
    char* tipo;
    _nodoCampo* siguiente;
};

struct ListaCampos
{
    _nodoCampo *inicio;
};

_listaCampos* nuevoCampo();
void insertarCampos(_listaCampos* ptr, int id, char* nombre_campo, char* tipo);
void listarCampos(_listaCampos* inicio);

_listaCampos* nuevoCampo()
{
    _listaCampos* ptr;

    ptr = (_listaCampos *)malloc(sizeof(_listaCampos));
    ptr->inicio = NULL;
    return ptr;
}

void insertarCampos(_listaCampos* ptr, int id, char* nombre_campo, char* tipo)
{

    _nodoCampo *temp, *temp1;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoCampo *)malloc(sizeof(_nodoCampo));
        ptr->inicio->id_campo = id;
        ptr->inicio->nombre_campo = nombre_campo;
        ptr->inicio->tipo = tipo;
        ptr->inicio->siguiente = NULL;
        return;
    }
    temp = ptr->inicio;

    while(temp != NULL)
    {
        temp1 = temp;
        temp = temp->siguiente;
    }
    temp1->siguiente = (_nodoCampo *)malloc(sizeof(_nodoCampo));
    temp1->siguiente->id_campo = id;
    temp1->siguiente->nombre_campo = nombre_campo;
    temp1->siguiente->tipo = tipo;
    temp1->siguiente->siguiente = NULL;
}

void listarCampos(_listaCampos* inicio)
{
    _nodoCampo* temporal = inicio;

    while(temporal != NULL)
    {
        printf("%d , %s , %s\n", temporal->id_campo, temporal->nombre_campo, temporal->tipo);
        temporal = temporal->siguiente;
    }
}

#endif // CAMPOS_H
