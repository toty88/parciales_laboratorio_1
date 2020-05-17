#include"client_pet.h"


void printClientAndPet(aClient clients[], int lenC, aPet pets[], int lenP){

	char sp = ' ';
        printf("\n#########################################################################################################\n"
               "####################################### CLIENT WITH PETS LIST ###########################################\n"
               "#########################################################################################################\n");
        printf("# %2cID%7cFNAME%9cLNAME%10cLOCALE%6cTELEPHONE%5cSEX%5cAGE%15cPETS\n", sp, sp, sp, sp, sp, sp, sp, sp);
        printf("#########################################################################################################\n\n");
	for(int x = 0; x < 5; x++){
		if(clients[x].isEmpty == OCU){
			printf("%6d%12s%14s%16s%15s%8c%8d%5c", clients[x].idClient, clients[x].name, clients[x].last_name, 
						clients[x].locale, clients[x].phone, clients[x].sex, 
						clients[x].age, sp);
		}
		for(int j = 0; j < 20; j++){
			if(clients[x].idClient == pets[j].idClient && pets[j].isEmpty == 1){
				printf("%7s", pets[j].type);
			}
		}
		printf("\n");
				
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
	char sexo;
	int validType;
	int validNumber;
	int clientID;
	index = findFreePetSpot(pets, lenP);
	if(index != -1){
		getString("Input Pet's name: ", name);
		strcpy(pets[index].name, name);
		getString("Input Pet's race: ", race);
		strcpy(pets[index].race, race);
		getString("Input Pet's type [gato:perro:raro]: ", type);
		validType = validateType(type);
		while(validType !=0){
			getString("Error, input Pet's type [gato:perro:raro]: ", type);
			validType = validateType(type);
		}
		strcpy(pets[index].type, type);
		validNumber = validateNumber("Ingrese edad: ", number, 10);
		pets[index].age = validNumber;
		printf("Ingrese peso: ");
		__fpurge(stdin);
		scanf("%f", &weight);
		pets[index].weight = weight;
		printf("Ingrese sexo [f:m]: ");
		__fpurge(stdin);
		scanf("%c", &sexo);
		while(sexo != 'f' && sexo != 'm'){
			printf("Ingrese sexo [f:h]: ");
			__fpurge(stdin);
			scanf("%c", &sexo);
		}
		pets[index].sex = sexo;
		for(int x = 0; x < lenC; x ++){
			if(clients[x].isEmpty == OCU){
				printf("Name: %s, ID: %d\n", clients[x].name, clients[x].idClient);
			}
		}
		validNumber = validateNumber("Input client ID: ", number, 10);
		clientID = findClientById(clients, lenC, validNumber);
		while(clientID == -1){
			validNumber = validateNumber("Error, Input valid client ID: ", number, 10);
			clientID = findClientById(clients, lenC, validNumber);
		}
		
		pets[index].idPet = getId(count);
		pets[index].idClient = clientID;	
		pets[index].isEmpty = OCU;
		resu = 0;
	}
	return resu;
}
