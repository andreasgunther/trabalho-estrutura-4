#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

int menu(No *head, int valor){
    system("clear");
    if(head == NULL){
    printf("Bem-vindo ao sistema de viagens aéreas.\nPara começar, crie sua lista de passagens para que as demais opções sejam liberadas.\n");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃        SISTEMA DE LISTAGEM DE VIAGENS AÉREAS       ┃\n");
    printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
    printf("┃ 1) Criar nova lista de passagens aéreas            ┃\n");
    printf("┃ 0) Sair                                            ┃\n");
    printf("└────────────────────────────────────────────────────┘\n");
    printf("Escolha uma opção ▸ ");
    scanf("%d", &valor);
    system("clear");
    return valor;
    }

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃     SISTEMA DE LISTAGEM DE VIAGENS AÉREAS          ┃\n");
    printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
    printf("┃ 2) Listar passagens                               ┃\n");
    printf("┃ 3) Adicionar passagem (Prioridade)                ┃\n");
    printf("┃ 4) Remover passagem (Início)                      ┃\n");
    printf("┃ 5) Adicionar passagem                             ┃\n");
    printf("┃ 6) Remover passagem                               ┃\n");
    printf("┃ 7) Buscar passagem                                ┃\n");
    printf("┃ 0) Sair                                           ┃\n");
    printf("└────────────────────────────────────────────────────┘\n");
    printf("Escolha uma opção ▸ ");
    scanf("%d", &valor);
    system("clear");

    return valor;
}

int criar_lista(No **head){

    No *tp ,*aux, *haux;
    int valor;

    if(*head == NULL){
        printf("Quantos elementos haverá na sua lista? ");
        scanf("%d", &valor);
        if(valor < 0 || valor == 0){
            printf("Valor inválido! Por favor, tente novamente.\n");
            return 1;
        }

        *head = malloc(sizeof(No));
        if(*head == NULL){
            printf("Falha na alocação de memória. Encerrando...\n");
            return 2;
        }
        
        aux = *head;
        haux = *head;
        for(int i = 0; i < valor; i++){
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("┃           PASSAGEM AÉREA %d             ┃\n", i + 1);
            printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
            printf("┃ Número do avião: ");
            scanf("%d%*c", &aux->Naviao);

            printf("┃ Cidade de saída: ");
            fgets(aux->saida , sizeof(aux->saida), stdin);
            aux->saida[strcspn(aux->saida,"\n")] = '\0';  // remove o '\n' se existir

            printf("┃ Destino: ");
            fgets(aux->destino, sizeof(aux->destino), stdin);
            aux->destino[strcspn(aux->destino, "\n")] = '\0';

            printf("┃ Preço (R$ inteiro): ");
            scanf("%d%*c", &aux->preco);

            printf("┃ Data (DD/MM/AAAA): ");
            fgets(aux->data, sizeof(aux->data), stdin);
            aux->data[strcspn(aux->data, "\n")] = '\0';
 
            printf("└────────────────────────────────────────┘\n");

            if (i + 1 == valor) {
                aux->proximo = haux;
            } else {
                tp = malloc(sizeof(No));
                if (tp == NULL) {
                  printf("Falha na alocação de memória. Encerrando...\n");
                    aux->proximo = haux;
                    return 3;
                }
                aux->proximo = tp;
                aux = tp; 
            }
            system("clear");
        }
    }
    return 0;
}

void listar(No **head){
    system("clear");
    int a = 1;
    No *aux = *head, *haux = *head;

     if (*head == NULL) {
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃        NENHUMA ENTREGA CADASTRADA        ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        return;
    }

    do{
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃           PASSAGEM AÉREA %d             ┃\n", a);
        printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
        printf("┃ Número do avião: %d \n", aux->Naviao);
        printf("┃ Cidade de saída: %s \n", aux->saida);
        printf("┃ Destino: %s \n", aux->destino);
        printf("┃ Preço (R$ inteiro): %d \n", aux->preco);
        printf("┃ Data (DD/MM/AAAA): %s \n", aux->data);
        printf("└────────────────────────────────────────┘\n");
        printf("\n");
        a++;
        aux = aux->proximo; 

    } while (aux != haux && aux != NULL);
    printf("\nPressione ENTER para voltar ao menu.\n");
    getchar();
    getchar();
}

int inicil_lista(No **head){

    No *aux, *ahead = *head, *haux;

    *head = malloc(sizeof(No*));
    if(*head == NULL){
         printf("Falha na alocação de memória. Encerrando...\n");
         return 1;
    }

    aux = (*head);

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃              PASSAGEM AÉREA            ┃\n");
    printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
    printf("┃ Número do avião: ");
    scanf("%d%*c", &aux->Naviao);

    printf("┃ Cidade de saída: ");
    fgets(aux->saida , sizeof(aux->saida), stdin);
    aux->saida[strcspn(aux->saida,"\n")] = '\0';  // remove o '\n' se existir

    printf("┃ Destino: ");
    fgets(aux->destino, sizeof(aux->destino), stdin);
    aux->destino[strcspn(aux->destino, "\n")] = '\0';

    printf("┃ Preço (R$ inteiro): ");
    scanf("%d%*c", &aux->preco);

    printf("┃ Data (DD/MM/AAAA): ");
    fgets(aux->data, sizeof(aux->data), stdin);
    aux->data[strcspn(aux->data, "\n")] = '\0';

    printf("└────────────────────────────────────────┘\n");

    while (aux->proximo != ahead) {
        aux = aux->proximo;
    }
    aux->proximo = *head;
}

void remocao_inicil(No **head){

    
    No *headAtual = *head;              
    No *aux = headAtual;  
    if (headAtual->proximo == headAtual) {
        free(headAtual);
        *head = NULL;

        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃   Memória liberada com sucesso.      ┃\n");
        printf("┃   Itens excluídos.                   ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("\nPressione ENTER para voltar ao menu.\n");
        getchar();
        system("clear");

        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃            LISTA VAZIA               ┃\n");
        printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
        printf("┃ Você será redirecionado ao início    ┃\n");
        printf("┃ do sistema.                          ┃\n");
        printf("└──────────────────────────────────────┘\n");
        printf("\nPressione ENTER para voltar ao menu.\n");
        getchar();
        system("clear");
            
        return ;
    }   

     while (aux->proximo != headAtual) {
        aux = aux->proximo;
    }
    *head = headAtual->proximo;
    aux->proximo = *head;

    free(headAtual);
    headAtual = NULL;

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃   Memória liberada com sucesso.      ┃\n");
    printf("┃   Nó inicial removido.               ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\nPressione ENTER para voltar ao menu.\n");
    getchar();
    system("clear");
            
}
    
int final_lista(No *head){
    No *aux = head, *haux = head;

    while (aux->proximo != haux) {       
        aux = aux->proximo;
    }

    aux->proximo = malloc(sizeof(No));
    if(aux->proximo == NULL){
        printf("Falha na alocação de memória. Encerrando...\n");
        return 1;
    }

    aux = aux->proximo;

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃           PASSAGEM AÉREA %d             ┃\n");
    printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
    printf("┃ Número do avião: ");
    scanf("%d%*c", &aux->Naviao);

    printf("┃ Cidade de saída: ");
    fgets(aux->saida , sizeof(aux->saida), stdin);
    aux->saida[strcspn(aux->saida,"\n")] = '\0';  // remove o '\n' se existir

    printf("┃ Destino: ");
    fgets(aux->destino, sizeof(aux->destino), stdin);
    aux->destino[strcspn(aux->destino, "\n")] = '\0';

    printf("┃ Preço (R$ inteiro): ");
    scanf("%d%*c", &aux->preco);

    printf("┃ Data (DD/MM/AAAA): ");
    fgets(aux->data, sizeof(aux->data), stdin);
    aux->data[strcspn(aux->data, "\n")] = '\0';

    printf("└────────────────────────────────────────┘\n");
    
    aux->proximo = haux;

    return 0;
}   