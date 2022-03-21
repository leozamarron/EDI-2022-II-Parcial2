#include <stdio.h>
#include <string.h>
#define N 4
#define M 20

void capturaNombres(char nombres[N][M]);
int buscarNombres(char nombres[N][M]);

int main()
{
    char nombres[N][M];
    int val;

    capturaNombres(nombres);
    val = buscarNombres(nombres);

    printf("%d", val);

    return 0;
}

void capturaNombres(char nombres[N][M])
{
    for (int i = 0; i < N; i++)
    {
        printf("dame el nombre del numero %d: ", i);
        scanf("%s", &nombres[i][M]);
    }
}

int buscarNombres(char nombres[N][M])
{
    char nombre[M];
    int cantidad;
    int bandera = 0;

    printf("dame el nombre que quieras buscar: ");
    scanf("%s", nombre);

    for (int i = 0; i < N && bandera == 0; i++)
    {
        cantidad = strlen(nombres[i]);
        for (int j = 0; j < cantidad; j++)
        {
            if (nombre[j] == nombres[i][j])
            {
                bandera = i;
            }
            else
            {
                bandera = 0;
                j = cantidad;
            }
        }
    }
    return bandera;
}

