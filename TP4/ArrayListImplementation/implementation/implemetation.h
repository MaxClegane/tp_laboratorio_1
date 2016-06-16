/** \brief Muestra en pantalla el texto que se le envia y solicita al usuario una opcion (int)
 *  \param menu: Se envia cadena de caracteres
 *  \return retorna un entero, debe tener consistencia con el menu mostrado
*/
int imprimirMenu(char *menu);

void listar(ArrayList *usuarios,ArrayList *comentarios);
void altaUsuario(ArrayList *usuarios);
void modUsuario(ArrayList *usuarios);
void borrado(ArrayList * usuarios);
void nuevoComentario(ArrayList *usuarios,ArrayList *comentarios);
void nuevoLike(ArrayList *usuarios,ArrayList *comentarios);
int informar(ArrayList *usuarios,ArrayList *usuariosOriginales,ArrayList *comentarios,ArrayList *comentariosOriginales);
int cargarDesdeArchivo(ArrayList* pList,char* nombreArchivo, int opcion);
int guardarEnArchivo(ArrayList* pList, char* nombreArchivo, int opcion);
