#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"
#include "lib.h"

#define QUAN 50

int main()
{

    EMovie movies[QUAN];
    char seguir='s';
    char guardar= 's';
    int opcion=0;
    int i;
    // Inicializa el array
    for(i=0; i<QUAN; i++)
        movies[i].isEmpty = 1;

    //carga de datos iniciales desde archivo binario
    if(cargarDesdeArchivo(movies))
        printf("Se cargaron las estructuras con exito\n\n\n");
    else
        printf("No se pudo abrir el fichero\n\n\n");

    system("pause");
    system("cls");

    //Menu
    while(seguir=='s')
    {
        opcion=imprimirMenu("1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Generar pagina web\n5- Salir\n\n");
        fflush(stdin);
        printf("\n-------------------------------------------\n");
        switch(opcion)
        {
        case 1:
            agregarPelicula(movies, QUAN);
            break;
        case 2:
            borrarPelicula(movies,QUAN);
            break;
        case 3:
            modificarPelicula(movies,QUAN);
            break;
        case 4:
            crearHtml(movies, QUAN);
            break;
        case 5:
            // Ofrece guardar el archivo binario con nuevos datos y salir
            printf("\nGuardar cambios S/N ?: ");
            guardar = tolower(getche());

            if(guardar == 's')
            {
                if(guardarEnArchivo(movies))
                    printf("\nSe guardo la informacion con exito\n");
                else
                    printf("\nNo se pudo guardar, contacte a su administrador de sistemas!!!!\n");
            }
            else
            {
                printf("\nNO SE GUARDO, SALIENDO!\n");
            }

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
