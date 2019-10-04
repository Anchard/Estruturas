#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}tNode;

typedef struct list{
    tNode *head;
    int tam;
}tList;

void initList(tList *lista){
    lista->head = NULL;
    lista->tam = 0;
}

void insertHead(tList *lista, int data){
    tNode *newNode = (tNode *) malloc(sizeof(tNode));

    newNode->data = data;
    newNode->next = lista->head;

    lista->head = newNode;
    lista->tam++;
}

int search(tList *lista, int data){
    tNode *aux = lista->head;
    int i;

    for(i = 0; i < lista->tam; i++){
        if(aux->data == data) return i;
        aux = aux->next;
    }

    return -1;
}

void insertPos(tList *lista, int data, int pos){
    tNode *newNode = (tNode *) malloc(sizeof(tNode));
    tNode *aux_frente = lista->head;
    tNode *aux_tras = lista->head;
    int i;

    newNode->data = data;

    for(i = 0; i < pos; i++){
        aux_frente = aux_frente->next;
        if(i > 0) aux_tras = aux_tras->next;
    }

    aux_tras->next = newNode;
    newNode->next = aux_frente;
    lista->tam++;
}

void removeHead(tList *lista){
    tNode *aux = lista->head;
    tNode *trash = lista->head;

    aux = aux->next;
    lista->head = aux;
    free(trash);

    lista->tam--;
}

void removePos(tList *lista, int pos){
    tNode *aux_frente = lista->head;
    tNode *aux_tras = lista->head;
    tNode *trash = lista->head;
    int i;

    for(i = 0; i < pos; i++){
        aux_frente = aux_frente->next;
        if(i > 1) aux_tras = aux_tras->next;
    }

    trash = aux_tras->next;
    free(trash);
    aux_tras->next = aux_frente;
    lista->tam--;
}

void print(tList *lista){
    tNode *aux = lista->head;
    int i;

    for(i = 0; i < lista->tam; i++){
        printf("%d ", aux->data);
        aux = aux->next;
    }

    printf("\n");
}

int main(){
    tList lista;

    /** Interface
        initList(&list);
        insertHead(&list, data);
        insertPos(&list, data, position);
        removeHead(&list);
        removePos(&list, position);
        search(&list, data);
        print(&list);
    **/

    return 0;
}
