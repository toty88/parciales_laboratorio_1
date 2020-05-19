#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

/** \brief funcion que valida si lo que se ingresa por stdin es un numero entero
           caso negativo se vuelve a pedir el numero dentro de la funcion
 *
 * \param msg[] char: el mensaje que se le pasa al usuario
 * \param text[] char: el texto que contiene el numero a validad
 * \param size int: la longitud del texto
 * \return int: retorna el numero una vez validado
 *
 */
int validateNumber(char msg[], char text[], int size);

/** \brief funcion que solicita una cadena de texto
 *
 * \param msg[] char: el mensaje que se le pasa al usuario solicitando (nombre, apellido...)
 * \param name[] char: la variable donde se guarda lo que ingresa el usuario
 * \return void: no devuelve nada
 *
 */
void getString(char msg[], char name[]);

/** \brief funcion que genera un ID tanto para mascotas como clientes
 *
 * \param counter int: el contador que se pasa para generar el ID
 * \param opt int: variable que se utiliza para saber si calcular ID de mascota o cliente
 * \return int: retorna el ID
 *
 */
int getId(int counter, int opt);

/** \brief funcion que se utiliza para solicitar el sexo de la mascota o cliente
 *
 * \param msg[] char: mensaje que se le pasa al usuario
 * \return char: se retorna el caracter
 *
 */
char getSex(char msg[]);
