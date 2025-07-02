# ex08 - ft_print_combn

## Enunciado

Crie uma função que exibe todas as diferentes combinações de n números distintos em ordem crescente.

- O valor de n será tal que: 0 < n < 10.
- Apenas a função `write` pode ser utilizada para saída.
- As combinações devem ser separadas por vírgula e espaço, exceto a última.

**Protótipo da função:**
```c
void ft_print_combn(int n);
```

### Exemplo de saída para n = 2:
```
01, 02, 03, ..., 09, 12, ..., 79, 89
```

---

## Lógica da Solução

- Utilizamos recursão para gerar todas as combinações possíveis de n dígitos distintos, sempre em ordem crescente.
- Um array armazena a combinação atual.
- Cada chamada recursiva preenche uma posição do array, garantindo que o próximo dígito seja sempre maior que o anterior.
- Quando a combinação está completa, ela é impressa.
- A verificação se é a última combinação serve para não imprimir ", " após o último número.

---

## Estrutura do Código

- `ft_putchar`: Função auxiliar para imprimir um caractere usando `write`.
- `print_comb`: Imprime a combinação atual e adiciona a vírgula e espaço quando necessário.
- `generate_combn`: Função recursiva que gera todas as combinações possíveis.
- `ft_print_combn`: Função principal chamada pelo usuário.

---

## Comentários

- O código é flexível para qualquer valor de n entre 1 e 9.
- O uso de recursão torna a solução elegante e fácil de entender.
- O array `comb` armazena os dígitos da combinação atual.
- O controle de formatação evita a vírgula após a última combinação.

---

## Referências
- [Documentação da função write](https://man7.org/linux/man-pages/man2/write.2.html)
- [Recursividade em C](https://www.tutorialspoint.com/cprogramming/c_recursion.htm) 