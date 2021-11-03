#ifndef STEAMDB_H_INCLUDED
#define STEAMDB_H_INCLUDED

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

struct Game
{
    char nome[100];
    char genero[100];
    double preco;
    int avaliacao;
};

#endif // STEAMDB_H_INCLUDED
