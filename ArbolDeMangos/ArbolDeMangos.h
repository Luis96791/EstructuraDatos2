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
        void insertarFruta(Frutas* fruta, int pos);
        void eliminarFruta(int pos);
        void imprimirPeso();
        virtual ~ArbolDeMangos();

    protected:

    private:
};

#endif // ARBOLDEMANGOS_H
