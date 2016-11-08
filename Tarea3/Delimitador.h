#ifndef DELIMITADOR_H
#define DELIMITADOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaObjeto.h"

void escribirEnData(char* data);

void escribirEnData(char* data)
{
    memcpy(&data, "MiCasa", strlen("MiCasa")+1);
    memcpy(&data, "-", 1);
    printf("%s", data);
}

#endif // DELIMITADOR_H
