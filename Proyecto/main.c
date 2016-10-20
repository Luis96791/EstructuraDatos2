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

typedef struct Nodo _nodo;

_nodo* crearLista(_nodo *ptr)
{
    return (ptr = NULL);
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
    char leido[30];
    int _final = 0;

    misMenus = fopen(nombre_archivo, "r");

    _final = fscanf(misMenus," %[^\n]",&leido);

    while(_final != EOF)
    {
        printf("%s\n", leido);
        _final = fscanf(misMenus," %[^\n]",&leido);
    }

    fclose(misMenus);
}

int main()
{
    _nodo *miLista;
    miLista = crearLista(miLista);


    char* nombre;
    int id, orden;
    int opc;

    while(opc != 0)
    {
        printf("Nombre: ");
        scanf("%s",&nombre);
        printf("Id: ");
        scanf("%d",&id);
        printf("Orden: ");
        scanf("%d",&orden);
        miLista = agregar(miLista, &nombre, id, orden, NULL);
        printf("Seguir? ");
        scanf("%d",&opc);
    }
    imprimir(miLista);
    return 0;
}
