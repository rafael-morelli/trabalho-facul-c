#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Declarando a estrutura de Cadastro.
struct cadastro {
    char nome_arquivo[50];
    char tema[50];
    char habilidade[50];
    char nome_autor[50];
    char formato[50];
    char indicacao_atendimento[50];
};

// Declara um array de cadastros e variáveis para rastrear o número de elementos e um contador.
struct cadastro c_cadastro[5];
int i;
int n_cadastro = 0;

// Função para cadastrar um novo x_cadastro no vetor c_cadastro que não tem retorno, apenas faz o cadastro.
void cadastrar_arquivo(struct cadastro x_cadastro) {
    c_cadastro[n_cadastro] = x_cadastro;
    n_cadastro++;
}

// Função para ler as informações do novo cadastro de arquivo
struct cadastro lerDados() {
    struct cadastro reservado;
    printf("Digite o nome do arquivo: ");
    fflush(stdin);
    fgets(reservado.nome_arquivo, 50, stdin);
    printf("Digite o tema: ");
    fflush(stdin);
    fgets(reservado.tema, 50, stdin);
    printf("Digite a habilidade: ");
    fflush(stdin);
    fgets(reservado.habilidade, 50, stdin);
    printf("Digite o nome do autor: ");
    fflush(stdin);
    fgets(reservado.nome_autor, 50, stdin);
    printf("Digite o formato do arquivo: ");
    fflush(stdin);
    fgets(reservado.formato, 50, stdin);
    printf("Digite a indicação do atendimento: ");
    fflush(stdin);
    fgets(reservado.indicacao_atendimento, 50, stdin);
    return reservado;
};

// Função para buscar todos os arquivos na tela
void buscaArquivo() {
    for (i = 0; i < n_cadastro; i++) {
        printf("Codigo do arquivo: %d\n", i + 1);
        printf("Nome do Arquivo: %s", c_cadastro[i].nome_arquivo);
        printf("Tema: %s", c_cadastro[i].tema);
        printf("Habilidade: %s", c_cadastro[i].habilidade);
        printf("Autor: %s", c_cadastro[i].nome_autor);
        printf("Formato: %s", c_cadastro[i].formato);
        printf("Indicação de atendimento: %s", c_cadastro[i].indicacao_atendimento);
        printf("\n\n");
    }
}

// Função para exibir o menu de opções, que retorna um valor int, que é o número digitado pelo usuário.
int menu() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao;

    printf("\n-------------- Bem vindo ao Software da Clinica --------------\n");
    printf("\n----------------------- Menu de opções -----------------------\n");
    printf("Escolha uma opção abaixo\n");
    printf("1 - Cadastrar\n");
    printf("2 - Buscar\n");
    printf("3 - Alterar\n");
    printf("4 - Apagar\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);

    return opcao;
}

//Função principal, aqui começa o programa.
int main() {

    int opcao_selecionada;
    struct cadastro novo_cadastro;

    do
    {
        opcao_selecionada = menu();
        switch (opcao_selecionada)
        {
        case 0:
            break;

        case 1:
            if (n_cadastro == 5)
            {
                printf("\nBANCO DE DADOS CHEIO!\n ");
            }
            novo_cadastro = lerDados();
            cadastrar_arquivo(novo_cadastro);
            break;
        case 2:
            buscaArquivo();
            break;

        default:
            printf(" Opção inválida! ");
        }
    } while (opcao_selecionada != 0);

    return 0;
}
