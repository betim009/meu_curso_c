ft_substr.c — Explicacao Passo a Passo
======================================

Visao geral
-----------
O arquivo define tres funcoes:
1. `ft_strlen`: calcula o numero de caracteres de uma string.
2. `ft_substr`: cria uma substring de uma string de entrada.
3. `main`: demonstra o uso de `ft_substr`.

Cada secao abaixo segue a ordem do arquivo original e explica linha a linha o que acontece.

Cabecalhos (linhas 1-3)
-----------------------
- `#include <stdlib.h>`: disponibiliza as funcoes de alocacao de memoria `malloc` e `free`.
- `#include <stddef.h>`: define o tipo `size_t`, usado para tamanhos e contagens sem sinal.
- `#include <stdio.h>`: fornece `printf` e `fprintf`, usados apenas pela funcao `main` de teste.

Funcao `ft_strlen` (linhas 9-17)
--------------------------------
- `size_t ft_strlen(const char *s)`: declara a funcao que recebe um ponteiro constante para caracteres e devolve um numero do tipo `size_t`.
- `size_t i;`: cria a variavel usada para contar caracteres.
- `i = 0;`: inicializa o contador.
- `while (s && s[i])`: percorre a string enquanto o ponteiro `s` nao for nulo e o caractere atual nao for `'\0'`.
- `i++;`: avanca para o proximo indice a cada caractere valido.
- `return (i);`: devolve a quantidade total de caracteres lidos.

Funcao `ft_substr` (linhas 28-58)
---------------------------------
- `char *ft_substr(char const *s, unsigned int start, size_t len)`: assinatura que recebe a string de origem, o indice inicial e o tamanho maximo desejado.
- `size_t s_len; size_t i; char *sub;`: variaveis auxiliares para armazenar o tamanho da string original, o indice de copia e o ponteiro da nova substring.
- `if (!s) return (NULL);`: verifica se a string de entrada e nula; se for, nao ha o que fazer.
- `s_len = ft_strlen(s);`: calcula o comprimento da string para validar o intervalo pedido.
- `if (start >= s_len)`: trata o caso em que o ponto de inicio ultrapassa o fim da string.
- `sub = (char *)malloc(1);`: aloca 1 byte para uma string vazia.
- `if (!sub) return (NULL);`: verifica falha de alocacao.
- `sub[0] = '\0'; return (sub);`: garante que a substring vazia esteja terminada e devolve o ponteiro.
- `if (len > s_len - start) len = s_len - start;`: ajusta `len` para nao ultrapassar o fim da string original.
- `sub = (char *)malloc(len + 1);`: aloca memoria suficiente para os caracteres pedidos mais o terminador nulo.
- `if (!sub) return (NULL);`: confere a alocacao.
- `i = 0; while (i < len)`: inicializa o contador e copia caractere a caractere.
- `sub[i] = s[start + i]; i++;`: transfere cada caractere da posicao correta da string original.
- `sub[i] = '\0';`: adiciona o terminador nulo no final da substring.
- `return (sub);`: devolve a substring alocada dinamicamente.

Funcao `main` de teste (linhas 60-75)
------------------------------------
- `int main(void)`: ponto de entrada usado apenas para testar localmente.
- `char *original; char *substring;`: ponteiros para a string original e para a substring retornada.
- `original = "School 42 - libft";`: string literal usada como exemplo.
- `substring = ft_substr(original, 7, 5);`: chama a funcao para copiar a partir do indice 7, com ate 5 caracteres.
- `if (!substring) { fprintf(...); return (1); }`: trata possivel falha de alocacao e informa o erro.
- `printf("String original: ...); printf("Substring extraida: ...);`: imprime o resultado no terminal.
- `free(substring);`: libera a memoria alocada por `ft_substr`.
- `return (0);`: indica termino normal do programa.

Comentarios finais (linhas 79-82)
--------------------------------
- Bloco que descreve os comandos para compilar e executar:
  1. `gcc ft_substr.c -Wall -Wextra -Werror -o ft_substr`
  2. `./ft_substr`

Observacao sobre o projeto 42
-----------------------------
A `main` e o uso de `<stdio.h>` servem apenas para testes locais. Para entregar na 42, costumar separar esses testes em outro arquivo, mantendo `ft_substr.c` com apenas os cabecalhos aprovados e sem `main`.
