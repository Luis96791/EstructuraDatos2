#ifndef BLOQUETABLAS_H
#define BLOQUETABLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"
#include "BloqueCampos.h"
#include "BloqueRegistros.h"
#include "Utilidades.h"

#define PUNTO_COMA  59

typedef struct BloqueTablas _bloqueTablas;
typedef struct ListaBloqueTablas _listaBloqueTablas;

struct BloqueTablas
{
    int bloque_anterior;
    int bloque_siguiente;
    int cantidad_tablas;
    _bloqueTablas* siguiente;
    _listaTablas* listaTablas;
};

struct ListaBloqueTablas
{
    _bloqueTablas* inicio;
};

/**
    \brief Crea un nuevo espacio en memoria para una lista de bloqueTablas.
    \return Devuelve una lista de bloqueTablas.
*/
_listaBloqueTablas* nuevaListaBloqueTablas();
/**
    \brief Crea un nuevo espacio en memoria para un bloqueTablas
    \param Apuntador en memoria al bloqueTablas anterior
    \param Apuntador en memoria al bloqueTablas siguiente
    \param Cantidad de tablas que soporta el bloque
    \param Lista de bloques de tablas
    \param Una instancia de la ultima tabla creada para asignarla a la lista de tablas del ultimo bloque
*/
void nuevoBloqueTablas(int bloque_anterior, int bloque_siguiente, int cantidad_tablas, _listaBloqueTablas* listaBloqueTablas, _tabla* tabla);
/**
    \brief Agraga un bloque creado previamente a la lista de bloque de tablas
    \param Lista de bloque de Tablas
    \param bloque de tablas que se va a agregar a la lista de bloqueTablas
    \param Una instancia de la ultima tabla creada para asignarla a la lista de tablas del ultimo bloque
*/
void agregarNuevoBloqueTablasLista(_listaBloqueTablas* listaBloqueTablas, _bloqueTablas* bloqueTablas, _tabla* tabla);
/**
    \brief Agrega una tabla a un bloque existente pero que la cantidad de tablas es menor al limite que soporta
    \param bloque Tablas que es el bloque en donde se agregara la tabla
    \param La tabla que se agregara a la lista de tablas del bloque
*/
void agregarTablaEnBloqueExistente(_bloqueTablas* bloqueTablas, _tabla* tabla);
/**
    \brief Muestra la lista de bloque de tablas e imprime tambien la lista de tablas que contiene el bloque
    \param Lista de Bloque de Tablas que se desea imprimir
*/
void listarBloqueTablas(_listaBloqueTablas* listaBloqueTablas);
/**
    \brief A partir de un bloque especifico cuenta la cantidad de tablas que hay en el bloque
    \param Bloque de Tablas del que se quiere obtener la cantidad de tablas
    \return Cantidad de tablas en el bloqueTablas
*/
int getCantidadDeTablasEnBloque(_bloqueTablas* bloqueTablas);
/**
    \brief Itera en la lista y obtiene el ultimo bloqueTablas de la lista
    \param Lista de bloques de tablas
    \return Ultimo bloque de tablas
*/
_bloqueTablas* getUltimoBloqueTablas(_listaBloqueTablas* listaBloqueTablas);
/**
    \brief Valida los diferentes escenarios de la lista de bloques de tablas y llama las funciones necesarias
    para agregar un nuevo bloque a la lista
    \param Tabla a agregar en la lista de bloqueTablas.
    \param Lista de bloque de tablas en donde se va a agregar la nueva tabla
    \param Puntero al bloque de tablas antrior
    \param Puntero al bloque de tablas siguiente
    \param Cantidad de tablas que soporta el bloque
*/

void escribirEncabezadoBloqueTablasEnArchivo(_bloqueTablas* bloqueTablas);
void escribirTablaEnArchivo(_tabla* tabla);
char* leerArchivo();

_listaBloqueTablas* nuevaListaBloqueTablas()
{
    _listaBloqueTablas* listaBloqueTablas;

    listaBloqueTablas = (_listaBloqueTablas *)malloc(sizeof(_listaBloqueTablas));
    listaBloqueTablas->inicio = NULL;
    return listaBloqueTablas;
}

void nuevoBloqueTablas(int bloque_anterior, int bloque_siguiente, int cantidad_tablas, _listaBloqueTablas* listaBloqueTablas, _tabla* tabla)
{
    _bloqueTablas* bloqueTablas;

    bloqueTablas = (_bloqueTablas *)malloc(sizeof(_bloqueTablas));
    bloqueTablas->bloque_anterior = bloque_anterior;
    bloqueTablas->bloque_siguiente = bloque_siguiente;
    bloqueTablas->cantidad_tablas = cantidad_tablas;
    bloqueTablas->listaTablas = nuevaListaTablas();
    bloqueTablas->siguiente = NULL;

    agregarNuevoBloqueTablasLista(listaBloqueTablas, bloqueTablas, tabla);
}

void agregarNuevoBloqueTablasLista(_listaBloqueTablas* listaBloqueTablas, _bloqueTablas* bloqueTablas, _tabla* tabla)
{
    _bloqueTablas* temporal;

    if(listaBloqueTablas->inicio == NULL)
    {
        listaBloqueTablas->inicio = bloqueTablas;
        agregarTabla(tabla->nombreTabla, bloqueTablas->listaTablas, tabla->primerBloqueCampos, tabla->primerBloqueRegistros);
        return;
    }
    temporal = listaBloqueTablas->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = bloqueTablas;
    agregarTabla(tabla->nombreTabla, bloqueTablas->listaTablas, tabla->primerBloqueCampos, tabla->primerBloqueRegistros);
}

void agregarTablaEnBloqueExistente(_bloqueTablas* bloqueTablas, _tabla* tabla)
{
    agregarTabla(tabla->nombreTabla, bloqueTablas->listaTablas, tabla->primerBloqueCampos, tabla->primerBloqueRegistros);
}

void listarBloqueTablas(_listaBloqueTablas* listaBloqueTablas)
{
    _bloqueTablas* temporal = listaBloqueTablas->inicio;

    while(temporal != NULL)
    {
        printf("%d %d %d \n", temporal->bloque_anterior, temporal->bloque_siguiente, temporal->cantidad_tablas);
        listarTablas(temporal->listaTablas);
        temporal = temporal->siguiente;
    }
}

_bloqueTablas* getUltimoBloqueTablas(_listaBloqueTablas* listaBloqueTablas)
{
    _bloqueTablas* temporal = listaBloqueTablas->inicio;

    while( 1 )
    {
        if(temporal->siguiente == NULL)
            return temporal;
        else
            temporal = temporal->siguiente;
    }
    return NULL;
}

int getCantidadDeTablasEnBloque(_bloqueTablas* bloqueTablas)
{
    int contador = 0;
    _tabla* temporal = bloqueTablas->listaTablas->inicio;

    if(temporal == NULL)
        return contador;

    while(temporal != NULL)
    {
        temporal = temporal->siguiente;
        contador++;
    }

    return contador;
}

void agregarTablaEnBloqueTablas(_tabla* tabla, _listaBloqueTablas* listaBloqueTablas, int bloque_anterior, int bloque_siguiente, int cantidad_tablas)
{

    if(listaBloqueTablas->inicio == NULL)
    {
        nuevoBloqueTablas(bloque_anterior, bloque_siguiente, cantidad_tablas, listaBloqueTablas, tabla);
//        escribirEncabezadoBloqueTablasEnArchivo(listaBloqueTablas->inicio);
        return;
    }

     _bloqueTablas* ultimoBloqueListaTablas = getUltimoBloqueTablas(listaBloqueTablas);

    if(getCantidadDeTablasEnBloque(ultimoBloqueListaTablas) < ultimoBloqueListaTablas->cantidad_tablas)
    {
        agregarTablaEnBloqueExistente(ultimoBloqueListaTablas, tabla);
    }
    else{
        nuevoBloqueTablas(bloque_anterior, bloque_siguiente, cantidad_tablas, listaBloqueTablas, tabla);
//        escribirEncabezadoBloqueTablasEnArchivo(ultimoBloqueListaTablas);
    }
}

char* bloqueToChar(_bloqueTablas* bloqueTabla){
    char destino[1000] = "";
    char numero[12];
    itoa(0,numero,10);
    strcat(destino,numero);
    strcat(destino,",");
    itoa(bloqueTabla->bloque_anterior,numero,10);
    strcat(destino,numero);
    strcat(destino,",");
    itoa(bloqueTabla->bloque_siguiente,numero,10);
    strcat(destino,numero);
    strcat(destino,",");
    itoa(bloqueTabla->cantidad_tablas,numero,10);
    strcat(destino,numero);
    if(bloqueTabla->listaTablas!=NULL){
        _tabla* tab = bloqueTabla->listaTablas->inicio;
        while(tab!=NULL){
            strcat(destino,",");
            strcat(destino,tab->nombreTabla);
            strcat(destino,",");
            itoa(tab->primerBloqueCampos,numero,10);
            strcat(destino,numero);
            strcat(destino,",");
            itoa(tab->primerBloqueRegistros,numero,10);
            strcat(destino,numero);
            tab = tab->siguiente;
        }
    }
    strcat(destino,";");
    return destino;
}

void escribir(_listaBloqueTablas* listaBloqueTablas,int modo,int posicion){
    FILE* fr = fopen("Data.txt","r+");
    int comienzoEscritura = 0;
    if(modo==1){
        comienzoEscritura = sizeLista(listaBloqueTablas)-1;
    }else{
       comienzoEscritura = posicion;
    }
    fseek(fr,(long)(comienzoEscritura*2000),SEEK_SET);
    fprintf(fr,"%s",bloqueToChar(getUltimoBloqueTablas(listaBloqueTablas)));
    //printf(bloqueToChar(getUltimoBloqueTablas(listaBloqueTablas)));
    fclose(fr);
}

char* leerDataTabla(FILE* fr, int pos){
    char* data = (char *)malloc(sizeof(char)*2000);
    if(fr==NULL){
        printf("No existe!!\n");
    }else{
        fseek(fr,(long)(pos*2000),SEEK_SET);
        fgets(data, 2000, fr);
    }
    return data;
}

void cargarTablas(_listaBloqueTablas* listaBloqueTablas, _listaTablas* listaTablas){
    FILE* fr = fopen("Data.txt","r");
    int posicionFile = 0;
    char* data = (char *)malloc(sizeof(char)*2000);
    while(!feof(fr)){
        data = leerDataTabla(fr,posicionFile);
        //printf(data);
        interpretarData(listaBloqueTablas,listaTablas,data);
        posicionFile++;
    }
}

void interpretarData(_listaBloqueTablas* listaBloqueTablas, _listaTablas* listaTablas, char* dataFile){
    int cont = 0;
    int del = 0;
    int tamano = 0;
    while(dataFile[cont] != ';')
    {
        del = buscarDelimitador(dataFile, cont);
        tamano = del - cont;
        printf("delimitador: %d - contador: %d  - tamanio: %d\n" , del, cont, tamano);
        cont++;
    }
}

int buscarDelimitador(char* dataFile, int cont){
    int start = cont;
    while(dataFile[start] != ';')
    {
        if(dataFile[start] == ',')
        {
            return start;
        }
        start++;
    }
    return start;
}

int sizeLista(_listaBloqueTablas* listaBloqueTablas){
    if(listaBloqueTablas->inicio==NULL){
        return 0;
    }else{
        _bloqueTablas* temporal= listaBloqueTablas->inicio;
        int tamanio = 0;
        while(temporal!=NULL){
            tamanio++;
            temporal = temporal->siguiente;
        }
        return tamanio;
    }
    return -1;
}

#endif // BLOQUETABLAS_H
