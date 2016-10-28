#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* buffer;

void leerArchivo(char* nombre_archivo);

void leerArchivo(char* nombre_archivo)
{
    FILE* file = NULL;

    int num1, num2, suma = 0, resta = 0, mult = 0;

    int *ptr_suma;
    int *ptr_resta;
    int *ptr_mult;

    file = fopen(nombre_archivo, "r+");

    if(file == NULL)
    {
        printf("Error!\n");
    }

    int x = 0;

    while(!feof(file))
    {
        fscanf(file,"%d%d", &num1, &num2);
    }

    printf("%d\n",num1);
    printf("%d\n",num2);

    suma = num1 + num2;
    resta = num1 - num2;
    mult = num1 * num2;

    ptr_suma = &suma;

    fseek(file, SEEK_END, 1);

    fwrite(ptr_suma, sizeof(int), sizeof(suma),file);
    fwrite(ptr_resta, sizeof(int), sizeof(resta),file);
    fwrite(ptr_mult, sizeof(int), sizeof(mult), file);

    fclose(file);
}

int main()
{
    leerArchivo("operacion.txt");
    printf(buffer);

    return 0;
}
