#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maximoDeClientes 100

typedef struct {
    char nome[100];
    int dia, mes, ano;
    char cpf[15];
} Cliente;

Cliente clientes[maximoDeClientes];
int totalClientes = 0;

void exportarCSV() {
    FILE *arquivo = fopen("clientes.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao gerar arquivo CSV.\n");
        perror("fopen");
        return;
    }
    printf("Arquivo criado\n");

    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        fclose(arquivo);
        return;
    }
    printf("%d clientes para exportar\n", totalClientes);

    fprintf(arquivo,"Nome,Data_nascimento,CPF\n");

    for(int i = 0; i < totalClientes; i++) {
        fprintf(arquivo, "%s,%02d/%02d/%04d,%s\n",
                clientes[i].nome, clientes[i].dia,
                clientes[i].mes, clientes[i].ano, clientes[i].cpf);
    }
    fflush(arquivo);
    fclose(arquivo);
    printf("Csv criado como clientes.csv");
}

void removerNovaLinha(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void cadastrarClientes() {
    if (totalClientes >= maximoDeClientes) {
        printf("Agenda cheia, maximo de %d clientes.\n", maximoDeClientes);
        return;
    }

    char buffer[100];

    printf("Digite o nome do cliente: ");
    fgets(clientes[totalClientes].nome, 100, stdin);
    removerNovaLinha(clientes[totalClientes].nome);

    printf("Digite a data de nascimento (dd mm aaaa): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d %d %d", &clientes[totalClientes].dia, &clientes[totalClientes].mes, &clientes[totalClientes].ano);

    printf("Digite o CPF: ");
    fgets(clientes[totalClientes].cpf, 15, stdin);
    removerNovaLinha(clientes[totalClientes].cpf);

    totalClientes++;
    printf("Cliente cadastrado com sucesso.\n");
}

void listarClientes() {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    for (int i = 0; i < totalClientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("  Nome: %s\n", clientes[i].nome);
        printf("  Data de nascimento: %02d/%02d/%04d\n", clientes[i].dia, clientes[i].mes, clientes[i].ano);
        printf("  CPF: %s\n", clientes[i].cpf);
        printf("===========\n");
    }
}

void editarClientes() {
    int indice;

    if (totalClientes == 0) {
        printf("Nenhum cliente para editar.\n");
        return;
    }

    listarClientes();
    printf("Digite o numero do cliente (1-%d): ", totalClientes);
    scanf("%d", &indice);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (indice < 1 || indice > totalClientes) {
        printf("Indice invalido.\n");
        return;
    }
    indice--;

    printf("Voce esta editando: %s\n", clientes[indice].nome);

    printf("Novo nome: ");
    fgets(clientes[indice].nome, 100, stdin);
    removerNovaLinha(clientes[indice].nome);

    printf("Nova data (dd mm aaaa): ");
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d %d %d", &clientes[indice].dia, &clientes[indice].mes, &clientes[indice].ano);

    printf("Novo CPF: ");
    fgets(clientes[indice].cpf, 15, stdin);
    removerNovaLinha(clientes[indice].cpf);

    printf("Cliente atualizado.\n");
}

void excluirCliente() {
    int indice;

    if (totalClientes == 0) {
        printf("Nenhum cliente para excluir.\n");
        return;
    }

    listarClientes();
    printf("Digite o numero do cliente (1-%d): ", totalClientes);
    scanf("%d", &indice);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (indice < 1 || indice > totalClientes) {
        printf("Indice invalido.\n");
        return;
    }
    indice--;

    printf("Deseja mesmo excluir %s?: ", clientes[indice].nome);
    char confirma[10];
    fgets(confirma, 10, stdin);
    removerNovaLinha(confirma);

    if (strcmp(confirma, "sim") != 0 && strcmp(confirma, "Sim") != 0) {
        printf("Exclusao cancelada.\n");
        return;
    }

    for (int i = indice; i < totalClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }
    totalClientes--;
    printf("Cliente excluido.\n");
}

int main(void) {
    int opcao;

    do {
        printf("\n=== Cadastro de Clientes ===\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Editar cliente\n");
        printf("4 - Excluir cliente\n");
        printf("5 - Exportar CSV\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (opcao) {
            case 1: cadastrarClientes(); break;
            case 2: listarClientes(); break;
            case 3: editarClientes(); break;
            case 4: excluirCliente(); break;
            case 5: exportarCSV(); break;
            case 6: printf("Foi bom trabalhar com vc\n"); break;
            default: printf("Opcao invalida.\n"); break;
        }
    } while (opcao != 6);

    return 0;
}