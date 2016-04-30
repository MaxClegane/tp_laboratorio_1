#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief inicializa recorriendo todo el array de personas colocando en 1 su estado
 * \param lista el array se pasa como parametro.
 * \param lenght: se pasa el tamaño del array
 * \return null
 */
 void init(EPersona* lista, int lenght);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param lenght: se pasa el tamaño del array
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona* lista, int lenght);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param lenght: se pasa el tamaño del array
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona* lista, int dni, int lenght);

/** \brief Agrega una persona al primer indice libre
 * \param lista: el array se pasa como parametro
 * \param lenght: se pasa el tamaño del array
 * \return [1] si agrego, [0] si falla
 */
int addPerson(EPersona* lista, int lenght);

/** \brief Borra una persona, colocando en 1 su estado
 * \param lista: el array se pasa como parametro
 * \param lenght: se pasa el tamaño del array
 * \return [1] si borro, [0] si falla
 */
int deletePerson(EPersona* lista, int lenght);

/** \brief Informara al usuario si logro agregar
 * \param respuesta: valor numerico para definir la informacion a mostrar
 * \return null
 */

void informa(int respuesta);

/** \brief Ordena a las personas por nombre
 * \param lista: el array se pasa como parametro
 * \param lenght: se pasa el tamaño del array
 * \return [1] si borro, [0] si falla
 */
int orderPerson(EPersona* lista, int lenght);

/** \brief Valida el dni ingresado. En caso de incorrecto, solicita el reingreso y vuelve a validar.
 * \param dni: entero donde se envia el dni
 * \param MAXDNI: un define declarado. Actualmente el valor es 99.999.999, se hardcodea ya que en un futuro podria ser mayor.
 * \param validador: Variable utilizada para determinar si el valor es un entero o bien posee algun caracter incorrecto.
 * \return retorna el dni validado
 */
int dniValidado(int dni, int MAXDNI, int validador);

/** \brief Valida la edad ingresada. En caso de incorrecta, solicita el reingreso y vuelve a validar.
 * \param edad: entero donde se envia la edad
 * \param MAXEDAD: un define declarado. Actualmente el valor es 100, se hardcodea ya que en un futuro podria ser mayor.
 * \param validador: Variable utilizada para determinar si el valor es un entero o bien posee algun caracter incorrecto.
 * \return retorna la edad validada
 */
int edadValidada(int edad, int MAXEDAD, int validador);

/** \brief Funcion para graficar, tomando como referencia las edades de las personas cargadas.
 * \param lista: el array se pasa como parametro
 * \param lenght: se pasa el tamaño del array
 * \return null
 */
void graficar(EPersona* lista, int lenght);
#endif // FUNCIONES_H_INCLUDED
