#include <stdio.h>
#include <stdlib.h>

int cajas[10];
char* colores[10];

void imprimir()
{
    int x;
    for(x = 0; x < 10; x++)
    {
        if(cajas[x] != NULL)
        {
            printf("%i ,",cajas[x]);
        }
    }
    printf("\n");
}

int totalColor(char* color)
{
    int x, acum = 0;
    for(x = 0; x < 10; x++)
    {
        if(colores[x] == color)
        {
            acum += cajas[x];
        }
    }
    return acum;
}

void imprimirColor(char* color)
{
    int n;
    for(n = 0; n < 10; n++)
    {
        if(colores[n] == color)
        {
            printf("%d ,", n);
        }
    }
    printf("\n");
}

int posVacia()
{
    int x = 0;
    for(; x < 10; x++)
    {
        if(colores[x]==NULL)
        {
            return x;
        }
    }
    return -1;
}

void eliminar(int caja)
{
    int h = 0;
    for( ; h < 10 ; h++)
    {
        if( h == caja )
        {
            cajas[h] = NULL;
            colores[h] = NULL;
        }
    }
}

void agregar(int num, char* color)
{
    int posicion = posVacia();

    if(posicion != -1)
    {
        cajas[posicion] = num;
        colores[posicion] = color;
        return;
    }
    printf("Arreglo lleno!\n");
}

int main()
{
    agregar(28, "blanco");
    agregar(12, "blanco");
    agregar(20, "negro");
    agregar(33, "negro");
    agregar(89, "negro");
    agregar(21, "blanco");
    agregar(29, "blanco");
    agregar(67, "negro");
    agregar(56, "negro");
    agregar(75, "blanco");
    //elimina caja en pos 5
    eliminar(5);

    printf("Cajas: ");
    imprimir();
    printf("Negras: ");
    imprimirColor("negro");
    printf("Blancas: ");
    imprimirColor("blanco");
    printf("Total Blancas: %d\n", totalColor("blanco"));
    printf("Total Negras: %d\n", totalColor("negro"));
    printf("Total Cajas: %d\n", (totalColor("blanco")+totalColor("negro")));

    return 0;
}
