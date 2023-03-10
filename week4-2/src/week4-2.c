/*
 ============================================================================
 Name        : week4-2.c
 Author      : Arkadii Lantukh
 Version     : 1.0
 Copyright   : I don't care
 Description : 4th week of C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct account{
	int number;
	char name[20];
	float balance;
};

void setAccount(int* number, char* name, float* balance){
	printf("Enter the account number: ");
	scanf("%d", number);
	printf("Enter the name of the account: ");
	char temp;
	scanf("%c",&temp); // temp statement to clear buffer
	scanf("%[^\n]", name);
	printf("Enter the balance in the account: ");
	scanf("%f", balance);
};

void getAccount(int* number, char* name, float* balance){
	printf("\n");
	printf("Account information:\n  number: %d\n  name: %s\n  balance: $%.2f \n", *number, name, *balance);
};

int main(void) {

//	struct account def = {0,"",1};
//	struct account *acc = NULL;
//	acc = &def;
	struct account *acc = malloc(sizeof(struct account));
	setAccount(&acc->number , *&acc->name, &acc->balance);
	getAccount(&acc->number , acc->name, &acc->balance);
	free(acc);
	while(1){};
	return EXIT_SUCCESS;
}
