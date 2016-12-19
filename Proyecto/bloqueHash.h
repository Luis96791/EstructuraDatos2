#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct IndexEntry Indice;
typedef struct ListIndex LIndice;
typedef struct HashBlock BloqueHash;
typedef struct ListHashBlock LBloqueHash;


struct IndexEntry{
    char* index;
    char* tabla;
    struct IndexEntry* nxt;
};

struct ListIndex{
    struct IndexEntry* inicio;
    int cantidad;
};

struct HashBlock{
    int anterior;
    int siguiente;
    int cantidadDeIndices;
    LIndice* ListaIndices;
    struct HashBlock* nxt;
};

struct ListHashBlock{
    struct HashBlock* inicio;
    int cantidad;
    int llaves;
};

Indice* nuevoIndice(char* indice, char* tab){
    Indice* ind;
    ind = (Indice*)malloc(sizeof(Indice));
    ind->index = (char*)malloc(sizeof(sizeof(char)*5));
    ind->tabla = (char*)malloc(sizeof(sizeof(char)*20));
    strcpy(ind->index,indice);
    strcpy(ind->tabla,tab);
    ind->nxt = NULL;
    return ind;
}

LIndice* nuevaListaHash(){
    LIndice* lind;
    lind = (LIndice*)malloc(sizeof(LIndice));
    lind->inicio = NULL;
    lind->cantidad = 0;
    return lind;
}

void agregarAListaIndice(LIndice* li, char* indice, char* tab){
    if(li->inicio==NULL){
        li->inicio = nuevoIndice(indice,tab);
        li->cantidad++;
    }else{
        Indice* tmp = li->inicio;
        while(tmp->nxt!=NULL){
            tmp=tmp->nxt;
        }
        tmp->nxt = nuevoIndice(indice,tab);
        li->cantidad++;
    }
}

BloqueHash* nuevoBloqueHash(int ant, int sig, int cant){
    BloqueHash* bh;
    bh = (BloqueHash*)malloc(sizeof(BloqueHash));
    bh->anterior = ant;
    bh->siguiente = sig;
    bh->cantidadDeIndices = cant;
    bh->ListaIndices = nuevaListaHash();
    bh->nxt = NULL;
    return bh;
}

LBloqueHash* nuevaListaBloqueHasgh(){
    LBloqueHash* lb;
    lb = (LBloqueHash*)malloc(sizeof(LBloqueHash));
    lb->inicio = NULL;
    lb->cantidad = 0;
    lb->llaves = 0;
}

void inicializarHash(LBloqueHash* lb,int cantBloques){
    int con = 0;
    while(con<cantBloques-1){
        agregarBloqueHash(lb,con-1,con+1,20);
        con++;
    }
    agregarBloqueHash(lb,con-1,-1,20);
}

void agregarBloqueHash(LBloqueHash* lb, int ant, int sig, int cant){
    if(lb->inicio==NULL){
        lb->inicio = nuevoBloqueHash(ant,sig,cant);
        lb->cantidad++;
    }else{
        BloqueHash* tmp = lb->inicio;
        while(tmp->nxt!=NULL){
            tmp = tmp->nxt;
        }
        tmp->nxt = nuevoBloqueHash(ant,sig,cant);
        lb->cantidad++;
    }
}

void agregarAlBloqueNum(LBloqueHash* lb,int numHash,char* indice, char* tab){
    if(lb->inicio!=NULL){

        BloqueHash* temp = lb->inicio;
        int con = 0;
        while(con<numHash){
            con++;
            temp = temp->nxt;
        }
        //infoBloques(lb);
        //printf("%d - %d\n",temp->anterior,temp->siguiente);
        agregarAListaIndice(temp->ListaIndices,indice,tab);
        lb->llaves++;
        //printf("%d",temp->ListaIndices->cantidad);
    }
}

int Hash(char* indice,int divi){
    int sum = 0;
    int con=0;
    while(con<divi){
        sum = sum + ((int)indice[con]);
        con++;
    }
    return sum%divi;
}

void infoBloques(LBloqueHash* lb){
    BloqueHash* tmp = lb->inicio;
    while(tmp!=NULL){
        printf("Ant:%d  Sig:%d\n",tmp->anterior,tmp->siguiente);
        tmp = tmp->nxt;
    }
}

void guardarHash(FILE* fa,LIndice* li){
    char cadena[1000] = "";
    Indice* temp = li->inicio;
    while(temp!=NULL){
        strcat(cadena,temp->index);
        temp = temp->nxt;
    }
    fprintf(fa,"%s",cadena);
}

void guardarListaBloque(LBloqueHash* LBH){
    FILE* fa;
    fa = fopen("INDICES.TXT","r+");
    BloqueHash* temp = LBH->inicio;
    while(temp!=NULL){
        guardarHash(fa,temp->ListaIndices);
        temp = temp->nxt;
    }
    fclose(fa);
}

void cargarListaHash(LBloqueHash* LBH, int div){
    FILE* fr;
    fr = fopen("INDICES.TXT","r");
    char cadena[100] = "";
    while(!feof(fr)){
        fscanf(fr,"%s\n",cadena);
        interpretarCadena(LBH,cadena,div);
    }
    fclose(fr);
}

void interpretarCadena(LBloqueHash* LBH,char* cadena,int div){
    char index[5] = "";
    int con = 0;
    while(con<strlen(cadena)/5){
        index[0] = cadena[0+(5*con)];
        index[1] = cadena[1+(5*con)];
        index[2] = cadena[2+(5*con)];
        index[3] = cadena[3+(5*con)];
        index[4] = cadena[4+(5*con)];
        //printf("%s\n",index);
        agregarAlBloqueNum(LBH,Hash(index,div),index,"None");
        con++;
    }
}

