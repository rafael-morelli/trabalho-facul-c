#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    char NomeLivro[5];
    char NomeAutor[5];
    char Editora[5];
    char FaixaEtaria[5];

    printf("Digite o nome do livro:");
    fgets(NomeLivro, sizeof(NomeLivro), stdin);
    NomeLivro[strcspn(NomeLivro, "\n")] = '\0';

    while (getchar() != '\n')
        ;

    printf("Digite o nome do autor:");
    fgets(NomeAutor, sizeof(NomeAutor), stdin);
    NomeAutor[strcspn(NomeAutor, "\n")] = '\0';

    while (getchar() != '\n')
        ;

    printf("Digite o nome da editora:");
    fgets(Editora, sizeof(Editora), stdin);
    Editora[strcspn(Editora, "\n")] = '\0';

    while (getchar() != '\n')
        ;

    setlocale(LC_ALL, "Portuguese");
    printf("Digite a faixa etária do livro:");
    fgets(FaixaEtaria, sizeof(FaixaEtaria), stdin);
    FaixaEtaria[strcspn(FaixaEtaria, "\n")] = '\0';

    return 0;
}