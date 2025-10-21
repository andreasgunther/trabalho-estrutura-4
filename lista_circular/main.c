#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main(){
    
    No *head = NULL;
    int c = 0, i = -1;

    while (c == 0){
        switch (menu(head,i)){
        case 1:
            int valor = 0;
            valor = criar_lista(&head);
            if(valor > 0){
                printf("Resultado do sistema: %d\n", valor);
                c = 1;
            }
            break;;
        case 2:
            listar(&head);
            break;
        case 3:
            valor = inicil_lista(&head);
            if(valor > 0){
                printf("Resultado do sistema: %d\n", valor);
            }
            break;
        case 4:
            remocao_inicil(&head);
            break;
        case 5:
            valor = final_lista(head);
            if(valor > 0){
                printf("Resultado do sistema: %d\n", valor);
            }
            break;
        case 6:
            remocao_final(&head);
            break;
         case 7:
            busca_aviao(&head);
            break;
        case 8:
            exibir(head);
            break;
        case 0:
            c = 2;
            break;
        default:
            printf("Valor inválido. Por favor, tente novamente.\n");
            break;
        }
    }
    if(c == 2){
        printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃    Obrigado por usar nosso sistema!  ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    }
}
