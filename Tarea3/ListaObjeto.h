#ifndef LISTAOBJETO_H
#define LISTAOBJETO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Delimitador.h"

typedef struct Nodo _nodoPersona;
typedef struct Lista _listaPersona;

struct Nodo
{
    char* nombre;
    char* apellido;
    int edad;
    _nodoPersona* siguiente;
};

struct Lista
{
    _nodoPersona* inicio;
};

_listaPersona* newListaPersona();
void insertarPersonas(_listaPersona* ptr, char* nombre, char* apellido, int edad);
void listarPersonas(_listaPersona* ptr);
_listaPersona* RunLista();
int getSize(_listaPersona* ptr);
int escribirCadena(char* cadena, _nodoPersona* NP, int seek);


_listaPersona* newListaPersona()
{
    _listaPersona* ptr;

    ptr = (_listaPersona *)malloc(sizeof(_listaPersona));
    ptr->inicio = NULL;
    return ptr;
}

void insertarPersonas(_listaPersona* ptr, char* nombre, char* apellido, int edad)
{
    _nodoPersona *temp;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_nodoPersona* )malloc(sizeof(_nodoPersona));
        ptr->inicio->nombre = nombre;
        ptr->inicio->apellido = apellido;
        ptr->inicio->edad = edad;
        ptr->inicio->siguiente = NULL;
        return;
    }
    temp = ptr->inicio;

    while(temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = (_nodoPersona* )malloc(sizeof(_nodoPersona));
    temp->siguiente->nombre = nombre;
    temp->siguiente->apellido = apellido;
    temp->siguiente->edad = edad;
    temp->siguiente->siguiente = NULL;
}

void listarPersonas(_listaPersona* ptr)
{
    _nodoPersona* temp = ptr->inicio;

    while(temp != NULL)
    {
        printf("Nombre: %s Apellido: %s Edad: %d\n", temp->nombre, temp->apellido, temp->edad);
        temp = temp->siguiente;
    }
}

_listaPersona* RunLista()
{
    _listaPersona* LP;

    LP = newListaPersona();
    int opc, edad;
    char *nombre, *apellido;
    char* cadena = malloc(2000);
    char* cadena2 = malloc(2000);
    int seek = 0;
    _nodoPersona* temp;

    do
    {
        nombre = (char *)malloc(sizeof(char)*20);
        apellido = (char *)malloc(sizeof(char)*20);

        printf("1-. Agregar Persona\n");
        printf("2-. Listar Personas\n");
        printf("3-. Pasar a Data\n");
        printf("Escoja una Opcion: ");
        scanf("%d", &opc);

        if(opc == 1)
        {
            printf("Ingrese Nombre: ");
            scanf("%s", nombre);
            printf("Ingrese Apellido: ");
            scanf("%s", apellido);
            printf("Ingrese Edad: ");
            scanf("%d", &edad);

            insertarPersonas(LP, nombre, apellido, edad);
        }

        if(opc == 2)
        {
            listarPersonas(LP);
        }

        if(opc == 3)
        {
            temp = LP->inicio;
            while(temp != NULL)
            {
                seek += escribirCadena(cadena, temp, seek);
                temp = temp->siguiente;
            }
            printf("%s\n", cadena);
        }

    }while(opc != 0);

    free(nombre);
    free(apellido);
    return LP;
}

int getSize(_listaPersona* ptr)
{
    _nodoPersona* temp = ptr->inicio;
    int cont = 0;

    while(temp != NULL)
    {
        cont++;
        temp = temp->siguiente;
    }
    return cont;
}

int escribirCadena(char* cadena, _nodoPersona* NP, int seek)
{
    memcpy(&(cadena[seek]), NP->nombre, strlen(NP->nombre)+1);
    seek += strlen(NP->nombre)+1;
    memcpy(&(cadena[seek]), "-", 1);
    seek += 1;
    memcpy(&(cadena[seek]), NP->apellido, strlen(NP->apellido)+1);
    seek += strlen(NP->apellido)+1;
    memcpy(&(cadena[seek]), "-", 1);
    seek += 1;

    return seek;
}

#endif // LISTAOBJETO_H
