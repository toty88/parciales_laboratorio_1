#include"pet_client.h"


void printClientAndPet(aClient clients[], int lenC, aPet pets[], int lenP){

	char sp = ' ';
        printf("\n#########################################################################################################\n"
               "####################################### CLIENT WITH PETS LIST ###########################################\n"
               "#########################################################################################################\n");
        printf("# %2cID%7cFNAME%9cLNAME%10cLOCALE%6cTELEPHONE%5cSEX%5cAGE%15cPETS\n", sp, sp, sp, sp, sp, sp, sp, sp);
        printf("#########################################################################################################\n\n");
	for(int x = 0; x < lenC; x++){
		if(clients[x].isEmpty == OCU){
			printf("%6d%12s%14s%16s%15s%8c%8d%5c", clients[x].idClient, clients[x].name, clients[x].last_name, 
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
		
		pets[index].idPet = getId(count);
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
