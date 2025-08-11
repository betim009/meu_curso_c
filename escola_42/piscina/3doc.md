## ex00 — `ft_ft`

### O que o exercício faz
Recebe um ponteiro para `int` e grava o valor **42** nesse endereço.

### Passo a passo
1. A função recebe `int *nbr` (um endereço de um `int`).
2. O operador `*` acessa o **conteúdo** no endereço (`*nbr`).
3. Atribua `42` ao conteúdo: `*nbr = 42;`.
4. Não retorna nada; o número muda **fora** da função porque alteramos
   a memória apontada.

### Gabarito

## ex01 — `ft_ultimate_ft`

### O que o exercício faz
Navega por **nove** níveis de ponteiro até o `int` final e escreve 42.

### Passo a passo
1. Recebe `int *********nbr` (ponteiro de ponteiro... 9 níveis).
2. Use `*********nbr` para alcançar o **inteiro** de verdade.
3. Atribua `42` lá: `*********nbr = 42;`.
4. A lógica é idêntica ao ex00, só muda a quantidade de `*`.

### Gabarito

## ex02 — `ft_swap`

### O que o exercício faz
Troca os **valores** de dois inteiros usando seus endereços.

### Passo a passo
1. Recebe `int *a` e `int *b` (endereços dos inteiros).
2. Guarde `*a` em `tmp`.
3. Copie `*b` para `*a`.
4. Copie `tmp` para `*b`.
5. Resultados visíveis fora da função, pois alteramos a memória apontada.

### Gabarito

## ex03 — `ft_div_mod`

### O que o exercício faz
Calcula **quociente** e **resto** de `a / b` e devolve via ponteiros.

### Passo a passo
1. Parâmetros: `a`, `b`, `int *div`, `int *mod`.
2. Calcule o quociente: `a / b` e grave em `*div`.
3. Calcule o resto: `a % b` e grave em `*mod`.
4. **Teste** com `b != 0` para evitar divisão por zero nos seus testes.

### Gabarito

## ex04 — `ft_ultimate_div_mod`

### O que o exercício faz
Sobrescreve `*a` com o **quociente** e `*b` com o **resto** de `*a / *b`.

### Passo a passo
1. Leia valores originais: `x = *a; y = *b;`.
2. Grave o quociente em `*a`: `*a = x / y;`.
3. Grave o resto em `*b`: `*b = x % y;`.
4. Usar cópias evita perder o valor inicial ao calcular o resto.

### Gabarito

## ex05 — `ft_putstr`

### O que o exercício faz
Imprime uma **string** caractere a caractere até o `\0` usando `write`.

### Passo a passo
1. Comece com `i = 0`.
2. Enquanto `str[i] != '\0'`, faça:
   - chame `write(1, &str[i], 1);` para escrever 1 caractere.
   - incremente `i++`.
3. Não use `printf` (não permitido nesse exercício).

### Gabarito

## ex06 — `ft_strlen`

### O que o exercício faz
Conta quantos caracteres existem **antes** do `\0` na string.

### Passo a passo
1. Inicie `len = 0`.
2. Enquanto `str[len] != '\0'`, aumente `len`.
3. Retorne `len` no final.

### Gabarito

## ex07 — `ft_rev_int_tab`

### O que o exercício faz
Inverte o array `tab` **in-place** (sem usar array extra).

### Passo a passo
1. Defina dois índices: `i = 0` e `j = size - 1`.
2. Enquanto `i < j`, troque `tab[i]` com `tab[j]`.
3. Faça `i++` e `j--` a cada iteração.
4. Pare quando se cruzarem (array ficou ao contrário).

### Gabarito

## ex08 — `ft_sort_int_tab`

### O que o exercício faz
Ordena o array de inteiros em **ordem crescente** (bubble sort simples).

### Passo a passo
1. Se `size <= 1`, não há o que ordenar, retorne.
2. Use um laço externo que repete "passagens" no array.
3. Em cada passagem, percorra `i = 0..size-2`.
4. Se `tab[i] > tab[i+1]`, troque os elementos e marque `swapped = 1`.
5. Quando uma passagem terminar **sem trocas** (`swapped == 0`), pare:
   o array está ordenado.

### Gabarito
