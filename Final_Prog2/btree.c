#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#define ORDER 3         // Definimos que a ordem da �rvore � 3

struct arvore {
    node_t * raiz;
    int (*comp)(void *, void *);    // Ponteiro para a fun��o de compara��o (recebe como argumento um void*, pois n�o sabemos o que ela vai receber)
};

struct btNode {
    int n;               // n � a quantidade de chaves que o n� possui
    void * key[ORDER - 1];
    node_t * p[ORDER];  // p[ORDER] s�o as liga��es dos filhos
    node_t * pai;
    int leaf;         //0 = false / 1 = true
};

arvore_t * tree_create(int(*c)(void *, void *)) {

    arvore_t * arvore;

    arvore = malloc(sizeof(arvore_t));

    arvore->raiz = NULL;    // N�o h� nenhum dado ainda na raiz

    arvore->comp = c;

    return arvore;
}

btNode_t tree_node_create(){
    btNode_t bn;
    int i;

    bn->n = 0;
    bn->pai = NULL;
    for (i = 0, i<ORDER; i++){
        m->p[i] = NULL;
    }
    bn->leaf = 0;

    return bn;
}


static int searchKey (btNode_t* btn, void* data, arvore_t* tree){
    int i;

     for (i = 0; i < btn->n; i++){
        if (tree->comp() == 0){
            break;
        }
     }

     return i;
}
