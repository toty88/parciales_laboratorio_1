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


void hardCodePets(aPet pets[], int len);
void initPet(aPet pets[], int len);
void printPets(aPet pets[], int lenP);
int findFreePetSpot(aPet pets[], int len);
int validateType(char validar[]);
int deletePet(aPet pets[], int len);
int getPetById(aPet pets[], int len, int id);
void modifyPet(aPet pets[], int len);
void printOnePet(aPet pets);
