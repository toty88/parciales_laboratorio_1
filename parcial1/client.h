#include<stdio.h>
#include<stdlib.h>
#include"gets.h"
#define TAM_C 10
#define LIBRE 0
#define OCU 1

typedef struct {

	char name[30];
	char last_name[30];
	char locale[30];
	char phone[20];
	char sex;
	int age;
	int idClient; // PK
	int isEmpty;

}aClient;



void hardCode(aClient clients[], int len);
void initClient(aClient clients[], int len);
void printClient(aClient clients[], int lenC);
int findClientById(aClient clients[], int len, int id);
int createClient(aClient clients[], int len, int count);
int findFreeClientSpot(aClient clients[], int len);
