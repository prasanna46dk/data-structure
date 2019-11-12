#include "string/string.h"
#include <math.h>

//
// Returns: max occuring charater from input string of ASCII characters
//
// Arg1: pointer to character string
//
char maxOccuringChar(char *str)
{
  unsigned count[ASCII] = {0}, i;
  char max = 0;
  for (i = 0; str[i] != '\0'; i++)  // traverse the string from start to end of string
    count[ (int)str[i]]++;	// increment the frequency at the index of each occuring character
  // ?? what if string having ' ' space in it

  // each index from count array corresponds to ASCII value of corresponding character
  for (i = 0; i < ASCII; i++) {  // traverse the count array to find maximum occuring character
    if (count[i] > count[(int) max])
      max = (char) i;	// find the index which has maximum frequency 
  }
  return max;
 }

//
// Returns: pointer to character string which don't have duplicate characters
//
// Arg1: pointer to character string (i/p)
// Arg2: pointer to character string not having duplicates (o/p)
//
char *removeDuplicates(char * str, char *str2)
{
  unsigned count[ASCII] = {0}, i, j;

  for (i = 0; str[i] != '\0'; i++) {  // traverse the string from start to end of string
      count[(int) str[i]]++;	// increment the frequency at the index of each occuring character
  }
  for (j = 0, i = 0; str[i]!= '\0'; i++) {
    if (count[(int)str[i]] > 0 || str[i] == ' ') { // if frequency of caracter is > 0 OR charactr is space
      str2[j++] = str[i];	// then add i'th character to 'str2' o/p character array
      count[(int)str[i]] = 0;	// & set the frequency of corresponding character to 0,
				// so that if this same character occures again in 'str' traversal,
				// then we need to avoid copying that character in 'str2'
    }
    // add '\0' to represent EoL
    str2[j] = '\0'; // ?? can we take this line out of loop
  }
  return str2;
}

//
// Returns: void
//
// Arg1: pointer to character string (i/p)
//
void printDuplicates(char *str)
{
  unsigned count[ASCII] = {0}, i;
  for (i = 0; str[i] != '\0'; i++) {  // traverse the string from start to end of string
    if (str[i] != ' ') // ignore the spaces from the i/p string
    count[(int)str[i]]++; // increment the frequency at the index of each occuring character
  }

  printf("Duplicate Elements are: ");
  for (i = 0; str[i] != '\0'; i++) {  // traverse the string from start to end of string
    if (count[(int) str[i]] > 1) { // print the characters whose frequency is greater than 1
      printf("%c, ",str[i]);	
      count[(int) str[i]] = 0;	// set the frequency of corresponding character to 0,
			 	// to avoid printing same character again
    }
  }
  printf("\n"); // ?? why
}

//
// Returns: void
//
// Arg1: pointer to character string (i/p)
// Arg2: pointer to character string (i/p) which should be removed from string provided in Arg1 
//
void rmFromFirstString(char *src, char *dest)
{
  unsigned count[ASCII] = {0}, i;

  for (i = 0; dest[i] != '\0'; i++) {  // traverse the SECOND string from start to end of string
    if (count[(int) dest[i]] < 1) // if frequency is already set to '1', then ignore it
      count[(int) dest[i]]++;	// set the frequency as '1' at the index of each occuring character
  }

  printf("Charcters which are not present in second string: ");

  for (i = 0; src[i] != '\0'; i++) {
    if (count[(int) src[i]] != 1) {  // if frequency at index of character is not set to '1'
      printf("%c, ", src[i]);   // then print it
      count[(int) src[i]] = 1;  // And, set the frequency as '1' at the index of that character
				// so that if same character occured again in STR1, it should get ignored
    }
  }

  printf("\n");
}

//
// Returns: 'true' if 2 strings are in rotation of each other, else 'false'
//
// Arg1: pointer to character string1 (i/p)
// Arg2: pointer to character string2 (i/p)
//
bool areRotation(char *src, char *dest)
{
  int i, j, shift, dlen, slen;

  slen = strlen(src);   //find length of string1
  dlen = strlen (dest); //find length of string2

  if(dlen != slen)  // check if lengths of both strings are same or not 
    return false;

  for (i = 0, j = 0; dest[j] != '\0'; j++) {  // traverse the SECOND string from start to end of string
    if (src[i] == dest[j]) // src[0] == dest[j]
      break;	// break if character from SECOND string which maches 1st character from FIRST string
  }

  shift = j; // store the index from SECOND string att which 1st char match found
  for (i = 0; src[i] != '\0'; i++) {
    if (i + shift < dlen) {	// if (src index + shift) < length of SECOND string
      if (src[i] != dest[i+shift])  // source charcter should repeate after (src index + shift) in dest string
        return false;
    } else {	// if (src index + shift) >= length of SECOND string
      if (src[i] != dest[(i+shift) % dlen])  // source charcter should repeate after (src index + shift) in dest string
        return false;
    }
  }
  return true;
}

void swap(char *src, unsigned start, unsigned end)
{
  if (start < end) {
    src[start] ^= src[end];
    src[end] ^= src[start];
    src[start] ^= src[end];
  }
}

//
// Returns: Reversed character string
//
// Arg1: pointer to character string (i/p)
// Arg2: start index of string
// Arg3: end index of string
//
char *revStrRecursion(char *str, unsigned start, int end)
{
  if(end < 1)
    return str;

  if (start >= end)  // if start & end indices crossed the mid of string each other
    return str;  // then return string

  if(start < end) {  // if start & end indices have not crossed the mid of string each other
    swap(str, start, end); // swap the characters at start & end indices with each other
  }
  return revStrRecursion(str, ++start, --end); // pass the in-bound string along with pre-incremented & pre-decremented indices
}

char *revStr(char *str)
{
  int start = 0;
  int end = strlen(str)-1;
  if(!str)
    return str;
  while (start < end){
    swap(str, start++, end--);
  }
  return str;
}

void permuteString(char *str, unsigned left, unsigned right)
{
  unsigned i;
  if (left == right)
    printf("%s\n",str);
  else {
    for (i = left; i <= right; i++) {
      swap(str, left, i);
      permuteString(str, left+1, right);
      swap(str, left, i);
    }
  }
}

char firstNonRepeatingChar(char *str)
{
  unsigned count[ASCII] = {0}, i;
  for (i = 0; str[i] != '\0'; i++) {
    count[(int) str[i]] += 1;
  }

  for (i = 0; str[i] != '\0'; i++) {
    if (count[(int)str[i]] == 1)
      return str[i];
  }
  return '\0';
}

char *reverseWords(char *str)
{
  unsigned i = 0, start = 0, end;
  while (str[i] != '\0') {
    while (str[i] != ' ' && str[i] != '\0')
      i++;
    end = i-1;
    while (start < end)
      swap(str, start++, end--);
    start = i+1;
    i++;
  }
  return str;
}

bool areAnagram(char *src, char *dest)
{
  int result = 0, i;
  for (i = 0; src[i] != '\0'; i++) {
    result ^= src[i];
  }

  for (i = 0; dest[i] != '\0'; i++) {
    result ^= dest[i];
  }
  return (result == 0);
}

bool isPalindrome(char *str)
{
  unsigned start = 0, end = strlen(str)-1;
  while (start < end) {
    if (str[start++] != str[end--])
      return false;
  }
  return true;
}

int strToInt(char *str)
{
  unsigned i = 0;
  int sign = 1, result = 0;
  while(str[i] < '0' ||
        str[i] >  '9') {
    sign = (str[i] == '-') ? -1 : 1;
    i++;
  }
  while (str[i] != '\0') {
    result = (10*result) + (str[i]-'0');
    i++;
  }
  return sign*result;
}

char *rmGivenChar(char *str, char c)
{
  unsigned i = 0, j = 0;
  while (true) {
    while (str[i] != c)
      i++;
    j = i;
    while (str[j] == c)
      j++;
    swap(str, i++, j++);
    if (str[j] == '\0')
      break;
  }
  str[i] = '\0';
  return str;
}

unsigned countWords(char *str)
{
  unsigned count = 0, i = 0;
  while (str[i] == ' ' ||
         str[i] == '\t'||
         str[i] == '\n')
    i++;
  while(true) {
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
      count++;
    if (str[i] == '\0')
      break;
    i++;
  }
  return count;
}

bool isValidParenthesis(char *str, int length)
{
  unsigned i = 0, j = 0;
  char *stk = (char *) malloc(sizeof(length));
  memset(stk, '\0', length);
  while(str[i] != '\0') {
    if (str[i] == '(' ||
        str[i] == '{' ||
        str[i] == '[' ||
        str[i] == '<') {
      stk[j] = str[i];
    } else if (str[i] == ')') {
      if (stk[--j] != '(')
        return false;
      else {
        stk[j--] = '\0';
      }
    } else if (str[i] == '}') {
      if (stk[--j] != '{')
        return false;
      else {
        stk[j--] = '\0';
      }
    } else if (str[i] == ']') {
      if (stk[--j] != '[')
        return false;
      else {
        stk[j--] = '\0';
      }
    } else if (str[i] == '>') {
      if (stk[--j] != '<')
        return false;
      else {
        stk[j--] = '\0';
      }
    } else {
      stk[j] = '\0';
    }
    i++;
    j++;
  }
  return (stk[0] == '\0');
}

char *smallestWindow(char *str, char *pattern, char *resultStr)
{
  unsigned
    i,
    count = 0,
    minLen = INT_MAX,
    startIndex = -1,
    lenWindow = 0,
    start = 0,
    lenStr = strlen(str),
    lenPattern = strlen(pattern),
    hashStr[ASCII] = {0},
    hashPattern[ASCII] = {0};

  if (lenStr < lenPattern)
    return NULL;

  for (i = 0; i < lenPattern; i++)
    hashPattern[(unsigned) pattern[i]]++;

  for (i = 0; i < lenStr; i++) {
    hashStr[(unsigned) str[i]]++;

    if (hashPattern[(unsigned) str[i]] != 0 &&
        hashStr[(unsigned) str[i]] <= hashPattern[(unsigned) str[i]])
      count++;

    if (count == lenPattern) {
      while (hashStr[(unsigned) str[start]] >
             hashPattern[(unsigned) str[start]] ||
             hashPattern[(unsigned) str[start]] == 0) {
        if (hashStr[(unsigned) str[start]] >
            hashPattern[(unsigned) str[start]])
          hashStr[(unsigned) str[start]]--;
        start++;
      }

      lenWindow = i - start + 1;
      if (minLen > lenWindow) {
        minLen = lenWindow;
        startIndex = start;
      }
    }
  }

  if (startIndex == -1) {
    return NULL;
  }
  strncpy(resultStr, str+startIndex, minLen);
  return resultStr;
}

char *reverseWordOrder(char *str)
{
  str = reverseWords(str);
  return revStr(str);
}

//
// Returns:
// <0 The element pointed by a goes before the element pointed by b
// 0  The element pointed by a is equivalent to the element pointed by b
// >0 The element pointed by a goes after the element pointed by b
//
// Arg1: pointer to an void
// Arg2: pointer to an void
//
int compare(const void* a, const void* b)
{
  // The comparator function
  // takes two arguments and contains logic to decide their relative order in sorted output.
  return strcmp(*(const char**)a, *(const char**)b);
}

//
// Returns: pointer to character string which don't have duplicate characters
//
// Arg1: pointer to character string (i/p)
//
void sort(const char* arr[], int n)
{
  // qsort: C library function
  qsort(arr, n, sizeof(const char*), compare);
}
