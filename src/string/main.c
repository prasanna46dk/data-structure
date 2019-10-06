#include<stdio.h>
#include<stdlib.h>

#include"string/string.h"

#define TEST_INPUT "Prasanna Dattatraya Kulkarni"
#define TEST_INPUT_1 "Prasanna"
#define TEST_INPUT_2 "rasannaP"
#define TEST_INPUT_3 "Prasanna"
#define TEST_INPUT_4 "asannaPr"
#define TEST_INPUT_5 "Prasanna"
#define TEST_INPUT_6 "sannaPra"
#define TEST_INPUT_7 "Prasanna"
#define TEST_INPUT_8 "rasanna"
#define TEST_INPUT_9 "Prasanna"
#define TEST_INPUT_10 "Prasaann"
#define TEST_INPUT_11 "Prasanna"
#define TEST_INPUT_12 "rasnnaPa"
#define TEST_INPUT_13 "P Dat"

int main()
{
  char *str = (char *)malloc(strlen(TEST_INPUT));
  printf("max occuring char is: '%c'\n", maxOccuringChar(TEST_INPUT));
  printf("String without duplicates: '%s'\n",
	 removeDuplicates(TEST_INPUT, str));
  printDuplicates(TEST_INPUT);
  rmFromFirstString(TEST_INPUT, TEST_INPUT_1);
  printf("'%s', '%s' are %sRotation of each other\n",
	 TEST_INPUT_1, TEST_INPUT_2,
	 (areRotation(TEST_INPUT_1, TEST_INPUT_2) == 0 ? "not ": ""));

  // do not pass INPUT directly because INPUT is read only memory and if you try
  // to change char you will get segmentation fault.
  // checkout this link for further explanation:
  // https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-string-initialized-with-cha
  strcpy(str, TEST_INPUT_1);
  printf("Reverse string: %s\n", revStrRecursion(str, 0, strlen(str)-1));
  printf("Reverse string: %s\n", revStr(str));
  printf("Permuations of string %s are:\n",str);
  strcpy(str, "HOW");
  permuteString(str, 0, strlen(str)-1);
  return 0;
}
