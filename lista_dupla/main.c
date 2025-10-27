#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    struct Musica *atual = NULL, *playlist = NULL; //ponteiro para início da playlist
    int n;
    do {
        system("clear");
        printf("=============== MENU ===============\n");
        printf("[0] - Sair\n");
        printf("[1] - Inserir música no início\n");
        printf("[2] - Inserir música no final\n");
        printf("[3] - Remover primeira música\n");
        printf("[4] - Remover música atual\n");
        printf("[5] - Remover ultima música\n");
        printf("[6] - Buscar música\n");
        printf("[7] - Passar música\n");
        printf("[8] - Tocar música atual\n");
        printf("[9] - Voltar música\n");
        printf("[10] - Imprimir playlist\n");
        printf("====================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &n);
        switch(n){
            case 0:
                printf("Código finalizado!\n");
                break;
            
            case 1:
                inserir_inicio(&playlist);
                atual = playlist;
                break;

            case 2:
                inserir_final(&playlist);
                break;

            case 3:
                remover_inicio(&playlist);
                break;

            case 4:
                remover_atual(&atual, &playlist);
                break;

            case 5:
                remover_final(&playlist);
                break;

            case 6:
                buscar(&playlist);
                break;

            case 7:
                passar_musica(&atual);
                break;

            case 8:
                tocar_musica(&atual);
                break;

            case 9:
                voltar_musica(&atual);
                break;

            case 10:
                imprimir(playlist);
                break;

            default:
                printf("Valor Inválido!\n");
                printf("Pressione Enter para continuar\n");
                getchar(); getchar();
                break;
        }
    } while(n != 0);
    return 0;
}
