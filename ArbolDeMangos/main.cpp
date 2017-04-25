#include <iostream>
#include "ArbolDeMangos.h"
#include "Frutas.h"

using namespace std;

int main()
{
    ArbolDeMangos* arbolDeMangos = new ArbolDeMangos();
    Frutas* fruta = new Frutas();
    Frutas* fruta1 = new Frutas();
    Frutas* fruta2 = new Frutas();
    Frutas* fruta3 = new Frutas();

    fruta->peso = 45;
    fruta1->peso = 28;
    fruta2->peso = 78;
    fruta3->peso = 75;

    arbolDeMangos->agregarFruta(fruta);
    arbolDeMangos->agregarFruta(fruta1);
    arbolDeMangos->agregarFruta(fruta2);
    arbolDeMangos->agregarFruta(fruta3);

    arbolDeMangos->imprimirPeso();

    //El apuntador fin esta funcionando
    printf("\n%d", arbolDeMangos->fin->getPeso());

    delete fruta;
    delete fruta1;
    delete fruta2;
    delete fruta3;

    return 0;
}
