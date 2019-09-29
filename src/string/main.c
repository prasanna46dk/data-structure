#include<stdio.h>
#include<stdlib.h>

#include"string/string.h"

#define INPUT "Prasanna Dattatraya Kulkarni"
#define INPUT1 "P Dat"
#define ROTATION_TEST_1 "Prasanna"
#define ROTATION_TEST_2 "rasannaP"

int main()
{
  char *str = (char *)malloc(strlen(INPUT));
  printf("max occuring char is: '%c'\n", maxOccuringChar(INPUT));
  printf("String without duplicates: '%s'\n", removeDuplicates(INPUT, str));
  printDuplicates(INPUT);
  rmFromFirstString(INPUT, INPUT1);
  printf("");
  return 0;
}
