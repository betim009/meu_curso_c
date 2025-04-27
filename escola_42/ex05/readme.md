## Exercício 05: ft_print_comb

### Requisitos

- **Função**: `ft_print_comb`
- **Arquivo**: `ft_print_comb.c`
- **Diretório**: `ex05/`
- **Protótipo**: `void ft_print_comb(void);`
- **Funções permitidas**: `write`

### Enunciado

O objetivo deste exercício é criar uma função que imprima todas as combinações possíveis de três dígitos diferentes, usando apenas os números de 0 a 9. Essas combinações precisam obedecer à seguinte regra:

- Os três dígitos devem estar **em ordem crescente**. Por exemplo:
  - "123" é válido (1 < 2 < 3).
  - "321" não é válido (3 > 2).

- **Não pode haver repetição** de dígitos:
  - "112" não é permitido.
  - Cada dígito na combinação deve ser único.

- Cada combinação impressa deve ser seguida por uma vírgula e um espaço (",") **exceto** depois da última combinação.

- O formato da saída deve ser uma sequência de combinações, como no exemplo abaixo:

**Exemplo de Saída:**
```text
012, 013, 014, ..., 789
```

A ideia é construir todas as sequências possíveis sem repetir dígitos e sempre respeitando a ordem crescente.

### Entendimento do Exercício

- Precisamos gerar todas as combinações possíveis de três dígitos onde:
  - Todos os dígitos são diferentes.
  - Os números aparecem em ordem crescente.
  - Separar as combinações com ", ".
  - Não adicionar a vírgula após a última combinação.

### Explicação do Código

```c
#include <unistd.h>

void ft_print_comb(void)
{
    char a;
    char b;
    char c;

    a = '0';
    while (a <= '7')
    {
        b = a + 1;
        while (b <= '8')
        {
            c = b + 1;
            while (c <= '9')
            {
                write(1, &a, 1);
                write(1, &b, 1);
                write(1, &c, 1);
                if (!(a == '7' && b == '8' && c == '9'))
                    write(1, ", ", 2);
                c++;
            }
            b++;
        }
        a++;
    }
}
```

#### Como funciona passo a passo:

1. **Definimos três variáveis** (`a`, `b`, `c`) que representam os dígitos.
2. **Primeiro loop**:
   - `a` vai de '0' a '7'.
   - (Se `a` fosse maior que '7', não sobrariam dois números maiores para formar a combinação.)
3. **Segundo loop**:
   - `b` começa de `a+1` e vai até '8'.
   - (Garantindo que `b` é sempre maior que `a`.)
4. **Terceiro loop**:
   - `c` começa de `b+1` e vai até '9'.
   - (Garantindo que `c` é maior que `b`.)
5. **Escrita dos caracteres**:
   - Imprimimos `a`, `b` e `c` juntos.
6. **Separador**:
   - Se a combinação atual **não** for "789", imprimimos também ", ".

### Exemplo da Saída

```text
012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, ..., 789
```

### Como testar seu código

```c
#include <unistd.h>

void ft_print_comb(void);

int main(void)
{
    ft_print_comb();
    write(1, "\n", 1); // Para adicionar quebra de linha no final.
    return (0);
}
```

### Dicas importantes

- Sempre que trabalhar com combinações:
  - Certifique-se que os dígitos não se repetem.
  - Certifique-se que a ordem é crescente.
- No C, os caracteres numéricos ('0', '1', etc.) são tratados como `char`, por isso usamos comparação de caracteres.
- Atenção para não adicionar ", " após a última combinação.

### Conclusão

Esse exercício é essencial para entender:
- Como funcionam **loops aninhados**.
- Como fazer **combinações** de valores.
- Como **formatar saídas** de forma precisa.

-------------
