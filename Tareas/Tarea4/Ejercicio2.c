#include <stdio.h>
#include <math.h>

typedef struct coordenadas
{
    int puntoX[2];
    int puntoY[2];
    int distancia;
} estructura_coordenadas;

void capturaDatos(estructura_coordenadas *puntos);
void imprimeDatos(estructura_coordenadas puntos);
void calculaDistancia(estructura_coordenadas *puntos);
void imprimeDistancia(estructura_coordenadas puntos);

int main()
{
    estructura_coordenadas puntos;

    capturaDatos(&puntos);
    imprimeDatos(puntos);
    calculaDistancia(&puntos);
    imprimeDistancia(puntos);
}

void imprimeDistancia(estructura_coordenadas puntos)
{
    printf("La distancia es: %d", puntos.distancia);
}

void calculaDistancia(estructura_coordenadas *puntos)
{
    puntos -> distancia = sqrt( pow(puntos -> puntoX[1] - puntos -> puntoX[0], 2) + pow(puntos -> puntoY[1] - puntos -> puntoY[0], 2));
}

void imprimeDatos(estructura_coordenadas puntos)
{
    printf("Punto 1: (%d,%d)\n", puntos.puntoX[0], puntos.puntoY[0]);
    printf("Punto 2: (%d,%d)\n", puntos.puntoX[1], puntos.puntoY[1]);
}

void capturaDatos(estructura_coordenadas *puntos)
{
    for (int i = 0; i < 2; i++)
    {
        printf("Dame el punto x%d: ", i+1);
        scanf("%d", &(puntos -> puntoX[i]));

        printf("Dame el punto y%d: ", i+1);
        scanf("%d", &(puntos -> puntoY[i]));
    }
}