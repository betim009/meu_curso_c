# Guia de Estudo: ft_putchar (Escola 42)

## Sobre o Exercício

Este guia aborda o exercício `ft_putchar` da Piscine C da Escola 42, que é um dos primeiros exercícios do currículo.

## Requisitos do Exercício

- **Função**: `ft_putchar`
- **Objetivo**: Exibir um caractere na tela
- **Arquivo de entrega**: `ft_putchar.c`
- **Diretório**: `ex00/`
- **Funções permitidas**: Apenas `write`
- **Protótipo**: `void ft_putchar(char c);`

## Explicação Detalhada

### 1. Fundamentos da Saída de Caracteres em C

Em programação C, existem várias formas de exibir caracteres no terminal:

| Função | Biblioteca | Nível | Descrição |
|--------|------------|-------|-----------|
| `printf()` | `stdio.h` | Alto | Função versátil para formatar e exibir texto |
| `putchar()` | `stdio.h` | Médio | Função dedicada para exibir um único caractere |
| `write()` | `unistd.h` | Baixo | Função de sistema que escreve em descritores de arquivo |

A Escola 42 intencionalmente limita as funções permitidas para encorajar o aprendizado profundo das operações fundamentais em C.

### 2. Entendendo a Função `write()`

A função `write()` é uma chamada de sistema de baixo nível definida em `unistd.h`:

```c
ssize_t write(int fd, const void *buf, size_t count);
```

#### Parâmetros:
- `fd` (File Descriptor): Um número que representa um fluxo de entrada/saída
  - `0`: Entrada padrão (stdin)
  - `1`: Saída padrão (stdout) - o que queremos usar
  - `2`: Erro padrão (stderr)
- `buf`: Um ponteiro para os dados que queremos escrever
- `count`: Quantidade de bytes a serem escritos

#### Valor de Retorno:
- Em caso de sucesso: retorna o número de bytes escritos
- Em caso de erro: retorna -1

### 3. Implementação de ft_putchar

```c
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
```

#### Explicação linha por linha:

1. `#include <unistd.h>`: Inclui o cabeçalho necessário para usar a função `write()`
2. `void ft_putchar(char c)`: Define uma função que:
   - Recebe um caractere como parâmetro
   - Não retorna nenhum valor (`void`)
3. `write(1, &c, 1)`:
   - `1`: Escreve na saída padrão (terminal)
   - `&c`: Passa o endereço do caractere (precisamos de um ponteiro)
   - `1`: Escreve apenas 1 byte (tamanho de um char)

### 4. Importância no Currículo

Este exercício, apesar de simples, estabelece fundamentos cruciais:

1. **Base para saída**: Todas as funções futuras de saída de texto usarão esse conhecimento
2. **Introdução a ponteiros**: O uso de `&c` introduz o conceito de endereços de memória
3. **E/S de baixo nível**: Ensina como os dados são escritos em nível de sistema
4. **Norma de código**: Pratica o estilo de codificação exigido pela Escola 42

### 5. Como Testar

Crie um arquivo `main.c` para testar sua função:

```c
#include <unistd.h>

void ft_putchar(char c);  // Protótipo

int main(void)
{
    ft_putchar('H');
    ft_putchar('e');
    ft_putchar('l');
    ft_putchar('l');
    ft_putchar('o');
    ft_putchar('\n');
    return (0);
}
```

Para compilar e executar:
```bash
gcc -Wall -Wextra -Werror main.c ft_putchar.c -o test
./test

gcc ft_putchar.c -o ft_putchar.exe
./ft_putchar.exe

```

Deve exibir:
```
Hello
```

## Solução Completa

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:00:00 by student           #+#    #+#             */
/*   Updated: 2025/04/23 10:00:00 by student           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

## Conhecimentos Relacionados para Explorar

- **Descritores de arquivo**: Como o sistema operacional gerencia fluxos de E/S
- **ASCII e representação de caracteres**: Como caracteres são armazenados como números
- **Funções de E/S em C**: A hierarquia completa de funções de entrada e saída
- **Buffers de E/S**: Como a saída é otimizada através de buffers

---

Este guia foi criado para ajudar estudantes da Escola 42 a entenderem melhor o exercício ft_putchar e seus conceitos subjacentes.