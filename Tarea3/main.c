#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaObjeto.h"
#include "TamanioFijo.h"

int main()
{
    _listaPersona* LP1;
    LP1 = newListaPersona();
    LP1 = RunLista();

    _nodoPersona* temp = LP1->inicio;

    int cantRegistros = getSize(LP1);

    listarPersonas(LP1);

//    int tamanioRegistro = 44;
//    char* cadena = malloc(tamanioRegistro * cantRegistros);
//
//    int n = 0;
//    int pos = 0;
//
//    if(temp != NULL)
//    {
//        while(temp->siguiente != NULL)
//        {
//            escribirData(cadena, temp, ++n, tamanioRegistro);
//            temp = temp->siguiente;
//            pos += tamanioRegistro;
//        }
//    }
//    printf("%s", &cadena);
    return 0;
}
