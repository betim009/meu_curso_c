# 📘 Exercícios de Fundamentos em C (Versão Didática e Detalhada)

Estes exercícios foram criados com base nos códigos `ft_print_comb.c`, `ft_print_comb2.c` e `ft_putnbr.c`, com o objetivo de **reforçar os principais fundamentos da linguagem C**, como loops, condições, manipulação de caracteres e escrita com `write`.

Os enunciados foram escritos de forma clara e didática, para que qualquer iniciante consiga compreender o que deve ser feito.

---

## 🧠 Exercício 1: Imprima os dígitos de 0 a 9 com separador

**Objetivo:** Criar uma função chamada `ft_print_digits` que imprime todos os dígitos de `0` a `9`, em ordem crescente, **separados por vírgula e espaço**, tudo na mesma linha.

**Regras:**

- Use apenas a função `write` para exibir os caracteres.
- Não utilize `printf`, `puts` ou `putchar`.
- Cada número deve ser separado por `", "`.
- O **último número (9)** não deve ser seguido por vírgula.
- A função **não recebe nenhum parâmetro**.

**Saída esperada:**

```
0, 1, 2, 3, 4, 5, 6, 7, 8, 9
```

---

## 🧪 Exercício 2: Imprimir todos os múltiplos de 5 entre 10 e 99

**Objetivo:** Criar uma função chamada `ft_print_multiples_of_5` que exibe todos os números múltiplos de 5 entre `10` e `99`, com dois dígitos, separados por vírgula e espaço, **na mesma linha**.

**Regras:**

- Os números devem ter sempre **dois dígitos** (ex: `10`, `15`, `95`).
- A função **não pode imprimir vírgula após o último número**.
- Só use a função `write` para imprimir na tela.
- Não é permitido o uso de `printf` ou `puts`.
- A função **não recebe nenhum parâmetro**.

**Saída esperada (exemplo):**

```
10, 15, 20, 25, ..., 95
```

---

## 🔄 Exercício 3: Contagem reversa de 9 até 0

**Objetivo:** Criar uma função chamada `ft_print_reverse_digits` que imprime os números de `9` até `0` na mesma linha, **em ordem decrescente**, separados por espaço.

**Regras:**

- Usar apenas `write` para imprimir.
- Os números devem ser exibidos na mesma linha, separados por **espaço**.
- Nenhum espaço deve ser colocado **depois do último número (0)**.
- A função não recebe parâmetros.

**Saída esperada:**

```
9 8 7 6 5 4 3 2 1 0
```

---

## 🔢 Exercício 4: Todas as combinações possíveis de duas letras minúsculas

**Objetivo:** Criar uma função chamada `ft_print_letter_pairs` que imprime todas as combinações possíveis de **duas letras minúsculas do alfabeto**, sem repetição e sem inverter a ordem.

**Regras:**

- As letras devem ir de `'a'` até `'z'`.
- A primeira letra sempre deve ser menor do que a segunda.
- As combinações devem ser separadas por `", "`.
- Exemplo de combinações válidas: `ab`, `ac`, `ad`, ..., `az`, `bc`, ..., `yz`.
- A função **não deve** colocar vírgula após a última combinação.
- Use apenas `write` para exibir os dados.
- Não use `printf`, `puts` ou `putchar`.

**Saída esperada (início):**

```
ab, ac, ad, ae, ..., yz
```

---

## 🧠 Exercício 5: Imprimir os dígitos de um número de trás para frente

**Objetivo:** Criar uma função chamada `ft_print_digits_reversed` que recebe um número inteiro positivo como parâmetro e imprime cada dígito desse número em **ordem inversa**, com **um dígito por linha**.

**Regras:**

- A função deve receber um número do tipo `int` como argumento.
- O número deve ser tratado como **positivo** (não precisa validar negativo).
- Cada dígito deve ser impresso **em uma linha separada**.
- O primeiro dígito impresso deve ser o último número do valor original.
- Use apenas a função `write`.

**Exemplo de entrada:**

```c
ft_print_digits_reversed(432);
```

**Saída esperada:**
```
2
3
4
```

---

Esses exercícios foram pensados para fixar os conceitos de lógica, estruturas de repetição, manipulação de caracteres e impressão com `write`.

🧠 **Dica:** Releia os exemplos dos arquivos anteriores para se inspirar nas soluções. Use sempre a lógica passo a passo e cuide da formatação!

Bons estudos, e bora codar! 🚀