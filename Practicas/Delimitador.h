#ifndef DELIMITADOR_H
#define DELIMITADOR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef struct  Registro _registros;
typedef struct ListaRegistros _listaRegistros;

struct Registro
{
    int id;
    char* nombre;
    _registros* siguiente;
};

struct ListaRegistros
{
    _registros* inicio;
};

_listaRegistros* nuevaListaRegistros();
_registros* insertarRegistros(_listaRegistros* ptr, int id, char* nombre);
void listarRegistros(_listaRegistros* ptr);
char* llenarCadena(char* cadena);
char* agregarCaracter(char* cadena, char caracter);
_listaRegistros* leerArchivo();

_listaRegistros* nuevaListaRegistros()
{
    _listaRegistros* ptr;

    ptr = (_listaRegistros *)malloc(sizeof(_listaRegistros));
    ptr->inicio = NULL;
    return ptr;
}

_registros* insertarRegistros(_listaRegistros* ptr, int id, char* nombre)
{
    _registros *temp;

    if(ptr->inicio == NULL)
    {
        ptr->inicio = (_registros *)malloc(sizeof(_registros));
        ptr->inicio->id = id;
        ptr->inicio->nombre = nombre;
        ptr->inicio->siguiente = NULL;
        return ptr->inicio;
    }
    temp = ptr->inicio;

    while(temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = (_registros *)malloc(sizeof(_registros));
    temp->siguiente->id = id;
    temp->siguiente->nombre = nombre;
    temp->siguiente->siguiente = NULL;
    return temp->siguiente;
}

void listarRegistros(_listaRegistros* ptr)
{
    _registros* temp = ptr->inicio;

    while(temp != NULL)
    {
        printf("ID: %d Nombre: %s\n", temp->id, temp->nombre);
        temp = temp->siguiente;
    }
}

_listaRegistros* leerArchivo()
{
    FILE* file;

    _listaRegistros* LR;

    char caracter = ' ';
    char palabrasReservadas[50];
    char cadena[50];
    char* pasoCadena = NULL;
    int isDato = FALSE;
    int ptrInt;

    llenarCadena(palabrasReservadas);
    llenarCadena(cadena);

    file = fopen("archivo.txt", "r");

    if (file == NULL) {
		printf("\nError de apertura del archivo. \n\n");
	}
	else{
        while(!feof(file))
        {
            caracter = fgetc(file);

            agregarCaracter(cadena, caracter);

            if(strcmp(cadena, "{") == 0)
            {
                LR = nuevaListaRegistros();
                llenarCadena(cadena);
            }

            if(strcmp(cadena, "[ID:\"")== 0)
            {
                isDato = TRUE;
                llenarCadena(cadena);
            }

            if(isDato)
            {
                while(!feof(file))
                {
                    caracter = fgetc(file);

                    if(caracter != '\"')
                    {
                        agregarCaracter(cadena, caracter);
                    }
                    else{
                        isDato = FALSE;
                        ptrInt = atoi(cadena);
                        llenarCadena(cadena);
                        break;
                    }
                }
            }

            if(strcmp(cadena,",Nombre:\"")==0)
            {
                isDato = TRUE;
                llenarCadena(cadena);
            }

            if(isDato)
            {
                while(!feof(file))
                {
                    caracter = fgetc(file);

                    if(caracter != '\"')
                    {
                        agregarCaracter(cadena, caracter);
                    }
                    else{
                        isDato = FALSE;
                        pasoCadena = cadena;

                        insertarRegistros(LR, ptrInt, cadena);

                        llenarCadena(cadena);
                        break;
                    }
                }
            }

            if(strcmp(cadena, "\"]") == 0)
            {
                llenarCadena(cadena);
            }
        }
	}
	fclose(file);
	return LR;
}

char* llenarCadena(char* cadena)
{
    int n = 0;
    for(; n < 50; n++)
    {
        cadena[n] = '\0';
    }
    return cadena;
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

#endif // DELIMITADOR_H
