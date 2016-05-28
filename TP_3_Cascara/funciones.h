#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[150];
    int puntaje;
    char linkImagen[200];

    int isEmpty;
} EMovie;

#endif // FUNCIONES_H_INCLUDED

/**
 *  \brief Agrega una pelicula al array de estructuras
 *  @param movies: estructura donde se guardara el registro
 *  @param lenght: Tamaño del array de estructura
 *  @return retorna 1 si pudo agregar o 0 si fallo
 */
void agregarPelicula(EMovie* movies,int lenght);

/**
 *  \brief Borra logicamente (colocando 1 en isEmpty)
 *  @param movies: estructura donde se borrara el registro
 *  @param lenght: Tamaño del array de estructura
 *  @return retorna 1 si pudo borrar o 0 si fallo
 */
void borrarPelicula(EMovie* movies,int lenght);

/**
 *  \brief Funcion para modificar una pelicula. Se solicita el nombre de la pelicula, en caso de existir
 *  se muestra un menu con opciones para modificar
 *  @param movies: estructura de peliculas
 *  @param lenght: Tamaño del array de estructura
 */
void modificarPelicula(EMovie* movie,int lenght);

/** \brief Al ejecutar el programa, se lee el archivo "bin.dat" y se guarda en memoria. El archivo
 *  debe estaren la misma carpeta que el proyecto, si no existe lo crea.
 * \param movies: Se envia direccion de memoria del array de estructuras donde debe guardar la info leida
 * \return retorna 1 si pudo cargar o 0 si fallo.
 */
int cargarDesdeArchivo(EMovie *movies);

/** \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param movies: la lista de peliculas a ser agregadas en el archivo.
 *  @param lenght: Tamaño del array de estructura
 *  @param nombre el nombre para el archivo.
 */
void crearHtml(EMovie *movies,int lenght);

/** \brief Al salir del programa con la opcion 5 del menu, se ofrece la posibilidad de
 *  guardar informacion en el archivo bin.dat
 *  @param movies: la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
int guardarEnArchivo(EMovie *movies);
