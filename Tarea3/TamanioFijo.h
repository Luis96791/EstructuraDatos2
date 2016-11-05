#ifndef TAMANIOFIJO_H
#define TAMANIOFIJO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaObjeto.h"

char* escribirData(char* cadena, _nodoPersona* NP, int nRegistro, int tamanio);
void leerData(char* cadena, _nodoPersona* NP, int nRegistro, int tamanio);

char* escribirData(char* cadena, _nodoPersona* NP, int nRegistro, int tamanio)
{
    char* pasarCadena = (char*)malloc(tamanio);
    int posLocal = 0;
    memcpy(&(pasarCadena[posLocal]), NP->nombre, 20);
    posLocal += 20;
    memcpy(&(pasarCadena[posLocal]), NP->apellido, 20);
    posLocal += 20;
    memcpy(&(pasarCadena[posLocal]), (char*)NP->edad, 4);
    posLocal += 4;

    int posCadena = nRegistro * tamanio;
    memcpy(&(cadena[posCadena]), pasarCadena, tamanio);

    free(pasarCadena);
    return cadena;
}

void leerData(char* cadena, _nodoPersona* NP, int nRegistro, int tamanio)
{
    int posCadena = nRegistro*tamanio;
    char* pasarCadena = &(cadena[posCadena]);

    int posLocal = 0;
    memcpy(NP->nombre, &(pasarCadena[posLocal]), 20);
    posLocal += 20;
    memcpy(NP->apellido, &(pasarCadena[posLocal]), 20);
    posLocal += 20;
    memcpy((int)NP->edad, &(pasarCadena[posLocal]), 4);
    posLocal += 4;
}

#endif // TAMANIOFIJO_H
