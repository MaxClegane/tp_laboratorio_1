#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estructuras.h"
#include "ArrayList.h"
#include "implemetation.h"
int main(void)
{
    ArrayList* usuarios = al_newArrayList();
    ArrayList* comentarios = al_newArrayList();

    char seguir='s';
    char guardar;
    int opcion;

    if(cargarDesdeArchivo(usuarios, "usuarios.dat", 1))
        printf("Se cargaron los usuarios con exito\n");
    else
        printf("No se pudo abrir el fichero de usuarios!!!\n\n\n");

    if(cargarDesdeArchivo(comentarios, "comentarios.dat", 2))
        printf("Se cargaron los comentarios con exito\n\n\n");
    else
        printf("No se pudo abrir el fichero de comentarios!!!\n\n\n");

    ArrayList* comentariosOriginales = comentarios->clone(comentarios);
    ArrayList* usuariosOriginales = usuarios->clone(usuarios);

    system("pause");
    system("cls");

    while(seguir=='s')
    {
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c\t[1]-  Alta usuario\t\t\t\t\t%c\n%c\t[2]- Modificar Usuario\t\t\t\t\t%c\n%c\t[3]- Baja de usuario\t\t\t\t\t%c\n%c\t\t[3.1]- Borrar un usuario\t\t\t%c\n%c\t\t[3.2]- Borrar y mostrar\t\t\t\t%c\n%c\t\t[3.3]- Borrar todos los usuarios\t\t%c\n%c\t[4]- Nuevo comentario\t\t\t\t\t%c\n%c\t[5]- Nuevo Me gusta\t\t\t\t\t%c\n%c\t[6]- INFORMAR\t\t\t\t\t\t%c\n%c\t\t[6.1]- Mostrar cantidad de usuarios\t\t%c\n%c\t\t[6.2]- Mostrar a los usuarios\t\t\t%c\n%c\t\t[6.3]- Mostrar usuarios y sus comentarios\t%c\n%c\t\t[6.4]- Cosas nuevas de la sesion\t\t%c\n%c\t\t[6.5]- los primeros usuarios dados de alta\t%c\n%c\t[7]- Listar\t\t\t\t\t\t%c\n%c\t[8]-Salir\t\t\t\t\t\t%c\n",186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186);
        //opcion=imprimirMenu("%c\t[1]-  Alta usuario\t\t\t\t\t%c\n%c\t[2]- Modificar Usuario\t\t\t\t\t%c\n%c\t[3]- Baja de usuario\t\t\t\t\t%c\n%c\t\t[3.1]- Borrar un usuario\t\t\t%c\n%c\t\t[3.2]- Borrar y mostrar\t\t\t\t%c\n%c\t\t[3.3]- Borrar todos los usuarios\t\t%c\n%c\t[4]- Nuevo comentario\t\t\t\t\t%c\n%c\t[5]- Nuevo Me gusta\t\t\t\t\t%c\n%c\t[6]- INFORMAR\t\t\t\t\t\t%c\n%c\t\t[6.1]- Mostrar cantidad de usuarios\t\t%c\n%c\t\t[6.2]- Mostrar a los usuarios\t\t\t%c\n%c\t\t[6.3]- Mostrar usuarios y sus comentarios\t%c\n%c\t\t[6.4]- Cosas nuevas de la sesion\t\t%c\n%c\t\t[6.5]- los primeros usuarios dados de alta\t%c\n%c\t[7]- Listar\t\t\t\t\t\t%c\n%c\t[8]-Salir\t\t\t\t\t\t%c\n",186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        //"1- Alta usuario\n2- Modificar Usuario\n3- Baja de usuario\n4- Nuevo comentario\n5- Nuevo Me gusta\n6- INFORMAR\n7- Listar\n8- Salir\n\n");
        printf("\nOpcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        printf("\n-------------------------------------------\n");
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            altaUsuario(usuarios);
            system("pause");
            system("cls");
            break;
        case 2:
            modUsuario(usuarios);
            system("pause");
            system("cls");
            break;
        case 3:
            borrado(usuarios);
            system("pause");
            system("cls");
            break;
        case 4:
            nuevoComentario(usuarios,comentarios);
            system("pause");
            system("cls");
            break;
        case 5:
            nuevoLike(usuarios,comentarios);
            system("pause");
            system("cls");
            break;
        case 6:
            informar(usuarios,usuariosOriginales,comentarios,comentariosOriginales);
            system("pause");
            system("cls");
            break;
        case 7:
            listar(usuarios,comentarios);
            system("pause");
            system("cls");
            break;
        case 8:
            printf("\nGuardar cambios S/N ?: ");
            guardar = tolower(getche());
            if(guardar == 's')
            {
                if(guardarEnArchivo(usuarios, "usuarios.dat", 1))
                    printf("\nSe guardaron los usuarios con exito\n");
                else
                    printf("\nNo se pudo guardar, contacte a su administrador de sistemas!!!!\n");

                if(guardarEnArchivo(comentarios, "comentarios.dat", 2))
                    printf("\nSe guardaron los comentarios con exito\n");
                else
                    printf("\nNo se pudo guardar, contacte a su administrador de sistemas!!!!\n");
            }
            else
            {
                printf("\nNO SE GUARDO, SALIENDO!\n");
            }
            usuarios->deleteArrayList(usuarios);
            comentarios->deleteArrayList(comentarios);
            seguir='n';
            break;
        default:
            printf("No existe esa opcion... Reintente\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
}
