//
//  main.c
//  learning_debugging
//
//  Created by Lee Barney on 4/16/20.
//  Edited by Eric Sokolowsky on 2/25/22.
//  This work is licensed under a Creative Commons Attribution 4.0 International License.
//

// Libraries and directives for Windows/Linux-based machines necessary to compile this program
#ifdef _WIN32
  #define _CRT_SECURE_NO_WARNINGS
#endif /* _WIN32 */


#include <stdio.h>
#include <time.h>



int total(int count, int *numbers) {  // the * means a pointer. Pointers and arrays are mostly interchangeable.

  int sum = 0;
  for (int i = 0; i < count; i++) { // loop from 0 to count-1 (body of loop is executed 'count' times)
    int anInt = numbers[i]; // get the next int from the array
    sum += anInt;
  }
  return sum;
}

int main(int argc, const char* argv[]) {

  // current date/time based on current system
  time_t now = time(0);

  // convert now to string form
  char *currentDateAndTime = ctime(&now);

  printf("It is now %s\n", currentDateAndTime);


  int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // array of integers; compiler determines size from initialization
  int theTotal = total(10, numbers);  // using an array name without subscript produces a pointer to first element in array

  printf("The total is %d\n", theTotal);
  return 0;
}

