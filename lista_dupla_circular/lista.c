#include "lista.h"

void partialFrame() {
    system("clear");
    printf("+===================================+\n");
    printf("|ºººººº| Carrossel de Imagem |ºººººº|\n");
    printf("+===================================+\n");
}

int mainFrame(Node *head) {
    int choice;
    partialFrame();
    printf("[0] -> Sair\n");
    printf("[1] -> Adicionar\n");
    printf("[2] -> Remover\n");
    printf("[3] -> Buscar\n");
    printf("[4] -> Exibir\n");
    printf("+===================================+\n");
    printf("Digite: ");
    scanf("%d", &choice);
    if (choice == 1) {
        system("clear");
        partialFrame();
        printf("[1] -> Adicionar no inicio\n");
        printf("[2] -> Adicionar no fim\n");
        printf("+===================================+\n");
        printf("Digite: ");
        scanf("%d", &choice);
        if (choice == 1) {
            return 1;
        } else {
            return 5;
        }
    }
    if (head == NULL && choice != 0) {
        printf("Lista vazia..\n");
        printf("Utilize a funcao de adicionar!\n");
        return 7;
    }
    if (choice == 2) {
        system("clear");
        partialFrame();
        printf("[1] -> Remover do inicio\n");
        printf("[2] -> Remover do fim\n");
        printf("+===================================+\n");
        printf("Digite: ");
        scanf("%d", &choice);
        if (choice == 1) {
            return 2;
        } else {
            return 6;
        }
    }
}

void create(Node **head, char label[]) {
    Node *tmp;
    tmp = malloc(sizeof (Node *));
    if (tmp == NULL) {
        printf("Erro de alocacao...\n");
        return;
    }
    (*head) = tmp;
    strcpy((*head)->label, label);
    (*head)->prev = (*head);
    (*head)->next = (*head);
    printf("Adicionado com sucesso!\n");
}

void addBeg(Node **head, char label[]) {
    Node *node, *tmp, *aux;
    if ((*head) == NULL) {
        create(&(*head), label);
        return;
    }
    tmp = malloc(sizeof (Node *));
    if (tmp == NULL) {
        printf("Erro de alocacao...\n");
        return;
    }
    node = tmp;
    strcpy(node->label, label);
    node->next = (*head);
    node->prev = (*head)->prev;
    aux = node->prev;
    aux->next = node;
    (*head)->prev = node;
    (*head) = node;
    printf("Adicionado com sucesso!\n");
}

void addEnd(Node **head, char label[]) {
    Node *node, *tmp, *aux;
    if ((*head) == NULL) {
        create(&(*head), label);
        return;
    }
    tmp = malloc(sizeof (Node *));
    if (tmp == NULL) {
        printf("Erro de alocacao...\n");
        return;
    }
    node = tmp;
    strcpy(node->label, label);
    node->next = (*head);
    node->prev = (*head)->prev;
    aux = (*head)->prev;
    aux->next = node;
    (*head)->prev = node;
    printf("Adicionado com sucesso!\n");
}

void rmBeg(Node **head) {
    Node *node;
    if ((*head)->next == (*head)) {
        free((*head));
        (*head) = NULL;
        printf("Espaco liberado na memoria...\n");
        printf("Lista deletada com sucesso!\n");
        return;
    }
    node = (*head)->next;
    node->prev = (*head)->prev;
    node = (*head)->prev;
    node->next = (*head)->next;
    free((*head));
    (*head) = node->next;
    printf("Removido com sucesso!\n");
}

void rmEnd(Node **head) {
    Node *node;
    if ((*head)->next == (*head)) {
        free((*head));
        (*head) = NULL;
        printf("Espaco liberado na memoria...\n");
        printf("Lista deletada com sucesso!\n");
        return;
    }
    node = (*head)->prev;
    node = node->prev;
    node->next = (*head);
    free((*head)->prev);
    (*head)->prev = node;
}

void search(Node *head, char label[]) {
    Node *node = head;
    int cnt = 0;
    do {
        if (strcmp(node->label, label) == 0) {
            cnt++;
        }
        node = node->next;
    } while (node != head);

    if (cnt > 0) {
        printf("%s esta na lista!\n", label);
        printf("Aparece %d vezes...\n", cnt);
    } else {
        printf("%s nao esta na lista!\n", label);
    }
}

void print01() {
    printf("           .--.          \n");
    printf("          |o_o |         \n");
    printf("          |:_/ |         \n");
    printf("         //   \\ \\       \n");
    printf("        (|     | )      \n");
    printf("       /'\\_   _/'\\     \n");
    printf("       \\___)=(___/      \n\n");
}

void print02() {
    printf("                       \n");
    printf("          /\\_/\\      \n");
    printf("         ( o.o )       \n");
    printf("          > ^ <       \n\n");
}

void print03() {
    printf("          ,     ,        \n");
    printf("         (\\____/)      \n");
    printf("          (_oo_)         \n");
    printf("            (O)          \n");
    printf("          __||__    \\)  \n");
    printf("       []/______\\[] /   \n");
    printf("       / \\______/ \\/   \n");
    printf("      /    /__\\        \n");
    printf("     (\\   /____\\       \n\n");
}

void show(Node *head) {
    Node *node = head;
    int choice, simbol, no = 0;
    partialFrame();
    printf("Selecione um modo de exibicao: \n");
    printf("[1] - Navegacao\n");
    printf("[2] - Automatico\n");
    printf("+===================================+\n");
    printf("Digite: ");
    scanf("%d", &choice);
    if (choice == 1) {
        do {
            partialFrame();
            printf("Nome: %s\n", node->label);
            if (no == 0) {
                print01();
                no++;
            } else if (no == 1) {
                print02();
                no++;
            } else {
                print03();
                no = 0;
            }
            printf("[1] Retroceder\n");
            printf("[2] Avancar\n");
            printf("[0] Parar\n\n");
            printf("Digite: ");
            scanf("%d", &simbol);
            if (simbol == 2){
                node = node->next;
            } else if (simbol == 1) {
                node = node->prev;
            } else {
                choice = 0;
            }
        } while (choice != 0);

        return;
    }

    do {
        partialFrame();
        printf("Nome: %s\n", node->label);
        if (no == 0) {
            print01();
            no++;
        } else if (no == 1) {
            print02();
            no++;
        } else {
            print03();
            no = 0;
        }
        fflush(stdout);
        sleep(TIME);
        node = node->next;
    } while (node != head);
}