#ifndef BLOQUE_H
#define BLOQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BloquesTablas.h"

typedef struct Bloque _bloque;
typedef struct ListaBloques _listaBloques;


struct Bloque
{
    int bloqueAnterior;
    int bloqueSiguiente;
    int cantTablasEnBloque;
    _listaBloqueTablas* ptrListaBloqueTablas;
    _bloque* siguiente;
};

struct ListaBloques
{
    _bloque* inicio;
};

void agregarBloque();

void agregarBloque()
{

}

#endif // BLOQUE_H
