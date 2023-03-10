/*
 ============================================================================
 Name        : week5.c
 Author      : Arkadii Lantukh
 Version     : 1.0
 Copyright   : I don't care
 Description : 5th week of C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Account{
	int number;
	char name[20];
	float balance;
	struct Account * next;
} Account;

void add_account(Account** root){
	Account* new_node = malloc(sizeof(Account));
	if(new_node == NULL){
		exit(1);
	}
	printf("Enter the account number: ");
	scanf("%d", &new_node->number);
	printf("Enter the name of the account: ");
	scanf("%s", new_node->name);
	printf("Enter the balance in the account: ");
	scanf("%f", &new_node->balance);
	new_node->next = NULL;

	if(*root == NULL){
		*root = new_node;
		return;
	}

	Account* curr = *root;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = new_node;
}

void print_menu(){
	printf("Menu:\n1. Add account\n2. Display all accounts\n0. Quit\n");
}

int main(int argc, char* argv[])
	{
	Account* root = NULL;
	int quit = -1;
	while(quit != 0){
		print_menu();
		printf("Enter >: ");
		scanf("%d", &quit);
		switch (quit){
		case 1: add_account(&root); break;
		case 2:
			for(Account* curr = root; curr != NULL; curr = curr->next){
				printf("Account information: \n");
				printf("number: %d\n", curr->number);
				printf("name: %s\n", curr->name);
				printf("balance: $%.2f \n", curr->balance);
			}
			break;
		case 0: break;
		default: printf("[error]\n");
		}
	}

	free(root);

	while(1){};
	return EXIT_SUCCESS;
}
