/*
 ============================================================================
 Name        : week1.c
 Author      : Arkadii Lantukh
 Version     : 1.0
 Copyright   : I don't care
 Description : First week of C, Ansi-style
 ============================================================================
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main(void) {
	// set of variables
	char ch = 'a';
	short s = 0;
	int i = 1;
	long l = 2;

	// print statements
	printf("The character 'c' value is %c. The size of 'c' is %zd\n", ch, sizeof(ch));
	printf("The short 's' value is %d. The size of 's' is %zd\n", s, sizeof(s));
	printf("The integer 'i' value is %d. The size of 'i' is %zd\n", i, sizeof(i));
	printf("The long 'l' value is %ld. The size of 'l' is %zd\n", l, sizeof(l));

	// float
	float n;
	printf("Enter a float value : ");
	scanf("%f", &n);
	printf("%f %e %g The size is %zd\n", n, n, n, sizeof(n));

	// character array
	char str[20];
	printf("Enter a string: ");
	scanf("%s", str);
	printf("%s\n%d", str, sizeof(str));

	// struct
	struct car {
		char color[5];
		int wheels;
		float engine;
	};


	struct car c;
	c.color[0] = 'r';
	c.color[1] = 'e';
	c.color[2] = 'd';
	c.color[3] = 0;
	c.wheels = 4;
	c.engine = 1.5;
	printf("Car: \ncolor - %s, size of color = %zd\nwheels - %d, size of wheels = %zd\nengine - %g, size of engine = %zd\nTotal size of the structure = %zd\n",
		c.color, sizeof(c.color), c.wheels, sizeof(c.wheels), c.engine, sizeof(c.engine), sizeof(c));

	// enum
	enum summerMonths {
		June = 1,
		July,
		August
	};
	printf("Summer months:\nJune: %d\nJuly: %d\nAugust: %d\n", June, July, August);
	printf("Sizes of enums: \nJune = %zd\nJuly = %zd\nAugust = %zd\nTotal %zd\n",
		sizeof(June), sizeof(July), sizeof(August), sizeof(enum summerMonths));


	while (1) {}
	return EXIT_SUCCESS;
}
