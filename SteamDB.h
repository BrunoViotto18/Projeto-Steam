#ifndef STEAMDB_H_INCLUDED
#define STEAMDB_H_INCLUDED

#include <string.h>
#include <locale.h>

/*struct Game
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
};*/

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

void seek_line(FILE *arq, int linha_index)
{
    rewind(arq);
    int counter = 1;
    while(counter < linha_index)
    {
        if(fgetc(arq) == '\n')
        {
            counter++;
        }
    }
}

int len_line(FILE *arq, int linha_index)
{
    rewind(arq);
    char *linha;
    for (int i = 1; i < linha_index; i++)
    {
        fgets(linha, 1024, arq);
    }
    fgets(linha, 1024, arq);
    int index = 0;
    seek_line(arq, linha_index);
    for (int i = 0; i < 1024; i++)
    {
        char c = fgetc(arq);
        if (c == '\n' || c == EOF)
        {
            return index;
        }
        index++;
    }
    return -1;
}

char* get_line(FILE *arq, int linha_index)
{
    rewind(arq);
    char *linha;
    for (int i = 1; i < linha_index; i++)
    {
        fgets(linha, 1024, arq);
    }
    fgets(linha, 1024, arq);
    return linha;
}

count_collumns(FILE* arq)
{
    rewind(arq);
    int counter = 1;
    while(true)
    {
        char c = fgetc(arq);
        if (c == '\n' || c == EOF)
        {
            break;
        }
        else if (c == ';')
        {
            counter++;
        }
    }
    return counter;
}

int count_lines(FILE* arq)
{
    rewind(arq);
    int counter = 1;
    char* linha;
    while(true)
    {
        char c = fgetc(arq);
        if (c == '\n')
        {
            counter += 1;
        }
        else if (c == EOF)
        {
            break;
        }
    }
    return counter;
}

char* get_item(FILE *arq, int line, int collumn, char* vetor)
{
    rewind(arq);
    seek_line(arq, line);
    int counter = 1;
    while (counter < collumn)
    {
        if (fgetc(arq) == ';')
        {
            counter++;
        }
    }
    int i = 0;
    while (true)
    {
        char c = fgetc(arq);
        if (c == ';' || c == '\n')
        {
            break;
        }
        vetor[i] = c;
        i++;
    }
    return vetor;
}

void listar(FILE *arq)
{
    setlocale(LC_ALL, "");
    rewind(arq);
    int linhas = count_lines(arq);
    int colunas = count_collumns(arq);

    for (int i = 2; i < linhas; i++)
    {
        for (int j = 1; j <= colunas; j++)
        {
            char chave[128];
            char valor[128];
            get_item(arq, 1, j, chave);
            get_item(arq, i, j, valor);
            printf("%s: %s\t", chave, valor);
            for (int k = 0; k < 128; k++)
            {
                chave[k] = '\0';
                valor[k] = '\0';
            }
        }
        printf("\n\n");
    }
}

void adicionar_jogo(FILE *arq, char* nome, char* genero, char* preco, char* avaliacao)
{
    seek_line(arq, count_lines(arq));
    fputs(nome, arq);
    fputs(";", arq);
    fputs(genero, arq);
    fputs(";", arq);
    fputs(preco, arq);
    fputs(";", arq);
    fputs(avaliacao, arq);
    fputs("\n", arq);
    fprintf(arq, "%s;%s;%s;%s", nome, genero, preco, avaliacao);
}

void adicionar_cliente(FILE *arq)
{

}

#endif // STEAMDB_H_INCLUDED
