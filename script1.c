#include <stdio.h>

// int muda(int *p)
// {
//     return *p = 100;
// }

// int main()
// {
//     int x = 10;
//     muda(&x);
//     printf("%d", x);
//     return 0;
// }

// // Código utilizando variavel simples para dobrar de valor.
// int main() {
//     int numero = 10;
//     numero+=numero;

//     printf("%d", numero);
//     return 0;
// }

// int dobrar(int *p)
// {
//     *p+=*p;
//     return *p;
// }

// int main()
// {   
//     int numero = 10;
//     dobrar(&numero);

//     printf("%d", numero);
// }

void exibindo(const char *pNome, int *pIdade) {
    printf("%s tem %d anos de idade.", pNome, *pIdade);
} 


int main()
{   
    char nome[20] = "Jean";
    int numero = 10;

    exibindo(nome, &numero);

    return 0;
}