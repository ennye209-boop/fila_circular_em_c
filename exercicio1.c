#include <stdio.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int inicio;      // posição do próximo elemento a ser removido
    int fim;         // posição do último elemento inserido
    int quantidade;  // número de elementos armazenados
} Fila;

void inicializar(Fila *f) {
    f->inicio = -1;
    f->fim = -1;
    f->quantidade = 0;
}

int estaVazia(Fila *f) {
    return f->quantidade == 0;
}

int estaCheia(Fila *f) {
    return f->quantidade == MAX;
}

void inserir(Fila *f) {
    int valor;

    if (estaCheia(f)) {
        printf("\nFila cheia! Nao e possivel inserir (overflow).\n");
        return;
    }

    printf("Digite o valor: ");
    if (scanf("%d", &valor) != 1) {
        printf("Entrada invalida.\n");
        while (getchar() != '\n') {}
        return;
    }

    if (estaVazia(f)) {
        f->inicio = 0;
        f->fim = 0;
    } else {
        f->fim = (f->fim + 1) % MAX;
    }

    f->dados[f->fim] = valor;
    f->quantidade++;

    printf("Valor %d inserido com sucesso.\n", valor);
}

void remover(Fila *f) {
    int removido;

    if (estaVazia(f)) {
        printf("\nFila vazia! Nao e possivel remover (underflow).\n");
        return;
    }

    removido = f->dados[f->inicio];

    if (f->quantidade == 1) {
        f->inicio = -1;
        f->fim = -1;
    } else {
        f->inicio = (f->inicio + 1) % MAX;
    }

    f->quantidade--;
    printf("Elemento removido: %d\n", removido);
}

void listar(Fila *f) {
    int i, posicao;

    if (estaVazia(f)) {
        printf("\nA fila esta vazia.\n");
        return;
    }

    printf("\nElementos da fila (do primeiro ao ultimo): ");
    posicao = f->inicio;

    for (i = 0; i < f->quantidade; i++) {
        printf("%d ", f->dados[posicao]);
        posicao = (posicao + 1) % MAX;
    }
    printf("\n");
}

void mostrarEstado(Fila *f) {
    printf("Inicio: %d | Fim: %d | Quantidade: %d\n",
           f->inicio, f->fim, f->quantidade);
}

int main(void) {
    Fila fila;
    int opcao;

    inicializar(&fila);

    do {
        printf("\n===== FILA CIRCULAR =====\n");
        printf("1. Inserir um elemento\n");
        printf("2. Remover um elemento\n");
        printf("3. Listar os elementos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida.\n");
            while (getchar() != '\n') {}
            continue;
        }

        switch (opcao) {
            case 1:
                inserir(&fila);
                mostrarEstado(&fila);
                break;
            case 2:
                remover(&fila);
                mostrarEstado(&fila);
                break;
            case 3:
                listar(&fila);
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
