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
	int isEmpty;

}aClient;

typedef struct{

	int idClient; // PK
	int counter;
	int isEmpty;

}aPetClientCounter;



void hardCodeClient(aClient clients[], int len);
void hardCodePetCounter(aPetClientCounter petCount[]);
void initClient(aClient clients[], int len);
void printClient(aClient clients[], int lenC);
int findClientById(aClient clients[], int len, int id);
int createClient(aClient clients[], int len, int count, aPetClientCounter petCount[]);
int findFreeClientSpot(aClient clients[], int len);
int modifyClient(aClient clients[], int len);
void printOneClient(aClient client);
void initPetCounter(aPetClientCounter petCounter[], int len);
