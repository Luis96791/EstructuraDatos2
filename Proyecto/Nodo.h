#ifndef NODO_H
#define NODO_H

typedef struct Nodo
{
    char* titulo;
    int id;
    int orden;
    struct Nodo* subOpciones;
    struct Nodo* siguiente;
}mi_nodo;

#endif // NODO_H
