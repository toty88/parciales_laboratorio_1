#include<string.h>
#include<stdio_ext.h>
#include<stdio.h>
#include<ctype.h>
#include"pet.h"

void initPet(aPet pets[], int len){

	for(int x = 0; x < len; x++){
		pets[x].isEmpty = LIBRE;
	}
}

void hardCodePets(aPet pets[], int len){

	int age[11] = {12, 2, 10, 1, 8, 3, 8, 10, 1, 11, 12};
	char name[11][30] = {"FIRULAIS", "ATHOS", "ZEUS", "ERGO", "ATHILA", "PEPITO", 
		"ROCKET", "CEREBRO", "SONRISAS", "HUMOROSO", "GRUTI"};

	char race[11][30] = {"SIAMES", "SIAMES", "OVEJERO", "OVEJERO", "PERSA", 
		"PITBULL", "IGUANA DE SOL", "LABRADOR", "CALLEJERO", "CALLEJERO", "BULLDOG"};

	char type[11][30] = {"GATO", "GATO", "PERRO", "PERRO", "GATO", "PERRO", 
		"RARO", "PERRO", "GATO", "GATO", "PERRO"};

	float weight[11]= {2.5, 7.4, 3.2, 1.8, 9.8, 8.7, 1.2, 4.3, 11.2, 6.3, 9.3};
	char sex[11]= {'m', 'm', 'f', 'm', 'f','m', 'm', 'f', 'm', 'f', 'm'};
	int idClient[11] = {100,100,101,101,101,102,102,103,104,104,104};
	int idPet[11] = {200,201,202,203,204,205,206,207,208,209,210};
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

int deletePet(aPet pets[], int len){

	char number[10];
	int validateN;
	int index;
	int output = -1;
	printPets(pets, len);
	char opt;
	validateN = validateNumber("Input Pet ID: ", number, 10);
	index = getPetById(pets, len, validateN);
	while(index == -1){
		validateN = validateNumber("Wrong ID, try again: ", number, 10);
		index = getPetById(pets, len, validateN);
	}
	printf("You're about to remove %s. Are you sure [y:n] ", pets[index].name);
	__fpurge(stdin);
	scanf("%c", &opt);
	while(opt !='y' && opt !='n'){
		printf("Wrong, Are you sure [y:n] ");
		__fpurge(stdin);
		scanf("%c", &opt);
	}
	if(opt == 'y'){
		pets[index].isEmpty = LIBRE;
		output = 0;
		printf("Pet deleted");
	}else{
		printf("No pet deleted");
	}
	return output;
}

int modifyPet(aPet pets[], int len){

	char number[10];
	int opt1, opt2;
	int validateN;
	char name[30];
	char race[20];
	char type[30];
	float weight;
	char sex;
	int index;
	int output = -1;
	int validType;
	int menu = 0;
	char sp = ' ';
	do{
		if(menu == 0){
			do{
				opt1 = modifyPetMenu(menu);

				switch(opt1){
					
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
						menu = 1;
						break;
					case 3:
						printf("Back to Main Menu");
						break;
					default:
						printf("Wrong, try again");
				}
               			 printf("\nPress any key to continue");
               			 __fpurge(stdin);
               			 getchar();
               			 system("clear");
			}while(opt1 !=3 && opt1 !=2);
		
		}else{
			do{
        			printf("#########################################################################################\n");
               			printf("################################### PET SUBMENU #########################################\n");
        			printf("#########################################################################################\n");
        			printf("# ID_P%2cID_C%12cNAME%9cTYPE%13cBREED%8cWEIGHT%5cSEX%5cAGE\n", sp, sp, sp, sp, sp, sp, sp);
        			printf("#########################################################################################\n");
				printOnePet(pets[index]);
        			printf("#########################################################################################\n");
				opt2 = modifyPetMenu(menu);
				switch(opt2){

				        case 1:
				        	 getString("Input New Pet's name: ", name);
				        	 strcpy(pets[index].name, name);
						 output = 0;
				        	 break;
				        case 2: 
				        	 sex = getSex("Input new sex [f:m]: ");
				        	 pets[index].sex = sex;
						 output = 0;
				        	 break;
				        case 3: 
				        	 validateN = validateNumber("Input age: ", number, 10);
				        	 pets[index].age = validateN;
						 output = 0;
				        	 break;
				        case 4: 
				        	 printf("Input weight: ");
				        	 __fpurge(stdin);
				        	 scanf("%f", &weight);
				        	 printf("Input Pet's ID first [2]");
						 output = 0;
				        	 break;
				        case 5: 
				        	 getString("Input Pet's breed: ", race);
				        	 strcpy(pets[index].race, race);
						 output = 0;
				        	 break;
				        case 6: 
				        	 getString("Input Pet's type [gato:perro:raro]: ", type);
				        	 validType = validateType(type);
				        	 while(validType !=0){
				        	 	getString("Error, input Pet's type [gato:perro:raro]: ", type);
				        	 	validType = validateType(type);
				        	 }
				        	 strcpy(pets[index].type, type);
						 output = 0;
				        	 break;

				        case 7: 
				        	 printf("Back to MAIN MENU");
						 menu = 0;
				        	 break;
				        default :
				       	 printf("Wrong, try again");
				}// fin swtich
				printf("\nPress any key to continue");
				__fpurge(stdin); 
				getchar();
				system("clear");
			}while(opt2 !=7);
		} // FIN ELSE
	}while(opt1 !=3); // fin while
	return output;
}

int validateType(char validar[]){

	int valido = 0;

	if(strcmp(validar, "GATO") != 0 && strcmp(validar, "PERRO")!= 0 && strcmp(validar, "RARO")!= 0){
		valido = -1;
	}

	return valido;
}

void printPets(aPet pets[], int lenP){
	char sp = ' ';
        printf("\n#########################################################################################\n"
               "###################################### PETS LIST ########################################\n"
               "#########################################################################################\n");
        printf("# ID_P%2cID_C%12cNAME%9cTYPE%13cBREED%8cWEIGHT%5cSEX%5cAGE\n", sp, sp, sp, sp, sp, sp, sp);
        printf("#########################################################################################\n\n");

	for(int x = 0; x < lenP; x++){
		if(pets[x].isEmpty == OCU){
			printf("%6d%6d%16s%13s%18s%12.2fkg%8c%8d\n", 
					pets[x].idPet, pets[x].idClient, pets[x].name, pets[x].type,
					pets[x].race,pets[x].sex,pets[x].weight, pets[x].age);
		}
	}
}

void printOnePet(aPet pets){

	printf("%6d%6d%16s%13s%18s%12.2fkg%8c%8d\n", pets.idPet, pets.idClient, pets.name, pets.type,
						pets.race,pets.sex,pets.weight, pets.age);
}

void printPetByChosenType(aPet pets[], int lenP){
	
	int validType;
	char type[30];
	char sp = ' ';
	int n = 1;

	getString("Input Pet's type [gato:perro:raro]: ", type);
	validType = validateType(type);
	while(validType !=0){
		getString("Error, input Pet's type [gato:perro:raro]: ", type);
		validType = validateType(type);
	}

        printf("\n############################################################################################\n");
        printf("# %3cID_P%2cID_C%12cNAME%9cTYPE%13cBREED%8cWEIGHT%5cSEX%5cAGE\n", sp, sp, sp, sp, sp, sp, sp, sp);
        printf("############################################################################################\n");
	for(int x = 0; x < lenP; x++){
		if(strcmp(pets[x].type, type) == 0 && pets[x].isEmpty == OCU){
			printf("%d) ", n);
			printOnePet(pets[x]);
			n++;
		}
	}
}

float promedioEdadMascota(aPet pets[], int lenP){
	int count = 0;
	int sum = 0;
	float resu;

	for(int x = 0; x < lenP; x++){
		if(pets[x].isEmpty == OCU){
			sum +=pets[x].age;
			count++;
		}
	}

	resu = (float)sum/count;
	return resu;
}

void promedioEdadMascotasPorTipo(aPet pets[], int lenP){

	int count = 0;
	int sum = 0;
	float resu;
	char type[30];
	int validType;
	getString("What type Do wish you to get average age of [perro:gato:raro]: ", type);
	validType = validateType(type);
	while(validType !=0){
		getString("Error, only types [gato:perro:raro]: ", type);
		validType = validateType(type);
	}
	for(int x = 0; x < lenP; x++){
		if(pets[x].isEmpty == OCU && strcmp(pets[x].type, type) == 0){
			sum +=pets[x].age;
			count++;
		}
	}
	resu = (float)sum/count;
	printf("Average Age of type %s -> %.2f",type, resu);
}

