#define TRUE    1
#define FALSE   0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MenuLista.h"
#include "Interprete.h"

int main()
{
    system("color A");
    char* dataFile = (char *)malloc(sizeof(char)*1000);

    leerDataFile(dataFile);
    dataFile = interpretarListaObjetos(dataFile);
    leerObjetos(dataFile);

    return 0;
}
