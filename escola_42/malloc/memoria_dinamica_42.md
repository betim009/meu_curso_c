# Módulo de Memória Dinâmica na School 42

Este material é um guia didático para entender a **alocação dinâmica de
memória** na linguagem C, essencial para projetos da School 42 como
*libft*, *get_next_line*, *push_swap* e *so_long*.

------------------------------------------------------------------------

## 1. `malloc` e `free`

### `malloc`

-   Reserva memória em tempo de execução.
-   Protótipo: `void *malloc(size_t size);`
-   Retorna ponteiro ou `NULL`.

### `free`

-   Libera memória reservada com `malloc`.
-   Protótipo: `void free(void *ptr);`
-   Obrigatório para evitar *memory leaks*.

**Exemplo:**

``` c
#include <stdlib.h>

int main(void)
{
    int *arr = (int *)malloc(5 * sizeof(int));
    if (!arr)
        return (1);

    arr[0] = 42;
    arr[1] = 84;

    free(arr);
    return (0);
}
```

------------------------------------------------------------------------

## 2. `sizeof`

-   Usado para calcular o tamanho em bytes de um tipo.
-   Muito importante para `malloc`.

**Exemplo:**

``` c
int *p = malloc(10 * sizeof(int)); // 10 inteiros
char *s = malloc(20 * sizeof(char)); // 20 chars
```

------------------------------------------------------------------------

## 3. `calloc` e `realloc`

### `calloc`

-   Igual ao `malloc`, mas inicializa a memória com zero.
-   Protótipo: `void *calloc(size_t nmemb, size_t size);`

### `realloc`

-   Redimensiona um bloco já alocado.
-   Protótipo: `void *realloc(void *ptr, size_t size);`

**Exemplo:**

``` c
#include <stdlib.h>

int main(void)
{
    int *arr = (int *)calloc(5, sizeof(int)); // 0 0 0 0 0
    arr = (int *)realloc(arr, 10 * sizeof(int)); // expande para 10
    free(arr);
    return (0);
}
```

------------------------------------------------------------------------

## 4. Strings Dinâmicas

Na 42 você recria funções como `ft_strdup`, `ft_strjoin` e `ft_substr`.
Todas usam `malloc` para criar novas strings.

**Exemplo: `ft_strdup`**

``` c
#include <stdlib.h>

char *ft_strdup(const char *src)
{
    int i = 0;
    char *dup;

    while (src[i])
        i++;
    dup = (char *)malloc((i + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
```

------------------------------------------------------------------------

## 5. Estruturas Dinâmicas

### Listas Encadeadas

``` c
#include <stdlib.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

t_node *create_node(int val)
{
    t_node *new = (t_node *)malloc(sizeof(t_node));
    if (!new)
        return (NULL);
    new->value = val;
    new->next = NULL;
    return (new);
}
```

➡️ Usado em *push_swap* e outros projetos.

------------------------------------------------------------------------

## 6. Valgrind e Debug de Memória

-   Para checar *memory leaks*:

    ``` sh
    valgrind --leak-check=full ./a.out
    ```

-   Erros comuns:

    -   **"Invalid read/write"** → acessar fora da memória alocada.
    -   **"Definitely lost"** → vazamento de memória (faltou `free`).

------------------------------------------------------------------------

## Exercícios Propostos

### Exercício 1: Array Dinâmico

-   Alocar um array de 10 inteiros.
-   Preencher com múltiplos de 3.
-   Imprimir no terminal.
-   Liberar memória.

### Exercício 2: `ft_strdup`

-   Reimplementar `strdup` usando `malloc`.
-   Testar copiando `"42 São Paulo"`.

### Exercício 3: `calloc`

-   Criar uma matriz 3x3 de inteiros inicializada com zeros usando
    `calloc`.

### Exercício 4: Lista Encadeada

-   Criar 3 nós ligados entre si.
-   Preencher valores 10, 20, 30.
-   Liberar todos no final.

------------------------------------------------------------------------

## Gabarito dos Exercícios

### Exercício 1

``` c
int *arr = malloc(10 * sizeof(int));
for (int i = 0; i < 10; i++)
    arr[i] = i * 3;
free(arr);
```

### Exercício 2

``` c
char *dup = ft_strdup("42 São Paulo");
// dup agora contém cópia da string
free(dup);
```

### Exercício 3

``` c
int *mat = calloc(9, sizeof(int));
// Acessa como mat[i*3 + j]
free(mat);
```

### Exercício 4

``` c
t_node *n1 = create_node(10);
t_node *n2 = create_node(20);
t_node *n3 = create_node(30);
n1->next = n2;
n2->next = n3;
free(n3);
free(n2);
free(n1);
```

------------------------------------------------------------------------

## Conclusão

Compreender `malloc`, `free`, `calloc`, `realloc`, `sizeof` e ponteiros
é essencial para evoluir na 42.\
Eles aparecem em praticamente todos os projetos, e dominar esses
conceitos garante códigos eficientes e sem vazamentos de memória.
