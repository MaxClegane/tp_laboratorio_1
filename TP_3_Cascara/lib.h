
/** \brief Obtiene el primer indice libre del array
 *  \param movies: el array de peliculas
 *  \param lenght: tamaño del array
 *  \return el primer indice disponible
 */
int obtenerEspacioLibre(EMovie* movies, int lenght);

/** \brief Muestra en pantalla el texto que se le envia y solicita al usuario una opcion (int)
 *  \param menu: Se envia cadena de caracteres
 *  \return retorna un entero, debe tener consistencia con el menu mostrado
*/
int imprimirMenu(char *menu);

/** \brief Muestra en pantalla datos del array de peliculas.
 *  \param movies: Seel array de peliculas
 *  \return NULL
*/
void mostrarPelicula(EMovie* movies);

/** \brief Solicita el ingreso de un numero y lo valida contra un rango especifico
 * \param minimo: Valor minimo del rango
 * \param maximo: Valor maximo del rango
 * \return Devuelve un numero valido.
 */
int solicitarInt(int minimo, int maximo);
