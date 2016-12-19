#ifndef INTERPRETE_H
#define INTERPRETE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MenuLista.h"
#include "Utilidades.h"

/* -------------------- Funciones ---------------------- */

/**
    \brief Abre y lee el archivo json.txt y escribe su contenido en una cadena.
    \param dataFile = Cadena en donde se va a escribir el archivo.
    \param nombre_archivo = Nombre del archivo del cual se leerá la cadena.
    \return Cadena con el contenido del archivo.
*/
char* leerDataFile(char* dataFile, char* nombre_archivo);
/**
    \brief Hace una copia del dataFile en dataCopy y elimina su llave de inicio
    y al final.
    \param dataFile = Contenido del archivo
    \return dataCopy (items interpretados).
*/
char* interpretarListaItems(char* dataFile);
/**
    \brief Recibe una lista de items hace una copia de ella y elimina sus
    corchetes.
    \param items = Lista de Items.
    \param pos = posicion de lectua.
*/
void interpretarItem(char* items, int pos);
/**
    \brief Busca la posicion donde haya un delimitador(parametro) y devuelve esa posicion
    \param items = Lista de Items.
    \param delimitador = caracter hasta donde queremos que llegue la lectura.
    \param pos = Posicion de donde comienza la lectura.
    \return posicion hasta donde llegó la lectura.
*/
int obtenerPosicionDeLectura(char* items, char delimitador, int pos);
/**
    \brief Lee los items y los manda uno por uno a la funcion interpretarItem(char* items, int pos).
    \param items = Lista de Items.
*/
void leerItems(char* items);
/**
    \brief Interpreta el atributo mas su valor asociado y lo almacena en un arreglo.
    \param item = Item.
*/
void interpretarAtributosMasValor(char* item);
/**
    \brief Maneja las funciones y los arreglos que interpretan los atributosValor.
    \param almacen_items = Arreglo ALMACEN_ITEMS de 3 posiciones que lo manda de parametro a otra funcion.
*/
void manejoAtributosInterpretados(char** almacen_items);
/**
    \brief Obtiene los atributos y su valor asociado limpios de commillas (") y de dos puntos(:)
    y lo agrega de dos en dos al arreglo ALMACEN_ATRIBUTOS.
    En esta función tambien se inicializa la ListaMenu y desde aqui se muestra el menu en pantalla.
    \param almacen_items = ALMACEN_ITEMS arreglo de 3 posiciones
    \param almacen_atributos = ALMACEN_ATRIBUTOS arreglo de 6 posiciones
    \param posAlmacenAtributos = posicion en el arreglo ALMACEN_ATRIBUTOS
    \param posAlmacenItems = posicion en el arreglo ALMACEN_ITEMS
*/

void obtenerAtributoInterpretado(char** almacen_items, char** almacen_atributos, int posAlmacenAtributos, int posAlmacenItems);
/**
    \brief Recibe la listaMenu en donde se van a almacenar los valores impares de ALMACEN_ATRIBUTOS
    Agrega un nuevo nodoMenu a la listaMenu
    \param listaMenu = Lista Menu
    \param almacen_atributos = ALMACEN_ATRIBUTOS arreglo de 6 posiciones
*/
void agregarAtributosAListaMenu(_listaMenu* listaMenu, char** almacen_atributos);
/**
    \brief Llama las funciones necesarias para que la aplicacion funcione.
    \param dataFile = Espacio en memoria donde se almacenará los datos del archivo
    \param nombre_archivo = Nombre del archivo a leer.
*/
void cargarJson(char* dataFile, char* nombre_archivo);

/* -------------------- Funciones ---------------------- */

char* leerDataFile(char* dataFile, char* nombre_archivo)
{
    FILE* file;

    file = fopen(nombre_archivo, "r");

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

char* interpretarListaItems(char* dataFile)
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

void interpretarItem(char* items, int pos)
{
    char* itemsCopy = (char *)malloc(sizeof(char)*100);
    int cont = 0;

    while(items[pos] != ']')
    {
        if(items[pos] != '[')
        {
            itemsCopy[cont-1] = items[pos];
        }
        cont++;
        pos++;
    }
    itemsCopy[cont-1] = '\0';
    interpretarAtributosMasValor(itemsCopy);
}

int obtenerPosicionDeLectura(char* items, char delimitador, int pos)
{
    while(items[pos] != delimitador)
    {
        pos++;
    }
    return pos+1;
}

void leerItems(char* items)
{
    int posLectura = 0;

    while(posLectura != strlen(items))
    {
        interpretarItem(items, posLectura);
        posLectura = obtenerPosicionDeLectura(items, ']', posLectura);
    }
}

void interpretarAtributosMasValor(char* item)
{
    char* itemCopy = (char *)malloc(sizeof(char)*50);
    char* ALMACEN_ITEMS[3];

    int contItem = 0;
    int contItemCopy = 0;

    while(item[contItem] != ',')
    {
        itemCopy[contItemCopy] = item[contItem];
        contItem++;
        contItemCopy++;
    }

    itemCopy[contItemCopy] = '\0';
    item[contItem++] = '\0';
    contItemCopy = 0;
    ALMACEN_ITEMS[0] = itemCopy;
    itemCopy = (char *)malloc(sizeof(char)*50);

    while(item[contItem] != ',')
    {
        itemCopy[contItemCopy] = item[contItem];
        contItem++;
        contItemCopy++;
    }
    itemCopy[contItemCopy] = '\0';
    item[contItem++] = '\0';
    contItemCopy = 0;
    ALMACEN_ITEMS[1] = itemCopy;
    itemCopy = (char *)malloc(sizeof(char)*50);

    while(item[contItem] != '\0')
    {
        itemCopy[contItemCopy] = item[contItem];
        contItem++;
        contItemCopy++;
    }
    itemCopy[contItemCopy] = '\0';
    ALMACEN_ITEMS[2] = itemCopy;

    manejoAtributosInterpretados(ALMACEN_ITEMS);
}

void manejoAtributosInterpretados(char** almacen_items)
{
    _listaMenu* listaMenu;
    listaMenu = nuevaListaMenu();

    char* ALMACEN_ATRIBUTOS[6];

    obtenerAtributoInterpretado(almacen_items, ALMACEN_ATRIBUTOS, 0, 0);
    obtenerAtributoInterpretado(almacen_items, ALMACEN_ATRIBUTOS, 2, 1);
    obtenerAtributoInterpretado(almacen_items, ALMACEN_ATRIBUTOS, 4, 2);

    agregarAtributosAListaMenu(listaMenu, ALMACEN_ATRIBUTOS);

    mostrarMenuEnPantalla(listaMenu);
}

void agregarAtributosAListaMenu(_listaMenu* listaMenu, char** almacen_atributos)
{
    _nodoMenu* nodoMenu;

    nodoMenu = (_nodoMenu *)malloc(sizeof(_nodoMenu));

    if(compareTo(almacen_atributos[0], "ID"))
    {
        nodoMenu->id = atoi(almacen_atributos[1]);

        if(compareTo(almacen_atributos[2], "Titulo"))
        {
            nodoMenu->titulo = almacen_atributos[3];
            nodoMenu->grado = almacen_atributos[5];
        }
        else{
            nodoMenu->titulo = almacen_atributos[5];
            nodoMenu->grado = almacen_atributos[3];
        }
    }
    else if(compareTo(almacen_atributos[2], "ID"))
    {
        nodoMenu->id = atoi(almacen_atributos[3]);

        if(compareTo(almacen_atributos[0], "Titulo"))
        {
            nodoMenu->titulo = almacen_atributos[1];
            nodoMenu->grado = almacen_atributos[5];
        }
        else{
            nodoMenu->titulo = almacen_atributos[5];
            nodoMenu->grado = almacen_atributos[1];
        }
    }
    else if(compareTo(almacen_atributos[4], "ID"))
    {
        nodoMenu->id = atoi(almacen_atributos[5]);

        if(compareTo(almacen_atributos[0], "Titulo"))
        {
            nodoMenu->titulo = almacen_atributos[1];
            nodoMenu->grado = almacen_atributos[3];
        }
        else{
            nodoMenu->titulo = almacen_atributos[3];
            nodoMenu->grado = almacen_atributos[1];
        }
    }
    nodoMenu->siguiente = NULL;

    agregarListaMenu(nodoMenu, listaMenu);
}

void obtenerAtributoInterpretado(char** almacen_items, char** almacen_atributos, int posAlmacenAtributos, int posAlmacenItems)
{
    char* itemTemporal = almacen_items[posAlmacenItems];
    char* itemTemporalCopy = (char *)malloc(sizeof(char)*20);
    int contItemTemporalCopy = 0;
    int contItemTemporal = 0;

    while(itemTemporal[contItemTemporal] != ':')
    {
        itemTemporalCopy[contItemTemporalCopy] = itemTemporal[contItemTemporal];
        contItemTemporalCopy++;
        contItemTemporal++;
    }
    itemTemporalCopy[contItemTemporalCopy] = '\0';
    //Aqui necesita eliminar dos caracteres la coma y las comillas del segundo atributo
    itemTemporal[contItemTemporal++] = '\0';
    itemTemporal[contItemTemporal++] = '\0';
    contItemTemporalCopy = 0;
    almacen_atributos[posAlmacenAtributos] = itemTemporalCopy;
    itemTemporalCopy = (char *)malloc(sizeof(char)*20);

    while(itemTemporal[contItemTemporal] != '\0')
    {
        itemTemporalCopy[contItemTemporalCopy] = itemTemporal[contItemTemporal];
        contItemTemporalCopy++;
        contItemTemporal++;
    }
    itemTemporalCopy[contItemTemporalCopy-1] = '\0';
    contItemTemporalCopy = 0;
    almacen_atributos[posAlmacenAtributos+1] = itemTemporalCopy;
}

void cargarJson(char* dataFile, char* nombre_archivo)
{
    leerDataFile(dataFile, nombre_archivo);
    dataFile = interpretarListaItems(dataFile);
    leerItems(dataFile);
}

#endif // INTERPRETE_H
