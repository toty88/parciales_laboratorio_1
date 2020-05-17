#include<stdio.h>
#include<string.h>
#include"client.h"

void hardCode(aClient clients[], int len){

	int age[5] = {64, 72, 15, 12, 65};
	char name[5][30] = {"MARIA", "PABLO", "PAOLA", "GERMAN", "HERNESTO"};
	char last_name[5][30] = {"GONZALEZ", "LORENZO", "HERNANDEZ", "GRECCO", "UZZO"};
	char locale[5][30] = {"ALDO BONZI", "CASANOVA", "TAPIALES", "CABA", "BERAZATEGUI"};
	char phone[5][20] = {"4442-4457", "4444-5667", "1234-6754", "9999-8888", "1235-8762"};
	char sex[5]= {'f', 'm', 'f', 'm', 'f'};
	int idClient[5] = {100, 101, 102, 103, 104};
	int isEmpty[5] = {OCU, OCU, OCU, OCU, OCU};
	
	for(int x = 0; x < 5; x++){
		strcpy(clients[x].name, name[x]);
		strcpy(clients[x].last_name, last_name[x]);
		strcpy(clients[x].locale, locale[x]);
		strcpy(clients[x].phone, phone[x]);
		clients[x].sex = sex[x];
		clients[x].age = age[x];
		clients[x].isEmpty = isEmpty[x];
		clients[x].idClient = idClient[x];
	}
}

void initClient(aClient clients[], int len){

	for(int x = 0; x < len; x++){
		clients[x].isEmpty = LIBRE;
	}
}

int findClientById(aClient clients[], int len, int id){

	int validId = -1;

	for(int x = 0; x < len; x ++){
		if(clients[x].isEmpty == OCU && clients[x].idClient == id){
			validId = x;
			break;
		}
	}
	return validId;
}

int findFreeClientSpot(aClient clients[], int len){
	int index = -1;

	for(int x = 0; x < len; x ++){
		if(clients[x].isEmpty == LIBRE){
			index = x;
			break;
		}
	}
	return index;
}

void printClient(aClient clients[], int lenC){

	char sp = ' ';
        printf("\n###############################################################################\n"
               "################################# CLIENT LIST #################################\n"
               "###############################################################################\n");
        printf("# %2cID%7cFNAME%9cLNAME%10cLOCALE%6cTELEPHONE%5cSEX%5cAGE\n", sp, sp, sp, sp, sp, sp, sp);
        printf("###############################################################################\n\n");
	for(int x = 0; x < lenC; x++){
		if(clients[x].isEmpty == OCU){
			printf("%6d%12s%14s%16s%15s%8c%8d\n", clients[x].idClient, clients[x].name, clients[x].last_name, 
						clients[x].locale, clients[x].phone, clients[x].sex, 
						clients[x].age);
		}
	}
}

int createClient(aClient clients[], int len, int count){

	int index;
        int output = -1;
        char name[30];
        char last_name[30];
        char locale[30];
        char phone[20];
        char sex;
	int id;
	int validNumber;
	char age[4];
	index = findFreeClientSpot(clients, len);
	if(index != -1){
       		 getString("Input client's name: ", name);
		 strcpy(clients[index].name, name);
       		 getString("Input client's last name: ", last_name);
		 strcpy(clients[index].last_name, last_name);
       		 getString("Input client's locale: ", locale);
		 strcpy(clients[index].locale, locale);
       		 getString("Input client's phone: ", phone);
		 strcpy(clients[index].phone, phone);
		 sex = getSex("Input client's sex [f:m]: ");
		 validNumber = validateNumber("Input client's age between 8 and 99: ", age, 4);
		 while(validNumber < 8 || validNumber > 99){
		 	validNumber = validateNumber("Error, onlye age between 8 and 99: ", age, 4);
		}
		 clients[index].age = validNumber;
		 clients[index].idClient = getId(count);
		 clients[index].isEmpty = OCU;
		 clients[index].sex = sex;
       		 output = 0;
	}
        return output;
}
