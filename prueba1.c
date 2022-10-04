#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int leerFecha(void)
{
    int dia, mes, year, res;
    do
    {
        printf("Ingrese dia de nacimiento ");
        scanf("%d", &dia);
    } while (dia > 31);

    do
    {
        printf("\n Ingrese el mes de nacimiento ");
        scanf("%d", &mes);
    } while (mes > 12);

    printf("\n Ingrese el año de nacimiento ");
    scanf("%d", &year);
    if (dia <= 9)
    {
        res = 100000000 + (dia * 1000000) + (mes * 10000) + (year);
        printf("\n Se a convertido los digitos que ingreso a un solo digito: %d ", res);
    }
    else
    {
        res = (dia * 1000000) + (mes * 10000) + (year);
        printf("\n Se a convertido los digitos que ingreso a un solo digito: %d ", res);
    }
    return (res);
}

int CalcularEdad(int x)
{
    time_t t;
    t = time(NULL);
    struct tm *year;
    year = localtime(&t); // fecha de ahora mismo
    int yu = year->tm_year + 1900;
    int y;
    int r;
    y = x % 10000;
    r = yu - y;
    return (r);
}

void EscribirFecha(int x)
{
    int aa, mm, dd, xx;
    aa = x % 10000;
    xx = x / 10000;
    mm = xx % 100;
    xx = xx / 100;
    dd = xx % 100;
    printf("%d-%d-%d", dd, mm, aa);
}

int main()
{
    int a;
    int e;
    a = leerFecha();
    e = CalcularEdad(a);
    if (e >= 18)
    {
        printf("\n eres mayor de edad, y tu fecha de nacimiento es esta: ");
        EscribirFecha(a);
    }
    else
    {
        printf("\n eres menor de edad, y tu fecha de nacimiento es esta: ");
        EscribirFecha(a);
    }
    return (0);
}
