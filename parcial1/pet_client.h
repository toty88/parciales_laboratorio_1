#include<stdlib.h>
#include<stdio.h>
#include<stdio_ext.h>
#include"pet.h"
#include"client.h"


void printClientAndPet(aClient clients[], int lenC, aPet pets[], int lenP);
void printPetAndClient(aPet pets[], int lenP, aClient clients[], int lenC);
void printPetsOlderThanThree(aPet pets[], int lenP, aClient clientes[], int lenC);
int createPet(aPet pets[], int lenP, aClient clients[], int lenC, int count);
int deleteAllFromClient(aClient clients[], int lenC, aPet pets[], int lenP);
void sortPetByType(aClient clients[], aPet pets[], int lenC, int lenP);
int printClientsWithMoreThanOnePet(aClient clients[], int lenC, aPet pets[], int lenP);
void sortClientsByPetCount(aClient clients[], int lenC, aPet pets[], int lenP, aPetClientCounter pCount[], int lenPC);
void sortClientByPetCountAndName(aClient clients[], int lenC, aPet pets[], int lenP, aPetClientCounter pCount[], int lenPC);
