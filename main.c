#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "");

    bool con = true;
    int op;
    while (con)
    {
        printf("MENU\n[ 1 ] Listar\n[ 2 ] Adiconar\n[ 3 ] Remover\n[ 4 ] Sair\nEscolha: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("LISTAR\n[ 1 ] Jogo\n[ 2 ] Publisher\n[ 3 ] User\n[ 4 ] Voltar ao Menu\nEscolha: ");
                scanf("%d", &op);
                break;

            case 2:
                break;

            case 3:
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
