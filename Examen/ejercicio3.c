#include <stdio.h>
#define N 20 //numero de carcateres
#define M 3  //numero de personas

typedef struct calificaciones
{
    char nombres[M][N];
    float calificacion[M];
} calif;


void capturaDatos(calif *cola);
void quickSort(calif *n, int inicio, int fin);
void salidaDatos(calif cola);

int main()
{
    calif cola;

    capturaDatos(&cola);
    quickSort(&cola,0,M-1);
    salidaDatos(cola);

    return 0;
}

void salidaDatos(calif cola)
{
    for (int i = 0; i < M; i++)
    {
        printf("%s ", cola.nombres[i]);
        printf("%.1f\n", cola.calificacion[i]);
    }
}


void quickSort(calif *n, int inicio, int fin)
{
    int derecha, izquierda;
    float pivote;
    float aux;

    if (inicio >= fin)
    {
        return;
    }

    pivote = n -> calificacion[inicio];
    izquierda = inicio;
    derecha = fin;

    do
    {
        while (n -> calificacion[izquierda] < pivote && izquierda < fin)
        {
            izquierda++;
        }
        while (pivote < n -> calificacion[derecha] && derecha > inicio)
        {
            derecha --;
        }
        if (izquierda <= derecha)
        {
            aux = n -> calificacion[izquierda];
            n -> calificacion[izquierda] = n -> calificacion[derecha];
            n -> calificacion[derecha] = aux;

            char aux[N];

            for (int i = 0; i < N; i++)
            {
                aux[i] = n -> nombres[izquierda][i];
                n -> nombres[izquierda][i] = n -> nombres[derecha][i];
                n -> nombres[derecha][i] = aux[i];
            }
            
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

void capturaDatos(calif *cola)
{
    for (int i = 0; i < M; i++)
    {
        printf("Dame el nombre de la persona %d: ",i);
        scanf("%s", &cola->nombres[i]);

        printf("Dame la calificacion de %s: ", cola->nombres[i]);
        scanf("%f", &cola->calificacion[i]);
    }
}