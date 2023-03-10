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
	printf("Account id: ");
	scanf("%d", &new_node->number);
	printf("Account name: ");
	char temp;
	scanf("%c",&temp);
	scanf("%[^\n]", new_node->name);
	printf("Account balance: ");
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
	printf("\
===============\n\
==== MENU: ====\n\
---------------\n\
  1. ADD\n\
  2. DISPLAY\n\
  3. FIND\n\
  4. UPDATE\n\
  5. DELETE\n\
  0. QUIT\n\
===============\n\
");
}

Account* root = NULL;
Account* find_account(Account** root, int id){
	for(Account* curr = *root; curr != NULL; curr = curr->next){
		if (curr->number == id){
			return curr;
		}
	}
	return NULL;
}

Account* update_account(Account** root, int update_id){
	for(Account* curr = *root; curr != NULL; curr = curr->next){
		if (curr->number == update_id){
			printf("UPDATE INFORMATION:\n");
			printf("New account id: ");
			scanf("%d", &curr->number);
			printf("New account name: ");
			char temp;
			scanf("%c",&temp);
			scanf("%[^\n]", curr->name);
			printf("New account balance: ");
			scanf("%f", &curr->balance);
			printf("[success] account updated\n");
		}
	}
	return 0;
}

void remove_account(Account** root, int delete_id){
	if(*root == NULL){
		return;
	}
	if((*root)->number == delete_id){
		Account* to_delete = *root;
		*root = (*root)->next;
		free(to_delete);
		printf("[success] account deleted\n");
		return;
	}
	for(Account* curr = *root; curr->next != NULL; curr = curr->next){
		if (curr->next->number == delete_id){
			Account* to_delete = curr->next;
			curr->next = curr->next->next;
			free(to_delete);
			printf("[success] account deleted\n");
			return;
		}
	}
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
				printf("[info] ID: %d | NAME: %s | BALANCE: $%.2f\n", curr->number, curr->name, curr->balance);
			}
			break;
		case 3:
			printf("Enter account ID: ");
			int id;
			scanf("%d", &id);
			Account* found = find_account(&root, id);
			if(found != NULL){
				printf("[match] ID: %d | NAME: %s | BALANCE: $%.2f\n", found->number, found->name, found->balance);
			}
			else printf("[info] no match found\n");
			break;
		case 4:
			printf("Enter account ID: ");
			scanf("%d", &id);
			Account* to_update = find_account(&root, id);
			if(to_update != NULL){
				update_account(&root, id);
			}
			else printf("[info] no match found\n");
			break;
		case 5:
			printf("Enter account ID: ");
			scanf("%d", &id);
			Account* to_delete = find_account(&root, id);
			if(to_delete != NULL){
				remove_account(&root, id);
			}
			else printf("[info] no match found\n");
			break;
		case 0: break;
		default: printf("[error] invalid menu entry\n");break;
		}
	}

	free(root);

	while(1){};
	return EXIT_SUCCESS;
}
