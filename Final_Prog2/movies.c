#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_enc.h"
#include "no.h"
#include "movies.h"

struct movies {
    char title[80];
    lista_enc_t * genres;
    int year;
    long int id;
};

lista_enc_t * ler_arquivo(char *arquivo) {

    int i;
    int j;
    char buffer[150];
    char genrebuffer[80];
    movie_t *dados;
    no_t *no;
    lista_enc_t *lista;

    lista = cria_lista_enc();

    FILE *fp = fopen(arquivo, "r");

    if (fp == NULL){
        perror("Erro em ler_arquivo: fopen");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, 150, fp);

    while( fgets(buffer, 150, fp) != NULL){
        i = 0;
        j = 0;
        dados = malloc(sizeof(struct movies));
        sscanf(buffer, "%ld, %50[^(](%d),%[^\n]", &dados->id, dados->title, &dados->year, genrebuffer);
        dados->genres = cria_lista_enc();   // Criando uma lista para os g�neros de cada filme
        while(genrebuffer[i] != '\0'){ // L�gica para pegar cada g�nero do filme da lista, que est�o dividos pelo car�cter '|'
            if(genrebuffer[i] == '|'){
                char * genre = malloc(strlen((genrebuffer + j) + 1));     // + 1 para caber o '\0'
                strcpy(genre, genrebuffer + j);
                no_t * no = cria_no(genre);
                add_cauda(dados->genres, no);
            }
        }
        no = cria_no(dados);
        add_cauda(lista, no);
    }
    fclose(fp);
    return lista;
}

void libera_movies(lista_enc_t * lista){

    movie_t *dados;
    char * g;
    no_t *no;

    no = cabeca_lista(lista);
    no_t * no_prox, *no_genre, *no_genre_prox;

    while (no){
        dados = obtem_dado(no);
        no_genre = cabeca_lista(dados->genres);
        while (no_genre){
            g = obtem_dado(no_genre);
            no_genre_prox = obtem_proximo(no_genre);
            free(g);
            free(no_genre);
            no_genre = no_genre_prox;
        }
        free(dados);
        no_prox = obtem_proximo(no);
        free(no);
        no = no_prox;
    }
    free(lista);
}
