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
        printf("MENU \n\n[ 1 ] Listar \n[ 2 ] Adicionar \n[ 3 ] Salvar \n[ 4 ] Comprar Jogo \n[ 5 ] Remover \n[ 6 ] Sair \n\nOp��o: ");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {

            // --- LISTAR ---

            case 1:
                printf("LISTAR: \n\n[ 1 ] Jogos \n[ 2 ] Publishers \n[ 3 ] Usu�rios \n[ 4 ] Voltar ao menu \n\nOp��o: ");
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
                        printf("USU�RIOS\n\n");
                        print_publishers_users(arq_users);
                        getch();
                        system("cls");
                        break;

                    case 4:
                        system("cls");
                        break;

                    default:
                        printf("Op��o Inv�lida!");
                        getch();
                        system("cls");
                        break;
                }
                break;



            // --- ADICIONAR ---

            case 2:
                printf("ADICIONAR: \n\n[ 1 ] Jogo \n[ 2 ] Publisher \n[ 3 ] Usu�rio \n[ 4 ] Voltar ao menu \n\nOp��o: ");
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
                        printf("G�nero: ");
                        fgets(genero, 64, stdin);
                        printf("Pre�o: ");
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
                        printf("Op��o Inv�lida!");
                        getch();
                        system("cls");
                        break;
                }
                break;



            // --- SALVAR ---

            case 3:
                printf("SALVAR: \n\n[ 1 ] Jogos \n[ 2 ] Publishers \n[ 3 ] Usu�rios \n[ 4 ] Voltar ao menu \n\nOp��o: ");
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
                        printf("Pre�o: ");
                        fgets(preco, 128, stdin);
                        printf("Avalia��o: ");
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
                        printf("Op��o Inv�lida!");
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
                printf("REMOVER: \n\n[ 1 ] Jogos\n[ 2 ] Publishers \n[ 3 ] Usu�rios \n[ 4 ] Voltar ao Menu \n\nOp��o: ");
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
                        printf("Op��o Inv�lida!");
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
                printf("Op��o inv�lida! Tente novamente.");
                break;
        }
    }

    fclose(arq_jogos);
    fclose(arq_publishers);
    fclose(arq_users);

    return 0;
}
