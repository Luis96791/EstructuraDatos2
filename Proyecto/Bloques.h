#ifndef BLOQUE_H
#define BLOQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"
#include "Campos.h"

typedef struct Bloque _bloque;
typedef struct ListaBloques _listaBloques;


struct Bloque
{
    int bloqueAnterior;
    int bloqueSiguiente;
    int cantTablasEnBloque;
    int cantCamposEnBloque;
    int cantRegistrosEnBloque;
    _listaTablas* ptrlistaTablas;
    _listaCampos* ptrListaCampos;
    _bloque* siguiente;
};

struct ListaBloques
{
    _bloque* inicio;
};

/* -------------------- Funciones para manejar los bloques ---------------------- */

/**
    Crea un nuevo espacio en memoria para almacenar bloques en una lista
    @return Retorna una lista de bloques.
*/
_listaBloques* nuevaListaBloques();
/**
    Agreaga un nuevo bloque al final de la lista de bloques.
    @param Bloque.
    @param Lista de Bloques.
*/
void agregarBloqueLista(_bloque* bloque, _listaBloques* listaBloques);
/**
   Muestra en pantalla los bloques que hay en la lista de bloques.
   @param Lista de Bloques.
*/
void listarBloques(_listaBloques* listaBloques);

/* -------------------- Funciones para manejar los bloques ---------------------- */

/* ------------------- Funciones para manejar tablas en Bloques ------------------- */
/**
    Agrega una tabla a un bloque especifico, si no hay espacio en un bloque crea uno nuevo y agrega
    la tabla.
    @param Nombre de tabla a agregar.
    @param Lista de Bloques.
    @param Primer Bloque de Campos.
    @param Primer Bloque de Registros.
    @param Cantidad de Tablas que soporta el bloque.
*/
void agregarTabla_ABloque(char* nombreTabla, _listaBloques* listaBloques, int pBC, int pBR, int cantTablas);
/**
    Crea el espacio de memoria para agregar un nuevo bloque a la lista de bloques.
    @param Lista de Bloques.
    @param Cantidad de tablas que soporta el bloque.
*/
void agregarBloqueTabla(_listaBloques* listaBloques, int cantTablas);
/**
    Busca un bloque que aun no este ocupado por completo
    @param Lista de Bloques.
    @return Retorna un bloque.
*/
_bloque* getBloqueTablasDisponble(_listaBloques* listaBloques);
/**
    @return Retorna la cantidad de tablas que hay en un bloque.
    @param Bloque.
*/
int cantidadTablasPorBloque(_bloque* bloque);

/* ------------------- Funciones para manejar tablas en Bloques ------------------- */

/* ------------------- Funciones para manejar campos en Bloques ------------------- */
/**
    Agrega un campo a un bloque ya creado.
    @param Lista de Bloques.
    @param Cantidad de Campos que soporta el bloque.
*/
void agregarBloqueCampo(_listaBloques* listaBloques, int cantCampos);
/**
    Obtiene la cantidad de campos que hay en un bloque.
    @param recibe un bloque e itera en su lista de Campos.
    @return Retorna la cantidad de Campos que hay en el bloque.
*/
int cantidadCamposPorBloque(_bloque* bloque);
/**
    Agrega un campo al final de la lista de campos de un bloque
    especifio.
    @param Nombre del Campo.
    @param Tipo de Campo.
    @param Lista de Bloques.
    @param Cantidad de campos que soporta el bloque.
*/
void agregarCampo_ABloque(char* nombreCampo, char* tipoCampo, _listaBloques* listaBloques, int cantCampos);
/**
    Obtiene el ultimo bloque de campos (para esto es necesario asegurarse de llamar la función
    agregarBloqueCampo(_listaBloques* listaBloques, int cantCampos) antes de usar esta función).
    @param Lista de Bloques.
    @return devuelve un bloque.
*/
_bloque* getBloqueCamposDisponble(_listaBloques* listaBloques);

/* ------------------- Funciones para manejar campos en Bloques ------------------- */

_listaBloques* nuevaListaBloques()
{
    _listaBloques* listaBloques;

    listaBloques = (_listaBloques* )malloc(sizeof(_listaBloques));
    listaBloques->inicio = NULL;

    return listaBloques;
}

void agregarBloqueLista(_bloque* bloque, _listaBloques* listaBloques)
{
    _bloque* temporal;

    if(listaBloques->inicio == NULL)
    {
        listaBloques->inicio = bloque;
        return;
    }

    temporal = listaBloques->inicio;

    while(temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = bloque;
}

void listarBloques(_listaBloques* listaBloques)
{
    _bloque* temporal = listaBloques->inicio;

    while(temporal != NULL)
    {
        if(temporal->ptrlistaTablas != NULL)
        {
            printf("%d, %d, %d\n", temporal->bloqueAnterior, temporal->bloqueSiguiente, temporal->cantTablasEnBloque);
            listarTablas(temporal->ptrlistaTablas);
        }

        if(temporal->ptrListaCampos != NULL)
        {
            printf("%d, %d, %d\n", temporal->bloqueAnterior, temporal->bloqueSiguiente, temporal->cantCamposEnBloque);
            listarCampos(temporal->ptrListaCampos);
        }
        temporal = temporal->siguiente;
    }
}

/*--------------- Funciones para las tablas en el bloque ------------------*/

void agregarBloqueTabla(_listaBloques* listaBloques, int cantTablas)
{
    _bloque* bloque;

    bloque = (_bloque *)malloc(sizeof(_bloque));
    bloque->bloqueAnterior = -1;
    bloque->bloqueSiguiente = -1;
    bloque->cantTablasEnBloque = cantTablas;
    bloque->ptrlistaTablas = nuevaListaTablas();
    bloque->ptrListaCampos = NULL;
    bloque->siguiente = NULL;

    agregarBloqueLista(bloque, listaBloques);
}

void agregarTabla_ABloque(char* nombreTabla, _listaBloques* listaBloques, int pBC, int pBR, int cantTablas)
{
    _bloque* bloque;
    int posicion = 0;
    if(listaBloques->inicio == NULL)
    {
        agregarBloqueTabla(listaBloques, cantTablas);
        bloque = getBloqueTablasDisponble(listaBloques);
        agregarTabla(nombreTabla, bloque->ptrlistaTablas, pBC, pBR);
        guardarUltimoBloque(listaBloques,0,0);
        return;
    }

    bloque = getBloqueTablasDisponble(listaBloques);

    if(bloque == NULL)
    {
        agregarBloqueTabla(listaBloques, cantTablas);
        bloque = getBloqueTablasDisponble(listaBloques);
        agregarTabla(nombreTabla, bloque->ptrlistaTablas, pBC, pBR);
        posicion = sizeLista(listaBloques)-1;
        printf("Entrada 1 %d\n", posicion);
        guardarUltimoBloque(listaBloques,posicion,0);
    }
    else{
        agregarTabla(nombreTabla, bloque->ptrlistaTablas, pBC, pBR);
        posicion = sizeLista(listaBloques)-1;
        printf("Entrada 2 %d\n", posicion);
        guardarUltimoBloque(listaBloques,posicion,0);
    }
}

int cantidadTablasPorBloque(_bloque* bloque)
{
    _tabla* tabla = bloque->ptrlistaTablas->inicio;
    int contador = 0;

    if(bloque->ptrlistaTablas->inicio == NULL)
    {
        return contador;
    }
    while(tabla != NULL)
    {
        contador++;
        tabla = tabla->siguiente;
    }
    return contador;
}

_bloque* getBloqueTablasDisponble(_listaBloques* listaBloques)
{
    _bloque* temporal = listaBloques->inicio;

    if(temporal == NULL)
    {
        return NULL;
    }

    while(temporal != NULL)
    {
        if(temporal->ptrlistaTablas != NULL)
        {
            if(temporal->cantTablasEnBloque > cantidadTablasPorBloque(temporal))
            {
                return temporal;
            }
        }
        temporal = temporal->siguiente;
    }
    return NULL;
}

/*--------------- Funciones para las tablas en el bloque ------------------*/

/*--------------- Funciones para los campos en el bloque ------------------*/

void agregarBloqueCampo(_listaBloques* listaBloques, int cantCampos)
{
    _bloque* bloque;

    bloque = (_bloque *)malloc(sizeof(_bloque));
    bloque->bloqueAnterior = -1;
    bloque->bloqueSiguiente = -1;
    bloque->cantCamposEnBloque = cantCampos;
    bloque->ptrlistaTablas = NULL;
    bloque->ptrListaCampos = (_listaCampos *)malloc(sizeof(_listaCampos));
    bloque->ptrListaCampos = nuevaListaCampos();
    bloque->siguiente = NULL;

    agregarBloqueLista(bloque, listaBloques);
}

void agregarCampo_ABloque(char* nombreCampo, char* tipoCampo, _listaBloques* listaBloques, int cantCampos)
{
    int posicion = 0;
    _bloque* bloque = getBloqueCamposDisponble(listaBloques);
    posicion = sizeLista()-1;
    printf("Mul %d\n", posicion);
    if(bloque == NULL)
    {
        //printf("Cdis");
        bloque = getBloqueCamposDisponble(listaBloques);
        //printf("add");
        agregarCampo(bloque->ptrListaCampos, nombreCampo, tipoCampo);
        //printf("file");
        guardarUltimoBloque(listaBloques,posicion,1);
    }else{
        printf("add1");
        agregarCampo(bloque->ptrListaCampos, nombreCampo, tipoCampo);
        printf("file1");
        guardarUltimoBloque(listaBloques,posicion,1);
    }
}

int cantidadCamposPorBloque(_bloque* bloque)
{
    _campo* campo = bloque->ptrListaCampos->inicio;
    int contador = 0;

    if(campo == NULL)
    {
        return contador;
    }
    while(campo != NULL)
    {
        contador++;
        campo = campo->siguiente;
    }
    return contador;
}

_bloque* getBloqueCamposDisponble(_listaBloques* listaBloques)
{
    _bloque* temporal = listaBloques->inicio;

    if(temporal == NULL)
    {
        return NULL;
    }

    while( 1 )
    {
        if(temporal->siguiente == NULL)
        {
            return temporal;
        }
        else
            temporal = temporal->siguiente;
    }
    return NULL;
}


/*--------------- Funciones para los campos en el bloque ------------------*/
char* bloqueAChar(_listaBloques* lB,int tipo);
void guardarUltimoBloque(_listaBloques* lB, int posicion, int tipo);

char* bloqueAChar(_listaBloques* lB,int tipo){
    char destino[1000] = "";
    char numero[10];
    _bloque* tmp = lB->inicio;
    while(tmp->siguiente!=NULL){
        tmp = tmp->siguiente;
    }
    _tabla* tabla;
    _campo* campo;
    itoa(tipo,numero,10);
    strcat(destino,numero);
    strcat(destino,",");
    itoa(tmp->bloqueAnterior,numero,10);
    strcat(destino,numero);
    strcat(destino,",");
    itoa(tmp->bloqueSiguiente,numero,10);
    strcat(destino,numero);
    strcat(destino,",");
    itoa(tmp->cantTablasEnBloque,numero,10);
    strcat(destino,numero);
    if(tmp->ptrlistaTablas==NULL){
        campo = tmp->ptrListaCampos->inicio;
        while(campo!=NULL){
            strcat(destino,",");
            strcat(destino,campo->nombre_campo);
            strcat(destino,",");
            strcat(destino,campo->tipo_campo);
            campo = campo->siguiente;
        }
    }else if(tmp->ptrListaCampos==NULL){
        tabla = tmp->ptrlistaTablas->inicio;
        while(tabla!=NULL){
            strcat(destino,",");
            strcat(destino,tabla->nombreTabla);
            itoa(tabla->primerBloqueCampos,numero,10);
            strcat(destino,",");
            strcat(destino,numero);
            itoa(tabla->primerBloqueRegistros,numero,10);
            strcat(destino,",");
            strcat(destino,numero);
            tabla = tabla->siguiente;
        }
    }
    strcat(destino,";");
    return destino;
}

void guardarUltimoBloque(_listaBloques* lB, int posicion, int tipo){
    FILE* fa = fopen("Bloques.data","r+");
    long moverPuntero = (long)(posicion*1000);
    fseek(fa,moverPuntero,SEEK_SET);
    char cadena[1000];
    fprintf(fa,"%s",bloqueAChar(lB,tipo));
    fclose(fa);
}

int sizeLista(_listaBloques* lB){
    if(lB->inicio==NULL){
        return 0;
    }else{
        _bloque* temporal = lB->inicio;
        int tamanio = 0;
        while(temporal!=NULL){
            tamanio++;
            temporal = temporal->siguiente;
        }
        return tamanio;
    }
    return -1;
}



#endif // BLOQUE_H
