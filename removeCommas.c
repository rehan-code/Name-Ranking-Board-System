#include <stdio.h>
#include <string.h>
/*
 * Program Name: removeCommas.c
 * Author(s): Rehan Nagoor Mohideen
 * Student ID: 1100592
 * Purpose: Removes commas from a string.
 */

 int removeCommas ( char *line ) {
  int i=0,j=0;
  int noofCommas = 0;
  int lineLength = strlen(line);
  while (i <= lineLength) {
    if (line[i]== ','){
        noofCommas++;
        for (j = i; j < lineLength; j++) { /* Removing comma by pulling all characters in the array back by one */
          line[j]=line[j+1];
        }
    }
    i++;
  }
  return noofCommas;
}
