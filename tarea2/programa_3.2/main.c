#include <stdio.h>

void main(void)
{
    int I, N, NUM, SUM;
    printf("Ingrese el numero de datos:\T");
    scanf("%d", &N);
    for (I=1; I<=N; I++)
{
    printf("ingrese el dato numero %d:\t", I);
    scanf("%d", &NUM);
    if (NUM > 0)
        SUM = SUM + NUM;
}
printf("\nLan suma de los numeros positivos es: %d", SUM);
}
