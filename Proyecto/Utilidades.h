#ifndef UTILDADES_H
#define UTILIDADES_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE    1
#define FALSE   0

int compareTo(char* cadena1, char* cadena2);

int compareTo(char* cadena1, char* cadena2)
{
    int cont = 0;

    while(cadena2[cont] != NULL)
    {
        if(cadena1[cont] == cadena2[cont])
        {
            cont++;
        }
        else{
            return FALSE;
        }
    }
    return TRUE;
}

#endif // UTILDADES_H
