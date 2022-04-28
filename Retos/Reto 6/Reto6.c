#include <stdio.h>
#define N 5

typedef struct cola
{
    int K;
    int last;
    int total[N+1];
    int fin;
    int inicio;
}Cola;
//cola->fin = N +1 % cola->fin + 1; 

void eliminarElemento(Cola *cola);

int main()
{
    Cola cola;

    printf("Dame un numero k tal que k es el numero que se cuenta: ");
    scanf("%d", &cola.K);

    inicializarCola(&cola);
    eliminarElemento(&cola);   
}

void eliminarElemento(Cola *cola)
{
    int i, j = 0;
    do
    {
        j++;
        
        cola->last = cola->total[i];
    } while (colaVacia == 1);
}

int colaVacia(Cola *cola)
{
    int v = 0;
    if(cola->inicio == cola->fin)
        v = 1;

    return v;
}

void inicializarCola(Cola *cola)
{
    cola->fin = 1;
    cola->inicio = 1;
    for (int i = 1; i < N+1; i++)
    {
        cola->total[i] = i; 
        cola->inicio++; 
    }
}