#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Declarando a estrutura de Cadastro.
struct cadastro
{
    char nome_arquivo[50];
    char tema[50];
    char habilidade[50];
    char nome_autor[50];
    char formato[50];
    char indicacao_atendimento[50];
};

// Declara um array de cadastros e variaveis para rastrear o número de elementos e um contador.
struct cadastro c_cadastro[5];
int i;
int n_cadastro = 0;

// Funï¿½ï¿½o para cadastrar um novo x_cadastro no vetor c_cadastro que não tem retorno, apenas faz o cadastro.
void cadastrar_arquivo(struct cadastro x_cadastro)
{
    c_cadastro[n_cadastro] = x_cadastro;
    n_cadastro++;
}

// Função para ler as informações do novo cadastro de arquivo
struct cadastro lerDados()
{
    struct cadastro reservado;
    printf("\n-------------- Bem vindo ao Software da Clinica --------------\n");
    printf("\n-------------------- Cadastro de materiais --------------------\n");
    printf("Digite o nome do arquivo: ");
    fflush(stdin);
    fgets(reservado.nome_arquivo, 50, stdin);
    printf("-------------------------\nDigite o tema: ");
    fflush(stdin);
    fgets(reservado.tema, 50, stdin);
    printf("-------------------------\nDigite a habilidade: ");
    fflush(stdin);
    fgets(reservado.habilidade, 50, stdin);
    printf("-------------------------\nDigite o nome do autor: ");
    fflush(stdin);
    fgets(reservado.nome_autor, 50, stdin);
    printf("-------------------------\nDigite o formato do arquivo: ");
    fflush(stdin);
    fgets(reservado.formato, 50, stdin);
    printf("-------------------------\nDigite a indicação do atendimento: ");
    fflush(stdin);
    fgets(reservado.indicacao_atendimento, 50, stdin);
    return reservado;
};

// Função para buscar todos os arquivos na tela
void buscaArquivo()
{
    for (i = 0; i < n_cadastro; i++)
    {
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

// Função para exibir o menu de opções, que retorna um valor int, que lê o número digitado pelo usuário.
int menu()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao;

    printf("\n-------------- Catálogo de Materiais Terapêuticos --------------\n");
    printf("\n------------------------ Menu de opções ------------------------");
    printf("\n------------------ Escolha uma opção abaixo --------------------\n\n");
    printf("1 - Cadastrar | ");
    printf("2 - Listar cadastros |  ");
    printf("3 - Apagar cadastro | ");
    printf("4 - Alterar cadastro| ");
    printf("0 - Sair | ");
    scanf("%d", &opcao);

    return opcao;
}
void apagar(int posicao)
{
    int indice = posicao - 1;
    int i = 0;

    if ((posicao < 1) || (posicao > n_cadastro)) {
        printf("\nNenhum registro encontrado!\n");
        return;
    }
 
    // 1. caso - remover no final do vetor
    if (posicao == n_cadastro) {
        n_cadastro--;
        return;
    }
 
    // 2. remove qualquer outra posicao
    for (i=indice; i<n_cadastro; i++) {
        c_cadastro[i] = c_cadastro[i + 1];
    }
    n_cadastro--;
}
void alterar(int posicao)
{
    if (posicao < 1 || posicao > n_cadastro) {
        printf("\nNenhum registro encontrado!\n");
        return;
    }

    printf("\nDigite os novos dados:\n");
    struct cadastro novo_cadastro = lerDados();

    c_cadastro[posicao - 1] = novo_cadastro;

    printf("\nCadastro alterado com sucesso!\n");
}

// Função principal, aqui começa o programa.
int main()
{

    int opcao_selecionada;
    struct cadastro novo_cadastro;
    int r;

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
        case 3:
            printf("Digite a posicao que deseja excluir: ");
            scanf("%d", &r);
            apagar(r);
            break;
        case 4:
            printf("Digite a posição que deseja alterar: ");
            scanf("%d", &r);
            alterar(r);
            break;

        default:
            printf(" Opção inválida! ");
        }
    } while (opcao_selecionada != 0);

    return 0;
}
