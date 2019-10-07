#include<string.h>
#include<stdio.h>

#define ASCII 256

typedef enum bool { false, true } bool;

char maxOccuringChar(char *str);
char *removeDuplicates(char *str, char *str2);
void printDuplicates(char *str);
char *rmFromFirstString(char *src, char *dest);
bool areRotation(char *src, char *dest);
void swap(char *src, unsigned start, unsigned end);
char *revStrRecursion(char *str, unsigned start, unsigned end);
char *revStr(char *str);
void permuteString(char *str, unsigned left, unsigned right);
char firstNonRepeatingChar(char *str);
char *reverseWords(char *str);
bool areAnagram(char *src, char *dest);
bool isPalindrome(char *str);
int strToInt(char *str);
char *rmGivenChar(char *str, char c);
unsigned countWords(char *str);
bool isValidParenthesis(char *str, int length);
