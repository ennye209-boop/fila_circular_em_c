# Fila Circular em C

**Nome:** Abene Uassena Una  
**Disciplina:** Estrutura de Dados

Este repositório contém dois programas em linguagem C que implementam uma fila circular utilizando arrays, `struct`, a regra FIFO (*First In, First Out*) e o operador módulo (`%`).

## Arquivos

- `exercicio1.c`: menu para inserir, remover e listar números em uma fila circular.
- `exercicio2.c`: simulação de uma fila de atendimento, com número de senha e nome de cada pessoa.

## Como compilar

Com o GCC instalado, abra o terminal na pasta do projeto e execute:

```bash
gcc exercicio1.c -o exercicio1
gcc exercicio2.c -o exercicio2
```

## Como executar

No Linux/macOS:

```bash
./exercicio1
./exercicio2
```

No Windows:

```bash
exercicio1.exe
exercicio2.exe
```

## Capacidade da fila

Os dois programas usam uma capacidade de 5 elementos (`MAX 5`). Esse valor pode ser alterado no início de cada código.

## Testes a realizar

1. Inserir cinco elementos/pessoas até completar a fila.
2. Tentar inserir mais um elemento e verificar a mensagem de fila cheia (*overflow*).
3. Remover um ou mais elementos.
4. Inserir novos elementos para verificar o reaproveitamento das posições liberadas no array.
5. Remover todos os elementos e tentar remover novamente para verificar a mensagem de fila vazia (*underflow*).

## Índices

- `inicio`: índice do próximo elemento a ser removido.
- `fim`: índice do último elemento inserido.
- `quantidade`: número de elementos atualmente armazenados.

Quando a fila fica vazia, `inicio` e `fim` recebem `-1`. A movimentação circular é feita com `(indice + 1) % MAX`.
