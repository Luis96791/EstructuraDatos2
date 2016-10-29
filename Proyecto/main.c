#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"
#include "Registros.h"
#include "Opciones.h"
#include "Interprete.h"

#define TRUE    1
#define FALSE   0


void inicializarTablas(_listaTabla* ptr);
void inicializarCampos(_listaCampos* ptr);

void inicializarTablas(_listaTabla* ptr)
{
    insertarTablas(ptr, 1, "Rentas");
    insertarTablas(ptr, 2, "Ventas");
    insertarTablas(ptr, 3, "Impuestos");
}

void inicializarCampos(_listaCampos* ptr)
{
    insertarCampos(ptr, 1, "Identidad", "entero");
    insertarCampos(ptr, 2, "Nombre", "texto");
    insertarCampos(ptr, 3, "Apellido", "texto");
}

int main()
{
    _listaTabla* T;
    T = nuevaTabla();
    inicializarTablas(T);
    listarTablas(T->inicio);

    _listaCampos* C = T->inicio->ptrCampo;

    C = nuevoCampo();
    inicializarCampos(C);
    listarCampos(C->inicio);


//    do
//    {
//        char* src = (char *)malloc(sizeof(char)*20);
//        printf("Nombre Opcion: ");
//        scanf("%s",src);
//        printf("Id Opcion: ");
//        scanf("%d",&a);
//        printf("seguir? ");
//        scanf("%d",&opc);
//        insertarTablas(L, a, src);
//    }while(opc != 0);


    return 0;
}
