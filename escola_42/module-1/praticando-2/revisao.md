# Fundamentos de C Trabalhados nos Códigos `ft_print_comb.c`, `ft_print_comb2.c` e `ft_putnbr.c`

Este material traz um resumo dos principais fundamentos da linguagem C aplicados nos três exercícios enviados. A ideia é entender **o que está sendo praticado** em cada código e como isso contribui para o aprendizado da linguagem.

---

## 1. Escrita na Saída Padrão (`write`)

### O que é?
`write` é uma função da biblioteca `<unistd.h>` usada para imprimir dados diretamente na saída padrão (normalmente o terminal).

### Por que usar?
Permite trabalhar com C puro, sem usar a função `printf` da biblioteca padrão. Ensina como lidar diretamente com fluxo de dados e sistema operacional.

### Como usar?
```c
write(1, &c, 1); // escreve 1 caractere
```

---

## 2. Estruturas de Repetição (`while`)

### O que é?
Permite executar blocos de código várias vezes enquanto uma condição for verdadeira.

### Por que usar?
É essencial para percorrer sequências de valores, como combinações de números ou dígitos de um número.

### Exemplo:
```c
int a = 0;
while (a <= 9)
{
    // código aqui
    a++;
}
```

---

## 3. Manipulação de Caracteres (ASCII)

### O que é?
A linguagem C trata caracteres como inteiros (valores da tabela ASCII). Para transformar números em caracteres, usamos `'0'` como base.

### Por que usar?
Para exibir números com `write`, é necessário convertê-los para caracteres.

### Exemplo:
```c
ft_putchar(n / 10 + '0');
```

---

## 4. Operações Matemáticas Básicas

### O que é?
Uso de divisão inteira (`/`) e resto (`%`) para separar algarismos.

### Por que usar?
Para imprimir cada dígito separadamente.

### Exemplo:
```c
int dezena = n / 10;
int unidade = n % 10;
```

---

## 5. Lógica Condicional (`if`)

### O que é?
Permite executar algo apenas se uma condição for verdadeira.

### Exemplo de usos:
- Evitar vírgula no final.
- Verificar se o número é negativo.
- Tratar o menor inteiro possível.

---

## 6. Funções e Modularização

### O que é?
Divisão do código em partes reutilizáveis (funções).

### Por que usar?
Organiza melhor o código, facilita a leitura e reutilização.

### Exemplo:
```c
void ft_putchar(char c);
void ft_putnbr(int nb);
```

---

## 7. Recursão

### O que é?
Quando uma função chama a si mesma.

### Onde aparece?
Na função `ft_putnbr`, que imprime cada dígito de um número.

### Por que usar?
É uma forma elegante de percorrer os dígitos de um número, da esquerda para a direita.

---

## 8. Loops Aninhados

### O que é?
Um `while` dentro de outro `while`.

### Por que usar?
Para gerar todas as combinações possíveis entre dois ou mais valores.

### Exemplo:
```c
while (a <= 98)
{
    b = a + 1;
    while (b <= 99)
    {
        // imprime combinação a b
        b++;
    }
    a++;
}
```

---

## 9. Limites de Tipos Primitivos

### O que é?
Valores máximos e mínimos que um tipo pode armazenar.

### Onde aparece?
Na linha:
```c
if (nb == -2147483648)
```

### Por que tratar?
Esse valor é especial: seu valor absoluto não cabe em um `int`.

---

## 10. Função `main`

### O que é?
O ponto de entrada de qualquer programa em C.

### Exemplo:
```c
int main(void)
{
    ft_print_comb();
    return 0;
}
```

---

## Conclusão

Os códigos apresentados são excelentes para reforçar:

- Manipulação de números e caracteres.
- Impressão sem `printf`.
- Estruturação do código em funções.
- Recursão e lógica condicional.
- Controle de repetições e combinações.

Esses fundamentos são a base para códigos mais complexos, como algoritmos, jogos, e manipulação de arquivos.

---

**Dica:** Tente alterar os limites dos loops ou os valores testados nas condições e observe como o comportamento muda. Isso ajuda a entender melhor o funcionamento de cada estrutura.

Bons estudos! 🚀