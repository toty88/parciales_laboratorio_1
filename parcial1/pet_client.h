#include<stdlib.h>
#include<stdio.h>
#include<stdio_ext.h>
#include"pet.h"
#include"client.h"


/** \brief funcion que imprime los clientes junto con sus mascotas
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos del array cliente
 * \param pets[] aPet: el array de tipo mascota
 * \param lenP int: la cantidad de elementos del array mascota
 * \return void: no retorna nada
 *
 */
void printClientAndPet(aClient clients[], int lenC, aPet pets[], int lenP);

/** \brief funcion que imprime las mascotas junto a sus clientes
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param lenP int: la cantidad de elementos del array mascota
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos del array cliente
 * \return void: no retorna nada
 *
 */
void printPetAndClient(aPet pets[], int lenP, aClient clients[], int lenC);

/** \brief funcion que imprime mas cotas mayores a 3 anios con sus duenios
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param lenP int: la cantidad de elementos del array mascota
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos del array cliente
 * \return void: no retorna nada
 *
 */
void printPetsOlderThanThree(aPet pets[], int lenP, aClient clientes[], int lenC);

/** \brief funcion que da de alta una mascota y la asocia a un cliente
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param lenP int: la cantidad de elementos del array mascota
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos del array cliente
 * \param count int: el contador de mascota que se utiliza para generar el ID
 * \return int: retorna 0 en caso que este OK o -1 en caso de que no haya mas espacio para crear mascotas
 *
 */
int createPet(aPet pets[], int lenP, aClient clients[], int lenC, int count, aTypeOfBreed breeds[], int lenB);

/** \brief funcion que eliminar cliente en cascada (junto con sus mascotas)
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos del array cliente
 * \param pets[] aPet: el array de tipo mascota
 * \param lenP int: la cantidad de elementos del array mascota
 * \return int: retorna 0 en caso de haber borrado o -1 en caso de que el usuario haya elegido no borrar
 *
 */
int deleteAllFromClient(aClient clients[], int lenC, aPet pets[], int lenP);

/** \brief funcion que ordena mascotas por tipo
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param pets[] aPet: el array de tipo mascota
 * \param lenC int: la cantidad de elementos del array cliente
 * \param lenP int: la cantidad de elementos del array mascota
 * \return void: no retorna nada
 *
 */
void sortPetByType(aClient clients[], aPet pets[], int lenC, int lenP);

/** \brief funcion que imprime clientes que tengan mas de 1 mascota
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos del array cliente
 * \param pets[] aPet: el array de tipo mascota
 * \param lenP int: la cantidad de elementos del array mascota
 * \return void: no retorna nada
 *
 */
void printClientsWithMoreThanOnePet(aClient clients[], int lenC, aPet pets[], int lenP);

/** \brief funcion que ordena a los clientes en funcion de la cantidad de mascotas
           la funcion brinda opcions para ver el listado de forma ascendente o descendente
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos del array cliente
 * \param pets[] aPet: el array de tipo mascota
 * \param lenP int: la cantidad de elementos del array mascota
 * \return void
 *
 */
void sortClientsByPetCount(aClient clients[], int lenC, aPet pets[], int lenP);

/** \brief funcion que permite eliminar una mascota
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param len int: la cantidad de elementos
 * \return int: retorna 0 en caso de eliminar una mascota o -1 en caso contrario
 *
 */
int deletePet(aPet pets[], int len, aClient clients[], int lenC);

/** \brief funcion que ordena a los clientes en funcion de la cantidad de mascotas y cuando estas son iguales en funcion
           del nombre, brinda 4 tipos de ordenamiento posible
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos del array cliente
 * \param pets[] aPet: el array de tipo mascota
 * \param lenP int: la cantidad de elementos del array mascota
 * \return void: no retorna nada
 *
 */
void sortClientByPetCountAndName(aClient clients[], int lenC, aPet pets[], int lenP);
