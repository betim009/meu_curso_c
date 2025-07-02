
# ✅ Gabarito — Exercícios em C com `write()`

---

## Exercício 1
```c
#include <unistd.h>

void ft_print_lowercase_odd(void) {
    char letter = 'a';
    while (letter <= 'y') {
        write(1, &letter, 1);
        letter += 2;
    }
}

int main() {
    ft_print_lowercase_odd();
    write(1, "\n", 1);
    return 0;
}
```

---

## Exercício 2
```c
#include <unistd.h>

void ft_print_even_digits(void) {
    char digit = '0';
    while (digit <= '9') {
        if ((digit - '0') % 2 == 0)
            write(1, &digit, 1);
        digit++;
    }
}

int main() {
    ft_print_even_digits();
    write(1, "\n", 1);
    return 0;
}
```

---

## Exercício 3
```c
#include <unistd.h>

void ft_is_zero(int n) {
    if (n == 0)
        write(1, "Z", 1);
    else if (n < 0)
        write(1, "N", 1);
    else
        write(1, "P", 1);
}

int main() {
    ft_is_zero(0);
    ft_is_zero(-1);
    ft_is_zero(1);
    write(1, "\n", 1);
    return 0;
}
```

---

## Exercício 4
```c
#include <unistd.h>

void ft_print_reverse_numbers(void) {
    char digit = '9';
    while (digit >= '0') {
        write(1, &digit, 1);
        digit--;
    }
}

int main() {
    ft_print_reverse_numbers();
    write(1, "\n", 1);
    return 0;
}
```

---

## Exercício 5
```c
#include <unistd.h>

void ft_print_case_switch(void) {
    char letter = 'a';
    int toggle = 0;

    while (letter <= 'f') {
        char current = letter;
        if (toggle)
            current = letter - 32;
        write(1, &current, 1);
        letter++;
        toggle = !toggle;
    }
}

int main() {
    ft_print_case_switch();
    write(1, "\n", 1);
    return 0;
}
```
