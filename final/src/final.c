/*
 ============================================================================
 Name        : final.c
 Author      : Arkadii Lantukh
 Version     : 1.0
 Copyright   : I don't care
 Description : Final project using the C language, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu(){
	printf("MENU:\n");
	printf("[1]. New\n");
	printf("[2]. Display all\n");
	printf("[3]. Display department\n");
	printf("[4]. Find\n");
	printf("[5]. Update\n");
	printf("[6]. Delete\n");
	printf("[7]. Sort\n");
	printf("[0]. Exit\n\n");
}

void clear_terminal() {
#if defined(_WIN32)
	system("cls");
#else
	system("clear");
#endif
}

typedef struct Employee{
	int id;
	char fullname[50];
	char department[50];
	char position[30];
	int y_hired;
	char m_hired[10];
	float salary;
	struct Employee * next;
} Employee;

void add_employee(Employee** root){
	Employee* new_emp = malloc(sizeof(Employee));
	if(new_emp == NULL){
		exit(1);
	}
	printf("ID[ex.101]: ");
	scanf("%d", &new_emp->id);
	printf("FULL NAME[ex.John Doe]: ");
	char temp;
	scanf("%c",&temp);
	scanf("%[^\n]", new_emp->fullname);
	printf("DEPARTMENT[ex.IT]: ");
	scanf("%c",&temp);
	scanf("%[^\n]", new_emp->department);
	printf("POSITION[ex.Developer]: ");
	scanf("%c",&temp);
	scanf("%[^\n]", new_emp->position);
	printf("YEAR HIRED[ex.1999]: ");
	scanf("%d", &new_emp->y_hired);
	printf("MONTH HIRED[ex.July]: ");
	scanf("%c",&temp);
	scanf("%[^\n]", new_emp->m_hired);
	printf("SALARY[ex.2500.99]: ");
	scanf("%f", &new_emp->salary);
	new_emp->next = NULL;
	printf("[success] employee added\n");

	if(*root == NULL){
		*root = new_emp;
		return;
	}

	Employee* curr = *root;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = new_emp;
}


Employee* find_employee(Employee** root, int id){
	for(Employee* curr = *root; curr != NULL; curr = curr->next){
		if (curr->id == id){
			return curr;
		}
	}
	return NULL;
}

Employee* update_employee(Employee** root, int update_id){
	for(Employee* curr = *root; curr != NULL; curr = curr->next){
		if (curr->id == update_id){
			printf("ID[ex.101]: ");
			scanf("%d", &curr->id);
			printf("FULL NAME[ex.John Doe]: ");
			char temp;
			scanf("%c",&temp);
			scanf("%[^\n]", curr->fullname);
			printf("DEPARTMENT[ex.IT]: ");
			scanf("%c",&temp);
			scanf("%[^\n]", curr->department);
			printf("POSITION[ex.Developer]: ");
			scanf("%c",&temp);
			scanf("%[^\n]", curr->position);
			printf("YEAR HIRED[ex.1999]: ");
			scanf("%d", &curr->y_hired);
			printf("MONTH HIRED[ex.July]: ");
			scanf("%c",&temp);
			scanf("%[^\n]", curr->m_hired);
			printf("SALARY[ex.2500.99]: ");
			scanf("%f", &curr->salary);
			printf("[success] employee updated\n");
		}
	}
	return 0;
}

void remove_employee(Employee** root, int delete_id){
	if(*root == NULL){
		return;
	}
	if((*root)->id == delete_id){
		Employee* to_delete = *root;
		*root = (*root)->next;
		free(to_delete);
		printf("[success] employee deleted\n");
		return;
	}
	for(Employee* curr = *root; curr->next != NULL; curr = curr->next){
		if (curr->next->id == delete_id){
			Employee* to_delete = curr->next;
			curr->next = curr->next->next;
			free(to_delete);
			printf("[success] employee deleted\n");
			return;
		}
	}
}
void swap(struct Employee *a, struct Employee *b)
{
    int temp_id = a->id;
    char temp_name[50]; strcpy(temp_name, a->fullname);
    char temp_dep[50]; strcpy(temp_dep, a->department);
    char temp_pos[30]; strcpy(temp_pos, a->position);
    int temp_year = a->y_hired;
    char temp_month[10]; strcpy(temp_month, a->m_hired);
    float temp_salary = a->salary;

    a->id = b->id; b->id = temp_id;
    strcpy(a->fullname, b->fullname); strcpy(b->fullname, temp_name);
    strcpy(a->department, b->department); strcpy(b->department, temp_dep);
    strcpy(a->position, b->position); strcpy(b->position, temp_pos);
    a->y_hired = b->y_hired; b->y_hired = temp_year;
    strcpy(a->m_hired, b->m_hired); strcpy(b->m_hired, temp_month);
    a->salary = b->salary; b->salary = temp_salary;

}

void sort_employee(struct Employee **root)
{
    int swapped;
    struct Employee *ptr;
    struct Employee *tail = NULL;

    if (root == NULL)
        return;

    do
    {
        swapped = 0;
        ptr = *root;

        while (ptr->next != tail)
        {
            if (ptr->id > ptr->next->id)
            {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        tail = ptr;
    }
    while (swapped);
}

int main(void) {
	Employee* root = NULL;
	int menu_entry = -1;
	int id;
	while(menu_entry != 0){
		clear_terminal();
		printf("=====================================\n");
		printf("======== Employee Management ========\n");
		printf("=====================================\n\n");
		print_menu();
		printf(">: ");
		scanf("%d", &menu_entry);
		switch(menu_entry){
			case 1: // new
				system("cls");
				printf("+------------------------------------+\n");
				printf("|------------ NEW EMPLOYEE ----------|\n");
				printf("+------------------------------------+\n\n");
				add_employee(&root);
				system("pause");
				break;
			case 2: // display all
				system("cls");
				printf("+------------------------------------+\n");
				printf("|--------- DISPLAY EMPLOYEES --------|\n");
				printf("+------------------------------------+\n\n");
				printf("================================================================================================================\n");
				printf("| ID    | NAME                 | DEPARTMENT        | POSITION           | YEAR HIRED | MONTH HIRED | SALARY    |\n");
				printf("================================================================================================================\n");
				for(Employee* curr = root; curr != NULL; curr = curr->next){
					printf("| %-6d| %-21s| %-18s| %-19s| %-11d| %-12s| $%-8.2f |\n",
							curr->id,
							curr->fullname,
							curr->department,
							curr->position,
							curr->y_hired,
							curr->m_hired,
							curr->salary);
					printf("----------------------------------------------------------------------------------------------------------------\n");
				}
				system("pause");
				break;
			case 3: // display department
				system("cls");
				printf("+------------------------------------+\n");
				printf("|------ DISPLAY BY DEPARTMENTS ------|\n");
				printf("+------------------------------------+\n\n");
				printf("Enter DEPARTMENT: ");
				char dep[50];
				char temp;
				scanf("%c",&temp);
				scanf("%[^\n]", dep);
				printf("============================================================================================\n");
				printf("| ID    | NAME                 | POSITION           | YEAR HIRED | MONTH HIRED | SALARY    |\n");
				printf("============================================================================================\n");
				for(Employee* curr = root; curr != NULL; curr = curr->next){
					if(strcmp(curr->department, dep)==0){
						printf("| %-6d| %-21s| %-19s| %-11d| %-12s| $%-8.2f |\n",
								curr->id,
								curr->fullname,
								curr->position,
								curr->y_hired,
								curr->m_hired,
								curr->salary);
						printf("--------------------------------------------------------------------------------------------\n");
					}
				}
				system("pause");
				break;
			case 4: // find
				system("cls");
				printf("+------------------------------------+\n");
				printf("|----------- FIND EMPLOYEE ----------|\n");
				printf("+------------------------------------+\n\n");
				printf("Employee ID: ");
				scanf("%d", &id);
				Employee* found = find_employee(&root, id);
				if(found != NULL){
					printf("================================================================================================================\n");
					printf("| ID    | NAME                 | DEPARTMENT        | POSITION           | YEAR HIRED | MONTH HIRED | SALARY    |\n");
					printf("================================================================================================================\n");
					printf("| %-6d| %-21s| %-18s| %-19s| %-11d| %-12s| $%-8.2f |\n",
							found->id,
							found->fullname,
							found->department,
							found->position,
							found->y_hired,
							found->m_hired,
							found->salary);
					printf("--------------------------------------------------------------------------------------------\n");
				}
				else printf("[info] no match found\n");
				system("pause");
				break;
			case 5: // update
				system("cls");
				printf("+------------------------------------+\n");
				printf("|---------- UPDATE EMPLOYEE ---------|\n");
				printf("+------------------------------------+\n\n");
				printf("Employee ID: ");
				scanf("%d", &id);
				Employee* to_update = find_employee(&root, id);
				if(to_update != NULL){
					update_employee(&root, id);
				}
				else printf("[info] no match found\n");
				system("pause");
				break;
			case 6: // delete
				system("cls");
				printf("+------------------------------------+\n");
				printf("|---------- DELETE EMPLOYEE ---------|\n");
				printf("+------------------------------------+\n\n");
				printf("Employee ID: ");
				scanf("%d", &id);
				Employee* to_delete = find_employee(&root, id);
				if(to_delete != NULL){
					remove_employee(&root, id);
				}
				else printf("[info] no match found\n");
				system("pause");
				break;
			case 7: // sort
				system("cls");
				printf("+------------------------------------+\n");
				printf("|-------- SORT EMLOYEES BY ID -------|\n");
				printf("+------------------------------------+\n\n");
				sort_employee(&root);
				printf("[success] employees sorted by ID\n");
				printf("Choose 'display' from the main menu to see them sorted.\n");
				system("pause");
				break;
			case 0: // exit
				printf("[note] goodbye..\n");
				system("pause");
				break;
			default: // undefined
				printf("[warning] invalid menu entry\n");
				system("pause");
				break;
			}
	}


	free(root);

	return EXIT_SUCCESS;
}
