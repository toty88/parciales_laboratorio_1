#include"menu.h"

int mainMenu(){

	int unsigned opt;
	printf("\n######################################################\n"
		"#################### ABM VET STORE ###################\n"
		"######################################################\n"
		"(1).  SHOW CLIENTS WITH PETS\n"
		"(2).  SHOW ONLY CLIENTS\n"
		"(3).  SHOW ONLY PETS\n"
		"(4).  ADD PET\n"
		"(5).  REMOVE PET\n"
		"(6).  MODIFY PET\n"
		"(7).  ADD CLIENT\n"
		"(8).  REMOVE CLIENT WITH PETS\n"
		"(9).  SORT PETS BY TYPE AND SHOW THEM WITH CLIENTS\n"
		"(10). MODIFY CLIENT\n"
		"(11). SHOW CLIENTS WITH MORE THAN 1 PET\n"
		"(12). SHOW PETS OLDER THAN 3\n"
		"(13). SHOW PETS BY CHOSEN TYPE\n"
		"(14). SORT CLIENTS BY PET AMOUNT\n"
		"(15). SORT CLIENTS BY PET AMOUNT AND NAME\n"
		"(16). SHOW AVERAGE PET AGE\n"
		"(17). SHOW AVERAGE PET AGE BY TYPE\n"
		"(18). SHOW AVERAGE AGE AMONG MALE AND FEMALE CLIENTS\n"
		"(19). EXIT \n"
		"(#).  -----> CHOICE: ");
		
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

int modifyClientMenu(int choice){

	int unsigned opt;
	if(choice == 0){

		printf("\n######################################################\n"
			"################ MODIFY CLIENTS SUBMENU ###############\n"
			"######################################################\n"
			"(1). SHOW CLIENT LIST\n"
			"(2). INPUT CLIENT'S ID TO BE MODIFIED\n"
			"(3). EXIT TO MAIN MENU ");
	}else{
		printf("(1). MODIFY NAME\n"
			"(2). MODIFY LAST NAME\n"
			"(3). MODIFY LOCALIDAD\n"
			"(4). MODIFY PHONE NUMBER\n"
			"(5). MODIFY SEX\n"
			"(6). MODIFY AGE\n"
			"(7). EXIT ");
	}
		
	scanf("%d", &opt); 
	return opt;
}
