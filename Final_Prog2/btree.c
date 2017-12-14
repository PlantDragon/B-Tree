#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#define ORDER 3         // Definimos que a ordem da �rvore � 3

struct arvore {
    btNode_t * raiz;
    int (*comp)(void *, void *);    // Ponteiro para a fun��o de compara��o (recebe como argumento um void*, pois n�o sabemos o que ela vai receber)
    int (*comp_search) (void *, void *); // Ponteiro para fun��o de compara��o para pesquisa na arvore
};

struct btNode {
    int n;               // n � a quantidade de chaves que o n� possui
    void * key[ORDER - 1];
    btNode_t * p[ORDER];  // p[ORDER] s�o as liga��es dos filhos
    btNode_t * pai;
    int leaf;         //0 = false / 1 = true
};

arvore_t * tree_create(int(*c)(void *, void *), int (*c_s)(void *, void *)) {

    arvore_t * arvore;

    arvore = malloc(sizeof(arvore_t));

    arvore->raiz = NULL;    // N�o h� nenhum dado ainda na raiz

    arvore->comp = c;

    arvore->comp_search = c_s;

    return arvore;
}

/*btNode_t tree_node_create(){
    btNode_t tNode;
    int i;

    tNode->n = 0;
    tNode->pai = NULL;
    for (i = 0; i<ORDER; i++){
        tNode->p[i] = NULL;
    }
    tNode->leaf = 0;

    return tNode;
}*/


static int searchKey (btNode_t* btn, void* data, arvore_t* tree){
    int i;

     for (i = 0; i < btn->n; i++){
        if (tree->comp(data, btn->key[i]) == 0){
            break;
        }
     }

     return i;
}
