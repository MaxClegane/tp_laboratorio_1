#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAXDNI 99999999
#define MAXEDAD 100

void init(EPersona* lista,int lenght)
{
    int i;
    for(i=0; i<lenght; i++)
    {
        lista[i].estado = 1;
    }
}

int obtenerEspacioLibre(EPersona* lista, int lenght)
{
    int i;
    int indice=-1;     // Se inicializa en -1. En caso de existir posicion libre, de actualiza con el valor del indice.
    for(i=0; i<lenght; i++)
    {
        if(lista[i].estado == 1)
        {
            indice = i;
            break;
        }

    }
    return indice;
}


int buscarPorDni(EPersona* lista, int dni, int lenght)
{
    int i;
    int indice=-1;     // Se inicializa en -1. En caso de encontrar el dni, de actualiza el valor.
    for(i=0; i<lenght; i++)
    {
        if(lista[i].estado == 1 && lista[i].dni==dni)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

int addPerson(EPersona* lista, int lenght)
{
    int indice, largoNombre,i;
    int agregado=2;
    int dni, validador,edad;
    char nombreExtendido[4096];

    indice = obtenerEspacioLibre(lista, lenght);
    if(indice != -1)
    {
        fflush(stdin);
        printf("Ingrese el nombre de la persona: ");
        gets(nombreExtendido);
        largoNombre = strlen(nombreExtendido);

        for(i=0; i<50; i++)
        {
            while((isalpha(nombreExtendido[i]) == 0 && largoNombre > i) || largoNombre>50)
            {
                fflush(stdin);
                printf("El nombre ingresado posee caracteres incorrectos o es demasiado largo. Reingrese un nombre valido: ");
                gets(nombreExtendido);
                largoNombre = strlen(nombreExtendido);
                i=0;
            }
        }

        strcpy(lista[indice].nombre,nombreExtendido);
        fflush(stdin);
        printf("Ingrese el dni de la persona: ");
        validador=scanf("%d",&dni);
        lista[indice].dni = dniValidado(dni,MAXDNI,validador);

        printf("Ingrese la edad de la persona: ");
        validador=scanf("%d",&edad);
        lista[indice].edad = edadValidada(edad,MAXEDAD, validador);
        lista[indice].estado=0;
        agregado=1;
    }
    return agregado;
}

int dniValidado(int dni, int maxdni, int validador)
{
    while(validador != 1 || (validador==1 && (dni < 1 || dni > maxdni)))
    {
        if(validador==0)
        {
            fflush(stdin);
            printf("El dni ingresado posee caracteres incorrectos. Reingrese un dni valido (1-99999999): ");
            validador=scanf("%d",&dni);
        }
        else
        {
            fflush(stdin);
            printf("El dni ingresado es superior a 99.999.999. Reingrese un dni valido (1-99999999): ");
            validador=scanf("%d",&dni);
        }
    }
    return dni;
}

int edadValidada(int edad, int maxedad, int validador)
{
    while(validador != 1 || (validador==1 && (edad < 1 || edad > maxedad)))
    {
        if(validador==0)
        {
            fflush(stdin);
            printf("La edad ingresada posee caracteres incorrectos. Reingrese una edad valida (1-100): ");
            validador=scanf("%d",&edad);
        }
        else
        {
            fflush(stdin);
            printf("La edad ingresado es superior 100. Reingrese una edad valida (1-100): ");
            validador=scanf("%d",&edad);
        }
    }
    return edad;
}

int deletePerson(EPersona* lista, int lenght)
{
    int opcion, i, auxDni;
    int borrado=0;
    char aux[50];

    printf("1- Borrar con el nombre de la persona.\n");
    printf("2- Borrar con el dni de la persona.\n");
    printf("\nOpcion: ");
    scanf("%d",&opcion);

    if(opcion == 1)
    {
        fflush(stdin);
        printf("\nIngrese el nombre de la persona a borrar: ");
        gets(aux);

        for(i=0; i<lenght; i++)
        {
            if(strcmp(lista[i].nombre,aux)==0)
            {
                lista[i].estado=1;
                borrado=1;
            }
        }
    }
    else if(opcion==2)
    {
        printf("\nIngrese el dni de la persona a borrar: ");
        scanf("%d",&auxDni);

        for(i=0; i<lenght; i++)
        {
            if(lista[i].dni==auxDni)
            {
                lista[i].estado=1;
                borrado=1;
            }
        }
    }
    return borrado;
}

void informa(int respuesta)
{
    switch(respuesta)
    {
        case 0:
        printf("\nLa operacion fue INCORRECTA!\n\n\n");
        break;
        case 1:
        printf("\nLa operacion fue CORRECTA!\n\n\n");
        break;
        case 2:
        printf("\nLlego al limite de altas. EN caso de necesitas ampliar el limite, contacte a su administrador de sistemas.\n\n\n");
        break;

    }

}

int orderPerson(EPersona* lista, int lenght)
{
    EPersona aux;
    int i,j;

    for(i=0; i<lenght-1; i++)
    {
        for(j=i+1; j<lenght; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }

    for(i=0; i<lenght-1; i++)
    {
        if(lista[i].estado==0)
        {
            printf("nombre: %s, edad: %d, dni: %d.\n",lista[i].nombre,lista[i].edad,lista[i].dni);
        }

    }
    printf("\n\n");
    return 0;
}

void graficar(EPersona* lista, int lenght)
{

    int i,j,max;
    int menores=0, adultos=0, mayores=0;

    for(i=0; i<lenght; i++)
    {
        if(lista[i].estado==0)
        {
            if(lista[i].edad<18)
                menores=menores+1;
            else if(lista[i].edad>35)
                mayores=mayores+1;
            else
                adultos=adultos+1;
        }

    }

    int columnas[]= {menores, adultos, mayores};
    //int columnas[] = {1, 3, 9, 7, 5};

    max = 0;
    for(i = 0; i < 3; i++) // recorre el array de numeros para determinar el mayor
    {
        if (columnas[i] > max)
        {
            max = columnas[i];
        }
    }

    for(i=max; i>0; i--)
    {
        for (j = 0; j < 3; j++)
        {
            if (columnas[j] >= i)
                printf("   *");
            else
                printf("    ");
        }
        putchar('\n');
    }
    printf("<18 19-35 >35\n\n");
    system("pause");
}
