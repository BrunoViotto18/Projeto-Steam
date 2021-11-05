#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "SteamDB.h"

void main()
{
    setlocale(LC_ALL, "");

    FILE *jogos;
    FILE *publishers;
    FILE *users;

    jogos = fopen("Games.csv", "rt");
    publishers = fopen("Publishers.csv", "rt");
    users = fopen("Users.csv", "rt");

    bool con = true;
    int op;
    char caminho[100];
    while (con)
    {
        printf("MENU\n[ 1 ] Listar \n[ 2 ] Adicionar \n[ 3 ] Remover \n[ 4 ] Sair \nEscolha: ");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {
            case 1:
                printf("LISTAR: \n[ 1 ] Jogos \n[ 2 ] Publishers \n[ 3 ] Usuários \n[ 4 ] Voltar ao menu \nEscolha: ");
                scanf("%d", &op);
                system("cls");
                switch(op)
                {
                    case 1:
                        printf("\t\t\t\tJOGOS\n\n");
                        listar(jogos);
                        getch();
                        system("cls");
                        break;

                    case 2:

                        printf("\t\t\t\tPUBLISHERS\n\n");
                        listar(publishers);
                        getch();
                        system("cls");
                        break;
                    case 3:

                        printf("\t\t\t\tUSUÁRIOS\n\n");
                        listar(users);
                        getch();
                        system("cls");
                        break;

                    case 4:
                        system("cls");
                        break;

                    default:
                        printf("Opção Inválida!");
                        getch();
                        system("cls");
                        break;
                }
                break;

            case 2:
                printf("ADICIONAR: \n[ 1 ] Jogos\n[ 2 ] Publishers \n[ 3 ] Usuários \n[ 4 ] Voltar ao menu \nEscolha: ");
                scanf("%d", &op);
                system("cls");
                switch(op)
                {
                        char nome[128];
                        char genero[128];
                        char preco[128];
                        char avaliacao[128];
                    case 1:
                        printf("Adicionar JOGO");
                        printf("Nome: ");
                        fgets(nome, 128, stdin);
                        printf("Genero: ");
                        fgets(genero, 128, stdin);
                        printf("Preço: ");
                        fgets(preco, 128, stdin);
                        printf("Avaliação: ");
                        fgets(avaliacao, 128, stdin);
                        adicionar_jogo(jogos, nome, genero, preco, avaliacao);
                        break;

                    case 2:
                        break;

                    case 3:
                        break;

                    case 4:
                        system("cls");
                        break;

                    default:
                        printf("Opção Inválida!");
                        getch();
                        system("cls");
                        break;
                }
                break;

            case 3:
                printf("REMOVER: \n[ 1 ] Jogos\n[ 2 ] Publishers \n[ 3 ] Usuários \n[ 4 ] Voltar ao  \nEscolha: ");
                scanf("%d", &op);
                system("cls");
                break;

            case 4:
                con = false;
                break;

            default:
                printf("Opção inválida! Tente novamente.");
                break;
        }
    }
    fclose(jogos);
    fclose(publishers);
    fclose(users);
}
