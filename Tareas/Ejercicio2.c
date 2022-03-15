#include <stdio.h>
#include <string.h>
#define N 20

int palindroma(char *cadena, int inicio, int fin);
void cambioAlRevez(char *copia, int fin);
void eliminaEspacios(char *cadena, int *fin);

int main()
{
    char cadena[N];
    int inicio = 0;
    int fin;
    int palindroma;

    printf("Dame la cadena: ");
    scanf("%[^\n]", &cadena);

    fin = strlen(cadena);
    eliminaEspacios(cadena, &fin);

    palindroma = recursividad(cadena, inicio, fin);
    printf("%d", palindroma);

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
    int aux;

    for (int j = fin; j > 0; j--)
    {
        for (int i = 0; i < fin; i++)
        {
            aux = copia[j];
            copia[j] = copia[i];
            copia[i] = copia[j];
        }
    }
}

int palindroma(char *cadena, int inicio, int fin)
{
    int val = 1;
    char copia[N];
    strcpy(copia, cadena);
    cambioAlRevez(copia, fin);

//    if (inicio > fin)
//    {
//        return 1;
//    }
//    if (cadena[inicio] == copia [fin])
//    {
//        return recursividad(cadena, inicio + 1, fin - 1);
//    }
//    else
//    {
//        return 0;
//    }

    for (int i = 0; i < fin-1; i++)
    {
        for (int j = fin-1; j > i; j--)
        {
            if (cadena[i] != cadena[j])
            {
                val = 0;
            }
            
        }
    }
}