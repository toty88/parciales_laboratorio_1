#include"menu.h"

int mainMenu(){

	int unsigned opt;
	printf("\n######################################################\n"
		"################## ABM VETERINARIA ###################\n"
		"######################################################\n"
		"(1). MOSTRAR CLIENTES Y MASCOTAS\n"
		"(2). MOSTRAR SOLO CLIENTES\n"
		"(3). MOSTRAR SOLO MASCOTAS\n"
		"(4). ALTA MASCOTA\n"
		"(5). BAJA MASCOTA\n"
		"(6). MODIFICAR MASCOTA\n"
		"(7). ALTA CLIENTE\n"
		"(9). EXIT ");
		
	scanf("%d", &opt); 
	return opt;
}

int modifyPetMenu(){

	int unsigned opt;
	printf("\n######################################################\n"
		"############ SUBMENU MODIFICAR MASCOTA ###############\n"
		"######################################################\n"
		"(1). MOSTRAR LISTA MASCOTAS\n"
		"(2). INGRESE ID MASCOTA A MODIFICAR\n"
		"(3). MODIFICAR NOMBRE\n"
		"(4). MODIFICAR SEXO\n"
		"(5). MODIFICAR EDAD\n"
		"(6). MODIFICAR PESO\n"
		"(7). MODIFICAR RAZA\n"
		"(8). MODIFICAR TIPO\n"
		"(9). EXIT ");
		
	scanf("%d", &opt); 
	return opt;
}
