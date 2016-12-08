#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

/* -------------------- Funciones ---------------------- */

/**
    \brief Compara dos cadenas caracter por caracter
    \param cadena 1
    \param cadena 2
    \return Devuelve TRUE o FALSE
*/
int compareTo(char* cadena1, char* cadena2);
/**
    \brief Sirve para probar si el programa esta funcionando en un punto especifico
*/
void debug();
FILE* abrirArchivo(char* modo_apertura);
char* agregarACadena(char* cadena, char caracter);

/* -------------------- Funciones ---------------------- */

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

FILE* abrirArchivo(char* modo_apertura)
{
    FILE* file;

    file = fopen("BaseDatos.txt", modo_apertura);

    if(file == NULL)
    {
        printf("Error de lectura..!\n");
        return NULL;
    }
    return file;
}

char* agregarACadena(char* cadena, char caracter)
{
    int pos = 0;

    while( 1 )
    {
        if(cadena[pos] == '\0')
        {
            cadena[pos] = caracter;
            cadena[pos+1] = '\0';
            return cadena;
        }
        pos++;
    }
    return cadena;
}

#endif // UTILIDADES_H
