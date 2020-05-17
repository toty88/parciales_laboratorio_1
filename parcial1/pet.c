#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include"pet.h"

void initPet(aPet pets[], int len){

	for(int x = 0; x < len; x++){
		pets[x].isEmpty = LIBRE;
	}
}

void hardCodePets(aPet pets[], int len){

	int age[11] = {12, 11, 10, 5, 8, 6, 8, 10, 7, 11, 12};
	char name[11][30] = {"FIRULAIS", "ATHOS", "ZEUS", "ERGO", "ATHILA", "PEPITO", 
		"ROCKET", "CEREBRO", "SONRISAS", "HUMOROSO", "GRUTI"};

	char race[11][30] = {"SIAMES", "SIAMES", "OVEJERO", "OVEJERO", "PERSA", 
		"PITBULL", "IGUANA DE SOL", "LABRADOR", "CALLEJERO", "CALLEJERO", "BULLDOG"};

	char type[11][30] = {"GATO", "GATO", "PERRO", "PERRO", "GATO", "PERRO", 
		"RARO", "PERRO", "GATO", "GATO", "PERRO"};

	float weight[11]= {2.5, 7.4, 3.2, 1.8, 9.8, 8.7, 1.2, 4.3, 11.2, 6.3, 9.3};
	char sex[11]= {'m', 'm', 'f', 'm', 'f','m', 'm', 'f', 'm', 'f', 'm'};
	int idClient[11] = {100,100,101,101,101,102,102,103,104,104,104};
	int idPet[11] = {200,201,203,204,205,206,207,208,209,210,211};
	int isEmpty[11] = {OCU, OCU, OCU, OCU, OCU, OCU, OCU, OCU, OCU, OCU, OCU};
	
	for(int x = 0; x < 11; x++){
		pets[x].age = age[x];
		strcpy(pets[x].name, name[x]);
		strcpy(pets[x].race, race[x]);
		strcpy(pets[x].type, type[x]);
		pets[x].sex = sex[x];
		pets[x].weight = weight[x];
		pets[x].idClient = idClient[x];
		pets[x].idPet = idPet[x];
		pets[x].isEmpty = isEmpty[x];
	}
}

int findFreePetSpot(aPet pets[], int len){

	int index = -1;
	for(int x = 0; x < len; x++){
		if(pets[x].isEmpty == LIBRE){
			index = x;
			break;
		}
	}
	return index;
}

void printPets(aPet pets[], int lenP){
	char sp = ' ';
        printf("\n#########################################################################################\n"
               "###################################### PETS LIST ########################################\n"
               "#########################################################################################\n");
        printf("# %2cID%2cID_C%12cNAME%9cTYPE%14cRACE%8cWEIGHT%5cSEX%5cAGE\n", sp, sp, sp, sp, sp, sp, sp, sp);
        printf("#########################################################################################\n\n");

	for(int x = 0; x < lenP; x++){
		if(pets[x].isEmpty == OCU){
			printf("%6d%6d%16s%13s%18s%12.2fkg%8c%8d\n", 
					pets[x].idPet, pets[x].idClient, pets[x].name, pets[x].type,
					pets[x].race,pets[x].sex,pets[x].weight, pets[x].age);
		}
	}
}

int getPetById(aPet pets[], int len, int id){
	int index = -1;
	for(int x = 0; x < len; x++){
		if(pets[x].isEmpty == OCU && pets[x].idPet == id){
			index = x;
			break;
		}
	}
	return index;
}

void deletePet(aPet pets[], int len){

	char number[10];
	int validateN;
	int index;
	printPets(pets, len);
	validateN = validateNumber("Input Pet ID: ", number, 10);
	index = getPetById(pets, len, validateN);
	while(index == -1){
		validateN = validateNumber("Wrong ID, try again: ", number, 10);
		index = getPetById(pets, len, validateN);
	}
	pets[index].isEmpty = LIBRE;
	printf("Pet deleted");
}

void modifyPet(aPet pets[], int len){

	char number[10];
	int opt;
	int validateN;
	char name[30];
	char race[20];
	char type[30];
	float weight;
	char sexo;
	int index;
	int flag = 0;
	int validType;
	do{
		opt = modifyPetMenu();

		switch(opt){
			
			case 1:
				printPets(pets, len);
				break;

			case 2:
				validateN = validateNumber("Input Pet ID to be modified: ", number, 10);
				index = getPetById(pets, len, validateN);
				while(index == -1){
					validateN = validateNumber("Wrong ID, try again: ", number, 10);
					index = getPetById(pets, len, validateN);
				}
				flag = 1;
				break;

			case 3:
				if(flag == 1){
					getString("Input New Pet's name: ", name);
					strcpy(pets[index].name, name);

				}else{
					printf("Input Pet's ID first [2]");
				}
				break;
			case 4:
				if(flag == 1){
					printf("Input new sex [f:m]: ");
					__fpurge(stdin);
					scanf("%c", &sexo);
					while(sexo != 'f' && sexo != 'm'){
						printf("Ingrese sexo [f:m]: ");
						__fpurge(stdin);
						scanf("%c", &sexo);
					}
					pets[index].sex = sexo;

				}else{
					printf("Input Pet's ID first [2]");
				}
				break;
			case 5:
				if(flag == 1){
					strcpy(pets[index].type, type);
					validateN = validateNumber("Input age: ", number, 10);
					pets[index].age = validateN;

				}else{
					printf("Input Pet's ID first [2]");
				}
				break;
			case 6:
				if(flag == 1){
					printf("Input weight: ");
					__fpurge(stdin);
					scanf("%f", &weight);
					pets[index].weight = weight;

				}else{
					printf("Input Pet's ID first [2]");
				}
				break;
			case 7:
				if(flag == 1){
					getString("Input Pet's race: ", race);
					strcpy(pets[index].race, race);

				}else{
					printf("Input Pet's ID first [2]");
				}
				break;
			case 8:
				getString("Input Pet's type [gato:perro:raro]: ", type);
				validType = validateType(type);
				while(validType !=0){
					getString("Error, input Pet's type [gato:perro:raro]: ", type);
					validType = validateType(type);
				}
				break;

			case 9:
				printf("Back to MAIN MENU");
				break;
			default:
				printf("Wrong, try again");
		}// fin swtich
		printf("\nPress any key to continue");
		__fpurge(stdin); 
		getchar();
		system("clear");
	}while(opt !=9); // fin while
}

int validateType(char validar[]){

	int valido = 0;
	int len;
	len = strlen(validar);

	for(int x = 0; x < len; x++){
		validar[x] = tolower(validar[x]);
	}

	if(strcmp(validar, "gato") != 0 && strcmp(validar, "perro")!= 0 && strcmp(validar, "raro")!= 0){
		valido = -1;
	}

	return valido;
}
