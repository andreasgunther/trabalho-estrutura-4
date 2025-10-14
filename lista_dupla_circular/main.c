#include "lista.h"

int main(void) {
    int choice = 0;
    char label[SIZE];
    Node *head = NULL;
    while (choice != 1) {
        switch(mainFrame(head)) {
        case 0:
            choice = 1;
            break;
        case 1:
            printf("Digite o nome do arquivo: ");
            scanf("%s", label);
            addBeg(&head, label);
            break;
        case 2:
            rmBeg(&head);
            break;
        case 3:
            printf("Digite o nome do arquivo: ");
            scanf("%s", label);
            search(head, label);
            break;
        case 4:
            show(head);
            break;
        case 5:
            printf("Digite o nome do arquivo: ");
            scanf("%s", label);
            addEnd(&head, label);
            break;
        case 6:
            rmEnd(&head);
            break;
        default:
            break;
        }
        printf("Pressione [ENTER] para continuar");
        getchar();
        getchar();
    }

    return 0;
}