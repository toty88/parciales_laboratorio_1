#include<stdio.h>
#include<stdlib.h>
#include"gets.h"
#include"menu.h"
#define LIBRE 0
#define OCU 1
#define TAM_M 20

typedef struct {

	char name[30];
	char race[20];
	char type[30];
	char sex;
	int age;
	float weight;
	int idClient;
	int idPet;
	int isEmpty;

}aPet;


/** \brief funcion que hardcodea 11 mascotas para testear durante el programa
 *
 * \param pets[] aPet: el array de tipo estructura mascota
 * \param len int: la cantidad de elementos del array
 * \return void: no retorna nada
 *
 */
void hardCodePets(aPet pets[], int len);

/** \brief funcion que setea la variable isEmpty de todas las mascotas en 0
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param len int: la cantidad de elementos
 * \return void: no retorna nada
 *
 */
void initPet(aPet pets[], int len);

/** \brief funcion que imprime todas las mascotas
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param len int: la cantidad de elementos
 * \return void: no retorna nada
 *
 */
void printPets(aPet pets[], int lenP);

/** \brief funcion que busca un subindice libre dentro del array de mascotas
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param len int: la cantidad de elementos
 * \return int: retorna el subindice en caso de haber espacio o -1 en caso contrario
 *
 */
int findFreePetSpot(aPet pets[], int len);

/** \brief funcion que valida el tipo [perro:gato:raro] de mascota
 *
 * \param validar[] char: mensaje que se le muestra al usuario
 * \return int: retorna 0 si la validacion esta ok o -1 en caso contrario
 *
 */
int validateType(char validar[]);


/** \brief funcion que busca una mascota de acuerdo a un ID proporcionado por el usuario
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param len int: la cantidad de elementos
 * \param id int: el ID proporcionado por el usuario
 * \return int: devuelve el subindice de la mascota si esta OK o -1 en caso de no hacer match con el ID
 *
 */
int getPetById(aPet pets[], int len, int id);

/** \brief funcion que nos permite modificar una mascota, dividia en 2 secciones
           solo se puede acceder a la seccion [2] una vez que el usuario ingresa el ID
           caso contrario se sigue mostrando seccion [1]
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param len int: la cantidad de elementos
 * \return int: retorna cero si se hizo al menos 1 modificacion o -1 en caso de ninguna
 *
 */
int modifyPet(aPet pets[], int len);

/** \brief funcion que imprime una sola mascota
 *
 * \param pets aPet la variable de tipo mascota
 * \return void: no retorna nada
 *
 */
void printOnePet(aPet pets);

/** \brief funcion que imprime las mascotas de acuerdo a un tipo elegido por el usuario
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param len int: la cantidad de elementos
 * \return void: no retorna nada
 *
 */
void printPetByChosenType(aPet pets[], int lenP);

/** \brief funcion que calcula el promedio de edad de todas las mascotas
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param len int: la cantidad de elementos
 * \return float: se retorna el promedio calculado
 *
 */
float averagePetAge(aPet pets[], int lenP);

/** \brief funcion que calcula el promedo de edad segun tipo de mascota
 *
 * \param pets[] aPet: el array de tipo mascota
 * \param len int: la cantidad de elementos
 * \return void: no retorna nada
 *
 */
void averagePetAgeByType(aPet pets[], int lenP);
