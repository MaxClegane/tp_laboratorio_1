#ifndef __USER
#define ____USER
struct
{
    char name[51];
    char nick[51];
    char password[51];
    char email[51];

    int id;
    int isEmpty;

}typedef User;

struct
{
    char comments[250];
    int likes;
    int idComentador;
    int isEmpty;
    int id;

}typedef EComments;
#endif  //____USER

int compareUser(void* pEmployeeA,void* pEmployeeB);

User* newUser(char *name, char *nick, char *password,char *email, int id);

void printUser(User* user);

EComments* newComment(char *comments, int idComentador,int id);
