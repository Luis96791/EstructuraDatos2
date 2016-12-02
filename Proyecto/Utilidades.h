#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE    1
#define FALSE   0

/**
    Compara dos cadenas caracter por caracter
    @param cadena 1
    @param cadena 2
    @return Devuelve TRUE o FALSE
*/
int compareTo(char* cadena1, char* cadena2);
void debug();

int compareTo(char* cadena1, char* cadena2)
{
    int cont = 0;

    while(cadena2[cont] != '\0')
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

void debug()
{
    printf("PROBANDO...!");
}

#endif // UTILIDADES_H
