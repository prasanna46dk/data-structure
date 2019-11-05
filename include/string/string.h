#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define ASCII 256

typedef enum bool { false, true } bool;

char maxOccuringChar(char *str);
char *removeDuplicates(char *str, char *str2);
void printDuplicates(char *str);
void rmFromFirstString(char *src, char *dest);
bool areRotation(char *src, char *dest);
void swap(char *src, int start, int end);
char *revStrRecursion(char *str, int start, int end);
char *revStr(char *str);
void permuteString(char *str, int left, int right);
char firstNonRepeatingChar(char *str);
char *reverseWords(char *str);
bool areAnagram(char *src, char *dest);
bool isPalindrome(char *str);
int strToInt(char *str);
char *rmGivenChar(char *str, char c);
int countWords(char *str);
bool isValidParenthesis(char *str, int length);
char *smallestWindow(char *str, char *pattern, char *resultStr);
char *reverseWordOrder(char *str);
int compare(const void *a, const void *b);
void sort(const char *arr[], int n);
