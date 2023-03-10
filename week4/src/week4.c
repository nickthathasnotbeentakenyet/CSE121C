/*
 ============================================================================
 Name        : week4.c
 Author      : Arkadii Lantukh
 Version     : 1.0
 Copyright   : I don't care
 Description : 4th week of C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int find_minimum(int *a, int *b){
	printf("Enter the first number: ");
	scanf("%d", a);
	printf("Enter the second number: ");
	scanf("%d", b);
	if (*a <= *b) return *a;
	else return *b;
}

int main(void) {

	int x = 0;
	int y = 0;

	printf("Before function call: a is %d and b is %d\n", x, y);
	int minimum = find_minimum(&x, &y);
	printf("The minimum value is: %d\n", minimum);
	printf("After function call: a is %d and b is %d\n", x, y);

	while(1){};
	return EXIT_SUCCESS;
}
