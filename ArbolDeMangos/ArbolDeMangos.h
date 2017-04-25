#ifndef ARBOLDEMANGOS_H
#define ARBOLDEMANGOS_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "Frutas.h"

using namespace std;

class ArbolDeMangos
{
    public:
        Frutas* inicio;
        Frutas* fin;
        ArbolDeMangos();
        Frutas* insertarFruta(Frutas* fruta, int pos);
        bool agregarFruta(Frutas* fruta);
        void eliminarFruta(int pos);
        void imprimirPeso();
        virtual ~ArbolDeMangos();

    protected:

    private:
};

#endif // ARBOLDEMANGOS_H
