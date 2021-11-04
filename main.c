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
    bool con = true;
    int op;
    char caminho[100] = "games.txt";
    char caminho2[100] = "publishers.txt";
    char caminho3[100] = "usuarios.txt";
    while (con)
    {
        printf("MENU\n[ 1 ] Listar\n[ 2 ] Adicionar\n[ 3 ] Remover\n[ 4 ] Sair\nEscolha:\n");
        scanf("%d", &op);


        switch (op)
        {
            case 1:
                printf("LISTAR: \n[ 1 ] Jogos \n[ 2 ] Publishers \n[ 3 ] Usuarios \n \n[ 4 ] Voltar ao menu\nEscolha:\n");
                scanf("%d", &op);
                switch(op)
                {
                case 1:
                    Le_Arq(caminho);
                    break;

                case 2:
                    Le_Arq2(caminho2);
                    break;
                case 3:
                    Le_Arq3(caminho3);
                    break;
                case 4:
                    break;
                }
                break;

            case 2:
                printf("ADICIONAR: \n[ 1 ] Jogos \n[ 2 ] Publishers \n[ 3 ] Usuarios \n \n[ 4 ] Voltar ao menu\nEscolha:\n");
                break;

            case 3:
                printf("REMOVER: \n[ 1 ] Jogos \n[ 2 ] Publishers \n[ 3 ] Usuarios \n[ 4 ] Voltar ao menu\nEscolha:\n");
                break;

            case 4:
                con = false;
                break;

            default:
                printf("Opção inválida! Tente novamente.");
                break;
        }
    }
}
