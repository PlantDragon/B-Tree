#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

typedef struct arvore arvore_t;

typedef struct btNode btNode_t;

arvore_t * tree_create(int (*comp)(void*, void*));

void insert_tree(void * dado, arvore_t *arvore); // Balanceamento feito dentro da inser��o

void * search_tree(void * dado, arvore_t *arvore);

void free_tree(arvore_t *arvore);


#endif // BTREE_H_INCLUDED
