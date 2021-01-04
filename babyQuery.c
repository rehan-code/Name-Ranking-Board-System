#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "babies.h"
#include <stdbool.h>

/*
 *   Program name: babyQuery.c
 *   Author: Rehan Nagoor Mohideen
 *   Student ID: 1100592
 *   Function: The program stores information of data on popular baby names over the decades 1880-2010 and allows the the user to search for a rank information, find a name and view information or see top ten.
 *   Compilation: make babyQuery
 */

int main ( int argc, char *argv[] ) {
  char answer[20], decadeAnswer[20], choice[20];
  FILE *f1;
  struct pNames popNames;
  int rank, rank1, genderChoice;
  char maleSNumber[20];
  char femaleSNumber[20];
  char string[100];
  int i=0;
  bool maleExists = false, femaleExists = false;
  char anotherQ = 'Y', changeYear = 'Y';

  while (changeYear == 'Y' || changeYear == 'y') {
    anotherQ = 'Y';

    do {
      printf("%s", "What decade do you want to look at? [1880 to 2010]:");
      scanf("%s", decadeAnswer);
      if (atoi(decadeAnswer) != 1880 && atoi(decadeAnswer) != 1890 && atoi(decadeAnswer) != 1900 && atoi(decadeAnswer) != 1910 && atoi(decadeAnswer) != 1920 && atoi(decadeAnswer) != 1930 && atoi(decadeAnswer) != 1940 && atoi(decadeAnswer) != 1950 && atoi(decadeAnswer) != 1960 && atoi(decadeAnswer) != 1970 && atoi(decadeAnswer) != 1980 && atoi(decadeAnswer) != 1990 && atoi(decadeAnswer) != 2000 && atoi(decadeAnswer) != 2010 ) {
        printf("%s\n", "Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable.");
      }else {
        popNames.year= atoi(decadeAnswer);
      }
    } while(atoi(decadeAnswer) != 1880 && atoi(decadeAnswer) != 1890 && atoi(decadeAnswer) != 1900 && atoi(decadeAnswer) != 1910 && atoi(decadeAnswer) != 1920 && atoi(decadeAnswer) != 1930 && atoi(decadeAnswer) != 1940 && atoi(decadeAnswer) != 1950 && atoi(decadeAnswer) != 1960 && atoi(decadeAnswer) != 1970 && atoi(decadeAnswer) != 1980 && atoi(decadeAnswer) != 1990 && atoi(decadeAnswer) != 2000 && atoi(decadeAnswer) != 2010);
    strcat(decadeAnswer, "Names.txt");

    i=0;
    if ( (f1 = fopen(decadeAnswer, "r")) != NULL ) {
       while ( fgets(string, 100, f1) != NULL ) {
          sscanf (string, "%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
    /* printf ( "%d %s %s %s %s\n",popNames.rank[i],popNames.maleName[i],maleSNumber,popNames.femaleName[i],femaleSNumber ); */
          removeCommas ( maleSNumber );
          removeCommas ( femaleSNumber );
          popNames.maleNumber[i] = atoi ( maleSNumber );
          popNames.femaleNumber[i] = atoi ( femaleSNumber );
          i++;
       }
    } else {
       printf ( "Cannot open %s\n", decadeAnswer );
       return ( -2 );
    }
    fclose(f1);


    while (anotherQ == 'Y' || anotherQ == 'y') {
      do {
        printf("%s", "Would you like to see a rank, search for a name, or see the top 10? [rank, search, top]:");
        scanf("%s", choice);

        if (strcmp(choice, "rank")==0) {
          do {
            printf("%s", "What rank do you wish to see? [1-200]:");
            while (scanf("%d", &rank) != 1) {
              while ((getchar()!='\n')) {
              }
              printf("Only numbers between 1 and 200 are acceptable \n");
              printf("%s", "What rank do you wish to see? [1-200]:");
            }
            if (rank<1 || rank>200) {
              printf("Only numbers between 1 and 200 are acceptable \n");
            }
          } while(rank<1 || rank>200);

          do {
            printf("%s", "Would you like to see the male (0), female (1), or both (2) names(s)? [0-2]:");
            while (scanf("%d", &genderChoice)!=1) {
              while ((getchar()!='\n')) {
              }
              printf("Only the numbers 0, 1, or 2 are acceptable.\n");
              printf("%s", "Would you like to see the male (0), female (1), or both (2) names(s)? [0-2]:");
            }
            if (genderChoice==0) {
              printf("Rank %d: Male: %s (%d)\n", rank, popNames.maleName[rank-1], popNames.maleNumber[rank-1]);
            } else if (genderChoice==1) {
              printf("Rank %d: Female: %s (%d)\n", rank, popNames.femaleName[rank-1], popNames.femaleNumber[rank-1]);
            }else if (genderChoice==2) {
              printf("Rank %d: Male: %s (%d) and Female: %s (%d)\n", rank, popNames.maleName[rank-1], popNames.maleNumber[rank-1], popNames.femaleName[rank-1], popNames.femaleNumber[rank-1]);
            }else {
              printf("Only the numbers 0, 1, or 2 are acceptable.\n");
            }
          } while(genderChoice<0 || genderChoice > 2);

        }else if (strcmp(choice, "search")==0) {

          printf("What name do you want to search for? [case sensitive]:" );
          scanf("%s", answer);
          for (i = 0; i < 200; i++) {
            if (strcmp(popNames.maleName[i],answer)==0) {
              rank=i;
              maleExists=true;
            }
            if (strcmp(popNames.femaleName[i],answer)==0) {
              rank1=i;
              femaleExists=true;
            }
          }

          do {
            printf("Do you wish to search male (0), female (1), or both (2) name? [0-2]:" );
            while (scanf("%d", &genderChoice)!=1) {
              while ((getchar()!='\n')) {
              }
              printf("Only the numbers 0, 1, or 2 are acceptable.\n");
              printf("Do you wish to search male (0), female (1), or both (2) name? [0-2]:" );
            }
            if (genderChoice==0) {
              if (maleExists== true) {
                printf("In %d, the male name %s is ranked %d with a count of %d.\n", popNames.year, popNames.maleName[rank], popNames.rank[rank], popNames.maleNumber[rank]);
              }else{
                printf("In %d, the male name %s is not ranked.\n", popNames.year, answer);
              }
            }else if (genderChoice==1) {
              if (femaleExists== true) {
                printf("In %d, the female name %s is ranked %d with a count of %d.\n", popNames.year, popNames.femaleName[rank1], popNames.rank[rank1], popNames.femaleNumber[rank1]);
              }else{
                printf("In %d, the female name %s is not ranked.\n", popNames.year, answer);
              }
            }else if (genderChoice==2) {
              if (femaleExists == true && maleExists == true) {
                printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d.\n", popNames.year, popNames.femaleName[rank1], popNames.rank[rank1], popNames.femaleNumber[rank1], popNames.maleName[rank], popNames.rank[rank], popNames.maleNumber[rank]);
              }else if (femaleExists == true && maleExists == false) {
                printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked.\n", popNames.year, popNames.femaleName[rank1], popNames.rank[rank1], popNames.femaleNumber[rank1], answer);
              }else if (femaleExists == false && maleExists == true) {
                printf("In %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d.\n", popNames.year, answer, popNames.maleName[rank], popNames.rank[rank], popNames.maleNumber[rank]);
              }else {
                printf("In %d, the female name %s is not ranked and the male name %s is not ranked.\n", popNames.year, answer, answer);
              }
            }else {
              printf("Only the numbers 0, 1, or 2 are acceptable.\n");
            }
        } while(genderChoice < 0 || genderChoice > 2);

      }else if (strcmp(choice, "top")==0) {
          for (i = 0; i < 10; i++) {
            printf("%-4d %-14s %-10d %-14s %d\n", popNames.rank[i], popNames.maleName[i], popNames.maleNumber[i], popNames.femaleName[i], popNames.femaleNumber[i]);
          }
        }else {
          printf("%s\n", "Please type in rank, search, or top exactly as requested.");
        }
      } while(strcmp(choice, "rank")!=0 && strcmp(choice, "search")!=0 && strcmp(choice, "top")!=0);

      do {
        printf("Do you want to ask another question about %d? [Y or N]:", popNames.year);
        scanf("%s", answer);
        if (strcmp(answer, "Y")!=0 && strcmp(answer, "y")!=0 && strcmp(answer, "N")!=0 && strcmp(answer, "n")!=0) {
          printf("Only single characters Y or N are acceptable.\n");
        }
      } while(strcmp(answer, "Y") && strcmp(answer, "y") && strcmp(answer, "N") && strcmp(answer, "n"));
      anotherQ=answer[0];

    }

    do {
      printf("Would you like to select another year? [Y or N]:");
      scanf("%s", answer);
      if (strcmp(answer, "Y")!=0 && strcmp(answer, "y")!=0 && strcmp(answer, "N")!=0 && strcmp(answer, "n")!=0) {
        printf("Only single characters Y or N are acceptable.\n");
      }
    } while(strcmp(answer, "Y") && strcmp(answer, "y") && strcmp(answer, "N") && strcmp(answer, "n"));
    changeYear = answer[0];

  }

  printf("Thank you for using babyQuery.\n");


  return 0;
}
