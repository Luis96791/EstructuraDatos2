#ifndef INTERPRETE_H
#define INTERPRETE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Opciones.h"

char *cadenaJson;
_nodoOpciones* nuevoNodo;

void interpretarArchivo(char* nombre_archivo);
void interpretarArreglo(char caracter);
void interpretarObjeto(char caracter);

void interpretarArchivo(char* nombre_archivo)
{
    FILE* menu = NULL;

    menu = fopen(nombre_archivo, "r");

    fscanf(menu, " %[^\n]", &cadenaJson);
    fgets(cadenaJson, NULL, menu);

    fclose(menu);
}

void interpretarArreglo(char caracter)
{
    if(caracter == '[')
    {
        nuevaOpcion();
    }
}

void interpretarObjeto(char caracter)
{
    if(caracter == '{')
    {
        nuevoNodo = NULL;
    }
}

void interpretarAtributo(char* cadena)
{

}

void interpretarComillas(char* cadena)
{

}

#endif // INTERPRETE_H
