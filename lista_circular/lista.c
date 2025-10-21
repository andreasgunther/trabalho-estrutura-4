#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include "lista.h"
#include <sys/types.h>

static int enter_pressed_now(void){
    struct timeval tv;
    fd_set rfds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds); 
    if (select(1, &rfds, NULL, NULL, &tv) > 0) {
        int c = getchar(); 
        return (c == '\n' || c == '\r');
    }
    return 0;
}

static void drain_stdin(void){
    struct timeval tv;
    fd_set rfds;
    for(;;){
        tv.tv_sec = 0;
        tv.tv_usec = 0;
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        if (select(1, &rfds, NULL, NULL, &tv) > 0) {
            int c = getchar();
            if (c == EOF) break;
        } else {
            break;
        }
    }
}

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
    printf("┃ 8) Exibir passagem                                ┃\n");
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
    printf("┃             PASSAGEM AÉREA             ┃\n");
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

void remocao_final(No **head){
    No *aux = *head;
    No *prev = NULL;

    if (aux->proximo == *head) {
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

    while (aux->proximo != *head) {
        prev = aux;
        aux = aux->proximo;
    }
    prev->proximo = *head;  
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

void busca_aviao(No **head){
     system("clear");
    int a = 1;
    No *aux = *head;

    printf("Número do avião: ");
    scanf("%d%*c", &a);

    do{
        if(aux->Naviao == a){
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
            printf("\nPressione ENTER para voltar ao menu.\n");
            getchar();
            return;
        }
        aux = aux->proximo; 
    } while (aux->proximo != *head && aux != NULL);
    

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃  ESTE AVIÃO NÃO CONSTA NA LISTA DE VOOS  ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\nPressione ENTER para voltar ao menu.\n");
    getchar();
    return;
}

void exibir(No *head){
    system("clear");

    if (!head){
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃  ESTE AVIAO NAO CONSTA NA LISTA DE VOOS  ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("\nPressione ENTER para voltar ao menu.\n");
        while (getchar() != '\n');
        return;
    }

    drain_stdin();

    No *cur = head;
    int a = 1;
    const useconds_t delay_us = 4000000; 

    printf("Carrossel simples - pressione ENTER para parar.\n");
    usleep(3000000);

    for(;;){
        system("clear");

        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃           PASSAGEM AEREA %d             ┃\n", a);
        printf("┡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┩\n");
        printf("┃ Numero do aviao: %d \n",  cur->Naviao);
        printf("┃ Cidade de saida: %s \n",  cur->saida);
        printf("┃ Destino: %s \n",          cur->destino);
        printf("┃ Preco (R$ inteiro): %d \n", cur->preco);
        printf("┃ Data (DD/MM/AAAA): %s \n", cur->data);
        printf("└────────────────────────────────────────┘\n");
        printf("\n(Aperte ENTER para encerrar o carrossel)\n");

        if (enter_pressed_now()){
            printf("\nEncerrado pelo usuario.\n");
            break;
        }

        usleep(delay_us);
        cur = (cur->proximo ? cur->proximo : head);
        a = (cur == head) ? 1 : (a + 1);
    }
}