#include <stdio.h>

void dobrar(int valor) {
    valor = valor * 2;
    printf("valor: %d", valor);
}

int main() {
    int x = 5;
    dobrar(x);
    printf("x: %d\n", x); // Saída: 5 (não mudou)
    return 0;
}