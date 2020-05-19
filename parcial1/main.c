#include<stdlib.h>
#include<stdio.h>
#include<stdio_ext.h>
#include"menu.h"
#include"pet_client.h"

int main(){

	aClient clients[TAM_C];
	aPet pets[TAM_M];
	aTypeOfBreed breeds[TAM_B] = {{1, "PASTOR", "ALEMAN"}, {2, "LABRADOS", "INGLES"},{3, "PITBULL", "INGLES"}, 
					{4, "GATO", "PERSA"}, {5, "GATO", "SIAMES"}, 
					{6, "LAGARTO", "OVERO"}, {7, "IGUANA", "AUSTRALIA"},
					{8, "BULLDOG", "INGLES"}};
	initClient(clients, TAM_C);
	initPet(pets, TAM_M);

	hardCodeClient(clients, TAM_C);
	hardCodePets(pets, TAM_M);

	int resu;
	int opt;
//	int clientCounter = 0;
//	int petCounter = 0;
	int clientCounter = 5;
	int petCounter = 11;

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
					printPetsAndBreeds(pets, TAM_M, breeds, TAM_B);
				}
				break;
			case 4:
				resu = createPet(pets, TAM_M, clients, TAM_C, petCounter, breeds, TAM_B);
				if(resu == 0){
					printf("Pet created");
					petCounter++;
				}else{
					printf("No more slots");
				}
				break;
			case 5:
				resu = deletePet(pets, TAM_M, clients, TAM_C);
				if(resu == 0){
					petCounter--;
				}
				break;
			case 6:
				if(petCounter < 1){
					printf("You need to add a pet first [4].");
				}else{
					resu = modifyPet(pets, TAM_M);
					if (resu == 0){
						printf("Pet modified");
					}else{
						printf("No modification made");
					}
				}
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
				sortPetByType(clients, pets, TAM_C, TAM_M);
				break;
			case 10:
				if(clientCounter < 1){
					printf("You need to add a client first [7].");
				}else{
					resu = modifyClient(clients, TAM_C);
					if (resu == 0){
						printf("Client modified");
					}else{
						printf("No modification made");
					}
				}
				break;

			case 11:
				printClientsWithMoreThanOnePet(clients, TAM_C, pets, TAM_M);
				break;
			case 12:
				printPetsOlderThanThree(pets, TAM_M, clients, TAM_C);
				break;
			case 13:
				printPetByChosenType(pets, TAM_M);
				break;
			case 14:
				sortClientsByPetCount(clients, TAM_C, pets, TAM_M);
				printClientAndPet(clients, TAM_C, pets, TAM_M);
				break;
			case 15:
				sortClientByPetCountAndName(clients, TAM_C, pets, TAM_M);
				printClientAndPet(clients, TAM_C, pets, TAM_M);
				break;
			case 16:

				printf("Average Age -> %.2f", averagePetAge(pets, TAM_M));
				break;
			case 17:
				averagePetAgeByType(pets, TAM_M);
				break;
			case 18:
			//	averageAgeAmongClients(clients, TAM_C);
				printf("\n");
				averageWomen(clients, TAM_C);
				break;
			case 19:
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
	}while(opt != 19);
	return 0;
}


