#include <stdio.h>
#include <string.h>
#define N 20

int calculaC(char *cadena, int inicio, int fin);
void cambioAlRevez(char *copia, int fin);
void eliminaEspacios(char *cadena, int *fin);

int main()
{
    char cadena[N];
    int inicio = 0;
    int fin;
    int regreso;

    printf("Dame la cadena: ");
    scanf("%[^\n]", &cadena);

    fin = strlen(cadena);
    eliminaEspacios(cadena, &fin);

    regreso = calculaC(cadena, inicio, fin);
    printf("%d", regreso);

    return 0;
}

void eliminaEspacios(char *cadena, int *fin)
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == ' ')
        {
            for (int j = i; j < *fin; j++)
            {
                cadena[j] = cadena[j+1];
            }
            *fin = *fin - 1;
        }
        
    }
}

void cambioAlRevez(char *copia, int fin)
{
    char aux;

    for (int i = 0, j = fin - 1; i < (fin / 2);
       i++, j--) 
    {
        aux = copia[i];
        copia[i] = copia[j];
        copia[j] = aux;
    }
}

int calculaC(char *cadena, int inicio, int fin)
{
    int val = 1;
    char copia[N];
    strcpy(copia, cadena);
    cambioAlRevez(copia, fin);

    for (int i = 0; i < fin-1; i++)
    {
        if (cadena[i] != copia[i])
        {
            val = 0;
            i = fin;
        }
    }
    return val;
}