#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

typedef struct No{
    int Naviao;
    char saida[100];
    char destino[100];
    int preco;
    char data[12];
    struct No *proximo;
} No;


int  menu(No *head, int valor);
int criar_lista(No **head);
void listar(No **head);
int inicio_lista(No **head);
void remocao_inicio(No **head);
int final_lista(No *head);
void remocao_final(No **head);
void busca_aviao(No **head);
void exibir(No *head);

#endif
