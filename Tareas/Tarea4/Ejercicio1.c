#include <stdio.h>

typedef struct fecha
{
    int dia;
    char mes[12];
    int anio;
} estructura_fecha;

void capturaDatos(estructura_fecha *fecha);
void imprimeDatos(estructura_fecha fecha);

int main()
{
    estructura_fecha fech;
    capturaDatos(&fech);
    fech.mes[0] = toupper(fech.mes[0]);
    imprimeDatos(fech);
}

void imprimeDatos(estructura_fecha fecha)
{
    printf("%d/%s/%d", fecha.dia, fecha.mes, fecha.anio);
}

void capturaDatos(estructura_fecha *fecha)
{
    printf("Dame el dia: ");
    scanf("%d", &(fecha -> dia));
    
    printf("Dame el mes: ");
    scanf("%s", &(fecha -> mes));

    printf("Dame el anio: ");
    scanf("%d", &(fecha -> anio));
}