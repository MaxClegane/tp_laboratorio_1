#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    float primerOperando, segundoOperando;
    int flag1=0, flag2=0;                       // Variables flag, para indicar que fueron ingresados ambos operandos .

    while(seguir=='s')
    {
        if(!flag1)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        } else {
                printf("1- Ingresar 1er operando (A=%.2f)\n",primerOperando);
                }
        if(!flag2)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        } else {
                printf("2- Ingresar 2do operando (B=%.2f)\n",segundoOperando);
                }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                primerOperando = IngresarPrimerOperando();
                flag1 = 1;
                system("cls");
                break;
            case 2:
                segundoOperando = IngresarSegundoOperando();
                flag2 = 1;
                system("cls");
                break;
            case 3:
                CalcularSuma(primerOperando,segundoOperando,flag1, flag2);
                system("pause");
                system("cls");
                break;
            case 4:
                CalcularResta(primerOperando,segundoOperando,flag1, flag2);
                system("pause");
                system("cls");
                break;
            case 5:
                CalcularDivision(primerOperando,segundoOperando,flag1, flag2);
                system("pause");
                system("cls");
                break;
            case 6:
                CalcularMultiplicacion(primerOperando,segundoOperando,flag1, flag2);
                system("pause");
                system("cls");
                break;
            case 7:
                CalcularFactorialA(primerOperando,flag1);
                system("pause");
                system("cls");
                break;
            case 8:
                TodasOperaciones(primerOperando,segundoOperando,flag1, flag2);
                system("pause");
                system("cls");
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
}
