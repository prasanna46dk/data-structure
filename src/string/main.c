#include<stdio.h>
#include<stdlib.h>

#include"string/string.h"

#define INPUT "Prasanna Dattatraya Kulkarni"
#define INPUT1 "P Dat"
#define ROTATION_TEST_1 "Prasanna"
#define ROTATION_TEST_2 "rasannaP"
#define ROTATION_TEST_3 "Prasanna"
#define ROTATION_TEST_4 "asannaPr"
#define ROTATION_TEST_5 "Prasanna"
#define ROTATION_TEST_6 "sannaPra"
#define ROTATION_TEST_7 "Prasanna"
#define ROTATION_TEST_8 "rasanna"
#define ROTATION_TEST_9 "Prasanna"
#define ROTATION_TEST_10 "Prasaann"
#define ROTATION_TEST_11 "Prasanna"
#define ROTATION_TEST_12 "rasnnaPa"

int main()
{
  char *str = (char *)malloc(strlen(INPUT));
  printf("max occuring char is: '%c'\n", maxOccuringChar(INPUT));
  printf("String without duplicates: '%s'\n", removeDuplicates(INPUT, str));
  printDuplicates(INPUT);
  rmFromFirstString(INPUT, INPUT1);
  printf("'%s', '%s' are %sRotation of each other\n",
	 ROTATION_TEST_1, ROTATION_TEST_2,
	 (areRotation(ROTATION_TEST_1, ROTATION_TEST_2) == 0 ? "not ": ""));

  // do not pass INPUT directly because INPUT is read only memory and if you try
  // to change char you will get segmentation fault.
  // checkout this link for further explanation:
  // https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-string-initialized-with-cha
  strcpy(str, INPUT);
  printf("Reverse string: %s\n", revStrRecursion(str, 0, strlen(str)-1));
  printf("Reverse string: %s\n", revStr(str));
  return 0;
}
