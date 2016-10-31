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
_nodoCampo* insertarCampos(_listaCampos* ptr, char* nombre_campo, char* tipo);
void listarCampos(_listaCampos* inicio);
_nodoCampo* buscarCampo(_listaCampos* ptr, char* nombre);

_listaCampos* nuevoCampo()
{
    _listaCampos* ptr;

    ptr = (_listaCampos *)malloc(sizeof(_listaCampos));
    ptr->inicio = NULL;
    return ptr;
}

_nodoCampo* insertarCampos(_listaCampos* ptr, char* nombre_campo, char* tipo)
{
    _nodoCampo *temp, *temp1;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoCampo *)malloc(sizeof(_nodoCampo));
        ptr->inicio->nombre_campo = nombre_campo;
        ptr->inicio->tipo = tipo;
        ptr->inicio->siguiente = NULL;
        return ptr->inicio;
    }
    temp = ptr->inicio;

    while(temp != NULL)
    {
        temp1 = temp;
        temp = temp->siguiente;
    }
    temp1->siguiente = (_nodoCampo *)malloc(sizeof(_nodoCampo));
    temp1->siguiente->nombre_campo = nombre_campo;
    temp1->siguiente->tipo = tipo;
    temp1->siguiente->siguiente = NULL;
    return temp1->siguiente;
}

void listarCampos(_listaCampos* inicio)
{
    _nodoCampo* temporal = inicio;

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
