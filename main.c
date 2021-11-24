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

    FILE *arq_jogos;
    FILE *arq_publishers;
    FILE *arq_users;

    arq_jogos = fopen("Teste2.csv", "rt+");
    arq_publishers = fopen("Publishers.csv", "rt+");
    arq_users = fopen("Users.csv", "rt+");

    GameNode lista_games[1024];
    PublisherNode lista_publishers[1024];
    UserNode lista_users[1024];


    /*for (int i = 0; i < 1024; i++)
    {
        lista_games[i] = NULL;
        lista_publishers[i] = NULL;
        lista_users[i] = NULL;
    }*/

    bool con = true;
    int op;

    while (con)
    {
        printf("MENU \n\n[ 1 ] Listar \n[ 2 ] Adicionar \n[ 3 ] Salvar \n[ 4 ] Comprar Jogo \n[ 5 ] Remover \n[ 6 ] Sair \n\nOpção: ");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {

            // --- LISTAR ---

            case 1:
                printf("LISTAR: \n\n[ 1 ] Jogos \n[ 2 ] Publishers \n[ 3 ] Usuários \n[ 4 ] Voltar ao menu \n\nOpção: ");
                fget("%d", &op);
                system("cls");

                switch(op)
                {
                    case 1:
                        printf("JOGOS\n\n");
                        print_games(arq_jogos);
                        getch();
                        system("cls");
                        break;

                    case 2:
                        printf("PUBLISHERS\n\n");
                        print_publishers_users(arq_publishers);
                        getch();
                        system("cls");
                        break;

                    case 3:
                        printf("USUÁRIOS\n\n");
                        print_publishers_users(arq_users);
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
                printf("ADICIONAR: \n\n[ 1 ] Jogo \n[ 2 ] Publisher \n[ 3 ] Usuário \n[ 4 ] Voltar ao menu \n\nOpção: ");
                scanf("%d", &op);
                system("cls");

                switch(op)
                {
                    char nome[64];
                    char genero[64];
                    double preco;

                    case 1:
                        printf("Nome: ");
                        fgetc(stdin);
                        fgets(nome, 64, stdin);
                        printf("Gênero: ");
                        fgets(genero, 64, stdin);
                        printf("Preço: ");
                        scanf("%f", &preco);
                        printf("%s %s %f", nome, genero, preco);
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



            // --- SALVAR ---

            case 3:
                printf("SALVAR: \n\n[ 1 ] Jogos \n[ 2 ] Publishers \n[ 3 ] Usuários \n[ 4 ] Voltar ao menu \n\nOpção: ");
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



            // -- COMPRAR JOGO --

            case 4:
                break;



            // --- REMOVER ---

            case 5:
                printf("REMOVER: \n\n[ 1 ] Jogos\n[ 2 ] Publishers \n[ 3 ] Usuários \n[ 4 ] Voltar ao Menu \n\nOpção: ");
                scanf("%d", &op);
                system("cls");
                switch (op)
                {
                    case 1:
                        printf("JOGOS\n\n");

                        for (int i = 2; i < count_lines(arq_jogos); i++)
                        {
                            char c[len_item(arq_jogos, i, 1)];
                            get_item(arq_jogos, i, 1, c);
                            printf("[ %d ] %s\n", i-1, c);
                            clear_array(c, len_item(arq_jogos, i, 1));
                        }

                        printf("\nEscolha o jogo a ser removido: ");
                        scanf("%d", &op);
                        remove_line(arq_jogos, op+1);
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

            case 6:
                con = false;
                break;



            // --- DEFAULT ---

            default:
                printf("Opção inválida! Tente novamente.");
                break;
        }
    }

    fclose(arq_jogos);
    fclose(arq_publishers);
    fclose(arq_users);

    return 0;
}
