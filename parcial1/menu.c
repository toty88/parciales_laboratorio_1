#include"menu.h"

int mainMenu(){

	int unsigned opt;
	printf("\n######################################################\n"
		"#################### ABM VET STORE ###################\n"
		"######################################################\n"
		"(1). SHOW CLIENTS WITH PETS\n"
		"(2). SHOW ONLY CLIENTS\n"
		"(3). SHOW ONLY PETS\n"
		"(4). ADD PET\n"
		"(5). REMOVE PET\n"
		"(6). MODIFY PET\n"
		"(7). ADD CLIENT\n"
		"(8). REMOVE CLIENT WITH PETS\n"
		"(9). EXIT ");
		
	scanf("%d", &opt); 
	return opt;
}

int modifyPetMenu(int choice){

	int unsigned opt;
	if(choice == 0){

		printf("\n######################################################\n"
			"################ MODIFY PETS SUBMENU #################\n"
			"######################################################\n"
			"(1). SHOW PET LIST\n"
			"(2). INPUT PET'S ID T BE MODIFIED\n"
			"(3). EXTI TO MAIN MENU ");
	}else{
		printf("(1). MODIFY NAME\n"
			"(2). MODIFY SEX\n"
			"(3). MODIFY AGE\n"
			"(4). MODIFY WEIGHT\n"
			"(5). MODIFY BREED\n"
			"(6). MODIFY TYPE\n"
			"(7). EXIT ");
	}
		
	scanf("%d", &opt); 
	return opt;
}
