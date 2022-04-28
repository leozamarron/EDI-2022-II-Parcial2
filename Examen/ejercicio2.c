#include <stdio.h>
#include <string.h>
#define N 20

void recursividad(char *cambio, int i, int fin);

int main()
{
    char cambio[N];
    int fin;

    printf("Dame una palabra: ");
    scanf("%[^\n]", &cambio);

    fin = strlen(cambio);

    recursividad(cambio, 0, fin);

    return 0;
}

void recursividad(char *cambio, int i, int fin)
{
    if (i != fin)
    {
    recursividad(cambio, i+1, fin);
    }
    
    printf("%c",cambio[i]);
}