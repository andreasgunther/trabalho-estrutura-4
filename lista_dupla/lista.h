#ifndef LISTA_H
#define LISTA_H

struct Musica {
    char nome[100];
    struct Musica *prox;
    struct Musica *ante;
};

// Protótipos das funções
void inserir_inicio(struct Musica **playlist);
void inserir_final(struct Musica **playlist);
void remover_inicio(struct Musica **playlist);
void remover_atual(struct Musica **atual, struct Musica **playlist);
void remover_final(struct Musica **playlist);
struct Musica* buscar(struct Musica **playlist); //tipo struct porque retona um ponteiro para struct
void passar_musica(struct Musica **atual);
void musica_atual(struct Musica **atual, struct Musica **playlist);
void voltar_musica(struct Musica **atual);
void imprimir(struct Musica *playlist);

#endif
