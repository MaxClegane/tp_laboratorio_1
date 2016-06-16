#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"
#include "ArrayList.h"
#include "implemetation.h"

int imprimirMenu(char *menu)
{
    int opcion;
    printf("%s",menu);
    printf("\nOpcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

/** \brief Funcion para dar de alta un usuario
 * \param usuarios: arraylist donde se guardan los usuarios
 * \return
 */
void altaUsuario(ArrayList *usuarios)
{
    char name[51];
    char pass[51];
    char mail[51];
    char nick[51];
    int id;
    User *usuario;

    printf("ALTA DE USUARIO\n==================\n");
    printf("Ingrese su nombre: ");
    gets(name);
    printf("Ingrese su nick: ");
    gets(nick);
    printf("Ingrese su contraseña: ");
    gets(pass);
    printf("Ingrese su eMail: ");
    gets(mail);

    id=usuarios->size;
    usuario = newUser(name, nick,pass,mail, id);
    usuarios->add(usuarios,usuario);

    printf("\n\nUSUARIO DADO DE ALTA! :) \n\n");
}

/** \brief Permite modificar un usuario, ingresando el nick del mismo
 *         se puede alterar Nombre, Mail y/o Clave de acceso
 * \param usuarios: arraylist donde se guardan los usuarios
 * \return
 */
void modUsuario(ArrayList *usuarios)
{
    char nickAux[51];
    char nameAux[51];
    char passAux[51];
    char mailAux[51];
    int i;
    int flag = 0;
    User *usuario;

    if(usuarios->size==0)
    {
        printf("NO HAY USUARIOS!!!\n\n");
    }
    else
    {
        printf("MODIFICACION DE USUARIO\n=============================\n");
        printf("Ingrese su nick: ");
        gets(nickAux);
        fflush(stdin);
        for(i=0; i<usuarios->size; i++)
        {

            usuario = usuarios->get(usuarios,i);

            if(strcmp(nickAux,usuario->nick) == 0)
            {
                printf("Ingrese su nuevo nombre: ");
                gets(nameAux);
                printf("Ingrese su nueva contraseña: ");
                gets(passAux);
                printf("Ingrese su nuevo eMail: ");
                gets(mailAux);
                usuario = newUser(nameAux, usuario->nick,passAux,mailAux, usuario->id);

                usuarios->set(usuarios,usuario->id,usuario);
                flag =1;
            }
        }
        if(flag==0)
        {
            printf("\n\nNo se realizo la modificacion :(\n\n");
        }
        else
        {
            printf("\n\nSe realizo la modificacion :)\n\n");
        }
    }
}

/** \brief Menu para borrado de usuarios.
            1= borra el usuario
            2= borra a todos los usuarios
            3= borra y muestra en pantalla al usuario borrado
 * \param usuarios: arraylist donde se guardan los usuarios
 */
void borrado(ArrayList * usuarios)
{
    char nickAux[51];
    char nickAux2[51];
    int opcion,i;
    User *usuario;
    User *usuario2;


    if(usuarios->size==0)
    {
        printf("NO HAY USUARIOS!!!\n\n");
    }
    else
    {
        printf("Ingrese su nick: ");
        gets(nickAux);
        fflush(stdin);
        for(i=0; i<usuarios->size; i++)
        {

            usuario = usuarios->get(usuarios,i);

            if(strcmp(nickAux,usuario->nick) == 0)
            {
                printf("BORRADO DE USUARIO\n=============================\n");
                opcion=imprimirMenu("1- Borrar un usuario\n2- Borrar y mostrar\n3- Borrar todos los usuarios\n\n");
                fflush(stdin);
                printf("\n-------------------------------------------\n");

                switch(opcion)
                {
                case 1:
                    printf("Ingrese el nick a borrar: ");
                    gets(nickAux2);
                    fflush(stdin);
                    for(i=0; i<usuarios->size; i++)
                    {

                        usuario = usuarios->get(usuarios,i);

                        if(strcmp(nickAux2,usuario->nick) == 0)
                        {
                            printf("Usuario borrado o.O!!!!\n\n");
                            usuarios->remove(usuarios,i);
                        }
                    }
                    break;

                case 2:
                    printf("Ingrese el nick a borrar: ");
                    gets(nickAux2);
                    fflush(stdin);
                    for(i=0; i<usuarios->size; i++)
                    {

                        usuario = usuarios->get(usuarios,i);

                        if(strcmp(nickAux2,usuario->nick) == 0)
                        {
                            usuario2 = usuarios->pop(usuarios,i);
                            printf("El usuario %s fue borrado o.O!!!!\n\n",usuario2);
                        }
                    }
                    break;
                case 3:
                    usuarios->clear(usuarios);
                    printf("ACABA DE BORRAR A TODOS LOS USUARIOS o.O!!!!\n\n");
                    break;
                default:
                    printf("No existe esa opcion... Reintente\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
            }
            else
            {
                printf("Ese usuario no existe =(\n\n");
            }
        }

    }


}

/** \brief Funcion para crear un nuevo comentario
 * \param listaUsuarios: arraylist donde se guardan los usuarios
 * \param listaComentarios: arraylist donde se guardan los comentarios
 */
void nuevoComentario(ArrayList *listaUsuarios,ArrayList *listaComentarios)
{
    char nickAux[51];
    char passAux[51];
    char commentAux[250];
    User *usuario;
    EComments *comentario;
    int i,id;

    printf("Ingrese su nick: ");

    gets(nickAux);
    fflush(stdin);
    printf("Ingrese su pass: ");
    gets(passAux);
    fflush(stdin);

    for(i=0; i<listaUsuarios->size; i++)
    {
        usuario = listaUsuarios->get(listaUsuarios,i);

        if((strcmp(nickAux,usuario->nick) == 0) && (strcmp(passAux,usuario->password) == 0))
        {
            printf("Ingrese su comentario: ");
            gets(commentAux);
            fflush(stdin);

            id=listaComentarios->size;
            comentario=newComment(commentAux, usuario->id,id);
            if(listaComentarios->size > 0)
                listaComentarios->push(listaComentarios,0,comentario);
            else
                listaComentarios->add(listaComentarios,comentario);

        }
    }
}

/** \brief Funcion para dar un like
 * \param usuarios: arraylist donde se guardan los usuarios
 * \param comentarios: arraylist donde se guardan los comentarios
 */
void nuevoLike(ArrayList *usuarios,ArrayList *comentarios)
{
    char nickAux[51];
    char passAux[51];
//   char commentAux[250];
    User *usuario;
    EComments *comentario;
    int i,num;

    printf("Ingrese su nick: ");
    gets(nickAux);
    fflush(stdin);
    printf("Ingrese su pass: ");
    gets(passAux);
    fflush(stdin);

    for(i=0; i<usuarios->size; i++)
    {
        usuario = usuarios->get(usuarios,i);

        if((strcmp(nickAux,usuario->nick) == 0) && (strcmp(passAux,usuario->password) == 0))
        {
            printf("Ingrese el identificador del comentario: ");
            scanf("%d",&num);
            break;
        }
    }

    for(i=0; i<comentarios->size; i++)
    {
        comentario = comentarios->get(comentarios,i);

        if(num == comentario->id)
        {
            comentario->likes++;
            printf("Comentario likeado!!!") ;
        }

    }


}

/** \brief Menu de funciones para informar datos en pantalla.
    1= Mostrar cantidad de usuarios
    2= Mostrar a los usuarios
    3= Mostrar usuarios y sus comentarios
    4= Cosas nuevas de la sesion
    5= los primeros usuarios dados de alta
 * \param usuarios: arraylist donde se guardan los usuarios
 * \param comentarios: arraylist donde se guardan los comentarios
 * \param usuariosOriginales: arraylist donde se guardan los usuarios que se tenian al iniciar el programa
 * \param comentariosOriginales: arraylist donde se guardan los comentarios que se tenian al iniciar el programa
 */
int informar(ArrayList *usuarios,ArrayList *usuariosOriginales,ArrayList *comentarios,ArrayList *comentariosOriginales)
{
    int i,j, opcion;
    EComments* comment;
    EComments *commentAux;
    User *usuario;
    User *userAux;
    int usuariosAMostrar=5;
    ArrayList* pArray;

    opcion=imprimirMenu("1- Mostrar cantidad de usuarios\n2- Mostrar a los usuarios\n3- Mostrar usuarios y sus comentarios\n4- Cosas nuevas de la sesion\n5- los primeros usuarios dados de alta\n");
    fflush(stdin);
    printf("\n-------------------------------------------\n");
    switch(opcion)
    {
    case 1:
        if(usuarios->isEmpty(usuarios)==1)
            printf("No hay usuarios dados de alta!\n\n");
        if(usuarios->isEmpty(usuarios)==0)
            printf("Existen %d usuarios dados de alta.\n\n",usuarios->len(usuarios));
        break;
    case 2:
        for(i=0; i<usuarios->size; i++)
        {
            printUser(usuarios->get(usuarios,i));
        }
        printf("\n");
        break;
    case 3:
        for(i=0; i<usuarios->size; i++)
        {
            usuario= usuarios->get(usuarios,i);
            printUser(usuarios->get(usuarios,i));

            for(j=0; j<comentarios->size; j++)
            {
                comment = (comentarios->get(comentarios,j));
                if(usuario->id == comment->idComentador)
                {
                    printf("Indice: %d. Comentario: %s Nick:%s Cantidad de likes:%d\r\n\n",comentarios->indexOf(comentarios,*(comentarios->pElements+j)),comment->comments,usuario->name,comment->likes);
                }
            }
        }
        printf("\n");

        break;

        {
        case 4:
            if((al_containsAll(usuarios, usuariosOriginales)) && (al_containsAll(comentarios, comentariosOriginales)) && usuarios->size == usuariosOriginales->size && comentarios->size == comentariosOriginales->size)
            {
                printf("No se realizaron modificaciones en la sesion actual.\n\n");
            }
            else
            {
                for(i=0; i<usuarios->size; i++)
                {
                    userAux=usuarios->get(usuarios,i);
                    if(usuarios->contains(usuariosOriginales,userAux)==0)
                    {
                        printf("\n-----NUEVOS USUARIOS-----\nNombre= %s\nNick= %s\n",userAux->name, userAux->nick);
                    }
                }
                for(i=0; i<comentarios->size; i++)
                {
                    commentAux=comentarios->get(comentarios,i);
                    if(comentarios->contains(comentariosOriginales,commentAux)==0)
                    {
                        printf("\n-----NUEVOS COMENTARIOS-----\nCOMENTARIO= %s\nLikes= %d\n",commentAux->comments, commentAux->likes);
                    }
                }
            }
            printf("\n");
            break;
        case 5:
            if(usuarios->size < usuariosAMostrar)
                usuariosAMostrar =usuarios->size;

            pArray = usuarios->subList(usuarios,0,usuariosAMostrar);
            printf("Los primeros usuarios fueron:");
            for(i=0; i<usuariosAMostrar; i++)
            {
                userAux=pArray->get(pArray,i);
                printf("\n%d = %s (Nick= %s)",i+1,userAux->name,userAux->nick);
            }
            printf("\n\n\n");

            break;
        default:
            printf("No existe esa opcion... Reintente\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    return 0;
}

/** \brief LISTAR: Realiza un solo listado de los comentarios (mostrando por pantalla el comentario y la cantidad de “Me gusta”) ordenados por los siguientes criterios:
 * Nombre de usuario (descendentemente) && Nick (ascendentemente).
 * \param usuarios: arraylist donde se guardan los usuarios
 * \param comentarios: arraylist donde se guardan los comentarios
 */
void listar(ArrayList *usuarios,ArrayList *comentarios)
{
    ArrayList *cloneUsuarios;
    EComments *comentario;
    User *userAux;
    int i,j;

    cloneUsuarios=usuarios->clone(usuarios);
    al_sort(cloneUsuarios,compareUser,0);

    for(i=0; i<cloneUsuarios->size; i++)
    {
        userAux=al_get(cloneUsuarios,i);
        for(j=0; j<comentarios->size; j++)
        {
            comentario = (comentarios->get(comentarios,j));
            if(userAux->id == comentario->idComentador)
            {
                printf("Comentario %d:%s Nick:%s Cantidad de likes:%d\r\n\n",j+1,comentario->comments,userAux->nick,comentario->likes);
            }
        }
    }
    cloneUsuarios->deleteArrayList(cloneUsuarios);
}

/** \brief Funcion para la carga iniciar de datos guardados en un archivo,
 * \param pList: arrayList donde se guardara la data levantada por la funcion
 * \param nombreArchivo: Nombre del archivo que contiene los datos.
 * \param opcion: parametro utilizado para diferenciar si el dato es un usuario (1) o comentario (2)
 */
int cargarDesdeArchivo(ArrayList* pList,char* nombreArchivo, int opcion)
{
    int flag = 1;
    int retorno=1;
    FILE *archivo;
    User* users;
    EComments* comentarios;

    if(pList != NULL)
    {
        archivo=fopen(nombreArchivo, "rb");
        if(archivo==NULL)
        {
            flag = 0;
            archivo= fopen(nombreArchivo, "wb");
            if(archivo==NULL)
                retorno=0;
        }
        if(flag ==1 && opcion ==1)
        {
            while(!feof(archivo))
            {
                users = malloc(sizeof(User));
                fread(users, sizeof(User),1,archivo);
                if(feof(archivo))
                {
                    break;
                }
                pList->add(pList, users);
            }
        }
        if(flag ==1 && opcion ==2)
        {
            while(!feof(archivo))
            {
                comentarios = malloc(sizeof(EComments));
                fread(comentarios, sizeof(EComments),1,archivo);
                pList->add(pList, comentarios);
            }
        }
        fclose(archivo);
    }
    return retorno;
}

/** \brief Funcion para la guardar datos en un archivo,
 * \param pList: arrayList donde se encuentra la data a guardar
 * \param nombreArchivo: Nombre del archivo.
 * \param opcion: parametro utilizado para diferenciar si el dato es un usuario (1) o comentario (2)
 */
int guardarEnArchivo(ArrayList* pList, char* nombreArchivo, int opcion)
{
    int i;
    int retorno=1;
    FILE *archivo;
    User* users;
    EComments* comentarios;

    if(pList != NULL)
    {
        archivo = fopen(nombreArchivo, "wb");
        if( archivo != NULL)
        {
            if(opcion ==1)
            {
                for(i = 0; i< pList->len(pList); i++)
                {
                    users = al_get(pList, i);
                    if(users != NULL)
                    {
                        fwrite(users, sizeof(User),1, archivo);
                    }
                }
            }
            if(opcion ==2)
            {
                for(i = 0; i< pList->len(pList); i++)
                {
                    comentarios = al_get(pList, i);
                    if(comentarios != NULL)
                    {
                        fwrite(comentarios, sizeof(EComments), 1, archivo);
                    }
                }
            }
            fclose(archivo);
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}
