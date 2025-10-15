#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inserir_inicio(struct Musica **playlist){
    struct Musica *novo = malloc(sizeof(struct Musica));
    if(novo == NULL){
        printf("Erro de alocação!\n");
        printf("Pressione Enter para continuar\n");
        getchar(); getchar();
        return;
    }
    printf("Digite o nome da música: \n");
    getchar(); //limpa o buffer, retirando o \n do enter
    fgets(novo->nome, 100, stdin); //fgets faz a leitura da string e stdin é a entrada padrão que nesse caso é o teclado
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; //strcspn encontra o \n(enter do usuário) no cod e substitui por \0(finaliza a string)
    novo->prox = *playlist; //novo nó aponta para o antigo primeiro
    novo->ante = NULL; //não tem valor anterior
    if (*playlist != NULL){
        (*playlist)->ante = novo; //caso a cabeça seja diferente de NULL o ante(agora a antiga cabeça) aponta para o novo
    }
    *playlist = novo; //cabeça vira novo valor
    printf("Música adicionada!\n");
    printf("Pressione Enter para continuar!\n");
    getchar(); //limpa o buffer
}

void inserir_final(struct Musica **playlist){
    struct Musica *aux, *novo = malloc(sizeof(struct Musica));
    if(novo == NULL){
        printf("Erro de alocação!\n");
        printf("Pressione Enter para continuar\n");
        getchar(); getchar();
        return;
    }
    printf("Digite o nome da música: \n");
    getchar();
    fgets(novo->nome, 100, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';
    novo->prox = NULL;
    if(*playlist == NULL){
        *playlist = novo;
        novo->ante = NULL;
    }
    else {
        aux = *playlist; //aux recebe a cabeça da lista
        while(aux->prox != NULL){ //percorre até o ultimo
            aux = aux->prox; 
        }
        aux->prox = novo; //ultimo valor vira o novo
        novo->ante = aux; //antigo ultimo valor vira o penúltimo
    }
    printf("Música adicionada!\n");
    printf("Pressione Enter para continuar!\n");
    getchar(); 
}

void remover_inicio(struct Musica **playlist){
    struct Musica *remover;
    if (*playlist == NULL){
        printf("Playlist vazia!\n");
        printf("Pressione Enter para continuar!\n");
        getchar(); getchar();
        return;
    }
    remover = *playlist;
    *playlist = remover->prox;
    if (*playlist != NULL){
        (*playlist)->ante = NULL;
    }
    free(remover);
    printf("Primeira música removida!\n");
    printf("Pressione Enter para continuar\n");
    getchar(); getchar();
}

void remover_final(struct Musica **playlist){
    struct Musica *aux, *remover;
    if (*playlist == NULL) {
        printf("Playlist vazia!\n");
        printf("Pressione Enter para continuar\n");
        getchar(); getchar();
        return;
    }
    if((*playlist)->prox == NULL){
        free(*playlist);
        *playlist = NULL;
        printf("Úlima música removida!\n");    
        printf("Pressione Enter para continuar\n");
        getchar(); getchar();
        return;
    } else {
        aux = *playlist;
        while (aux->prox->prox != NULL){ //vai ate o penúltimo valor
            aux = aux->prox;
        }
    }
    remover = aux->prox;
    aux->prox = NULL; //penúltimo valor virou o ultimo
    free(remover);
    printf("Úlima música removida!\n");    
    printf("Pressione Enter para continuar\n");
    getchar(); getchar();
}

struct Musica* buscar(struct Musica **playlist){
    struct Musica *aux;
    aux = *playlist;
    if(*playlist == NULL){
        printf("Playlist vazia!\n");
        printf("Pressione Enter para continuar\n");
        getchar(); getchar();
        return NULL;
    }
    char nome[100];
    printf("Digite o nome da música que quer buscar:\n");
    getchar();
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    while(aux != NULL){
        if(strcmp(aux->nome, nome) == 0){ //compara 2 strings caractere por caractere, se for igual retorna 0
            printf("Essa música existe na playlist!\n");
            printf("Pressione Enter para continuar\n");
            getchar();
            return aux;
        }
        aux = aux->prox;
    }

    printf("Essa música não existe na playlist!\n");
    printf("Pressione Enter para continuar\n");
    getchar();
    return NULL;
}

void passar_musica(struct Musica **atual){
    if(*atual == NULL){
        printf("Playlist vazia!\n");
    }
    else if((*atual)->prox == NULL){
        printf("Você já está na última música da playlist!\n");
    }
    else {
        *atual = (*atual)->prox;
        printf("Música atual: %s\n", (*atual)->nome);
    }   
    printf("Pressione Enter para continuar\n");
    getchar(); getchar();
}

void musica_atual(struct Musica **atual){
    if (*atual == NULL){
        printf("Playlist vazia!\n"); 
    }
    else {
        printf("Música atual: %s\n", (*atual)->nome);
    }
    printf("Pressione Enter para continuar\n");
    getchar(); getchar();
}

void voltar_musica(struct Musica **atual){
    if(*atual == NULL){
        printf("Playlist vazia!\n"); 
    }
    else if((*atual)->ante == NULL){
        printf("Você já está na primeira música da playlist!\n");
    }

    else {
        *atual = (*atual)->ante;
        printf("Música atual: %s\n", (*atual)->nome);
    }
    printf("Pressione Enter para continuar\n");
    getchar(); getchar();
}

void imprimir(struct Musica *playlist){
    struct Musica *aux = playlist;
    while (aux != NULL){
        printf("%s <--> ", aux->nome);
        aux = aux->prox;
    }
    printf("NULL\n");
    printf("Pressione Enter para continuar\n");
    getchar(); getchar();
}
