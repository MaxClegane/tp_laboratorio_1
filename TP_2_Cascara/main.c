#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20

int main()
{
    EPersona lista[TAM];
    char seguir='s';
    int opcion=0;
    int funciono;
    init(lista, TAM);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\nOpcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        printf("\n-------------------------------------------\n");
        switch(opcion)
        {
            case 1:
                funciono=addPerson(lista, TAM);
                informa(funciono);
                system("pause");
                system("cls");
                break;
            case 2:
                funciono=deletePerson(lista, TAM);
                informa(funciono);
                system("pause");
                system("cls");
                break;
            case 3:
                orderPerson(lista, TAM);
                system("pause");
                system("cls");
                break;
            case 4:
                graficar(lista, TAM);
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion no valida, reingrese.\n\n");
                fflush(stdin);
                system("PAUSE");
                system("cls");
        }
    }
    return 0;
}
