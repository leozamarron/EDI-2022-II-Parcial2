#include <stdio.h>
#define N 4

void capturaDatos(int *nums);
void calculaDatos(int *nums, int *resultado);
void imprimeDatos(int *resultado);

int main()
{
    int nums[N];
    int resultado[N];

    capturaDatos(nums);
    calculaDatos(nums, resultado);
    imprimeDatos(resultado);

    return 0;
}

void imprimeDatos(int *resultado)
{
    for(int i = 0; i < N; i++)
    {
        printf("%d ",resultado[i]);
    }
}

void calculaDatos(int *nums, int *resultado)
{
    for (int j = 0; j < N; j++)
    {
        resultado[j] = 1;
        for (int i = 0; i < N; i++)
        {
            if (i != j)
            {
                resultado[j] = nums[i] * resultado[j];  
            }  
        }
    }
    
}

void capturaDatos(int *nums)
{
    for (int i = 0; i < N; i++)
    {
        printf("Dame un numero entre el -30 al 30: ");
        scanf("%d", &nums[i]);
        while (nums[i] < -30 || nums[i] > 30)
        {
            printf("Valor no valido, dame un numero entre el -30 al 30: ");
            scanf("%d", &nums[i]);
        }
    }
}