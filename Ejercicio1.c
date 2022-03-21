#include <stdio.h>
#include <string.h>
#define N 12

int recursividad(char *cadena, int inicio, int fin, char *copia);
void cambioAlRevez(char *copia, int fin);
void eliminaEspacios(char *cadena, int *fin);

int main()
{
    char cadena[N];
    int inicio = 0;
    int fin;
    int palindroma;
    char copia[N];

    printf("Dame la cadena: ");
    scanf("%[^\n]", &cadena);

    fin = strlen(cadena);
    eliminaEspacios(cadena, &fin);
    strcpy(copia, cadena);
    cambioAlRevez(copia, fin);
    palindroma = recursividad(cadena, inicio, fin, copia);
    
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
    char aux;

    for (int i = 0, j = fin - 1; i < (fin / 2);
       i++, j--) 
    {
        aux = copia[i];
        copia[i] = copia[j];
        copia[j] = aux;
    }
}

int recursividad(char *cadena, int inicio, int fin, char *copia)
{
    
    if (fin < 0)
    {
        return 1;
    }
    else if(cadena[inicio] != copia[inicio])
    {
        return 0;
    }
    else
    {
        return recursividad(cadena, inicio + 1, fin-1, copia);
    }
}