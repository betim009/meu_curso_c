#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t s_len;
    size_t i;
    char *sub;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
    {
        sub = (char *)malloc(1);
        if (!sub)
            return (NULL);
        sub[0] = '\0';
        return (sub);
    }
    if (len > s_len - start)
        len = s_len - start;
    sub = (char *)malloc(len + 1);
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}

int main(void)
{
    char *original;
    char *substring;

    original = "Banana";
    substring = ft_substr(original, 0, 5);
    if (!substring)
    {
        fprintf(stderr, "Erro: falha ao alocar memoria para substring.\n");
        return (1);
    }
    printf("String original: \"%s\"\n", original);
    printf("Substring extraida: \"%s\"\n", substring);
    free(substring);
    return (0);
}

/*
** Como compilar e executar:
** 1. gcc ft_substr.c -o ft_substr
** 2. ./ft_substr
*/
