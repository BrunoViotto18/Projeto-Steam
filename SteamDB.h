#ifndef STEAMDB_H_INCLUDED
#define STEAMDB_H_INCLUDED

#include <string.h>
#include <locale.h>

struct Game
{
    char* nome;
    char* genero[100];
    double preco;
    int avaliacao;
};

/*
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
    int cursor = 0;

    while(counter < linha_index)
    {
        cursor++;
        if(fgetc(arq) == '\n')
        {
            cursor++;
            counter++;
        }
    }

    fseek(arq, cursor, SEEK_SET);
}

//Retorna o tamanho de uma das linhas do arquivo
int len_line(FILE *arq, int linha_index)
{
    int cursor = ftell(arq);

    rewind(arq);
    char linha[1024];

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
            fseek(arq, cursor, SEEK_SET);
            return index;
        }
        index++;
    }

    fseek(arq, cursor, SEEK_SET);
    return -1;
}

//Retorna a string da linha desejada
void get_line(FILE *arq, int linha_index, char* linha)
{
    int cursor = ftell(arq);

    rewind(arq);
    seek_line(arq, linha_index);

    for (int i = 0; i < len_line(arq, linha_index); i++)
    {
        linha[i] = fgetc(arq);
    }

    fseek(arq, cursor, SEEK_SET);
}

//Retorna o número de colunas do arquivo CSV
int count_collumns(FILE* arq, int linha)
{
    int cursor = ftell(arq);

    seek_line(arq, linha);
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

    fseek(arq, cursor, SEEK_SET);
    return counter;
}

//Retorna o número de linhas de um arquivo
int count_lines(FILE* arq)
{
    int cursor = ftell(arq);

    rewind(arq);
    int counter = 1;

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

    fseek(arq, cursor, SEEK_SET);
    return counter;
}

//Retorna o temanho do item referente a linha e coluna fornecidas;
int len_item(FILE* arq, int line, int collumn)
{
    int cursor = ftell(arq);

    int counter = 1;
    seek_line(arq, line);

    while (counter < collumn)
    {
        if (fgetc(arq) == ';')
        {
            counter++;
        }
    }

    counter = 0;
    while (true)
    {
        char c = fgetc(arq);
        if (c == ';' || c == '\n' || c == EOF)
        {
            break;
        }
        counter++;
    }

    fseek(arq, cursor, SEEK_SET);
    return counter;
}

//Retorna o item referente a linha e coluna fornecida
void get_item(FILE *arq, int line, int collumn, char* vetor)
{
    int cursor = ftell(arq);

    seek_line(arq, line);
    int counter = 1;

    while (counter < collumn)
    {
        char c = fgetc(arq);
        if (c == ';')
        {
            counter++;
        }
    }

    int i = 0;

    while(true)
    {
        char c = fgetc(arq);
        if (c == ';' || c == '\n' || c == EOF)
        {
            break;
        }
        vetor[i] = c;
        i++;
    }

    fseek(arq, cursor, SEEK_SET);
}

//Retorna o número de caracateres de um arquivo (incluindo "\n" e "EOF")
int length(FILE* arq)
{
    int cursor = ftell(arq);

    int counter = 0;
    rewind(arq);

    while (!feof(arq))
    {
        fgetc(arq);
        counter++;
    }

    fseek(arq, cursor, SEEK_SET);
    return counter;
}

//Retorna uma string do arquivo de texto fornecido (incluindo caracters como "\n" e "EOF")
void get_file(FILE* arq, char* txt, int linha_index)
{
    int cursor = ftell(arq);

    seek_line(arq, linha_index);
    int counter = 0;

    while (!feof(arq))
    {
        txt[counter] = fgetc(arq);
        counter++;
    }

    txt[counter] = fgetc(arq);

    fseek(arq, cursor, SEEK_SET);
}

int length_until(FILE* arq, int linha_index)
{
    int cursor = ftell(arq);

    int counter = 0;
    int linha = 0;

    while (linha < linha_index)
    {
        char c = fgetc(arq);
        counter++;

        if (c == '\n' || c == EOF)
        {
            linha++;
        }
    }

    fseek(arq, cursor, SEEK_SET);
    return counter;
}

void get_file_until(FILE* arq, char* txt, int linha_index)
{
    int cursor = ftell(arq);

    int counter = 0;
    int linha = 0;

    while (linha < linha_index)
    {
        char c = fgetc(arq);
        txt[counter] = c;
        counter++;

        if (c == '\n' || c == EOF)
        {
            linha++;
        }
    }

    fseek(arq, cursor, SEEK_SET);
}

//Limpa um array
void clear_array(char* vetor, int len)
{
    for (int i = 0; i < len+1; i++)
    {
        vetor[i] = '\0';
    }
}


//Printa o arquivo CSV jogos na tela
void listar_jogo(FILE *arq)
{
    setlocale(LC_ALL, "");
    int cursor = ftell(arq);

    rewind(arq);
    int linhas = count_lines(arq);
    int colunas = count_collumns(arq, 1);

    for (int i = 2; i < linhas; i++)
    {
        for (int j = 1; j <= colunas; j++)
        {
            char chave[len_item(arq, 1, j)];
            char valor[len_item(arq, i, j)];

            get_item(arq, 1, j, chave);
            get_item(arq, i, j, valor);
            printf("%s: %s\n", chave, valor);

            clear_array(chave, len_item(arq, 1, j));
            clear_array(valor, len_item(arq, i, j));
        }
        printf("\n");
    }

    fseek(arq, cursor, SEEK_SET);
}

//Lista o arquivo CSV publishers e users na tela
void listar(FILE* arq)
{
    setlocale(LC_ALL, "");
    int cursor = ftell(arq);

    rewind(arq);
    int linhas = count_lines(arq);

    for (int i = 1; i < linhas; i++)
    {
        for (int j = 1; j <= count_collumns(arq, i); j++)
        {
            char c[len_item(arq, i, j)];
            get_item(arq, i, j, c);

            if (j == 1)
            {
                printf("%s\n", c);
            }
            else
            {
                printf("%d - %s\n", j-1, c);
            }
            clear_array(c, len_item(arq, i, j));
        }
        printf("\n");
    }

    fseek(arq, cursor, SEEK_SET);
}

void remover(FILE* arq, int linha)
{
    int cursor = ftell(arq);

    seek_line(arq, linha);
    fseek(arq, 0, SEEK_CUR);

    while(true)
    {
        char c = fgetc(arq);

        printf("%c", c);
        if (c == '\n' || c == EOF)
        {
            fprintf(arq, "\n");
            break;
        }

        fseek(arq, -1, SEEK_CUR);
        fprintf(arq, "");
        fseek(arq, +1, SEEK_CUR);
    }

    fseek(arq, cursor, SEEK_SET);
}


#endif // STEAMDB_H_INCLUDED
