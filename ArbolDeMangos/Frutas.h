#ifndef FRUTAS_H
#define FRUTAS_H
#include <stdlib.h>
#include <stdio.h>

class Frutas
{
    public:
        Frutas* anterior;
        Frutas* siguiente;
        int peso;
        Frutas();
        int getPeso();
        virtual ~Frutas();

    protected:

    private:
};

#endif // FRUTAS_H
