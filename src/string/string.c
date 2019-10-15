#include "string/string.h"
#include <math.h>

char maxOccuringChar(char *str)
{
  unsigned count[ASCII] = {0}, i;
  char max = 0;
  for (i = 0; str[i] != '\0'; i++)
    count[ (int)str[i]]++;
  for (i = 0; i < ASCII; i++) {
    if (count[i] > count[(int) max])
      max = (char) i;
  }
  return max;
 }

char *removeDuplicates(char * str, char *str2)
{
  unsigned count[ASCII] = {0}, i, j;

  for (i = 0; str[i] != '\0'; i++) {
      count[(int) str[i]]++;
  }
  for (j = 0, i = 0; str[i]!= '\0'; i++) {
    if (count[(int)str[i]] > 0 || str[i] == ' ') {
      str2[j++] = str[i];
      count[(int)str[i]] = 0;
    }
    str2[j] = '\0';
  }
  return str2;
}

void printDuplicates(char *str)
{
  unsigned count[ASCII] = {0}, i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] != ' ')
    count[(int)str[i]]++;
  }

  printf("Duplicate Elements are: ");
  for (i = 0; str[i] != '\0'; i++) {
    if (count[(int) str[i]] > 1)
      {
	printf("%c, ",str[i]);
	count[(int) str[i]] = 0;
      }
  }
  printf("\n");
}

void rmFromFirstString(char *src, char *dest)
{
  unsigned count[ASCII] = {0}, i;

  for (i = 0; dest[i] != '\0'; i++) {
    if (count[(int) dest[i]] < 1)
      count[(int) dest[i]]++;
  }

  printf("Charcters which are not present in second string: ");

  for (i = 0; src[i] != '\0'; i++) {
    if (count[(int) src[i]] != 1) {
      printf("%c, ", src[i]);
      count[(int) src[i]] = 1;
    }
  }

  printf("\n");
}

bool areRotation(char *src, char *dest)
{
  int i, j, shift, dlen, slen;

  slen = strlen(src);
  dlen = strlen (dest);

  if(dlen != slen)
    return false;

  for (i = 0, j = 0; dest[j] != '\0'; j++) {
    if (src[i] == dest[j])
      break;
  }

  shift = j;
  for (i = 0; src[i] != '\0'; i++) {
    if (i + shift < dlen) {
      if (src[i] != dest[i+shift])
	return false;
    } else {
      if (src[i] != dest[(i+shift) % dlen])
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

char *revStrRecursion(char *str, unsigned start, unsigned end)
{
  if(end <= 1)
    return str;

  if (start >= end)
    return str;

  if(start < end) {
    swap(str, start, end);
  }
  return revStrRecursion(str, ++start, --end);
}

char *revStr(char *str)
{
  unsigned start = 0, end = strlen(str)-1;
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
