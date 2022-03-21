#include <stdio.h>
#define N 4

void capturaDatos(int *n);
void ordenaDatos(int *datos);
int buscarDatos(int *datos, int target);

int main()
{
    int nums[N];
    int target;
    int val;

    capturaDatos(nums);
    ordenaDatos(nums);

    for (int i = 0; i < N; i++)
    {
        printf("%d ",nums[i]);
    }
    

    printf("\nDame el objetivo: ");
    scanf("%d", &target);

    val = buscarDatos(nums, target);

    printf("Posicion %d", val);


    return 0;
}

int buscarDatos(int *nums, int target)
{
    int val;
    int i = 0;

    if (target > nums[N-1])
    {
        val = N;
        i = N;
    }
    for (i; i < N; i++)
    {
        if (target == nums[i])
        {
            val = i;
        }
        
        else if (target > nums[i])
        {
            val = i+1;
        }
    }
    
    return val;
}

void ordenaDatos(int *datos)
{
    int aux;
    int U;
    for (int i = 1; i < N; i++)
    {
        U = i;
        for (int j = U - 1; j >= 0; j--)
        {
            if (datos[U] < datos[j])
            {
                aux = datos[U];
                datos[U] = datos[j];
                datos[j] = aux;
                U--;
            }
        }
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