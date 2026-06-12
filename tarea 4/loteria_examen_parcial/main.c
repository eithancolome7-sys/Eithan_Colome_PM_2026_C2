#include <studio.h>

void elegircantidadjugadas(int *cant);
void ingresarjugadas(int numeros[],  float dineros[], int cant);
void jugarloteria(int numeros[], float dineros[], int cant);

void main(void)
{
    int opcion;
    int cantidadjugadas = 0;

    int numerosjugados[100];
    float dinerojugado[100];

    do
    {
        printf("\n-- menu de loteria ---\n");
        printf("1. elegir cantidad de jugadas\n");
        printf("2. jugar\n");
        printf("3. salir\n");
        printf("seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            elegircantidadjugadas(&cantidadjugadas);
            ingresarjugadas(numerosjugados, dinerojugado, cantidadjugadas);
            break;

            case 2;
                 if (cantidadjugadas == 0)
                 {
                     printf("\nprimero debe elegir la cantidad de jugadas en la opcion 1. \n");

                 }
                 else
                 {
                     jugarloteria(numerosjugados, dinerojugado, cantidadjugadas);
                 }
                 break;

            case 3:
                printf("\ngracias por participar. !haste luego!\n");
                break;

            default:
                printf("\nopcion no valida. intente de nuevo.\n");
        }
    }
    while(opcion !=3);

}
void elegircantidadjugadas(int *cant)
{
    printf("\ncuantas jugadas desea realizar?: ");
    scanf("%d", cant);

    if (*cant <= 0 || *cant > 100)
    {
        printf("vantidad no valida.cse fijara en 1 jugada por defecto.\n");
        *cant = 1;

    }
}

void ingresarjugadas(int numeros[], float dineros[], int cant)
{
    int i;
    printf("\n--- registro de jugadas ---\n");

    for (i = 0; i < cant; i++)
    {
        printf("\njugada #%d:\n", i + 1);
        do
        {
            printf(" 1. ingrese el numero a jugar (1 al 40): ");
            scanf("%d", &numeros[i]);
            if (numeros[i] < 1 || numeros[i] > 40)
            {
                printf(" [error] el numero debe estar entre 1 y 40.\n");
            }
        }
        while (numeros[i] < 1 || numeros[i] > 40);
        printf(" 2. ingrese la cantidad de dinero a apostar: ");
        scanf("%f", &dineros[i]);
    }
}
void jugarloteria(int numeros[], float dinero[], int cant)
{
    int i;
    int numeroganador;
    int hayganador = 0;
    float totalsuma = 0;

    for (i = 0; i < cant; i++)
    {
        numeroganador = ((int)totalsuma % 40) + 1;
        printf("=====================================\n");
        printf("el numero casual que salio es: %d!\n", numeroganador);
        printf("====================================\n");

        for (i = 0; i < cant; i++)
        {
            float premio = dinero[i] * 1000;
            printf("felicidades! la jugada #%d fue ganadora.\n", i + 1);
            printf("numero jugado: %d | cantidad apostada: %.2f\n", numeros[i], dinero[i]);
            printf("premio ganado: %.2f\n\n", premio);
            hayganador = 1;
        }
    }
    if (hayganador == 0)
    {
        printf("ninguna de las jugadas resulto ganadora en esta ocacion.\n");
    }
}
