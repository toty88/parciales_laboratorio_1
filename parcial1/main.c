#include<stdlib.h>
#include<stdio.h>
#include<stdio_ext.h>
#include"menu.h"
#include"client_pet.h"

int main(){

	aClient clients[TAM_C];
	aPet pets[TAM_M];
	initClient(clients, TAM_C);
	initPet(pets, TAM_M);
	hardCode(clients, TAM_C);
	hardCodePets(pets, TAM_M);
	int resu;
	int opt;
	int clientCounter = 104;
	int petCounter = 211;

	do{
		opt = mainMenu();

		switch(opt){

			case 1:
				printClientAndPet(clients, TAM_C, pets, TAM_M);
				break;
			case 2:
				printClient(clients, TAM_C);
				break;
			case 3:
				printPets(pets, TAM_M);
				break;
			case 4:
				resu = createPet(pets, TAM_M, clients, TAM_C, petCounter);
				if(resu == 0){
					printf("Pet created");
					petCounter++;
				}else{
					printf("No more slots");
				}
				break;
			case 5:
				deletePet(pets, TAM_M);
				break;
			case 6:
				modifyPet(pets, TAM_M);
				break;
			case 7:
				resu = createClient(clients, TAM_C, clientCounter);
				if(resu == 0){
					printf("Client created");
					clientCounter++;
				}else{
					printf("No more slots");
				}
				break;
			case 8:
				break;
			case 9:
				printf("BYE");
				break;
			default:
				printf("Wroing, try again");
		}
		if(opt != 6){
			printf("\nPress any key to continue");
			__fpurge(stdin); 
			getchar();
			system("clear");
		}
	}while(opt != 9);
	return 0;
}


