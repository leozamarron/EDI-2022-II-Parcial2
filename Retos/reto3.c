#include <stdio.h>
#define N 3

void ordenaAscendente(char *letras);
void capturaDatos(char *letras);
char calculaMayor(char *letras, char *objetivo);

int main()
{
    char letras[N];
    char objetivo, aux;
    
    capturaDatos(letras);
    ordenaAscendente(letras);

    printf("Dame el objetivo: ");
    scanf(" %c", &objetivo);

    aux = calculaMayor(letras, &objetivo);

    printf(" %c", aux);

    return 0;
}

char calculaMayor(char *letras, char *objetivo)
{

    for (int i = 0; i < N; i++)
    {
        if (*objetivo > letras[i]);
        {
            return letras[i];
        }
    }
    *objetivo = letras[0];
}

void ordenaAscendente(char *letras)
{
    char aux;
    char U; //ultimo
    char P; //primero
    char C;
    for (int i = 1; i < N; i++)
    {
        aux = letras[i];
        P = letras[i];
        U = letras[i-1];
        while (P <= U)
        {
            C = (P+U)/2;
            if (aux < letras[C])
            {
                U = C - 1;
            }
            else
            {
                P = C + 1;
            }
        }
        for (int j = i - 1; j > P; i--)
        {
            letras[j+1] = letras[j];
        }
        
    }
}

void capturaDatos(char *letras)
{
    for (int i = 0; i < N; i++)
    {
        printf("Dame la letra %d: ",i);
        scanf(" %c",&letras[i]);
    }
}