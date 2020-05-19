#include<stdio.h>
#include<stdlib.h>
#include"gets.h"
#include"menu.h"
#define TAM_C 10
#define TAM_PC 10
#define LIBRE 0
#define OCU 1

typedef struct {

	char name[30];
	char last_name[30];
	char locale[30];
	char phone[20];
	char sex;
	int age;
	int idClient; // FK
	int petCounter;
	int isEmpty;

}aClient;



/** \brief funcion que utilizamos para inicializar una cantidad de clientes y probar codigo
 *
 * \param clients[] aClient: el array de tipo aClient
 * \param len int: la cantidad de elementos del array
 * \return void: no retorna nada
 *
 */
void hardCodeClient(aClient clients[], int len);


/** \brief funcion que inicializa todas las variables isEmpty en cero
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param len int: la cantidad de elementos del array
 * \return void: no retorna nada
 *
 */
void initClient(aClient clients[], int len);

/** \brief funcion que muestra por pantalla todos los clientes
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos del array
 * \return void: no retorna nada
 *
 */
void printClient(aClient clients[], int lenC);

/** \brief funcion que busca un cliente determinado de acuerdo a su ID
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param len int: la canitdad de elementos
 * \param id int: el ID que se utiliza como comparacion
 * \return int: retorna el indice del cliente si esta OK o -1 en caso de no encontrar el ID
 *
 */
int findClientById(aClient clients[], int len, int id);

/** \brief funcion que crea un nuevo cliente
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param len int: la cantidad de elementos del array
 * \param count int: un contador de clientes que se utiliza para llamar a la funcion getId
 * \return int: retorna 0 si esta todo ok o -1 en caso de error
 *
 */
int createClient(aClient clients[], int len, int count);

/** \brief funcion que busca un indice libre dentro del array de estructuras cliente
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param len int: la cantidad de elementos del array
 * \return int: retorna el subinidce en caso de estar OK o -1 en caso de no haber mas subindices libres
 *
 */
int findFreeClientSpot(aClient clients[], int len);

/** \brief funcion que nos permite modificar un cliente, compuesta de 2 secciones
           solo se puede acceder a la seccion [2] ingresando el ID del cliente
           caso contrario se muestra la seccion [1]
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param len int: la cantidad de elementos del array
 * \return int: retorna 0 si se modifoco cliente o -1 en caso de que no haya habido modificacion
 *
 */
int modifyClient(aClient clients[], int len);

/** \brief funcin que imprime un solo cliente
 *
 * \param client aClient: variable de tipo cliente
 * \return void: no retorna nada
 *
 */
void printOneClient(aClient client);

/** \brief funcion que devuelve la edad promedio entre los clientes masculinos y femeninos
 *
 * \param clients[] aClient: el array de tipo cliente
 * \param lenC int: la cantidad de elementos
 * \return void: no devuelve nada
 *
 */
void averageAgeAmongClients(aClient clients[], int lenC);
void averageMenAndWomen(aClient clients[], int lenC);
