#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


/** \brief funcion que muestra el Menu Principal que muestra opciones que el usuario puede elegir
 *
 * \return int: retorna un numero dentro de las opciones elegidas por el usuario
 *
 */
int mainMenu();

/** \brief funcion que muestra el Menu de Modificacion de Mascotas
 *
 * \param int: variable que se utiliza para acceder a la seccion [2] del menu una vez ingresado el ID de la mascota
 * \return int: retorna un entero que se utiliza en un switch dentro de modifyPet
 *
 */
int modifyPetMenu(int);

/** \brief funcion que muestra el Menu de Modificacion del Cliente
 *
 * \param int: variable que se utiliza para acceder a la seccion [2] del menu una vez ingresado el ID del cliente
 * \return int: retorna un entero que se utiliza en un switch dentro de modifyClient
 *
 */
int modifyClientMenu(int);
