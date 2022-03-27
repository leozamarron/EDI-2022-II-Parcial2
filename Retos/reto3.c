#include <stdio.h>
#include <string.h>
#define N 3

void ordenaAscendente(char *letras, char *abecedario);
void capturaDatos(char *letras);
char calculaMayor(char *letras, char *objetivo, char *abecedario);

int main()
{
    char letras[N];
    char abecedario[52];
    char objetivo, aux;

    abecedario[0]='a'; abecedario[1]='b'; abecedario[2]='c'; abecedario[3]='d'; abecedario[4]='e'; abecedario[5]='f';
    abecedario[6]='g'; abecedario[7]='h'; abecedario[8]='i'; abecedario[9]='j'; abecedario[10]='k'; abecedario[11]='l';
    abecedario[12]='m'; abecedario[13]='n'; abecedario[14]='o'; abecedario[15]='p'; abecedario[16]='q'; abecedario[17]='r';
    abecedario[18]='s'; abecedario[19]='t'; abecedario[20]='u'; abecedario[21]='v'; abecedario[22]='w'; abecedario[23]='x';
    abecedario[24]='y'; abecedario[25]='z';

    
    capturaDatos(letras);
    ordenaAscendente(letras, abecedario);

    printf("\nDame el objetivo: ");
    scanf(" %c", &objetivo);

    aux = calculaMayor(letras, &objetivo, abecedario);

    printf("salida: %c", aux);

    return 0;
}

char calculaMayor(char *letras, char *objetivo, char *abecedario)
{
    int  contadorObj = 0;
    int aux, contador;
    char aux2;

    while (*objetivo != abecedario[contadorObj])
        {
            contadorObj++;
        }
    
    for (int i = 0; i < N; i++)
    {
        contador = 0;
        while (letras[i] != abecedario[contador])
        {
            contador++;
        }
        
        if (contador > contadorObj)
        {
            return letras[i];
        }
    }
    return letras[0];
}

void ordenaAscendente(char *letras, char *abecedario)
{
    int aux, contador;
    char aux2;
    for (int i = 0; i < N; i++)
    {
        contador = 0;
        while (letras[i] != abecedario[contador])
        {
            contador++;
        }

        if (i > 0 && aux > contador)
        {
            aux2 = letras[i];
            letras[i] = letras[i-1];
            letras[i-1] = aux2;
        }
        aux = contador;
    }
    for (int i = 0; i < N; i++)
    {
        printf("%c ",letras[i]);
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