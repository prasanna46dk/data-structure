#include "string/string.h"
#include <math.h>
char maxOccuringChar(char *str)
{
  unsigned count[ASCII] = {0}, i;
  char max = 0;
  for (i = 0; str[i] != '\0'; i++)
    count[ (int)str[i]]++;
  for (i = 0; i < ASCII; i++) {
    if (count[i] > count[max])
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

char *rmFromFirstString(char *src, char *dest)
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

bool
areRotation(char *src, char *dest)
{
  int result = 0, i, j, shift, rid, dlen, slen;

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
