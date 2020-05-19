#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gets.h"

void getString(char msg[], char name[]){

	int len;
	printf("%s", msg);
	__fpurge(stdin);
	fgets(name, 31, stdin);
	len = strlen(name);
	name[len-1] = '\0';
	len = strlen(name);
	for(int x = 0; x < len; x++){
		name[x] = toupper(name[x]);
	}
}


int getId(int counter, int opt){

        int id;
        if(opt == 1){
		id = 100 + counter;
	}else{
		id = 200 + counter;
	}
        return id;
}

int validateNumber(char msg[], char text[], int size){

	int num1, resultado, len;
	do{
		
		resultado = 0;
		printf("%s", msg);
		__fpurge(stdin);
		fgets(text, size, stdin);
		len = strlen(text);
		text[len-1] = '\0';
		
		for(int x =0; x < len -1; x++){
			num1 = (int)text[x];
			if(num1 < 48 || num1 > 57){
			
			   	 printf("\nError, No zero, letters or symbols: ");
			   	 resultado = -1;
				 break;
			}
		}
	}while(resultado == -1);
	resultado = atoi(text);
	return resultado;
}

char getSex(char msg[]){
	char sex;

       	printf("%s", msg);
       	__fpurge(stdin);
       	scanf("%c", &sex);
       	while(sex != 'f' && sex != 'm'){
       	     printf("Error, only [f:m]: ");
       	     __fpurge(stdin);
       	     scanf("%c", &sex);
       	}
	return sex;
}
