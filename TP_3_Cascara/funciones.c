#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"
#include "lib.h"

void agregarPelicula(EMovie* movies,int lenght)
{
    int indice,enRango=0;
    char aux[2048];

    /*Buscamos cual es el primer indice libre dentro del array*/
    indice=obtenerEspacioLibre(movies, lenght);

    if(indice!=-1)//si hay lugar:
    {
        printf("Ingrese el titulo de la pelicula: ");
        do
        {
            fflush(stdin);
            gets(aux);
            if(strlen(aux)>50)
                printf("La cantidad de caracteres ingresados excede el limite. Reingrese: ");
            else
                enRango=1;
        }
        while(enRango==0);
        strcpy(movies[indice].titulo,aux);

        printf("Ingrese el genero de la pelicula: ");
        do
        {
            fflush(stdin);
            gets(aux);
            if(strlen(aux)>50)
                printf("La cantidad de caracteres ingresados excede el limite. Reingrese: ");
            else
                enRango=1;
        }
        while(enRango==0);
        strcpy(movies[indice].genero,aux);


        printf("Ingrese la descripcion de la pelicula: ");
        do
        {
            fflush(stdin);
            gets(aux);
            if(strlen(aux)>150)
                printf("La cantidad de caracteres ingresados excede el limite. Reingrese: ");
            else
                enRango=1;
        }
        while(enRango==0);
        strcpy(movies[indice].descripcion,aux);


        printf("Ingrese el link de la pelicula: ");
        do
        {
            fflush(stdin);
            gets(aux);
            if(strlen(aux)>200)
                printf("La cantidad de caracteres ingresados excede el limite. Reingrese: ");
            else
                enRango=1;
        }
        while(enRango==0);
        strcpy(movies[indice].linkImagen,aux);

        printf("Ingrese puntaje: ");
        movies[indice].puntaje = solicitarInt(0,100);


        printf("Ingrese duracion: ");
        movies[indice].duracion = solicitarInt(0,500);
        system("cls");

        movies[indice].isEmpty = 0;

    }
    else
    {
        printf("No queda espacio");
        getch();
    }
}

void borrarPelicula(EMovie* movie,int lenght)
{
    char auxTitulo[1024];
    int flag=0,i;
    char opcion;

    printf("Ingrese el titulo de la pelicula a dar de baja: ");
    fflush(stdin);
    gets(auxTitulo);
    for(i=0; i<lenght; i++)
    {
        if((strcmp(auxTitulo,movie[i].titulo)==0) && movie[i].isEmpty==0)
        {
            printf("Pelicula encontrada, sus datos son:\n\n");

            mostrarPelicula(movie+i);

            printf("\nSeguro desea dar de baja S/N ?: ");
            opcion = tolower(getche());
            if(opcion=='s')
            {
                movie[i].isEmpty=-1;
                printf("\n\n­­Registro eliminado!!\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\n\nEl registro no fue eliminado!\n\n");
                system("pause");
                system("cls");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("\n\nPelicula inexistente\n\n");
        system("pause");
        system("cls");
    }
}

void modificarPelicula(EMovie* movie,int lenght)
{
    char auxTitulo[1024];
    int flag=0,i, opcion;
    char seguir='s';
    int puntaje, duracion;

    system("cls");
    printf("Ingrese el titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(auxTitulo);
    for(i=0; i<lenght; i++)
    {
        if((strcmp(auxTitulo,movie[i].titulo)==0) && movie[i].isEmpty==0)
        {
            printf("Pelicula encontrada, sus datos son:\n\n");

            mostrarPelicula(movie+i);

            do
            {
                opcion = imprimirMenu("\nQue desea modificar?: \n1- Genero\n2- Descripcion\n3- Link\n4- Puntuacion\n5- Duracion\n6- Recordar datos actuales\n7- Finalizar modificacion\n");
                switch(opcion)
                {
                case 1:
                    printf("Ingrese el genero de la pelicula: ");
                    fflush(stdin);
                    gets(movie[i].genero);
                    break;
                case 2:
                    printf("Ingrese la descripcion de la pelicula: ");
                    fflush(stdin);
                    gets(movie[i].descripcion);
                    break;
                case 3:
                    printf("Ingrese el linkImagen de la pelicula: ");
                    fflush(stdin);
                    gets(movie[i].linkImagen);
                    break;
                case 4:
                    printf("Ingrese puntaje: ");
                    scanf("%d", &puntaje);
                    movie[i].puntaje=puntaje;
                    break;
                case 5:
                    printf("Ingrese duracion: ");
                    scanf("%d", &duracion);
                    movie[i].duracion=duracion;
                    break;
                case 6:
                    mostrarPelicula(movie+i);
                    break;
                case 7:
                    seguir = 'n';
                    break;
                }


            }
            while(seguir == 's');

        }
    }
    if(flag==0)
    {
        printf("Pelicula inexistente\n\n");
        system("pause");
        system("cls");
    }
}

int cargarDesdeArchivo(EMovie *movie)
{
    int flag = 1;
    FILE *archivo;

    archivo=fopen("bin.dat", "rb");
    if(archivo==NULL)
    {
        archivo= fopen("bin.dat", "wb");
        if(archivo==NULL)
            flag = 0;
    }

    if(flag ==1)
        fread(movie,sizeof(EMovie),50,archivo);

    fclose(archivo);

    return flag;
}

void crearHtml(EMovie *movie, int lenght)
{
    int longi,i;
    char lineStr[128];
    char salida[50];

    printf("Ingrese el nombre del archivo de salida: ");
    fflush(stdin);
    gets(salida);
    strcat(salida,".html");

    // 1: Copia el contenido de index.html en el archivo de salida. Es el cabezal del cuerpo del html
    FILE* source = fopen("index.html", "r");
    FILE* dest = fopen(salida, "w");
    while(fgets(lineStr,128,source)!=NULL)
    {
        longi = strlen(lineStr);
        fwrite(lineStr, sizeof(char), longi, dest);
    }
    fclose(source);
    // 1 end.

    //  2: Recorre el array de peliculas para tomar los registros con isEmpty==0. Comienza a copiar e intercalar
    //  la estructura del html con los datos de las peliculas, en el archivo de salida.
    for(i=0; i<lenght; i++)
    {
        if(movie[i].isEmpty == 0)
        {
            fwrite("<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='",sizeof(char),97,dest );
            //link
            longi = strlen(movie[i].linkImagen);
            fwrite(movie[i].linkImagen,sizeof(char),longi,dest );
            fflush(stdin);
            fwrite("' alt=''></a><h3><a href='#'>",sizeof(char),29,dest );
            //titulo
            longi = strlen(movie[i].titulo);
            fwrite(movie[i].titulo,sizeof(char),longi,dest );
            fwrite("</a></h3><ul><li>Genero:",sizeof(char),24,dest );
            //Genero
            longi = strlen(movie[i].genero);
            fwrite(movie[i].genero,sizeof(char),longi,dest );
            fwrite("</li><li>",sizeof(char),9,dest );
            //puntaje
            fprintf(dest,"%d",movie[i].puntaje );
            fwrite("</li><li>",sizeof(char),9,dest );
            //duracion
            fprintf(dest,"%d",movie[i].duracion );
            fwrite("</li></ul><p>",sizeof(char),13,dest );
            //descripcion
            longi = strlen(movie[i].descripcion);
            fwrite(movie[i].descripcion,sizeof(char),longi,dest );
            fwrite("</p></article>",sizeof(char),14,dest );
        }
    }
    // 2 end

    // 3: Copia el contenido de index2.html en el archivo de salida. Es el pie del cuerpo del html
    FILE* source2 = fopen("index2.html", "r");
    while(fgets(lineStr,128,source2)!=NULL)
    {
        longi = strlen(lineStr);
        fwrite(lineStr, sizeof(char), longi, dest);
    }
    fclose(source2);
    fclose(dest);
    // 3 end

    printf("\nArchivo %s creado!\n\n\n",salida);
    system("PAUSE");
    system("cls");
}

int guardarEnArchivo(EMovie *movie)
{
    int retorno=1;
    FILE *file;

    file=fopen("bin.dat","wb");
    if(file == NULL)
    {
        retorno = 0;
    }

    fwrite(movie,sizeof(EMovie),50,file);
    fclose(file);
    return retorno;
}
