float IngresarPrimerOperando()
{
    float operando;
    printf("_________________________________\n");
    printf("Opcion 1 ingresada. Por favor, indique el primer operando (A): ");
    scanf("%f",&operando);

    return operando;
}

float IngresarSegundoOperando()
{
    float operando;
    printf("_________________________________\n");
    printf("Opcion 2 ingresada. Por favor, indique el segundo operando (B): ");
    scanf("%f",&operando);

    return operando;
}

void CalcularSuma(float operando1, float operando2,int flag1, int flag2)
{
    if(flag1 == 0 || flag2 == 0)
    {
        printf("No ingreso un operando. Ingrese el operando faltante: \n");
    } else {
            printf("La suma del operando 1 (%.2f) y el operando 2 (%.2f) es: %.2f\n",operando1, operando2, operando1+operando2);
            printf("_________________________________\n\n");
            }
}

void CalcularResta(float operando1, float operando2,int flag1, int flag2)
{
    if(flag1 == 0 || flag2 == 0)
    {
        printf("No ingreso un operando. Ingrese el operando faltante: \n");
    } else {
            printf("La resta del operando 1 (%.2f) y el operando 2 (%.2f) es: %.2f\n",operando1, operando2, operando1-operando2);
            printf("_________________________________\n\n");
            }
}

void CalcularDivision(float operando1, float operando2,int flag1, int flag2)
{
    if(operando2==0)
    {
        printf("La division no puede realizarse si el operando 2 (denominador) es 0. Ingrese un denominador valido.\n\n");
        printf("_________________________________\n\n");
    } else {
            if(flag1 == 0 || flag2 == 0)
            {
                printf("No ingreso un operando. Ingrese el operando faltante: \n");
            } else {
                        printf("La division del operando 1 (%.2f) y el operando 2 (%.2f) es: %.2f\n",operando1, operando2, operando1/operando2);
                        printf("_________________________________\n\n");
                    }
            }
}

void CalcularMultiplicacion(float operando1, float operando2,int flag1, int flag2)
{
    if(flag1 == 0 || flag2 == 0)
    {
        printf("No ingreso un operando. Ingrese el operando faltante: \n");
    } else {
            printf("La multiplicacion del operando 1 (%.2f) y el operando 2 (%.2f) es: %.2f\n",operando1, operando2, operando1*operando2);
            printf("_________________________________\n\n");
            }
}

void CalcularFactorialA(float Operando,int flag1)
{
    float resultado;
       if(flag1 == 0)           // Se analiza si el primer operando fue ingresado
    {
        printf("No ingreso el operando A. Ingrese el operando con la opcion 1. \n");
    } else {
                if(Operando<0) // Se analizará si el primer operando es negativo.
                {
                printf("El primer operando es un numero negativo. No se puede calcular su factorial.\n\n");
                } else {
                        // Se analizará si el primer operando posee decimal.
                        float numero = Operando;
                        int parteEntera = (int) numero;
                        if(numero - parteEntera)
                        {
                            printf("El primer operando posee numeros decimales. No se puede calcular su factorial.\n\n");
                        } else {
                                resultado = CalcularFactorialA2(parteEntera);
                                }
                        printf("El factorial de %.0f es %.0f\n",Operando,resultado);
                        printf("_________________________________\n\n");
                        }
            }
}

int CalcularFactorialA2(int Operando)
{
    int respuesta;
    if(Operando == 1 || Operando == 0 )
    {
    return 1;
    } else {
    respuesta = Operando * CalcularFactorialA2(Operando-1);
    return (respuesta);
    }
}

void TodasOperaciones(float operando1, float operando2,int flag1, int flag2)
{
    if(flag1 == 0 || flag2 == 0)
    {
        printf("No ingreso un operando. Ingrese el operando faltante: \n");
    } else {
            CalcularSuma(operando1,operando2,flag1, flag2);
            CalcularResta(operando1,operando2,flag1, flag2);
            CalcularDivision(operando1,operando2,flag1, flag2);
            CalcularMultiplicacion(operando1,operando2,flag1, flag2);
            CalcularFactorialA(operando1,flag1);
           }
}
