# 📚 Exercício 05: `ft_print_comb` (Explicação Completa para Iniciantes)

---

## 📌 Requisitos

* **Função**: `ft_print_comb`
* **Arquivo**: `ft_print_comb.c`
* **Diretório**: `ex05/`
* **Protótipo**: `void ft_print_comb(void);`
* **Funções permitidas**: `write`

---

## 📝 Enunciado Detalhado

O objetivo deste exercício é criar uma função que imprima **todas as combinações possíveis de três dígitos diferentes**, escolhidos de 0 a 9. Porém, essas combinações precisam seguir duas regras:

1. **Ordem crescente:** os dígitos devem estar sempre em ordem do menor para o maior. Exemplo: `012` é válido, mas `210` não é.
2. **Sem repetição de dígitos:** cada dígito deve aparecer **apenas uma vez** na mesma combinação. Exemplo: `112` não é permitido.

Além disso:

* As combinações devem ser separadas por vírgula e espaço (`, `), **exceto** a última combinação (`789`).

### ✅ Exemplo de saída correta:

```
012, 013, 014, ..., 789
```

### ❌ Exemplos que NÃO devem aparecer:

* `321` (fora de ordem)
* `999` (dígitos repetidos)
* `987` (apesar de ser formado pelos mesmos números de `789`, a ordem está errada)

---

## 🔍 Entendimento do Exercício

Para gerar todas as combinações possíveis:

* Precisamos de **três laços de repetição** (um para cada dígito).
* Vamos usar os caracteres `'0'` até `'9'` (valores `char`, não `int`).
* Cada laço precisa garantir que o próximo número **sempre seja maior que o anterior**, evitando repetições e mantendo a ordem.

---

## ⚙️ Estratégia de Solução (Explicação Didática)

1. **Usamos três variáveis:**

   * `a`: representa o primeiro dígito.
   * `b`: representa o segundo dígito.
   * `c`: representa o terceiro dígito.

2. **Valores iniciais e limites:**

   * `a` vai de `'0'` até `'7'`.

     * Por quê `'7'`? Porque depois de `'7'`, não há dois números maiores disponíveis.
   * `b` começa de `a + 1` e vai até `'8'`.
   * `c` começa de `b + 1` e vai até `'9'`.

3. **Impressão dos dígitos:**

   * Usamos a função `write(1, &a, 1)` para imprimir cada caractere.

4. **Separação entre combinações:**

   * Após imprimir `a`, `b` e `c`, verificamos se essa é a última combinação (`789`).
   * Se **não** for a última, imprimimos a vírgula e o espaço.

---

## 🧠 Visualizando as combinações

As primeiras combinações válidas:

```
012, 013, 014, ..., 019,
023, 024, 025, ..., 029,
...
789
```

Cada número é único e está em ordem crescente.

---

## 🧑‍💻 Código Completo com Explicação

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

---

## 🔬 Explicando passo a passo

1. `a = '0'` → começa com o menor valor possível.
2. `b = a + 1` → o próximo número tem que ser sempre maior.
3. `c = b + 1` → mesma lógica: sempre valores únicos e em ordem crescente.
4. `write` imprime os três caracteres.
5. `if (!(a == '7' && b == '8' && c == '9'))` → garante que não será impresso ", " após a última combinação.

---

## 🧪 Como testar seu código

```c
#include <unistd.h>

void ft_print_comb(void);

int main(void)
{
    ft_print_comb();
    write(1, "\n", 1);
    return (0);
}
```

---

## ⚠️ Dicas Importantes

* No C, os números como `'0'`, `'1'` etc. são caracteres (`char`), e não inteiros.
* Você pode fazer contas com caracteres, porque `'0' + 1` é igual a `'1'`.
* Sempre use `!=` ou `==` com cuidado, pois estamos comparando letras/dígitos e não valores numéricos reais.
* Preste atenção à **última combinação** para não imprimir a vírgula depois dela.

---

## ✅ Conclusão

Esse exercício ajuda a entender:

* Laços aninhados (um dentro do outro)
* Como construir combinações únicas
* Como manipular caracteres e trabalhar com formatação precisa

Se você dominar esse exercício, estará preparado para desafios que envolvem lógica de repetição e controle de saída na tela.

Bons estudos, meu rei! 🚀😉
