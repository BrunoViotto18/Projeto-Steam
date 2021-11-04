#ifndef STEAMDB_H_INCLUDED
#define STEAMDB_H_INCLUDED
//#define <string.h>

struct Game
{
    char nome[100];
    char genero[100];
    double preco;
    int avaliacao;
};

struct Publisher
{
    char nome[100];
    struct Game lista[100];
};

struct User
{
    char userName[100];
    struct Game biblioteca[100];
};

 /*Le_Arq(char[])
{
    FILE *arq;
    char linha[100];
    char *result;
    int row = 0;
    int column = 0;
    arq = fopen(char[], "read");

    if(!arq)
    {
        printf("Não foi possível ler o arquivo");
    }
    while (fgets(linha,
                     100, arq)) {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(linha, ";");

            while (value) {
                // Column 1
                if (column == 0) {
                    printf("Nome:");
                }

                // Column 2
                if (column == 1) {
                    printf("\tPublisher:");
                }

                // Column 3
                if (column == 2) {
                    printf("\tGenero:");
                }

                printf("%s", value);
                value = strtok(NULL, ";");
                column++;
            }

            printf("\n");
        }

        // Close the file
        fclose(fp);
    }
}*/



int len_line(FILE *arq, int linha_index)
{
    char *linha;
    for (int i = 1; i <= linha_index; i++)
    {
        fgets(linha, 1024, arq);
    }
    fgets(linha, 1024, arq);
    int index = 0;
    for (int i = 0; i < 1024; i++)
    {
        if (strcmp(linha[i], "\\") == 0 && strcmp(linha[i+1], "n") == 0)
        {
            return index;
        }
        printf("AAAAA");
        index++;
    }
    return -1;
}

char* get_line(FILE *arq, int linha_index)
{
    char *linha;
    for (int i = 1; i <= linha_index; i++)
    {
        fgets(linha, 1024, arq);
    }
    fgets(linha, 1024, arq);
    return linha;
}

#endif // STEAMDB_H_INCLUDED
