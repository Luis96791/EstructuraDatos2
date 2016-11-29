#ifndef INTERPRETE_H
#define INTERPRETE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utilidades.h"
#include "MenuLista.h"

char* leerDataFile(char* dataFile);
char* interpretarListaObjetos(char* dataFile);
void interpretarObjeto(char* dataFile, int pos);
int obtenerPosicionDeLectura(char* dataFile, char delimitador, int pos);
void leerObjetos(char* dataFile);
void interpretarItems(char* dataFile);
void interpretarAtributo(char** arreglo);
void obtenerAtributoInterpretado(char** arreglo, char** arreglo_atributos, int posAtributos, int posArreglo);
void pasarAtributosAListaMenu(_listaMenu* listaMenu, char** arreglo);


char* leerDataFile(char* dataFile)
{
    FILE* file;

    file = fopen("test.txt", "r");

    if(file == NULL)
    {
        printf("Error de lectura.\n");
    }
    else{
        fgets(dataFile, 1000, file);
    }

    fclose(file);

    return dataFile;
}

char* interpretarListaObjetos(char* dataFile)
{
    char* dataCopy = (char *)malloc(sizeof(char)*400);
    int cont = 0;

    while(dataFile[cont] != '}')
    {
        if(dataFile[cont] != '{')
        {
            dataCopy[cont-1] = dataFile[cont];
        }
        cont++;
    }
    dataCopy[cont-1] = '\0';

    return dataCopy;
}

void interpretarObjeto(char* dataFile, int pos)
{
    char* dataCopy = (char *)malloc(sizeof(char)*100);
    int cont = 0;

    while(dataFile[pos] != ']')
    {
        if(dataFile[pos] != '[')
        {
            dataCopy[cont-1] = dataFile[pos];
        }
        cont++;
        pos++;
    }
    dataCopy[cont-1] = '\0';
    interpretarItems(dataCopy);
}

int obtenerPosicionDeLectura(char* dataFile, char delimitador, int pos)
{
    while(dataFile[pos] != delimitador)
    {
        pos++;
    }
    return pos+1;
}

void leerObjetos(char* dataFile)
{
    int posLectura = 0;

    while(posLectura != strlen(dataFile))
    {
        interpretarObjeto(dataFile, posLectura);
        posLectura = obtenerPosicionDeLectura(dataFile, ']', posLectura);
    }
}

void interpretarItems(char* dataFile)
{
    char* dataCopy = (char *)malloc(sizeof(char)*50);
    char* ALMACEN_ITEMS[3];

    int contDataFile = 0;
    int contDataCopy = 0;

    while(dataFile[contDataFile] != ',')
    {
        dataCopy[contDataCopy] = dataFile[contDataFile];
        contDataFile++;
        contDataCopy++;
    }

    dataCopy[contDataCopy] = '\0';
    dataFile[contDataFile++] = '\0';
    contDataCopy = 0;
    ALMACEN_ITEMS[0] = dataCopy;
    dataCopy = (char *)malloc(sizeof(char)*50);

    while(dataFile[contDataFile] != ',')
    {
        dataCopy[contDataCopy] = dataFile[contDataFile];
        contDataFile++;
        contDataCopy++;
    }
    dataCopy[contDataCopy] = '\0';
    dataFile[contDataFile++] = '\0';
    contDataCopy = 0;
    ALMACEN_ITEMS[1] = dataCopy;
    dataCopy = (char *)malloc(sizeof(char)*50);

    while(dataFile[contDataFile] != '\0')
    {
        dataCopy[contDataCopy] = dataFile[contDataFile];
        contDataFile++;
        contDataCopy++;
    }
    dataCopy[contDataCopy] = '\0';
    ALMACEN_ITEMS[2] = dataCopy;

    interpretarAtributo(ALMACEN_ITEMS);
}

void interpretarAtributo(char** arreglo)
{
    _listaMenu* listaMenu;
    listaMenu = nuevaListaMenu();

    char* ALMACEN_ATRIBUTOS[6];
    char* ATRIBUTOS_OBTENIDOS;

    obtenerAtributoInterpretado(arreglo, ALMACEN_ATRIBUTOS, 0, 0);
    obtenerAtributoInterpretado(arreglo, ALMACEN_ATRIBUTOS, 2, 1);
    obtenerAtributoInterpretado(arreglo, ALMACEN_ATRIBUTOS, 4, 2);

    pasarAtributosAListaMenu(listaMenu, ALMACEN_ATRIBUTOS);

    listarNodosMenu(listaMenu);
}

void pasarAtributosAListaMenu(_listaMenu* listaMenu, char** arreglo)
{
    _nodoMenu* nodoMenu;

    nodoMenu = (_nodoMenu *)malloc(sizeof(_nodoMenu));

    if(compareTo(arreglo[0], "ID"))
    {
        nodoMenu->id = atoi(arreglo[1]);

        if(compareTo(arreglo[2], "Nombre"))
        {
            nodoMenu->titulo = arreglo[3];
            nodoMenu->grado = arreglo[5];
        }
        else{
            nodoMenu->titulo = arreglo[5];
            nodoMenu->grado = arreglo[3];
        }
    }
    else if(compareTo(arreglo[2], "ID"))
    {
        nodoMenu->id = atoi(arreglo[3]);

        if(compareTo(arreglo[0], "Nombre"))
        {
            nodoMenu->titulo = arreglo[1];
            nodoMenu->grado = arreglo[5];
        }
        else{
            nodoMenu->titulo = arreglo[5];
            nodoMenu->grado = arreglo[1];
        }
    }
    else if(compareTo(arreglo[4], "ID"))
    {
        nodoMenu->id = atoi(arreglo[5]);

        if(compareTo(arreglo[0], "Nombre"))
        {
            nodoMenu->titulo = arreglo[1];
            nodoMenu->grado = arreglo[3];
        }
        else{
            nodoMenu->titulo = arreglo[3];
            nodoMenu->grado = arreglo[1];
        }
    }
    nodoMenu->siguiente = NULL;

    agregarListaMenu(nodoMenu, listaMenu);
}

void obtenerAtributoInterpretado(char** arreglo, char** arreglo_atributos, int posAtributos, int posArreglo)
{
    char* itemTemporal = arreglo[posArreglo];
    char* dataCopy = (char *)malloc(sizeof(char)*20);
    int contDataCopy = 0;
    int contItemTemporal = 0;

    while(itemTemporal[contItemTemporal] != ':')
    {
        dataCopy[contDataCopy] = itemTemporal[contItemTemporal];
        contDataCopy++;
        contItemTemporal++;
    }
    dataCopy[contDataCopy] = '\0';
    //Aqui necesita eliminar dos caracteres la coma y las comillas del segundo atributo
    itemTemporal[contItemTemporal++] = '\0';
    itemTemporal[contItemTemporal++] = '\0';
    contDataCopy = 0;
    arreglo_atributos[posAtributos] = dataCopy;
    dataCopy = (char *)malloc(sizeof(char)*20);

    while(itemTemporal[contItemTemporal] != '\0')
    {
        dataCopy[contDataCopy] = itemTemporal[contItemTemporal];
        contDataCopy++;
        contItemTemporal++;
    }
    dataCopy[contDataCopy-1] = '\0';
    contDataCopy = 0;
    arreglo_atributos[posAtributos+1] = dataCopy;
}

#endif // INTERPRETE_H
