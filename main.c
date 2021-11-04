#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "SteamDB.h"

int main()
{
    setlocale(LC_ALL, "");

    FILE *arq;

    arq = fopen("Games.csv", "rt");

    printf("%s", get_line(arq, 5));

    /*bool con = true;
    int op;
    char caminho[100];
    while (con)
    {
        printf("MENU\n[ 1 ] Listar\n[ 2 ] Adicionar\n[ 3 ] Remover\n[ 4 ] Sair\nEscolha: ");
        scanf("%d", &op);


        switch (op)
        {
            case 1:
                printf("ADICIONAR: \n[ 1 ] Jogos \n[ 2 ] Publoishers \n[ 3 ] Usuarios \n \n[ 4 ] Voltar ao menu\nEscolha");
                scanf("%d", &op);
                switch(op)
                {
                case 1:
                    //caminho = "games.csv";
                    //Le_arq(caminho);
                    break;

                case 2:
                    caminho = "games.csv";
                    Le_arq(caminho);
                    break;
                case 4:
                    caminho = "games.csv";
                    Le_arq(caminho);
                    break;
                }
                break;

            case 2:
                printf("ADICIONAR: \n[ 1 ] Jogos \n[ 2 ] Publoishers \n[ 3 ] Usuarios \n \n[ 4 ] Voltar ao menu\nEscolha");
                break;

            case 3:
                printf("REMOVER: \n[ 1 ] Jogos \n[ 2 ] Publoishers \n[ 3 ] Usuarios \n \n[ 4 ] Voltar ao menu\nEscolha");
                break;

            case 4:
                con = false;
                break;

            default:
                printf("Opção inválida! Tente novamente.");
                break;
        }
    }*/
}
