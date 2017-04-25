#include "ArbolDeMangos.h"

ArbolDeMangos::ArbolDeMangos()
{
    inicio = fin = NULL;
}

bool ArbolDeMangos::agregarFruta(Frutas* fruta)
{
    if(insertarFruta(fruta, 0) != NULL)
    {
        return true;
    }
    return false;
}

Frutas* ArbolDeMangos::insertarFruta(Frutas* fruta, int pos)
{
    Frutas* temp;

    if(inicio == NULL)
    {
        inicio = fin = fruta;
        return inicio;
    }

    temp = inicio;

    while(temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }

    temp->siguiente = fin = fruta;

    return fin;
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
