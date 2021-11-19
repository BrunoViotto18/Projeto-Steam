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

    FILE *jogos;
    FILE *publishers;
    FILE *users;

    jogos = fopen("Teste.csv", "rt+");
    publishers = fopen("Publishers.csv", "rt+");
    users = fopen("Users.csv", "rt+");

    adicionar_linha(jogos, "Digital Devil Saga;RPG;20;8\n");


    /*bool con = true;
    int op;

    while (con)
    {
        printf("MENU\n[ 1 ] Listar \n[ 2 ] Adicionar \n[ 3 ] Remover \n[ 4 ] Sair \nEscolha: ");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {
            // --- LISTAR ---
            case 1:
                printf("LISTAR: \n[ 1 ] Jogos \n[ 2 ] Publishers \n[ 3 ] Usuários \n[ 4 ] Voltar ao menu \nEscolha: ");
                scanf("%d", &op);
                system("cls");
                switch(op)
                {
                    case 1:
                        printf("JOGOS\n\n");
                        listar_jogo(jogos);
                        getch();
                        system("cls");
                        break;

                    case 2:

                        printf("PUBLISHERS\n\n");
                        listar(publishers);
                        getch();
                        system("cls");
                        break;
                    case 3:
                        printf("USUÁRIOS\n\n");
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

            // --- ADICIONAR ---
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
                        printf("Adicionar JOGO\n");
                        printf("Nome: ");
                        fgets(nome, 128, stdin);
                        fgets(nome, 128, stdin);
                        printf("Genero: ");
                        fgets(genero, 128, stdin);
                        printf("Preço: ");
                        fgets(preco, 128, stdin);
                        printf("Avaliação: ");
                        fgets(avaliacao, 128, stdin);
                        //adicionar_jogo(jogos, nome, genero, preco, avaliacao);
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

            // --- REMOVER ---
            case 3:
                printf("REMOVER: \n[ 1 ] Jogos\n[ 2 ] Publishers \n[ 3 ] Usuários \n[ 4 ] Voltar ao  \nEscolha: ");
                scanf("%d", &op);
                system("cls");
                switch (op)
                {
                    case 1:
                        printf("JOGOS\n\n");

                        for (int i = 2; i < count_lines(jogos); i++)
                        {
                            char c[len_item(jogos, i, 1)];
                            get_item(jogos, i, 1, c);
                            printf("[ %d ] %s\n", i-1, c);
                            clear_array(c, len_item(jogos, i, 1));
                        }

                        printf("\nEscolha o jogo a ser removido: ");
                        scanf("%d", &op);
                        remover(jogos, op+1);
                        getch();
                        system("cls");
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

            // --- SAIR ---
            case 4:
                con = false;
                break;

            // --- DEFAULT ---
            default:
                printf("Opção inválida! Tente novamente.");
                break;
        }
    }*/

    fclose(jogos);
    fclose(publishers);
    fclose(users);

    return 0;
}
