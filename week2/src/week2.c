/*
 ============================================================================
 Name        : week2.c
 Author      : Arkadii Lantukh
 Version     : 1.0
 Copyright   : I don't care
 Description : Second week of C, Ansi-style
 ============================================================================
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// TASK 1 --------------------------------------------------------
	printf(".::TASK 1::.\n\n");
	// get two numbers from user
    float num1, num2;
	printf("Enter the first number: ");
	scanf("%f", &num1);
	printf("Enter the second number: ");
	scanf("%f", &num2);

    // compare and print numbers with 1 digit after decimal point
    if (num1 > num2) {
        printf("The first number (%.1f) is greater than the second (%.1f)\n", num1, num2);
    }
    else if (num1 < num2) {
        printf("The second number (%.1f) is greater than the first (%.1f)\n", num2, num1);
    }
    else {
        printf("Numbers (%.1f) and (%.1f) are equal\n", num1, num2);
    }

    // TASK 2 --------------------------------------------------------
    printf("\n");
    printf(".::TASK 2::.\n\n");
    // declare lists of products and prices
	char products[5][10] = {"Bread", "Milk", "Potatos", "Tomatos", "Beef"};
	double prices[] = {2.0, 4.0, 2.99, 3.60, 19.99};
	// print products list
	for (int i = 0; i < 5; i++){
		printf("%d. %s\n", i+1, products[i]);
	}
	// get product number from user and print corresponding price
	printf("Enter product number\n:> ");
	int choice;
	scanf("%d", &choice);
	switch (choice){
	case 1:
		printf("%s costs $%.2f\n", products[0], prices[0]);
		break;
	case 2:
		printf("%s costs $%.2f\n", products[1], prices[1]);
		break;
	case 3:
		printf("%s cost $%.2f\n", products[2], prices[2]);
		break;
	case 4:
		printf("%s cost $%.2f\n", products[3], prices[3]);
		break;
	case 5:
		printf("%s costs $%.2f\n", products[4], prices[4]);
		break;
	default:
		printf("item '%d' doesn't exist, sorry...\n", choice);
		break;
	}

    // TASK 3 --------------------------------------------------------
	printf("\n");
	printf(".::TASK 3::.\n\n");
	char weekdays[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int age = 0;
	int day = 0;
	// print weekdays
	for(int i=0; i< 7; i++){
		printf("%d. %s\n", i+1, weekdays[i]);
	}
	// get weekday number from user
	// looping until user provides a number within the range
	while(1){
		printf("Enter weekday number: ");
		scanf("%d", &day);
		// make sure it's in range between 1 and 7
		if (day >= 1 && day <= 7){break;}
		else{printf("Error: day is out of range!\n");}
	}
	// get age of a child
	printf("Enter child's age: ");
	scanf("%d", &age);

	// less then 6
	if(age >= 0 && age <= 5){
		// Everyday
		printf("Bed time is 7pm\n");
	}
	// 6 to 10
	else if(age > 5 && age <= 10){
		// Fr & Sat
		if (day == 6 || day == 7){
			printf("Bed time is 9pm\n");
		}
		// Sun-Th
		else{
			printf("Bed time is 8pm\n");
		}
	}
	// 11 to 17
	else if (age >= 11 && age <=17){
		//
		if(day == 6){
			// Fr
			printf("Bed time is at midnight\n");
		}
		// Sat
		else if(day == 7){
			printf("Bed time is 11pm\n");
		}
		// Sun-Th
		else{
			printf("Bed time is 9pm\n");
		}
	}
	// not yet born
	else if (age < 0){
		printf("Really? %d ? Not funny! I'll keep my eye on you, joker!", age);
	}
	// 18+
	else{
		printf("Not a child anymore!\n");
	}


    while (1){}
}
