#include<stdio.h>
#include<string.h>
#include"client.h"

void hardCodeClient(aClient clients[], int len){

	int age[5] = {64, 72, 15, 12, 65};
	char name[5][30] = {"MARIA", "PABLO", "PAOLA", "GERMAN", "HERNESTO"};
	char last_name[5][30] = {"GONZALEZ", "LORENZO", "HERNANDEZ", "GRECCO", "UZZO"};
	char locale[5][30] = {"ALDO BONZI", "CASANOVA", "TAPIALES", "CABA", "BERAZATEGUI"};
	char phone[5][20] = {"4442-4457", "4444-5667", "1234-6754", "9999-8888", "1235-8762"};
	char sex[5]= {'f', 'm', 'f', 'm', 'm'};
	int idClient[5] = {100, 101, 102, 103, 104};
	int petCounter[5] ={2, 3, 2, 1, 3};
	int isEmpty[5] = {OCU, OCU, OCU, OCU, OCU};
	
	for(int x = 0; x < 5; x++){
		strcpy(clients[x].name, name[x]);
		strcpy(clients[x].last_name, last_name[x]);
		strcpy(clients[x].locale, locale[x]);
		strcpy(clients[x].phone, phone[x]);
		clients[x].sex = sex[x];
		clients[x].age = age[x];
		clients[x].isEmpty = isEmpty[x];
		clients[x].petCounter = petCounter[x];
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
        printf("\n##################################################################################\n"
               "################################### CLIENT LIST ##################################\n"
               "##################################################################################\n");
        printf("# %4cID%7cFNAME%9cLNAME%10cLOCALE%6cTELEPHONE%5cSEX%5cAGE\n", sp, sp, sp, sp, sp, sp, sp);
        printf("##################################################################################\n\n");
	for(int x = 0; x < lenC; x++){
		if(clients[x].isEmpty == OCU){
			printf("%d)%6d%12s%14s%16s%15s%8c%8d\n", x+1, clients[x].idClient, clients[x].name, clients[x].last_name, 
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
	char age[5];
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
		 validNumber = validateNumber("Input client's age between 8 and 99: ", age, 5);
		 while(validNumber < 8 || validNumber > 99){
		 	validNumber = validateNumber("Error, onlye age between 8 and 99: ", age, 5);
		 }
		 clients[index].age = validNumber;
		 clients[index].idClient = getId(count, 1);
		 clients[index].isEmpty = OCU;
		 clients[index].sex = sex;
       		 output = 0;
	}
        return output;
}

void printOneClient(aClient client){

	printf("%6d%12s%14s%16s%15s%8c%8d\n", client.idClient, client.name, client.last_name, client.locale,
	     						client.phone, client.sex, client.age);
}

int modifyClient(aClient clients[], int len){

	char number[10];
	int opt1, opt2;
	int validateN;
	char name[30];
	char lastName[30];
	char locale[30];
	char phone[20];
	char age[5];
	char sex;
	int index;
	int menu = 0;
	int output = -1;
	do{
		if(menu == 0){
			do{
				opt1 = modifyClientMenu(menu);

				switch(opt1){
					
					case 1:
						printClient(clients, len);
						break;
		
					case 2:
						validateN = validateNumber("Input Client ID to be modified: ", number, 10);
						index = findClientById(clients, len, validateN);
						while(index == -1){
							validateN = validateNumber("Wrong ID, try again: ", number, 10);
							index = findClientById(clients, len, validateN);
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
        			printf("###############################################################################\n");
               			printf("################################# CLIENT SUBMENU ##############################\n");
				printOneClient(clients[index]);
				opt2 = modifyClientMenu(menu);
				switch(opt2){

				        case 1:
				        	 getString("Input New Client's name: ", name);
				        	 strcpy(clients[index].name, name);
						 output = 0;
				        	 break;
				        case 2: 
				        	 getString("Input New Client's last name: ", lastName);
				        	 strcpy(clients[index].last_name, lastName);
						 output = 0;
				        	 break;
				        case 3: 
				        	 getString("Input New Client's locale: ", locale);
				        	 strcpy(clients[index].locale, locale);
						 output = 0;
				        	 break;
				        case 4: 
				        	 getString("Input New Client's phone number: ", phone);
				        	 strcpy(clients[index].phone, phone);
						 output = 0;
				        	 break;
				        case 5: 
				        	 sex = getSex("Input new Client's sex [f:m]: ");
				        	 clients[index].sex = sex;
						 output = 0;
				        	 break;
				        case 6: 
		 				 validateN = validateNumber("Input new Client's age between 8 and 99: ", age, 5);
						 while(validateN < 8 || validateN > 99){
						 	validateN = validateNumber("Error, onlye age between 8 and 99: ", age, 5);
						 }
						 clients[index].age = validateN;
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

void averageAgeAmongClients(aClient clients[], int lenC){

	int countM = 0;
	int sumM = 0;
	int countF = 0;
	int sumF = 0;

	float resuM;
	float resuF;

	for(int x = 0; x < lenC; x++){
		if(clients[x].isEmpty == OCU){
			if(clients[x].sex == 'm'){
				countM++;
				sumM +=clients[x].age;
			}else{
				countF++;
				sumF+=clients[x].age;
			}
		}
	}
	resuM = (float)sumM/countM;
	resuF = (float)sumF/countF;

	if(countF == 0){
		printf("\nThere are no females");
	}else{
		printf("\nAverage Age among female clients -> %.2f", resuF);
	}

	if(countM == 0){
		printf("\nThere are no males");
	}else{
		printf("\nAverage Age among male clients -> %.2f", resuM);
	}
}

void averageMenAndWomen(aClient clients[], int lenC){

	int countM = 0;
	int countF = 0;
	int totalMyF;
	float averageM;
	float averageF;
	char por = '%';

	float resuM;
	float resuF;

	for(int x = 0; x < lenC; x++){
		if(clients[x].isEmpty == OCU){
			if(clients[x].sex == 'm'){
				countM++;
			}else{
				countF++;
			}
		}
	}

	totalMyF = countM + countF;
	averageM = (countM*100)/totalMyF;
	averageF = (countF*100)/totalMyF;

	printf("Average man among clients -> %.0f%c", averageM, por);
	printf("\nAverage female among clients -> %.0f%c",  averageF, por);

}
