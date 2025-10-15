#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

typedef struct No{
    int nCasa;
    char rua[100];
    char bairro[100];
    struct No *proximo;
} No;


int  menu(No *head, int valor);
int criar_lista(No **head);
void listar(No **head);
int inicil_lista(No **head);
void remocao_inicil(No **head);
int final_lista(No *head);
void remocao_final(No **head);
void busca_casa(No **head);


#endif