#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"
#include "ArrayList.h"
#include "implemetation.h"

int compareUser(void* UserA,void* UserB)
{
    int retorno=0;
    if(strcmp((((User*)UserA)->name),(((User*)UserB)->name)) >0)
    {
        retorno=1;
    }
    if(strcmp((((User*)UserA)->name),(((User*)UserB)->name)) <0)
    {
        retorno=-1;
    }

    return retorno;
}



void printUser(User* user)
{
    printf("%d= Nombre:%s Nick:%s Mail:%s\r\n",user->id,user->name,user->nick,user->email);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
User* newUser(char *name, char *nick, char *password,char *email, int id)
{
    User* returnAux = NULL;
    User* pUser = malloc(sizeof(User));

    if(pUser != NULL)
    {
        strcpy(pUser->name,name);
        strcpy(pUser->nick,nick);
        strcpy(pUser->password,password);
        strcpy(pUser->email,email);
        pUser->id=id;

        pUser->isEmpty = 0;

        returnAux = pUser;
    }

    return returnAux;

}

EComments* newComment(char *comments, int idComentador,int id)
{
    EComments* returnAux = NULL;
    EComments* pComment = malloc(sizeof(EComments));

    if(pComment != NULL)
    {
        strcpy(pComment->comments,comments);

        pComment->idComentador=idComentador;
        pComment->likes = 0;
        pComment->isEmpty = 0;
        pComment->id=id;

        returnAux = pComment;
    }

    return returnAux;

}

