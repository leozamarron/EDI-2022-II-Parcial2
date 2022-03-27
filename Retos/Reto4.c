#include <stdio.h>

void capturaTam(int *N);
void capturaDatos(int *array, int N);
void sumaMatrices(int *arr1, int *arr2, int *arrSuma, int M, int N, int C);
void quickSort(int *n, int inicio, int fin);
void imprimeDatos(int *arraySuma, int C);

int main()
{
    int M, N = 0;

    capturaTam(&N);
    capturaTam(&M);

    int C = M + N;
    int array1[N];
    int array2[M];
    int arraySuma[C];

    capturaDatos(array1, N);
    capturaDatos(array2, M);
    sumaMatrices(array1, array2, arraySuma, M, N, C);
    quickSort(arraySuma, 0, C-1);
    imprimeDatos(arraySuma, C);

    return 0;
}

void imprimeDatos(int *arraySuma, int C)
{
    for (int i = 0; i < C; i++)
    {
        printf("%d ",arraySuma[i]);
    }
    
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

void sumaMatrices(int *arr1, int *arr2, int *arrSuma,  int M, int N, int C)
{
    for (int i = 0; i < N; i++)
    {
        arrSuma[i] = arr1[i];
    }
    for (int i = N; i < C; i++)
    {
        arrSuma[i] = arr2[i-N];
    }
}

void capturaDatos(int *array, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("Dame el numero %d: ",i);
        scanf("%d",&array[i]);
    }
}

void capturaTam(int *N)
{
    printf("Dame el tamaño del arreglo: ");
    scanf("%d", N);

    if(*N > 100)
    {
        do
        {
            printf("El tamaño del arreglo tiene que ser menor o igual a 100: ");
            scanf("%d", N);
        } while (*N > 100);
    }
}