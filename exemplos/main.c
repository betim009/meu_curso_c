#include <stdio.h>

void hello(const char *name)
{
    printf("Hello %s\n", name);
}

int main()
{
    char name[50];
    printf("Digite seu nome: ");
    scanf("%49s", name);

    hello(name);
    hello("Alberto");
    return 0;
}
