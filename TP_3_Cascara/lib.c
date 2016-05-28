#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"

int obtenerEspacioLibre(EMovie* movie, int lenght)
{
    int i;
    int indice=-1;     // Se inicializa en -1. En caso de existir posicion libre, de actualiza con el valor del indice.
    for(i=0; i<lenght; i++)
    {
        if(movie[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarPelicula(EMovie* movie)
{
    printf("Titulo: %s\nGenero: %s\nDescripcion: %s\nLink: %s\nPuntuacion: %d\nDuracion: %d\n", movie->titulo, movie->genero, movie->descripcion,movie->linkImagen, movie->puntaje, movie->duracion);
}

int imprimirMenu(char *menu)
{
    int opcion;
    printf("%s",menu);
    printf("\nOpcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}


int solicitarInt(int minimo, int maximo)
{
    int entero, validador;
    fflush(stdin);
    validador=scanf("%d", &entero);

    while(validador != 1 || (validador==1 && (entero < minimo || entero > maximo)))
    {
        if(validador==0)
        {
            fflush(stdin);
            printf("El entero ingresado posee caracteres incorrectos. Reingrese un entero valido (%d-%d): ",minimo,maximo);
            validador=scanf("%d",&entero);
        }
        else
        {
            fflush(stdin);
            printf("El numero ingresado esta fuera de rango. Reingrese un numero valido(%d-%d): ",minimo,maximo);
            validador=scanf("%d",&entero);
        }
    }
    return entero;
}
