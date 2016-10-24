#ifndef TABLAS_H
#define TABLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

struct Tabla
{
    int id_tabla;
    char* nombre_tabla;
    struct Tabla* siguiente;
};
typedef struct Tabla _tabla;

int isVacioTabla(_tabla *ptr)
{
    if(ptr == NULL)
        return TRUE;

    return FALSE;
}

_tabla* insertar(_tabla* ptr, char* nombre_tabla, int id)
{
    _tabla *newTabla, *temporal;

    newTabla = (_tabla *) malloc(sizeof(_tabla));

    if(newTabla != NULL)
    {
        newTabla->id_tabla = id;
        newTabla->nombre_tabla = nombre_tabla;

        if(isVacioTabla(ptr))
        {
            ptr = newTabla;
            printf("entrando\n");
        }
        else{
            temporal = ptr;

            while(temporal->siguiente != NULL)
            {
                temporal = temporal->siguiente;
            }
            temporal->siguiente = newTabla;
//        }
    }
    printf("entrando5\n");
}

void listar(_tabla* inicio)
{
    _tabla* temporal = inicio;

    while(temporal != NULL)
    {
        printf("%d %s\n", temporal->id_tabla, temporal->nombre_tabla);
        temporal = temporal->siguiente;
    }
}

#endif // TABLAS_H
