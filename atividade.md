# Exercício: Encontrar o Maior Número em um Array (C)

## Objetivo
Praticar manipulação de arrays em C, trabalhando com lógica de comparação e funções.

---

## Parte 1: Implementação na `main`
1. **Crie um programa em C** que:
   - Declare um array de inteiros com **5 elementos** (ex.: `[7, 3, 12, 5, 9]`).
   - Utilize um loop (`for` ou `while`) para percorrer o array.
   - Encontre o maior número armazenado no array.
   - Imprima o maior número encontrado **diretamente na `main`**.

## Parte 2: Implementação com Função
2. **Refatore o programa**:
   - Crie uma função chamada `encontrarMaior` que:
     - Receba o array e seu tamanho como parâmetros.
     - Retorne o maior número do array.
   - Chame essa função na `main` e exiba o resultado.

---

## Exemplo de Saída
```bash
Array: [7, 3, 12, 5, 9]
Maior número (Parte 1): 12
Maior número (Parte 2): 12
```


**Dicas**

    Use uma variável auxiliar (ex.: maior) para armazenar o valor durante as comparações.

    Na função, o return deve devolver o valor encontrado.

**Extras (Opcional)**

    Modifique o programa para que o array seja preenchido pelo usuário via scanf.




# Solução Referência

## Parte 1: Implementação na `main`
```c
#include <stdio.h>

int main() {
    int array[5] = {7, 3, 12, 5, 9}; // Array pré-definido
    int maior = array[0]; // Assume que o primeiro é o maior inicialmente

    // Percorre o array para encontrar o maior número
    for (int i = 1; i < 5; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }

    printf("Maior número (Parte 1): %d\n", maior);
    return 0;
}
```

# Solução Referência

## Parte 2: Implementação com função

```c
#include <stdio.h>

// Função que encontra o maior número do array
int encontrarMaior(int array[], int tamanho) {
    int maior = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

int main() {
    int array[5] = {7, 3, 12, 5, 9};
    int tamanho = 5;

    // Chama a função e exibe o resultado
    printf("Maior número (Parte 2): %d\n", encontrarMaior(array, tamanho));
    return 0;
}
```