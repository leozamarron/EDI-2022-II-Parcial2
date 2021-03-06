#include <stdio.h>
#define N 5

void capturaDatos(int *n);
void quickSort(int *n, int inicio, int fin);

int main()
{
    int num[N];

    capturaDatos(num);
    quickSort(num, 0, N-1);

    for (int i = 0; i < N; i++)
    {
        printf("%d ",num[i]);
    }

    return 0;
}

void quickSort(int *n, int inicio, int fin)
{
    int derecha, izquierda;
    int pivote;
    int aux;

    if (inicio >= fin)
    {
        return;
    }

    pivote = n[inicio];
    izquierda = inicio;
    derecha = fin;

    do
    {
        while (n[izquierda] < pivote && izquierda < fin)
        {
            izquierda++;
        }
        while (pivote < n[derecha] && derecha > inicio)
        {
            derecha --;
        }
        if (izquierda <= derecha)
        {
            aux = n[izquierda];
            n[izquierda] = n[derecha];
            n[derecha] = aux;
            izquierda++;
            derecha--;
        }
        
        
    } while (izquierda <= derecha);

    if (inicio < derecha)
    {
        quickSort(n, inicio, derecha);
    }
    if (fin > izquierda)
    {
        quickSort(n, izquierda, fin);
    }
    
}

void capturaDatos(int *n)
{
    for (int i = 0; i < N; i++)
    {
        printf("Dame el numero %d: ",i);
        scanf("%d",&n[i]);
    }
}