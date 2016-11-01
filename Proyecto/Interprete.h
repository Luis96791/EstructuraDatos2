#ifndef INTERPRETE_H
#define INTERPRETE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

void leer();
char* agregarCaracter(char* cadena, char caracter);

void leer() {
	FILE *archivo;
	char caracter = 'x';
	char titulo[20];
	char id[5];
	char grado[5];
	archivo = fopen("file.txt", "r");
	int concatenar = 0;
	int elementos = 0;
	int secuencia = 0;
	int estoySO = 0;
	int posicion = 0;
	int acumulando = FALSE;
	if (archivo == NULL) {
		printf("\nError de apertura del archivo. \n\n");
	}
	else {
		//printf("\nEl contenido del archivo de prueba es \n\n");
		while (feof(archivo) == 0)
		{
			caracter = fgetc(archivo);
			if (caracter == ':') {
				//printf("Comenze a concatenar\n");
				concatenar = 1;
				secuencia++;
			}
			if (caracter == ',') {
				//printf("\nTermine de concatenar\n");
				concatenar = 0;
				posicion = 0;
			}
			if (caracter == ';') {
				elementos++;
			}
			if (caracter == '=') {
				estoySO = 1;
			}


			if (caracter != '"' && caracter != ':' && concatenar == 1 && caracter != ';') {
				if (caracter != '[' && caracter != ']') {
					if (caracter != '{' && caracter != '}') {
						printf("%c", caracter);
					}
				}
			}
		}
	}
	printf("\nNumero de elementos leidos: %d", elementos);
	fclose(archivo);
}

char* agregarCaracter(char* cadena, char caracter)
{
    int cont = 0;
    while( TRUE )
    {
        if(cadena[cont] == '\0')
        {
            cadena[cont] = caracter;
            return cadena;
        }
        cont++;
    }
    return cadena;
}

#endif // INTERPRETE_H
