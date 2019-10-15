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
#define TEST_INPUT_11 "143"
#define TEST_INPUT_12 "-645"
#define TEST_INPUT_13 "nitin"

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
  printf("First Non repeating character in '%s' is '%c'\n",
	 str, firstNonRepeatingChar(str));
  strcpy(str, TEST_INPUT);
  printf("Reversed words of string '%s' are '%s'\n",
	 TEST_INPUT,reverseWords(str));
  printf("'%s', '%s' are %sanagram of each other\n",
	 TEST_INPUT_1, TEST_INPUT_6,
	 (areAnagram(TEST_INPUT_1, TEST_INPUT_6) == 0 ? "not ": ""));
  printf("'%s' is %spalindrome\n",
	 TEST_INPUT_13,(isPalindrome(TEST_INPUT_13) == 0 ? "not ": ""));

  printf("String to int of '%s' is %d\n",
	 TEST_INPUT_11, strToInt(TEST_INPUT_11));
  printf("String to int of '%s' is %d\n",
	 TEST_INPUT_12, strToInt(TEST_INPUT_12));
  strcpy(str, TEST_INPUT_1);
  printf("Remove Char '%c' from '%s': '%s'\n", 'a',
	 TEST_INPUT_1, rmGivenChar(str, 'a'));
  printf("Number of words in %s are %d\n",TEST_INPUT, countWords(TEST_INPUT));
  printf("'%s' is %sa valid string\n",
	 "[(){}[]",
	 (isValidParenthesis("[(){}[]",
			     strlen("[(){}[]")) == 0 ? "not ": ""));
  strcpy(str, "this is a test string");
  char *str1 = (char *) malloc(sizeof(str));
  printf("Smallest window where `%s` found in '%s' is '%s':",
	"tist", str, smallestWindow(str, "tist", str1));
  return 0;
}
