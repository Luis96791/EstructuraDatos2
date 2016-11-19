#ifndef BLOQUESTABLAS_H
#define BLOQUESTABLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BloqueTablas _bloqueTablas;
typedef struct ListaBloqueTablas _listaBloqueTablas;

struct BloqueTablas
{
    char* nombreTabla;
    int primerBloqueCampos;
    int primerBloqueRegistros;
    _bloqueTablas* siguiente;
};

struct ListaBloqueTablas
{
    _bloqueTablas* inicio;
};

void agregarTablaBloque(char* nombreTabla, _listaBloqueTablas* listaBloqueTablas);

void agregarTablaBloque(char* nombreTabla, _listaBloqueTablas* listaBloqueTablas)
{

}
#endif // BLOQUESTABLAS_H
