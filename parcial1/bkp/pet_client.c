#include<string.h>
#include"pet_client.h"


void printClientAndPet(aClient clients[], int lenC, aPet pets[], int lenP){

	char sp = ' ';
        printf("\n############################################################################################################\n"
               "######################################### CLIENT WITH PETS LIST ############################################\n"
               "############################################################################################################\n");
        printf("# %5cID%7cFNAME%9cLNAME%10cLOCALE%6cTELEPHONE%5cSEX%5cAGE%15cPETS\n", sp, sp, sp, sp, sp, sp, sp, sp);
        printf("############################################################################################################\n\n");
	for(int x = 0; x < lenC; x++){
		if(clients[x].isEmpty == OCU){
			printf("%d) %6d%12s%14s%16s%15s%8c%8d%5c", x+1, clients[x].idClient, clients[x].name, clients[x].last_name, 
						clients[x].locale, clients[x].phone, clients[x].sex, 
						clients[x].age, sp);
			for(int j = 0; j < lenP; j++){
				if(clients[x].idClient == pets[j].idClient && pets[j].isEmpty == OCU){
					printf("%7s", pets[j].type);
				}
			}
			printf("\n");
		}
	}
}

void printPetAndClient(aPet pets[], int lenP, aClient clients[], int lenC){

	int n = 1;
	for(int x = 0; x < lenP; x++){
		if(pets[x].isEmpty == OCU){
			if(n<=9){
				printf("%d)%8d%6d%16s%13s%18s%12.2fkg%8c%8d", n, pets[x].idPet, 
					pets[x].idClient, pets[x].name, pets[x].type,
					pets[x].race,pets[x].sex,pets[x].weight, pets[x].age);
			}else{
				printf("%d)%7d%6d%16s%13s%18s%12.2fkg%8c%8d", n, pets[x].idPet, 
					pets[x].idClient, pets[x].name, pets[x].type,
					pets[x].race,pets[x].sex,pets[x].weight, pets[x].age);
			}
			for(int j = 0; j < lenC; j++){
				if(pets[x].idClient == clients[j].idClient){
					printf("%15s", clients[j].name);
				}
			
			}
			printf("\n");
			n++;
		}
	}
}

void printPetsOlderThanThree(aPet pets[], int lenP, aClient clients[], int lenC){

	char sp = ' ';
        printf("\n########################################################################################################\n"
               "########################################## PETS OLDER THAN 3 ###########################################\n"
               "########################################################################################################\n");
        printf("# ID_P%2cID_C%12cNAME%9cTYPE%13cBREED%8cWEIGHT%5cSEX%5cAGE%5cOWNER_NAME\n", sp, sp, sp, sp, sp, sp, sp, sp);
        printf("########################################################################################################\n\n");

	for(int j = 0; j < lenP; j++){
		if(pets[j].age > 3 && pets[j].isEmpty == OCU){
			printf("%6d%6d%16s%13s%18s%12.2fkg%8c%8d", 
					pets[j].idPet, pets[j].idClient, pets[j].name, pets[j].type,
					pets[j].race,pets[j].sex,pets[j].weight, pets[j].age);
			for(int x = 0; x < lenC; x++){
				if(pets[j].idClient == clients[x].idClient){
					printf("%15s", clients[x].name);
				}
			
			}
			printf("\n");
		}
	}
}


int createPet(aPet pets[], int lenP, aClient clients[], int lenC, int count){

	int resu = -1;
	int index;
	float weight;
	char name[31];
	char number[10];
	char race[20];
	char type[30];
	char sex;
	int validType;
	int validNumber;
	int clientIndex;
	index = findFreePetSpot(pets, lenP);
	if(index != -1){
		getString("Input Pet's name: ", name);
		strcpy(pets[index].name, name);
		getString("Input Pet's breed: ", race);
		strcpy(pets[index].race, race);
		getString("Input Pet's type [gato:perro:raro]: ", type);
		validType = validateType(type);
		while(validType !=0){
			getString("Error, input Pet's type [gato:perro:raro]: ", type);
			validType = validateType(type);
		}
		strcpy(pets[index].type, type);
		validNumber = validateNumber("Input pet's age: ", number, 10);
		pets[index].age = validNumber;
		printf("Input pet's weight: ");
		__fpurge(stdin);
		scanf("%f", &weight);
		pets[index].weight = weight;
		sex = getSex("Input pet's sex [f:m]: ");
		pets[index].sex = sex;
		for(int x = 0; x < lenC; x ++){
			if(clients[x].isEmpty == OCU){
				printf("Name: %s, ID: %d\n", clients[x].name, clients[x].idClient);
			}
		}
		validNumber = validateNumber("Input client ID: ", number, 10);
		clientIndex = findClientById(clients, lenC, validNumber);
		while(clientIndex == -1){
			validNumber = validateNumber("Error, Input valid client ID: ", number, 10);
			clientIndex = findClientById(clients, lenC, validNumber);
		}
		
		pets[index].idPet = getId(count, 2);
		pets[index].idClient = clients[clientIndex].idClient;
		pets[index].isEmpty = OCU;
		resu = 0;
	}
	return resu;
}


int deleteAllFromClient(aClient clients[], int lenC, aPet pets[], int lenP){


	printClientAndPet(clients, lenC, pets, lenP);
	char number[10];
	int validateN;
	int index;
	int id;
	int output = -1;
	char opt;
	validateN = validateNumber("\nInput Client ID: ", number, 10);
	index = findClientById(clients, lenC, validateN);
	while(index == -1){
		validateN = validateNumber("Wrong ID, try again: ", number, 10);
		index = findClientById(clients, lenC, validateN);
	}
	printf("You're about to remove %s %s with all his/her pet/s. Are you sure [y:n] ", clients[index].name, clients[index].last_name);
	id = clients[index].idClient;
	__fpurge(stdin);
	scanf("%c", &opt);
	while(opt !='y' && opt !='n'){
		printf("Wrong, Are you sure [y:n] ");
		__fpurge(stdin);
		scanf("%c", &opt);
	}
	if(opt == 'y'){
		for(int x = 0; x < lenC; x++){
			if(clients[x].idClient == id && clients[x].isEmpty == OCU){
				for(int j = 0; j < lenP; j++){
					if(clients[x].idClient == pets[j].idClient && pets[j].isEmpty == OCU){
						pets[j].isEmpty = LIBRE;
					}
				}
				clients[x].isEmpty = LIBRE;
				break;
			}
		}
		output = 0;
		printf("Client with all his/her pet/s has been removed");

	}else{
		printf("No Client removed");
	}
	return output;
}


void sortPetByType(aClient clients[], aPet pets[], int lenC, int lenP){

	aPet auxPet;
	char number[4];
	int option;
	char sp = ' ';
	option = validateNumber("Wanna sort pet types by UP [1] or DOWN [0]: ", number, 4);
	while(option != 1 && option != 0){
		option = validateNumber("Wrong, only UP [1] or DOWN [0]: ", number, 4);
	}

	
	if(option == 1){
		for(int x = 0; x < lenP-1; x++){
			for(int j = x+1; j < lenP; j++){
				if(strcmp(pets[x].type, pets[j].type)>0){
					auxPet = pets[x];
					pets[x] = pets[j];
					pets[j] = auxPet;
				}
			}
		}
	}else{
		for(int x = 0; x < lenP-1; x++){
			for(int j = x+1; j < lenP; j++){
				if(strcmp(pets[x].type, pets[j].type)<0){
					auxPet = pets[x];
					pets[x] = pets[j];
					pets[j] = auxPet;
				}
			}
		}
	}

        printf("\n############################################################################################################\n"
               "########################################### PETS SORTED BY TYPES ###########################################\n"
               "############################################################################################################\n");
        printf("# %4cID_P%2cID_C%12cNAME%9cTYPE%13cBREED%8cWEIGHT%5cSEX%5cAGE%5cOWNER_NAME\n", sp, sp, sp, sp, sp, sp, sp, sp, sp);
        printf("############################################################################################################\n\n");
	printPetAndClient(pets, lenP, clients, lenC);
}

int printClientsWithMoreThanOnePet(aClient clients[], int lenC, aPet pets[], int lenP){

	int petCounter;
	char sp = ' ';
        printf("###############################################################################\n");
        printf("# %2cID%7cFNAME%9cLNAME%10cLOCALE%6cTELEPHONE%5cSEX%5cAGE\n", sp, sp, sp, sp, sp, sp, sp);
        printf("###############################################################################\n");

	for(int x = 0; x < lenC; x++){
		petCounter = 0;
		for(int j = 0; j < lenP; j++){
			if(pets[j].idClient == clients[x].idClient){
				petCounter++;
			}
		}
		if(clients[x].isEmpty == OCU && petCounter>1){
			printOneClient(clients[x]);
		}
	}
        printf("###############################################################################\n");
}
	
void sortClientsByPetCount(aClient clients[], int lenC, aPet pets[], int lenP, aPetClientCounter pCount[], int lenPC){
	
	aClient auxClient;
	aPetClientCounter auxPetCounter;
	initPetCounter(pCount, lenPC);
	for(int x = 0; x < lenC; x++){
		for(int j = 0; j < lenP; j++){
			if(clients[x].idClient == pets[j].idClient && clients[x].isEmpty == OCU){
				pCount[x].counter +=1;	
			}
		}
	}
	for(int x = 0; x < lenC -1; x++){
		for(int j = x+1; j < lenC; j++){
			if(pCount[x].counter < pCount[j].counter && pCount[x].isEmpty == OCU){
				
				auxPetCounter = pCount[x];
				pCount[x] = pCount[j];
				pCount[j] = auxPetCounter;

				auxClient = clients[x];
				clients[x] = clients[j];
				clients[j] = auxClient;
			}
		}
	}
}

void sortClientByPetCountAndName(aClient clients[], int lenC, aPet pets[], int lenP, aPetClientCounter pCount[], int lenPC){
	
	aClient auxClient;
	aPetClientCounter auxPetCounter;
	initPetCounter(pCount, lenPC);
	for(int x = 0; x < lenC; x++){
		for(int j = 0; j < lenP; j++){
			if(clients[x].idClient == pets[j].idClient && clients[x].isEmpty == OCU){
				pCount[x].counter +=1;	
			}
		}
	}
	for(int x = 0; x < lenC -1; x++){
		for(int j = x+1; j < lenC; j++){
			if(clients[x].isEmpty == OCU){
				if(pCount[x].counter < pCount[j].counter){
					
					auxPetCounter = pCount[x];
					pCount[x] = pCount[j];
					pCount[j] = auxPetCounter;

					auxClient = clients[x];
					clients[x] = clients[j];
					clients[j] = auxClient;

				}else {
					if(pCount[x].counter == pCount[j].counter && (strcmp(clients[x].name, clients[j].name))>0){

						auxPetCounter = pCount[x];
						pCount[x] = pCount[j];
						pCount[j] = auxPetCounter;

						auxClient = clients[x];
						clients[x] = clients[j];
						clients[j] = auxClient;
					}
				}
			}
		}
	}
}
