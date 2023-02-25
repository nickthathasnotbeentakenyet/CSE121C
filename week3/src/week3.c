/*
 ============================================================================
 Name        : week3.c
 Author      : Arkadii Lantukh
 Version     : 1.0
 Copyright   : I don't care
 Description : 3rd week of C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// looping until user decides to exit
	while(1){
		char isExit[5]="";

	//	TASK 1 --------------------------
	char str[20];
	printf("Enter a string: ");
	scanf("%s", str);
	int length = strlen(str);
	for (int _= 0; _ < length; _++){
		printf("%x\n", str[_]);
	}

	// TASK 2 ---------------------------
	void display_binary(unsigned int num){
		printf("Number %d in binary is: ", num);
		for(int _ = 31; _ >= 0; _--){
			if (num & (1 << _)){
				printf("1");
			}
			else{
				printf("0");
			}
		}
		printf("\n");
	}
	while(1){
		printf("Enter a number between 0 and 4294967295 [enter -1 to exit]: ");
		unsigned int num;
		scanf("%u", &num);
		if (num == -1) {break;}
		display_binary(num);
		printf("\n");
	}

	// TASK 3 ---------------------------
	int first, second, result;
	printf("First operand: ");
	scanf("%d", &first);
	printf("Second operand: ");
	scanf("%d", &second);
	// bitwise &
	result = first & second;
	printf("Result of %d & %d is: %d\n", first, second, result);
	display_binary(result);
	// bitwise ^
	result = first ^ second;
	printf("Result of %d ^ %d is: %d\n", first, second, result);
	display_binary(result);
	// bitwise |
	result = first | second;
	printf("Result of %d | %d is: %d\n", first, second, result);
	display_binary(result);
	// bitwise ~
	result = ~first;
	printf("Result of ~ %d is: %d\n", first, result);
	display_binary(result);
	// bitwise <<
	result = first << second;
	printf("Result of %d << %d is: %d\n", first, second, result);
	display_binary(result);
	// bitwise >>
	result = first >> second;
	printf("Result of %d >> %d is: %d\n", first, second, result);
	display_binary(result);

	// exit ?
	printf("================================================\n");
	printf("start over? [y/n]: ");
	scanf("%s", isExit);
	if (isExit[0] != 'y'){break; exit(0);}
	}
	return EXIT_SUCCESS;
}
