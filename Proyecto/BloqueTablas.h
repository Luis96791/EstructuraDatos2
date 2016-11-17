#ifndef BLOQUETABLAS_H
#define BLOQUETABLAS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Tablas.h"

typedef struct Bloque _bloque;
typedef struct ListaBloques _listaBloques;
typedef struct BloqueTablas _bloqueTablas;
typedef struct ListaBloqueTablas _listaBloqueTablas;


//Este es un nodo Bloque
struct Bloque
{
    int posAnterior;
    int posSiguiente;
    int cantidadTablas;
    _bloque* siguiente;
    _listaBloqueTablas* ptrListaBloqueTablas;
};

// Este es una lista de Bloques esto tiene un ptr a la struct encabezadoBloqueTablas
// la cual tiene un ptr a una lista de tablas por cada bloque
struct ListaBloques
{
    _bloque* inicio;
};

// Este es un nodo BloqueTablas
struct BloqueTablas
{
    char* nombreTabla;
    int posPrimerBloqueCampos;
    int posPrimerBloqueRegistros;
    _bloqueTablas* siguiente;
};

// Esta es una lista de Tablas por cada Encabezado
struct ListaBloqueTablas
{
    _bloqueTablas* inicio;
};

_listaBloqueTablas* nuevaListaBloqueTablas();
void insertarTablasEnBloque(_listaBloqueTablas* ptr, char* nombreTabla, _bloque* bloque);
void listarTablasEnBloque(_listaBloqueTablas* ptr);
int getSizeListaBloqueTablas(_listaBloqueTablas* ptr);

_listaBloques* nuevaListaBloques();
void insertarBloque(_listaBloques* ptr, int anterior, int siguiente, int cantTablas);
void listarBloques(_listaBloques* ptr);

_listaBloqueTablas* nuevaListaBloqueTablas()
{
    _listaBloqueTablas* ptr;

    ptr = (_listaBloqueTablas *)malloc(sizeof(_listaBloqueTablas));
    ptr->inicio = NULL;
    return ptr;
}

void insertarTablasEnBloque(_listaBloqueTablas* ptr, char* nombreTabla, _bloque* bloque)
{
    _bloqueTablas* temp;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_bloqueTablas *)malloc(sizeof(_bloqueTablas));
        ptr->inicio->nombreTabla = nombreTabla;
        ptr->inicio->posPrimerBloqueCampos = -1;
        ptr->inicio->posPrimerBloqueRegistros = -1;
        ptr->inicio->siguiente = NULL;
    }
    else{
        temp = ptr->inicio;
        while(temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = (_bloqueTablas *)malloc(sizeof(_bloqueTablas));
        temp->siguiente->nombreTabla = nombreTabla;
        temp->siguiente->posPrimerBloqueCampos = -1;
        temp->siguiente->posPrimerBloqueRegistros = -1;
        temp->siguiente->siguiente = NULL;
    }
    bloque->ptrListaBloqueTablas = ptr;
}

void listarTablasEnBloque(_listaBloqueTablas* ptr)
{
    _bloqueTablas* temp = ptr->inicio;

    while(temp != NULL)
    {
        printf("%s \n", temp->nombreTabla);
        temp = temp->siguiente;
    }
}

int getSizeListaBloqueTablas(_listaBloqueTablas* ptr)
{
    _bloqueTablas* temp = ptr->inicio;
    int ac = 0;

    if(temp == NULL)
    {
        return ac;
    }

    while(temp != NULL)
    {
        temp = temp->siguiente;
        ac++;
    }
    return ac;
}

_listaBloques* nuevaListaBloques()
{
    _listaBloques* ptr;

    ptr = (_listaBloques *)malloc(sizeof(_listaBloques));
    ptr->inicio = NULL;
    return ptr;
}

void insertarBloque(_listaBloques* ptr, int anterior, int siguiente, int cantTablas)
{
    _bloque* temp;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_bloque *)malloc(sizeof(_bloque));
        ptr->inicio->posAnterior = anterior;
        ptr->inicio->posSiguiente = siguiente;
        ptr->inicio->cantidadTablas = cantTablas;
        ptr->inicio->ptrListaBloqueTablas = NULL;
        ptr->inicio->siguiente = NULL;
    }
    else{
        temp = ptr->inicio;
        while(temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = (_bloque *)malloc(sizeof(_bloque));
        temp->siguiente->posAnterior = anterior;
        temp->siguiente->posSiguiente = siguiente;
        temp->siguiente->ptrListaBloqueTablas = NULL;
        temp->siguiente->cantidadTablas = cantTablas;
        temp->siguiente->siguiente = NULL;
    }
}

void listarBloques(_listaBloques* ptr)
{
    _bloque* temp = ptr->inicio;

    while(temp != NULL)
    {
        printf("%d %d %d \n", temp->posAnterior, temp->posSiguiente, temp->cantidadTablas);
        temp = temp->siguiente;
    }
}

/************************************************************************************/

//Aqui lo hice con la tabla normal que teniamos por que veo que si vamos a necesitar la
//lista en memoria entonces lo que queria hacer era meter esa tabla en un bloque y o que
//sobra meterlo en el siguiente y asi sucesivamente...
//void probar(_listaTabla* LT)
//{
//    _listaBloques* LEB;
//    _nodoTabla* nodoTemp = LT->inicio;
//
//    while(nodoTemp != NULL)
//    {
//
//        nodoTemp = nodoTemp->siguiente;
//    }
//}

/************************************************************************************/
//
//char* escribirEncabezadoTablas(char* cadena, _bloque* temp, int seek)
//{
//    memcpy(&(cadena[seek]), itoa(temp->posAnterior, &(cadena[seek]), 10), 2);
//    seek += 2;
//    memcpy(&(cadena[seek]), itoa(temp->posSiguiente, &(cadena[seek]), 10), 2);
//    seek += 2;
//    memcpy(&(cadena[seek]), itoa(temp->cantidadTablas, &(cadena[seek]), 10), 2);
//    seek += 2;
//
//    return cadena;
//}

#endif // BLOQUETABLAS_H
