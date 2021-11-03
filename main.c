#include <stdio.h>
#include <stdlib.h>

int main()
{
    bool con = true;
    int op;
    while (con)
    {
        printf(
        "MENU\n" +
        "[ 1 ] Listar\n" +
        "[ 2 ] Adiconar\n" +
        "[ 3 ] Remover\n" +
        "[ 4 ] Sair");
        scanf("%d", &op)

        switch (op)
        {
            case 1:
                printf(
                "MENU\n" +
                "[ 1 ] Jogo\n" +
                "[ 2 ] Publisher\n" +
                "[ 3 ] User\n" +
                "[ 4 ] Voltar ao Menu");
                scanf("%d", &op)
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

    return 0;
}
