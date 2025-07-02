
# 📘 Explicações das Soluções — Exercícios em C

---

## 🧠 Exercício 1 — `ft_print_lowercase_odd`
- Usa um `char` iniciando em `'a'` e incrementa de 2 em 2.
- Só imprime letras nas posições ímpares do alfabeto.
- Usa `write()` para cada caractere.

---

## 🧠 Exercício 2 — `ft_print_even_digits`
- Usa `char digit` começando em `'0'` até `'9'`.
- Converte para int com `digit - '0'`.
- Usa `if` para verificar se o número é par.
- Imprime só os pares com `write()`.

---

## 🧠 Exercício 3 — `ft_is_zero`
- Recebe um `int`.
- Usa `if`, `else if` e `else` para decidir:
  - `Z` se for zero
  - `N` se for negativo
  - `P` se for positivo
- Não usa entrada externa; os números estão no `main()`.

---

## 🧠 Exercício 4 — `ft_print_reverse_numbers`
- Usa `char digit = '9'`.
- Decrementa com `--` até `'0'`.
- Imprime cada número com `write()`.

---

## 🧠 Exercício 5 — `ft_print_case_switch`
- Alterna letras entre minúsculas e maiúsculas usando `if` e uma flag `toggle`.
- `current = letter - 32` converte minúscula em maiúscula.
- Toggle troca entre 0 e 1 a cada letra.
- Usa `write()` para exibir letra a letra.
