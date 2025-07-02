#include <stdio.h>

int main()
{
    // Array armazenando idades
    int idades[] = {12, 5, 33, 21};

    float media, soma = 0;

    int i;

    int length = sizeof(idades) / sizeof(idades[0]);

    for (i = 0; i < length; i++)
    {
        printf("%d\n", idades[i]);
        soma += idades[i];
    }
    printf("Soma: %.f", soma);
    
    return 0;
}
