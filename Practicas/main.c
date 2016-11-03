#include <stdio.h>
#include <stdlib.h>
#include "Delimitador.h"

int main()
{

    listarRegistros(leerArchivo());
//
//    int opc = 0, id;
//
//    do
//    {
//        printf("\t1-. Agregar Registro\n");
//        printf("\t2-. Listar\n\n");
//        printf("Ingrese una Opcion: ");
//        scanf("%d", &opc);
//
//        char* nombre = (char *)malloc(sizeof(char)*20);
//
//        if(opc == 1)
//        {
//            printf("Ingrese ID: ");
//            scanf("%d", &id);
//            printf("Ingrese Nombre: ");
//            scanf("%s", nombre);
//            insertarRegistros(LR, id, nombre);
//        }
//
//        if(opc == 2)
//        {
//            listarRegistros(LR);
//        }
//    }while(opc != 0);
    return 0;
}
