#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tablas.h"

#define TRUE    1
#define FALSE   0


void inicializarTablas(_listaTabla* ptr);
void inicializarCampos(_listaCampos* ptr);
void inicializarRegistros(_listaRegistros* ptr);
void inicializarDescCampos(_listaDescCampos* ptr, _nodoCampo* ptrCampo);

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

void inicializarRegistros(_listaRegistros* ptr)
{
    insertarRegistros(ptr);
}

void inicializarDescCampos(_listaDescCampos* ptr, _nodoCampo* ptrCampo)
{
    insertarDesCampos(ptr, "cadenacaracter", ptrCampo);
    insertarDesCampos(ptr, 12, ptrCampo);

    printf("entrando");
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

    _listaRegistros* R = T->inicio->ptrRegistro;
    R = nuevoRegistro();
    inicializarRegistros(R);

    _listaDescCampos* DC = R->inicio->ptrNodoDescCampos;
    DC = nuevaDesCampos();
    _nodoCampo* temp = getCampo(C, getPosicionDescCampo(DC));
    inicializarDescCampos(DC, NULL);

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
