#include <stdio.h>
#include <stdlib.h>

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


char contenido_json[10];

typedef struct Nodo _nodo;

_nodo* crearLista(char caracter);
_nodo* agregar(_nodo* ptr, char* titulo, int id, int orden, _nodo* subOpcs);
void imprimir(_nodo* ptr);
void interpretarCadena();
char* nuevaAccion(int pos);
void nuevaOpcion(char caracter);



void interpretarArchivo(char* nombre_archivo);

_nodo* crearLista(char caracter)
{
    _nodo* ptr;
    if(caracter == '[')
        return (ptr = NULL);
}

void interpretarObjeto(char caracter, int pos)
{
    printf("entrando");
    if(caracter == "{")
    {
        nuevaAccion(pos);
    }
}

char* nuevaAccion(int pos)
{
    char stg[10];

    while(contenido_json[pos] != "}")
    {
        contenido_json[pos] += stg;
    }
    printf("%s",stg);
    return stg;
}

int isVacio(_nodo *ptr)
{
    if(ptr == NULL)
        return TRUE;

    return FALSE;
}

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

void interpretarCadena()
{
    int ac = 0;

    while(contenido_json[ac] != '\0')
    {
        ac++;
        crearLista(contenido_json[ac]);
        interpretarObjeto(contenido_json[ac],ac);
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

    interpretarArchivo("menus.json");

    printf("%s\n\n",contenido_json);
    interpretarCadena();
    return 0;
}
