#include <stdio.h>

void cambioHexadecimal(int hex);

int main()
{
    int hex;

    printf("Dame un numero decimal para cambiarlo a hexadecimal: ");
    scanf("%d", &hex);

    cambioHexadecimal(hex);

    return 0;
}

void cambioHexadecimal(int hex)
{
    int i = hex % 16;
    if (hex > 0)
    {
        cambioHexadecimal(hex/16);

        switch (i)
        {
        case 10:
            printf("A");
        break;
        case 11:
            printf("B");
        break;
        case 12:
            printf("C");
        break;
        case 13:
            printf("D");
        break;
        case 14:
            printf("E");
        break;
        case 15:
            printf("F");
        break;
        default:
            printf("%d", i);
        break;
        }
    }
}