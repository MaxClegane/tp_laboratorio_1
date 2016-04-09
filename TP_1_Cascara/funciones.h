#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
float IngresarPrimerOperando(void);
/** \brief: Funcion para el ingreso del primer operando.
 *
 * \param null
 * \param null
 * \return Regresa un numero flotante.
 *
 */

float IngresarSegundoOperando(void);
/** \brief: Funcion para el ingreso del segundo operando.
 *
 * \param null
 * \param null
 * \return Regresa un numero flotante.
 *
 */

void CalcularSuma(float,float,int,int);
/** \brief: Funcion para calcular la suma de 2 numeros flotante y mostrarlo en pantalla.
 *
 * \param1: El parametro 1 es el primer operando.
 * \param2: El parametro 2 es el segundo operando.
 * \param3: El parametro 3 es el flag del primer operando.
 * \param4: El parametro 4 es el flag del segundo operando.
 * \return null
 *
 */

void CalcularResta(float,float,int,int);
/** \brief: Funcion para calcular la resta de 2 numeros flotante y mostrarlo en pantalla.
 *
 * \param1: El parametro 1 es el primer operando.
 * \param2: El parametro 2 es el segundo operando.
 * \param3: El parametro 3 es el flag del primer operando.
 * \param4: El parametro 4 es el flag del segundo operando.
 * \return null
 *
 */

void CalcularDivision(float,float,int,int);
/** \brief: Funcion para calcular la division de 2 numeros flotante y mostrarlo en pantalla.
 *
 * \param1: El parametro 1 es el primer operando.
 * \param2: El parametro 2 es el segundo operando.
 * \param3: El parametro 3 es el flag del primer operando.
 * \param4: El parametro 4 es el flag del segundo operando.
 * \return null
 *
 */

void CalcularMultiplicacion(float,float,int,int);
/** \brief: Funcion para calcular la multiplicacion de 2 numeros flotante y mostrarlo en pantalla.
 *
 * \param1: El parametro 1 es el primer operando.
 * \param2: El parametro 2 es el segundo operando.
 * \param3: El parametro 3 es el flag del primer operando.
 * \param4: El parametro 4 es el flag del segundo operando.
 * \return null
 *
 */

void CalcularFactorialA(float,int);
/** \brief: Funcion para calcular el factorial del primer operando y mostrarlo en pantalla.
 *
 * \param1: El parametro 1 es el primer operando.
 * \param2: El parametro 2 es el flag del primer operando.
 * \return null
 *
 */

int CalcularFactorialA2(int);
/** \brief Funcion para calcular la recursividad del factorial
 *
 * \param: Parte entera del numero.
 *
 * \return: resultado de la recursividad.
 *
 */


void TodasOperaciones(float,float,int,int);
/** \brief: Funcion que calcula todas las operaciones, llamando al resto de las funciones.
 *
 * \param1: El parametro 1 es el primer operando.
 * \param2: El parametro 2 es el segundo operando.
 * \param3: El parametro 3 es el flag del primer operando.
 * \param4: El parametro 4 es el flag del segundo operando.
 * \return null
 *
 */

#endif // FUNCIONES_H_INCLUDED
