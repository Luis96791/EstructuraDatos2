#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

long double factorial(long double numero)
{
    long double fact = 1;

    for(long double x = 1; x <= numero; x++)
        fact *= x;

    return fact;
}

long double calcularPotencia(long double N, long double p)
{
    long double resultado = N * N;

    if(p == 0)
        return 1;

    if(p == 1)
        return N;

    p--;

    while(p != 1)
    {
        resultado *= N;
        p--;
    }
    return resultado;
}

void calcularProBinomial(long double n, long double r, long double p)
{
    cout<<"\n\t(Binomial) b(n,r,p) = (nCr)(p)^r (q)^(n-r)\n\n"<<endl;
    cout<<"Ingrese numero (n): ";
    cin>>n;
    cout<<"Ingrese numero (r): ";
    cin>>r;
    cout<<"Ingrese numero (p): ";
    cin>>p;

    long double result_combinacion = 0;
    long double result_potencia1 = 0;
    long double result_potencia2 = 0;

    result_combinacion = factorial(n)/(factorial(n-r)*factorial(r));
    result_potencia1 = calcularPotencia(p, r);
    result_potencia2 = calcularPotencia((1-p), (n-r));
    cout<<"<----------------------------->\n\tResultado: "<<(result_combinacion * result_potencia1 * result_potencia2)
    <<"\n<----------------------------->"<<endl;
}

int ingresoNumeroCalculos()
{
    int numero = 0;

    cout<<"Ingrese numero de Calculos (n1, n2...nk): ";
    cin>>numero;

    return numero;
}

int ingresoNumeroProbable()
{
    int numero = 0;

    cout<<"Ingrese numero Probable (n): ";
    cin>>numero;

    return numero;
}

void calcularProMultinomial()
{
    cout<<"\n\t(Multinomial) m(n, (n1, n2...nk)(p1, p2...pk))\n\n"<<endl;

    int INC = ingresoNumeroCalculos();
    int INP = ingresoNumeroProbable();

    long double dato, mult_factorial = 1, mult_potencia = 1, resultado;

    long double P[INC];
    long double N[INC];

    cout<<"\n\tNumero de Calculos (n1, n2...nk)\n"<<endl;

    for(int x = 0; x < INC; x++)
    {
        cout<<"Ingrese N["<<x+1<<"]: ";
        cin>>dato;
        N[x] = dato;
        mult_factorial *= factorial(N[x]);
    }

    cout<<"\n\tPorcentajes ((p1)^(n1), (p2)^(n2)...(pk)^(nk))\n"<<endl;

    for(int x = 0; x < INC; x++)
    {
        cout<<"Ingrese P["<<x+1<<"]: ";
        cin>>dato;
        P[x] = dato;
        mult_potencia *= calcularPotencia(P[x], N[x]);
    }

    resultado = (factorial(INP)/mult_factorial)* mult_potencia;

    cout<<"<----------------------------->\n\tResultado: "<<resultado
    <<"\n<----------------------------->"<<endl;
}

int main()
{
    system("color A");
    cout<<"\n\n\tCalculadora Distribucion de Probabilidades\n\n"<<endl;

    long double n = 0, r = 0, p = 0;
    int opcion;
    string continuar = "";

    do{
        cout<<"\t1-. Calcular Probabilidad Binomial"<<endl;
        cout<<"\t2-. Calcular Probabilidad Multinomial"<<endl;
        cout<<"Escoja una Opcion: ";
        cin>>opcion;

        switch(opcion)
        {
            case 1:
                calcularProBinomial(n, r, p);
                break;
            case 2:
                calcularProMultinomial();
                break;
        }

        cout<<"\n\tDesea hacer otro calculo? (si/no): ";
        cin>>continuar;

    }while(continuar == "si");

    return 0;
}
