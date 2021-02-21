#include<stdio.h>
#include<stdlib.h>

#include"string/string.h" // string handling functions, enums & macros

#define TEST_INPUT "Prasanna Dattatraya Kulkarni"
#define TEST_INPUT_1 ""
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
  int i;
  char *sortTestArray [] = {"Prasanna","Dattatraya"," Kulkarni"};
  char *str = (char *)malloc(strlen(TEST_INPUT));
  // 1. Max occuring char.
  printf("max occuring char is: '%c'\n", maxOccuringChar(TEST_INPUT));	// ?? escape character required for single quote
  // 2. Remove dulplicates from string.
  printf("String without duplicates: '%s'\n",
         removeDuplicates(TEST_INPUT, str));
  // 3. Print duplicates characters from string.
  printDuplicates(TEST_INPUT);
  // 4. Remove Characters from 1st string present in 2nd string.
  rmFromFirstString(TEST_INPUT, TEST_INPUT_1);
  // 5. Check if 2 strings are rotation of each other.
  printf("'%s', '%s' are %sRotation of each other\n",
         TEST_INPUT_1, TEST_INPUT_2,
         (areRotation(TEST_INPUT_1, TEST_INPUT_2) == 0 ? "not ": ""));

  // do not pass INPUT directly because INPUT is read only memory and if you try
  // to change char you will get segmentation fault.
  // checkout this link for further explanation:
  // https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-string-initialized-with-cha
  strcpy(str, TEST_INPUT_1);
  // 6. Reverse string with recursion.
  printf("Reverse string: %s\n", revStrRecursion(str, 0, strlen(str)-1));
  // 7. Reverse string without recursion.
  printf("Reverse string: %s\n", revStr(str));
  // 8. Print all permutations of a string.
  printf("Permuations of string %s are:\n",str);
  strcpy(str, "HOW");
  permuteString(str, 0, strlen(str)-1);
  // 9. Print first non occuring character from string.
  printf("First Non repeating character in '%s' is '%c'\n",
         str, firstNonRepeatingChar(str));
  strcpy(str, TEST_INPUT);
  // 10. Reverse words in given string.
  printf("Reversed words of string '%s' are '%s'\n",
         TEST_INPUT,reverseWords(str));
  // 11. Check if given strings are anagram of each other.
  printf("'%s', '%s' are %sanagram of each other\n",
         TEST_INPUT_1, TEST_INPUT_6,
         (areAnagram(TEST_INPUT_1, TEST_INPUT_6) == 0 ? "not ": ""));
  // 12. Check if given string is palindrome or not.
  printf("'%s' is %spalindrome\n",
         TEST_INPUT_13,(isPalindrome(TEST_INPUT_13) == 0 ? "not ": ""));
  // 13. Convert string to interger.
  printf("String to int of '%s' is %d\n",
         TEST_INPUT_11, strToInt(TEST_INPUT_11));
  printf("String to int of '%s' is %d\n",
         TEST_INPUT_12, strToInt(TEST_INPUT_12));
  // 14. Remove given character from string.
  strcpy(str, TEST_INPUT_1);
  printf("Remove Char '%c' from '%s': '%s'\n", 'a',
         TEST_INPUT_1, rmGivenChar(str, 'a'));
  // 15. Count words in given string.
  printf("Number of words in %s are %d\n",TEST_INPUT, countWords(TEST_INPUT));
  // 16. Check if given Parenthesis string is valid or not.
  printf("'%s' is %sa valid string\n",
         "[(){}[]",
         (isValidParenthesis("[(){}[]",
                             strlen("[(){}[]")) == 0 ? "not ": ""));
  // 17. Find the smallest window in a string containing all characters of another string.
  strcpy(str, "this is a test string");
  char *str1 = (char *) malloc(sizeof(str));
  printf("Smallest window where `%s` found in '%s' is '%s':\n",
        "tist", str, smallestWindow(str, "tist", str1));
  // 18. Reverse order of words in string.
  strcpy(str, TEST_INPUT);
  printf("Reverse Word order of '%s' is '%s'\n",
         TEST_INPUT, reverseWordOrder(str));
  // 19. Sort array of strings.
  printf("Sorted output of ");
  for(i = 0; i < 3; i++)
    printf("%s ",sortTestArray[i]);
  sort((const char **)sortTestArray, 3);
  for(i = 0; i < 3; i++)
    printf("%s ",sortTestArray[i]);
  printf("\n");

  return 0;
}
