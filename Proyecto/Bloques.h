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

    if(listaBloques->inicio == NULL)
    {
        agregarBloqueTabla(listaBloques, cantTablas);
        bloque = getBloqueTablasDisponble(listaBloques);
        agregarTabla(nombreTabla, bloque->ptrlistaTablas, pBC, pBR);
        guardarBloque(bloque,0);
        return;
    }

    bloque = getBloqueTablasDisponble(listaBloques);

    if(bloque == NULL)
    {
        agregarBloqueTabla(listaBloques, cantTablas);
        bloque = getBloqueTablasDisponble(listaBloques);
        agregarTabla(nombreTabla, bloque->ptrlistaTablas, pBC, pBR);
        guardarBloque(bloque,sizeLista(listaBloques)-1);
    }
    else{
        agregarTabla(nombreTabla, bloque->ptrlistaTablas, pBC, pBR);
        guardarBloque(bloque,sizeLista(listaBloques)-1);
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
    _bloque* bloque = getBloqueCamposDisponble(listaBloques);

    if(bloque == NULL)
    {
        bloque = getBloqueCamposDisponble(listaBloques);
        agregarCampo(bloque->ptrListaCampos, nombreCampo, tipoCampo);
        guardarBloque(bloque,sizeLista(listaBloques)-1);
    }
    else{
        agregarCampo(bloque->ptrListaCampos, nombreCampo, tipoCampo);
        guardarBloque(bloque,sizeLista(listaBloques)-1);
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

void guardarBloque(_bloque* bl, int puntero);

void guardarBloque(_bloque* bl, int puntero){
    FILE* fa = fopen("Bloques.data","wb+");
    if(fa==NULL){
        printf("El archivo no existe");
    }else{
        long moverPuntero = (long)(puntero*sizeof(_bloque));
        fseek(fa,moverPuntero,SEEK_SET);
     fwrite(&bl,sizeof(_bloque),1,fa);
    }
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
