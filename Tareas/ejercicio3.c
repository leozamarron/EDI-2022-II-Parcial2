#include <stdio.h>

int calculaPosicion(int pos);

int main()
{
    int pos;

    printf("Dame la posicion que quieres saber de fibonacci: ");
    scanf("%d", &pos);

    printf("El numero es %d", calculaPosicion(pos));

    return 0;
}

int calculaPosicion(int pos)
{
    int valor;
    if (pos < 3 && pos > 0)
    {
        valor = 1;
    }
    else if (pos == 0)
    {
        valor = 0;
    }
    else if(pos > 0)
    {
        valor = calculaPosicion(pos-1) + calculaPosicion(pos-2);
    }
    else
    {
        return -1;
    }
    return valor;
}