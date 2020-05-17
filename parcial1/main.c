#include<stdlib.h>
#include<stdio.h>
#include<stdio_ext.h>
#include"menu.h"
#include"pet_client.h"

int main(){

	aClient clients[TAM_C];
	aPet pets[TAM_M];
	initClient(clients, TAM_C);
	initPet(pets, TAM_M);
	hardCode(clients, TAM_C);
	hardCodePets(pets, TAM_M);
	int resu;
	int opt;
//	int clientCounter = 0;
//	int petCounter = 0;
	int clientCounter = 104;
	int petCounter = 211;

	do{
		opt = mainMenu();

		switch(opt){

			case 1:
				if(clientCounter < 1 || petCounter < 1){
					printf("You need to add either a client [7] or a pet [4].");
				}else{
					printClientAndPet(clients, TAM_C, pets, TAM_M);
				}
				break;
			case 2:
				if(clientCounter < 1){
					printf("You need to add a client first [7].");
				}else{
					printClient(clients, TAM_C);
				}
				break;
			case 3:
				if(petCounter < 1){
					printf("You need to add a pet first [4].");
				}else{
					printPets(pets, TAM_M);
				}
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
				resu = deletePet(pets, TAM_M);
				if(resu == 0){
					petCounter--;
				}
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
				deleteAllFromClient(clients, TAM_C, pets, TAM_M); 
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


