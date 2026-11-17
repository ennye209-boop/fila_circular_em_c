#include <stdio.h>
#include <string.h>

#define MAX 5
#define TAM_NOME 80

typedef struct {
    int senha;
    char nome[TAM_NOME];
} Pessoa;

typedef struct {
    Pessoa dados[MAX];
    int inicio;      // posição da próxima pessoa a ser chamada
    int fim;         // posição da última pessoa inserida
    int quantidade;  // total de pessoas na fila
    int proximaSenha;
} FilaAtendimento;

void inicializar(FilaAtendimento *f) {
    f->inicio = -1;
    f->fim = -1;
    f->quantidade = 0;
    f->proximaSenha = 1;
}

int estaVazia(FilaAtendimento *f) {
    return f->quantidade == 0;
}

int estaCheia(FilaAtendimento *f) {
    return f->quantidade == MAX;
}

void mostrarEstado(FilaAtendimento *f) {
    printf("Inicio: %d | Fim: %d | Quantidade: %d\n",
           f->inicio, f->fim, f->quantidade);
}

void inserirPessoa(FilaAtendimento *f) {
    char nome[TAM_NOME];

    if (estaCheia(f)) {
        printf("\nFila cheia! Nao e possivel inserir outra pessoa (overflow).\n");
        return;
    }

    printf("Nome da pessoa: ");
    if (scanf(" %79[^\n]", nome) != 1) {
        printf("Nome invalido.\n");
        return;
    }

    if (estaVazia(f)) {
        f->inicio = 0;
        f->fim = 0;
    } else {
        f->fim = (f->fim + 1) % MAX;
    }

    f->dados[f->fim].senha = f->proximaSenha;
    strcpy(f->dados[f->fim].nome, nome);

    printf("Pessoa inserida! Senha: %d | Nome: %s\n",
           f->proximaSenha, nome);

    f->proximaSenha++;
    f->quantidade++;
}

void chamarProximaPessoa(FilaAtendimento *f) {
    Pessoa chamada;

    if (estaVazia(f)) {
        printf("\nFila vazia! Nao ha pessoas para chamar (underflow).\n");
        return;
    }

    chamada = f->dados[f->inicio];
    printf("\nProxima pessoa: senha %d - %s\n",
           chamada.senha, chamada.nome);

    if (f->quantidade == 1) {
        f->inicio = -1;
        f->fim = -1;
    } else {
        f->inicio = (f->inicio + 1) % MAX;
    }

    f->quantidade--;
}

void visualizarFila(FilaAtendimento *f) {
    int i, posicao;

    if (estaVazia(f)) {
        printf("\nNao ha pessoas na fila.\n");
        return;
    }

    printf("\n===== FILA DE ESPERA =====\n");
    posicao = f->inicio;

    for (i = 0; i < f->quantidade; i++) {
        printf("Posicao %d: senha %d - %s\n",
               i + 1,
               f->dados[posicao].senha,
               f->dados[posicao].nome);

        posicao = (posicao + 1) % MAX;
    }
}

int main(void) {
    FilaAtendimento fila;
    int opcao;

    inicializar(&fila);

    do {
        printf("\n===== SISTEMA DE ATENDIMENTO =====\n");
        printf("1. Inserir pessoa na fila\n");
        printf("2. Chamar proxima pessoa\n");
        printf("3. Visualizar fila de espera\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida.\n");
            while (getchar() != '\n') {}
            continue;
        }

        switch (opcao) {
            case 1:
                inserirPessoa(&fila);
                mostrarEstado(&fila);
                break;
            case 2:
                chamarProximaPessoa(&fila);
                mostrarEstado(&fila);
                break;
            case 3:
                visualizarFila(&fila);
                mostrarEstado(&fila);
                break;
            case 4:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
