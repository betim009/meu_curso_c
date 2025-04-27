## Exercício 06: ft_print_comb2

### Requisitos

- **Função**: `ft_print_comb2`
- **Arquivo**: `ft_print_comb2.c`
- **Diretório**: `ex06/`
- **Protótipo**: `void ft_print_comb2(void);`
- **Funções permitidas**: `write`

### Enunciado

Neste exercício, você vai praticar a lógica de repetição e a forma correta de formatar uma saída na tela. O desafio é criar uma função que imprima **todas as combinações possíveis** de dois números de dois dígitos (variando de `00` até `99`), **sem repetições** e **em ordem crescente**.

A ideia é simular todas as possibilidades como se você estivesse listando combinações entre pessoas ou times: cada par é único, e "00 01" é diferente de "01 00" (não queremos combinações invertidas!).

- O primeiro número **sempre deve ser menor** que o segundo.
- Cada combinação é separada por uma **vírgula e um espaço**.
- A última combinação **não deve** ter vírgula e espaço após ela.

**Exemplo de Saída:**

```c
00 01, 00 02, 00 03, ..., 97 98, 97 99, 98 99
```

### Explicação do Objetivo

Imagine que você tem todos os números de 00 a 99 e quer formar todos os pares sem repetir nem inverter. Para isso:
- Primeiro, escolha um número (ex: 00).
- Depois, combine com todos os números maiores que ele (01, 02, 03, ..., 99).
- Em seguida, passe para o próximo número (01) e combine com 02, 03, ..., 99.
- E assim por diante até formar todos os pares.

Essa lógica vai te ensinar como "percorrer combinações" usando **loops aninhados**, um conceito super importante em programação!

### Entendimento do Exercício

- Gerar todos os pares de números de 0 a 99.
- Exibir apenas os pares onde o primeiro é menor que o segundo.
- Sempre imprimir dois dígitos, mesmo para números menores que 10 (ex: "03").
- Separar as combinações por ", ", exceto depois da última combinação.

### Explicação da Estratégia

1. Criar dois loops:
   - Um loop para o primeiro número (`a`), de 0 a 98.
   - Um loop para o segundo número (`b`), começando de `a + 1` até 99.

2. Para cada par (`a`, `b`):
   - Imprimir o `a` com dois dígitos.
   - Imprimir um espaço.
   - Imprimir o `b` com dois dígitos.
   - Se não for o último par ("98 99"), imprimir ", ".

### Exemplo de Estrutura de Código

```c {copy}
#include <unistd.h>

// Função para imprimir um caractere
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Função para imprimir dois dígitos
void ft_putnbr2(int n)
{
    ft_putchar(n / 10 + '0');
    ft_putchar(n % 10 + '0');
}

// Função principal que gera as combinações
void ft_print_comb2(void)
{
    int a;
    int b;

    a = 0;
    while (a <= 98)
    {
        b = a + 1;
        while (b <= 99)
        {
            ft_putnbr2(a);
            ft_putchar(' ');
            ft_putnbr2(b);
            if (!(a == 98 && b == 99))
                write(1, ", ", 2);
            b++;
        }
        a++;
    }
}
```

### Explicação do Código Passo a Passo

1. **`ft_putchar`**: Serve para escrever um caractere no terminal.
2. **`ft_putnbr2`**: Escreve um número sempre com dois dígitos, mesmo que seja "03", "09", etc.
3. **`ft_print_comb2`**:
   - Começa `a` em 0 e repete até 98.
   - Para cada `a`, `b` começa em `a+1` e vai até 99.
   - Imprime `a` e `b`, separados por espaço.
   - Adiciona ", " entre os pares, menos após "98 99".

### Como testar seu código

```c {copy}
#include <unistd.h>

void ft_print_comb2(void);

int main(void)
{
    ft_print_comb2();
    write(1, "\n", 1);
    return (0);
}
```

### Dicas Importantes

- **Sempre** lembre de imprimir dois dígitos.
- **Nunca** deixar uma vírgula sobrando no final.
- **Organize** seu código usando funções auxiliares para ficar mais limpo e entendível.
- **Pense passo a passo**, como se estivesse montando pares em um campeonato!

### Conclusão

Esse exercício é uma oportunidade de treinar:
- **Loops aninhados** (repetições dentro de repetições).
- **Comparar e respeitar regras** (primeiro menor que segundo).
- **Formatar saídas** exatamente como pedido.

Se você entender bem esse exercício, vai estar muito mais preparado para resolver problemas maiores que exigem combinações, comparação e controle de saídas!

---

Bons estudos! Vamos em frente! 🚀