#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"

#define TRUE    1
#define FALSE   0

struct Nodo
{
    char* titulo;
    int id;
    int orden;
    struct Nodo* subOpciones;
    struct Nodo* siguiente;
};
typedef struct Nodo _nodo;

struct Registro
{
    int id_registro;
    char* contenido;
};
typedef struct Registro _registro;

struct Campo
{
    int id_campo;
    char* nombre_campo;
    char* tipo;
    struct Campo* siguiente;
};
typedef struct Campo _campo;

char contenido_json[10];
char paso_caracteres[10];

int nuevaAccion(int pos)
{
    if(contenido_json[pos] == '}')
    {
        return TRUE;
    }
    return FALSE;
}

//Funciones de Lista
_nodo* crearLista(char caracter)
{
    _nodo* ptr;
    if(caracter == '[')
        return (ptr = NULL);
}

//Funciones de Lista
int isVacio(_nodo *ptr)
{
    if(ptr == NULL)
        return TRUE;

    return FALSE;
}

//Funciones de Lista
_nodo* agregar(_nodo* ptr, char* titulo, int id, int orden, _nodo* subOpcs)
{
    _nodo *newNodo, *temporal;

    newNodo = (_nodo *) malloc(sizeof(_nodo));

    if(newNodo != NULL)
    {
        newNodo->titulo = titulo;
        newNodo->id = id;
        newNodo->orden = orden;
        newNodo->subOpciones = subOpcs;
        newNodo->siguiente = NULL;

        if(isVacio(ptr))
        {
            ptr = newNodo;
        }
        else{
            temporal = ptr;

            while(temporal->siguiente != NULL)
            {
                temporal = temporal->siguiente;
            }
            temporal->siguiente = newNodo;
        }
    }
    return ptr;
}

//Funciones de Lista
void imprimir(_nodo* ptr)
{
    _nodo *temporal;

    temporal = ptr;

    while(temporal != NULL)
    {
        printf("%s\n",temporal->titulo);
        printf("%d\n", temporal->id);
        printf("%d\n", temporal->orden);
        temporal = temporal->siguiente;
    }
}

//interpreta la cadena que se genero en interpretar archivo()
void interpretarCadena()
{
    int ac = 0;
    const char t[4] = "}";
    char* token;

    token = strtok(contenido_json, t);

    if(contenido_json[ac] == '[')
    {
        crearLista(contenido_json[ac]);
        ac++;
        if(contenido_json[ac] == '{')
        {
            while(token != NULL)
            {
                printf("%s\n",token);
                token = strtok(NULL,t);
            }
        }
    }
}

void cargarMenu(int opc)
{

    do
    {
        printf("--  MENU PRINCIPAL  --\n\n");
        printf("1- Crear Tabla\n");
        printf("2- Consultar Tabla\n");
        printf("3- Editar Tabla\n");
        printf("4- Eliminar Tabla\n");
        printf("5- Salir\n");

        printf("Elija una Opcion: ");
        scanf("%d",&opc);

        switch(opc)
        {
            case 1:
                printf("\nEsta creando una Tabla\n\n");
                break;
            case 2:
                printf("\nEsta haciendo una Consulta\n\n");
                break;
            case 3:
                cargarSubmenu(0);
                break;
            case 4:
                printf("\nEsta eliminando una Tabla\n\n");
                break;
            case 5:
                printf("\nHas salido del Menu\n\n");
                break;
        }
    }
    while(opc != 5);

}

void cargarSubmenu(int opc)
{

    do
    {
        printf("--  EDITAR TABLA  --\n\n");
        printf("1- Crear Campos\n");
        printf("2- Listar Campos\n");
        printf("3- Eliminar Campos\n");
        printf("4- Salir\n");

        printf("Elija una Opcion: ");
        scanf("%d",&opc);

        switch(opc)
        {
            case 1:
                printf("\nEsta creando un Campo\n\n");
                break;
            case 2:
                printf("\nListando Campos\n\n");
                break;
            case 3:
                printf("\nEsta eliminando Campos\n\n");
                break;
            case 4:
                printf("\nSaliendo del Submenu\n\n");
                break;
        }
    }
    while(opc != 4);

}

//lee un archivo y almacena toda la informacion en una cadena
void interpretarArchivo(char* nombre_archivo)
{
    FILE* misMenus = NULL;

    misMenus = fopen(nombre_archivo, "r");

    fscanf(misMenus," %[^\n]",&contenido_json);
    fgets(contenido_json, NULL, misMenus);

    fclose(misMenus);
}

int main()
{
    return 0;
}
