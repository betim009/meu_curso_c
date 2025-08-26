# Guia Didático: `malloc` na School 42

## O que é o `malloc`?

-   `malloc` significa **Memory Allocation** (alocação de memória).\
-   É uma **função da biblioteca padrão do C** (definida em
    `<stdlib.h>`).\
-   Ela serve para **reservar memória durante a execução do programa**
    (memória dinâmica).

📌 Até então, você aprendeu a criar variáveis com tamanho fixo (ex:
`int x;` ou `char nome[50];`).\
Mas e se você não souber antes qual o tamanho que vai precisar? É aí que
entra o `malloc`.

------------------------------------------------------------------------

## Por que precisamos dele?

1.  **Tamanho variável em tempo de execução**
    -   Exemplo: ler uma string do usuário sem saber antes quantos
        caracteres ela terá.\
    -   Exemplo: criar uma lista de elementos que cresce conforme o
        programa roda.
2.  **Estruturas de dados**
    -   Listas ligadas, árvores, filas e pilhas **precisam de alocação
        dinâmica**.\
    -   Sem `malloc`, só conseguimos trabalhar com arrays fixos.
3.  **Controle da memória**
    -   O `malloc` dá a você o **poder de pedir memória para o sistema
        operacional**.\
    -   Mas também te dá a **responsabilidade de liberar essa memória**
        com `free`.

------------------------------------------------------------------------

## Como usar o `malloc`

A assinatura da função é:

``` c
void *malloc(size_t size);
```

-   `size` = quantidade de bytes que você quer reservar.\
-   Retorno = ponteiro genérico (`void *`) para o início da área de
    memória.\
-   Se der errado (sem memória disponível), `malloc` retorna `NULL`.

### Exemplo básico

``` c
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int *ptr;

    // Aloca espaço para 5 inteiros
    ptr = (int *)malloc(5 * sizeof(int));

    if (ptr == NULL)
        return (1); // Falha na alocação

    // Usando a memória
    ptr[0] = 42;
    ptr[1] = 84;

    // Libera a memória no final
    free(ptr);

    return (0);
}
```

------------------------------------------------------------------------

## Exemplos no contexto da 42

### 1. Guardar uma string (projeto *libft*)

``` c
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *str;

    // Aloca 6 chars (5 letras + '\0')
    str = (char *)malloc(6 * sizeof(char));

    if (!str)
        return (1);

    str[0] = 'H';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = '\0';

    // Escreve no terminal
    write(1, str, 5);

    free(str);
    return (0);
}
```

➡️ Esse tipo de lógica é usada em funções como `ft_strdup`, que você vai
implementar na *libft*.

------------------------------------------------------------------------

### 2. Criar um array dinâmico (projetos de algoritmos)

``` c
#include <stdlib.h>

int main(void)
{
    int n = 10;
    int *arr;
    int i;

    arr = (int *)malloc(n * sizeof(int));
    if (!arr)
        return (1);

    i = 0;
    while (i < n)
    {
        arr[i] = i * 2;  // Preenche
        i++;
    }

    free(arr);
    return (0);
}
```

➡️ Esse padrão aparece muito quando você precisa lidar com dados cujo
tamanho só é conhecido em **tempo de execução**.

------------------------------------------------------------------------

### 3. Listas encadeadas (projetos *push_swap*, *so_long*, etc.)

``` c
#include <stdlib.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

int main(void)
{
    t_node *head;

    // Aloca primeiro nó
    head = (t_node *)malloc(sizeof(t_node));
    if (!head)
        return (1);

    head->value = 42;
    head->next = NULL;

    free(head);
    return (0);
}
```

➡️ Sem `malloc`, não seria possível construir listas ou estruturas
dinâmicas.

------------------------------------------------------------------------

## Erros comuns no `malloc`

1.  **Esquecer de liberar a memória (`free`)**\
    → Isso causa **memory leaks** (vazamentos de memória).\
    Exemplo: cada `malloc` precisa ter um `free` correspondente.

2.  **Esquecer de verificar se retornou `NULL`**\
    → Em programas pequenos quase nunca acontece, mas em projetos
    grandes é obrigatório.

3.  **Alocar menos memória do que precisa**\
    → Sempre lembrar do `+1` para o `'\0'` em strings.

------------------------------------------------------------------------

## Resumindo

-   `malloc` = pedir memória na hora que o programa roda.\
-   Usado para strings, arrays dinâmicos, listas, árvores, etc.\
-   Você sempre deve liberar a memória depois com `free`.\
-   É uma ferramenta **essencial** para os projetos da 42, como `libft`,
    `get_next_line` e `so_long`.
