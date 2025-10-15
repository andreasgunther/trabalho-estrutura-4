#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"


int menu(No *head, int valor){
    system("clear");
    if(head == NULL){
    printf("Bem-vindo ao sistema de listagem de entregas.\nPara começar, crie sua lista de entregas para que as demais opções sejam liberadas.\n");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃           SISTEMA DE LISTAGEM DE ENTREGAS          ┃\n");
    printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
    printf("┃ 1) Criar nova lista de entregas                    ┃\n");
    printf("┃ 0) Sair                                            ┃\n");
    printf("└────────────────────────────────────────────────────┘\n");
    printf("Escolha uma opção ▸ ");
    scanf("%d", &valor);
    system("clear");
    return valor;
    }

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃           SISTEMA DE LISTAGEM DE ENTREGAS          ┃\n");
    printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
    printf("┃ 2) Listar entregas                                 ┃\n");
    printf("┃ 3) Adicionar entrega(Prioridade)                   ┃\n");
    printf("┃ 4) Remover entrega(Início)                         ┃\n");
    printf("┃ 5) Adicionar entrega                               ┃\n");
    printf("┃ 6) Remover entrega                                 ┃\n");
    printf("┃ 7) Buscar entrega                                  ┃\n");
    printf("┃ 0) Sair                                            ┃\n");
    printf("└────────────────────────────────────────────────────┘\n");
    printf("Escolha uma opção ▸ ");
    scanf("%d", &valor);
    system("clear");

    return valor;
}

int criar_lista(No **head){

    No *tp ,*aux;
    int valor;

    if(*head == NULL){
        printf("Quantos elementos haverá na sua lista? ");
        scanf("%d", &valor);
        if(valor < 0){
            printf("Valor inválido! Por favor, tente novamente.\n");
            return 1;
        }

        *head = malloc(sizeof(No));
        if(*head == NULL){
            printf("Falha na alocação de memória. Encerrando...\n");
            return 2;
        }

        aux = *head;

        for(int i = 0; i < valor; i++){
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("┃          ENDEREÇO Encomenda %d         ┃\n", i + 1);
            printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
            printf("┃ Número: ");
            scanf("%d%*c", &aux->nCasa);

            printf("┃ Rua: ");
            fgets(aux->rua , sizeof(aux->rua), stdin);
            aux->rua[strcspn(aux->rua, "\n")] = '\0';  // remove o '\n' se existir

            printf("┃ Bairro: ");
            fgets(aux->bairro, sizeof(aux->bairro), stdin);
            aux->bairro[strcspn(aux->bairro, "\n")] = '\0';
            printf("└────────────────────────────────────────┘\n");

            if (i + 1 == valor) {
                aux->proximo = NULL;
            } else {
                tp = malloc(sizeof(No));
                if (tp == NULL) {
                  printf("Falha na alocação de memória. Encerrando...\n");
                    aux->proximo = NULL;
                    return 3;
                }
                aux->proximo = tp;
                aux = tp; 
            }
        }
    }
    return 0;
}

void listar(No **head){
    system("clear");
    int a = 1;
    No *aux = *head;

     if (*head == NULL) {
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃        NENHUMA ENTREGA CADASTRADA        ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        return;
    }

    while (aux != NULL){
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃          ENDEREÇO Encomenda %d          ┃\n", a);
        printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
        printf("┃ Número: %d\n", aux->nCasa);
        printf("┃ Rua: %s\n", aux->rua);
        printf("┃ Bairro: %s\n", aux->bairro);
        a++;
        aux = aux->proximo; 
    }
    printf("\nPressione ENTER para voltar ao menu.\n");
    getchar();
    getchar();
}

void remocao_inicil(No **head){
    No *headAtual = *head;        
    (*head) = (*head)->proximo;
    free(headAtual);
    headAtual = NULL; 
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃   Memória liberada com sucesso.      ┃\n");
    printf("┃   Itens excluídos.                   ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\nPressione ENTER para voltar ao menu.\n");
    getchar();
    getchar();
    system("clear");

    if(*head == NULL){
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃            LISTA VAZIA               ┃\n");
    printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
    printf("┃ Você será redirecionado ao início    ┃\n");
    printf("┃ do sistema.                          ┃\n");
    printf("└──────────────────────────────────────┘\n");
    printf("\nPressione ENTER para voltar ao menu.\n");
    getchar();
    system("clear");
    }
}

void remocao_final(No **head){
    No *aux = *head;
    No *prev = NULL;

    if (aux->proximo == NULL) {
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃           Ação inválida              ┃\n");
        printf("┃     Não é possível. Use a opção      ┃\n");
        printf("┃    \"4) Remover entrega(Início)\"      ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("\nPressione ENTER para voltar ao menu.\n");
        getchar();
        getchar();
        system("clear");
        return ;
    }

    while (aux->proximo != NULL) {
        prev = aux;
        aux = aux->proximo;
    }
    prev->proximo = NULL;  
    free(aux);   
    aux = NULL;             

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃     Exclusão bem-sucedida    ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\nPressione ENTER para voltar ao menu.\n");
    getchar();
    getchar();
    system("clear");
}

int inicil_lista(No **head){

    No *aux, *novoHead = *head;

    *head = malloc(sizeof(No*));
    if(*head == NULL){
         printf("Falha na alocação de memória. Encerrando...\n");
         return 1;
    }

    aux = (*head);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃          ENDEREÇO Encomenda %d         ┃\n", 1);
    printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
    printf("┃ Número: ");
    scanf("%d%*c", &aux->nCasa);

    printf("┃ Rua: ");
    fgets(aux->rua , sizeof(aux->rua), stdin);
    aux->rua[strcspn(aux->rua, "\n")] = '\0';  // remove o '\n' se existir

    printf("┃ Bairro: ");
    fgets(aux->bairro, sizeof(aux->bairro), stdin);
    aux->bairro[strcspn(aux->bairro, "\n")] = '\0';
    printf("└────────────────────────────────────────┘\n");

    aux->proximo = novoHead;
    return 0;
}

int final_lista(No *head){
    No *aux = head;

     while (aux->proximo != NULL) {       
        aux = aux->proximo;
    }

    aux->proximo = malloc(sizeof(No));
    if(aux == NULL){
         printf("Falha na alocação de memória. Encerrando...\n");
         return 1;
    }

    aux = aux->proximo;

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃            ENDEREÇO Encomenda          ┃\n");
    printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
    printf("┃ Número: ");
    scanf("%d%*c", &aux->nCasa);

    printf("┃ Rua: ");
    fgets(aux->rua , sizeof(aux->rua), stdin);
    aux->rua[strcspn(aux->rua, "\n")] = '\0';  // remove o '\n' se existir

    printf("┃ Bairro: ");
    fgets(aux->bairro, sizeof(aux->bairro), stdin);
    aux->bairro[strcspn(aux->bairro, "\n")] = '\0';
    
    aux->proximo = NULL;

    return 0;
}

void busca_casa(No **head){
    system("clear");
    int a = 1;
    No *aux = *head;

    printf("Número da casa: ");
    scanf("%d%*c", &a);


    while (aux != NULL){
        if(aux->nCasa == a){
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("┃          ENDEREÇO Encomenda %d          ┃\n", a);
            printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
            printf("┃ Número: %d\n", aux->nCasa);
            printf("┃ Rua: %s\n", aux->rua);
            printf("┃ Bairro: %s\n", aux->bairro);
            printf("\nPressione ENTER para voltar ao menu.\n");
            getchar();
            return;
        }
        aux = aux->proximo;
    }

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃        NENHUMA ENTREGA CADASTRADA        ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\nPressione ENTER para voltar ao menu.\n");
    getchar();
    return;
}


