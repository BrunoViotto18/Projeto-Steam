#ifndef STEAMDB_H_INCLUDED
#define STEAMDB_H_INCLUDED

#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct
{
    char* nome[64];
    char* genero[64];
    double preco;
    int estrelas;
    int avaliacoes;
} Game;

typedef struct
{
    Game* game;
    bool null;
} GameNode;


typedef struct
{
    char nome[64];
    Game lista[1024];
} Publisher;

typedef struct
{
    Publisher* publisher;
    bool null;
} PublisherNode;


typedef struct
{
    char userName[64];
    Game biblioteca[1024];
} User;

typedef struct
{
    User* user;
    bool null;
} UserNode;


// Posiciona o cursor no começo de uma linha
void seek_line(FILE *arq, int linha_index)
{
    rewind(arq);

    int counter = 1;
    int cursor = 0;

    while(counter < linha_index)
    {
        cursor++;
        char c = fgetc(arq);
        if(c == '\n' || c == EOF)
        {
            cursor++;
            counter++;
        }
    }

    fseek(arq, cursor, SEEK_SET);
}

// Retorna o tamanho de uma das linhas do arquivo
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

// Armazena a string da linha desejada
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

// Retorna o número de colunas do arquivo CSV
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

// Retorna o número de linhas de um arquivo
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

// Retorna o temanho do item referente a linha e coluna fornecidas;
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

// Retorna o item referente a linha e coluna fornecida
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

    vetor[i] = '\0';

    fseek(arq, cursor, SEEK_SET);
}

// Retorna o número de caracateres de um arquivo (incluindo "\n" e "EOF")
int character_length(FILE* arq)
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

// Retorna uma string do arquivo de texto fornecido (incluindo caracters como "\n" e "EOF")
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

// Retorna a quantidade de caracteres de um arquivo até uma certa linha
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

// Armazena as primeiras X linhas do arquivo
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
    txt[counter] = '\0';

    fseek(arq, cursor, SEEK_SET);
}

// Retorna a quantidade de caracteres de um arquivo a partir de uma linha até o final do arquivo
int length_from(FILE* arq, int linha_index)
{
    int cursor = ftell(arq);

    seek_line(arq, linha_index);
    int length = 0;

    while(!feof(arq))
    {
        fgetc(arq);
        length++;
    }

    fseek(arq, cursor, SEEK_SET);
    return length;
}

// Armazena as ultimas linhas do arquivo a partir de uma certa linha
void get_file_from(FILE* arq, char* txt, int linha_index)
{
    int cursor = ftell(arq);

    seek_line(arq, linha_index);
    int index = 0;

    while (!feof(arq))
    {
        txt[index] = fgetc(arq);
        index++;
    }
    txt[index-1] = '\0';

    fseek(arq, cursor, SEEK_SET);
}



// Limpa um array
void clear_array(char* vetor, int len)
{
    for (int i = 0; i < len+1; i++)
    {
        vetor[i] = '\0';
    }
}



/* === Funções Premium === */



// Printa o arquivo CSV jogos na tela
void print_games(FILE *arq)
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

// Printa o arquivo CSV publishers e users na tela
void print_publishers_users(FILE* arq)
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

// Remove uma linha do arquivo
void remove_line(FILE* arq, int linha)
{
    char txt1[length_until(arq, linha-1)];
    char txt2[length_from(arq, linha+1)];
    get_file_until(arq, txt1, linha-1);
    get_file_from(arq, txt2, linha+1);

    fseek(arq, 0, SEEK_SET);

    fprintf(arq, "%s", txt1);
    fprintf(arq, "%s", txt2);
    ftruncate(fileno(arq), sizeof txt1 + sizeof txt2);

    fseek(arq, 0, SEEK_END);
}

// Adiciona uma linha ao final do arquivo
void add_line(FILE* arq, char* txt)
{
    int cursor = ftell(arq);

    fseek(arq, 0, SEEK_END);

    fprintf(arq, "%s", txt);

    fseek(arq, cursor, SEEK_SET);
}

// Adiciona um item na linha indicada
void add_item_to_line(FILE* arq, char* item, int linha)
{
    int cursor = ftell(arq);

    char txt1[length_until(arq, linha)];
    char txt2[length_from(arq, linha+1)];
    get_file_until(arq, txt1, linha);
    get_file_from(arq, txt2, linha+1);

    fprintf(arq, "%s", txt1);
    fseek(arq, -2, SEEK_CUR);
    fprintf(arq, ";%s\n", item);
    fprintf(arq, "%s", txt2);
    ftruncate(fileno(arq), sizeof txt1 + sizeof item + 2 + sizeof txt2);

    fseek(arq, cursor, SEEK_SET);
}

#endif // STEAMDB_H_INCLUDED
