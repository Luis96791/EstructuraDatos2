#include "ArbolDeMangos.h"

ArbolDeMangos::ArbolDeMangos()
{
    inicio = fin = NULL;
}

void ArbolDeMangos::insertarFruta(Frutas* fruta, int pos)
{
    Frutas* temp;

    if(inicio == NULL)
    {
        inicio = fin = fruta;
        return;
    }

    temp = inicio;

    while(temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }

    temp->siguiente = fin = fruta;
}

void ArbolDeMangos::imprimirPeso()
{
    Frutas* temp;

    temp = inicio;

    while(temp != NULL)
    {
        printf("%d \n", temp->getPeso());
        temp = temp->siguiente;
    }
}

ArbolDeMangos::~ArbolDeMangos()
{
    //dtor
}
