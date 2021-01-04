#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "babies.h"
#include <stdbool.h>

/*
 *   Program name: babiesQuery.c
 *   Author: Rehan Nagoor Mohideen
 *   Student ID: 1100592
 *   Function: The program stores information of data on popular baby names over the decades 1880-2010 and allows the the user to search for a rank information, find a name and view information or see top ten from two files at once.
 *   Compilation: make babiesQuery
 */


int main ( int argc, char *argv[] ) {
  char answer[20], decadeAnswer[20], decadeAnswer2[20], choice[20];
  FILE *f1;
  FILE *f2;
  struct pNames decade1;
  struct pNames decade2;
  int rank, rank1, rank2, rank3, genderChoice;
  char maleSNumber[20];
  char femaleSNumber[20];
  char string[100];
  int i=0, j, k, l;
  bool maleExists = false, femaleExists = false, maleExists2 = false, femaleExists2 = false;
  char anotherQ = 'Y', changeYear = 'Y';
  char commonNames[10][20];

  while (changeYear == 'Y' || changeYear == 'y') {
    anotherQ = 'Y';

    do {
      printf("%s", "What 2 decades do you want to look at? [1880 to 2010]:");
      scanf("%s %s", decadeAnswer, decadeAnswer2);
      if ((atoi(decadeAnswer) != 1880 && atoi(decadeAnswer) != 1890 && atoi(decadeAnswer) != 1900 && atoi(decadeAnswer) != 1910 && atoi(decadeAnswer) != 1920 && atoi(decadeAnswer) != 1930 && atoi(decadeAnswer) != 1940 && atoi(decadeAnswer) != 1950 && atoi(decadeAnswer) != 1960 && atoi(decadeAnswer) != 1970 && atoi(decadeAnswer) != 1980 && atoi(decadeAnswer) != 1990 && atoi(decadeAnswer) != 2000 && atoi(decadeAnswer) != 2010) || (atoi(decadeAnswer2) != 1880 && atoi(decadeAnswer2) != 1890 && atoi(decadeAnswer2) != 1900 && atoi(decadeAnswer2) != 1910 && atoi(decadeAnswer2) != 1920 && atoi(decadeAnswer2) != 1930 && atoi(decadeAnswer2) != 1940 && atoi(decadeAnswer2) != 1950 && atoi(decadeAnswer2) != 1960 && atoi(decadeAnswer2) != 1970 && atoi(decadeAnswer2) != 1980 && atoi(decadeAnswer2) != 1990 && atoi(decadeAnswer2) != 2000 && atoi(decadeAnswer2) != 2010) ||  (atoi(decadeAnswer) == atoi(decadeAnswer2))) {
        printf("%s\n", "Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable. You must enter 2 acceptable decades seperated by at least one space.");
      }else {
        decade1.year= atoi(decadeAnswer);
        decade2.year= atoi(decadeAnswer2);
      }
    } while((atoi(decadeAnswer) != 1880 && atoi(decadeAnswer) != 1890 && atoi(decadeAnswer) != 1900 && atoi(decadeAnswer) != 1910 && atoi(decadeAnswer) != 1920 && atoi(decadeAnswer) != 1930 && atoi(decadeAnswer) != 1940 && atoi(decadeAnswer) != 1950 && atoi(decadeAnswer) != 1960 && atoi(decadeAnswer) != 1970 && atoi(decadeAnswer) != 1980 && atoi(decadeAnswer) != 1990 && atoi(decadeAnswer) != 2000 && atoi(decadeAnswer) != 2010) || (atoi(decadeAnswer2) != 1880 && atoi(decadeAnswer2) != 1890 && atoi(decadeAnswer2) != 1900 && atoi(decadeAnswer2) != 1910 && atoi(decadeAnswer2) != 1920 && atoi(decadeAnswer2) != 1930 && atoi(decadeAnswer2) != 1940 && atoi(decadeAnswer2) != 1950 && atoi(decadeAnswer2) != 1960 && atoi(decadeAnswer2) != 1970 && atoi(decadeAnswer2) != 1980 && atoi(decadeAnswer2) != 1990 && atoi(decadeAnswer2) != 2000 && atoi(decadeAnswer2) != 2010) ||  (atoi(decadeAnswer) == atoi(decadeAnswer2)));

    strcat(decadeAnswer, "Names.txt");
    strcat(decadeAnswer2, "Names.txt");

    i=0;
    if ( (f1 = fopen(decadeAnswer, "r")) != NULL ) {
       while ( fgets(string, 100, f1) != NULL ) {
          sscanf (string, "%d %s %s %s %s", &decade1.rank[i], decade1.maleName[i], maleSNumber, decade1.femaleName[i], femaleSNumber);
    /* printf ( "%d %s %s %s %s\n",decade1.rank[i],decade1.maleName[i],maleSNumber,decade1.femaleName[i],femaleSNumber ); */
          removeCommas ( maleSNumber );
          removeCommas ( femaleSNumber );
          decade1.maleNumber[i] = atoi ( maleSNumber );
          decade1.femaleNumber[i] = atoi ( femaleSNumber );
          i++;
       }
    } else {
       printf ( "Cannot open %s\n", decadeAnswer );
       return ( -2 );
    }
    fclose(f1);

    i=0;
    if ( (f2 = fopen(decadeAnswer2, "r")) != NULL ) {
       while ( fgets(string, 100, f2) != NULL ) {
          sscanf (string, "%d %s %s %s %s", &decade2.rank[i], decade2.maleName[i], maleSNumber, decade2.femaleName[i], femaleSNumber);
    /* printf ( "%d %s %s %s %s\n",decade1.rank[i],decade1.maleName[i],maleSNumber,decade1.femaleName[i],femaleSNumber ); */
          removeCommas ( maleSNumber );
          removeCommas ( femaleSNumber );
          decade2.maleNumber[i] = atoi ( maleSNumber );
          decade2.femaleNumber[i] = atoi ( femaleSNumber );
          i++;
       }
    } else {
       printf ( "Cannot open %s\n", decadeAnswer2 );
       return ( -2 );
    }
    fclose(f2);



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
              printf("%s\n", "Only numbers between 1 and 200 are acceptable");
              printf("%s", "What rank do you wish to see? [1-200]:");
            }
            if (rank<1 || rank>200) {
              printf("%s\n", "Only numbers between 1 and 200 are acceptable");
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
              printf("Rank %d: %d: Male: %s (%d)\n         %d: Male: %s (%d)\n", rank, decade1.year, decade1.maleName[rank-1], decade1.maleNumber[rank-1], decade2.year, decade2.maleName[rank-1], decade2.maleNumber[rank-1]);
            } else if (genderChoice==1) {
              printf("Rank %d: %d: Female: %s (%d)\n         %d: Female: %s (%d)\n", rank, decade1.year, decade1.femaleName[rank-1], decade1.femaleNumber[rank-1], decade2.year, decade2.femaleName[rank-1], decade2.femaleNumber[rank-1]);
            }else if (genderChoice==2) {
              printf("Rank %d: %d: Male: %s (%d) and Female: %s (%d)\n         %d: Male: %s (%d) and Female: %s (%d)\n", rank, decade1.year, decade1.maleName[rank-1], decade1.maleNumber[rank-1], decade1.femaleName[rank-1], decade1.femaleNumber[rank-1], decade2.year, decade2.maleName[rank-1], decade2.maleNumber[rank-1], decade2.femaleName[rank-1], decade2.femaleNumber[rank-1]);
            }else {
              printf("Only the numbers 0, 1, or 2 are acceptable.\n");
            }
          } while(genderChoice<0 || genderChoice > 2);

        }else if (strcmp(choice, "search")==0) {

          printf("What name do you want to search for? [case sensitive]:" );
          scanf("%s", answer);
          for (i = 0; i < 200; i++) {
            if (strcmp(decade1.maleName[i],answer)==0) {
              rank=i;
              maleExists=true;
            }
            if (strcmp(decade1.femaleName[i],answer)==0) {
              rank1=i;
              femaleExists=true;
            }
            if (strcmp(decade2.maleName[i],answer)==0) {
              rank2=i;
              maleExists2=true;
            }
            if (strcmp(decade2.femaleName[i],answer)==0) {
              rank3=i;
              femaleExists2=true;
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
              if (maleExists == true && maleExists2 == true) {
                printf("In %d, the male name %s is ranked %d with a count of %d and\nIn %d, the male name %s is ranked %d with a count of %d.\n", decade1.year, decade1.maleName[rank], decade1.rank[rank], decade1.maleNumber[rank], decade2.year, decade2.maleName[rank2], decade2.rank[rank2], decade2.maleNumber[rank2]);
              } else if (maleExists == true && maleExists2 != true) {
                printf("In %d, the male name %s is ranked %d with a count of %d and\nIn %d, the male name %s is not ranked.\n", decade1.year, decade1.maleName[rank], decade1.rank[rank], decade1.maleNumber[rank], decade2.year, answer);
              } else if (maleExists != true && maleExists2 == true) {
                printf("In %d, the male name %s is not ranked and\nIn %d, the male name %s is ranked %d with a count of %d.\n", decade1.year, answer, decade2.year, decade2.maleName[rank2], decade2.rank[rank2], decade2.maleNumber[rank2]);
              }else{
                printf("In %d, the male name %s is not ranked and\nIn %d, the male name %s is not ranked.\n", decade1.year, answer, decade2.year, answer);
              }
            }else if (genderChoice==1) {
              if (femaleExists == true && femaleExists2 == true) {
                printf("In %d, the female name %s is ranked %d with a count of %d and\nIn %d, the female name %s is ranked %d with a count of %d.\n", decade1.year, decade1.femaleName[rank1], decade1.rank[rank1], decade1.femaleNumber[rank1], decade2.year, decade2.femaleName[rank3], decade2.rank[rank3], decade2.femaleNumber[rank3]);
              } else if (femaleExists == true && femaleExists2 != true) {
                printf("In %d, the female name %s is ranked %d with a count of %d and\nIn %d, the female name %s is not ranked.\n", decade1.year, decade1.femaleName[rank1], decade1.rank[rank1], decade1.femaleNumber[rank1], decade2.year, answer);
              } else if (femaleExists != true && femaleExists2 == true) {
                printf("In %d, the female name %s is not ranked and\nIn %d, the female name %s is ranked %d with a count of %d.\n", decade1.year, answer, decade2.year, decade2.femaleName[rank3], decade2.rank[rank3], decade2.femaleNumber[rank3]);
              }else{
                printf("In %d, the female name %s is not ranked and\nIn %d, the female name %s is not ranked.\n", decade1.year, answer, decade2.year, answer);
              }
            }else if (genderChoice==2) {
              if (femaleExists == true) {
                printf("In %d, the female name %s is ranked %d with a count of %d and ", decade1.year, decade1.femaleName[rank1], decade1.rank[rank1], decade1.femaleNumber[rank1]);
              }else{
                printf("In %d, the female name %s is not ranked and ", decade1.year, answer);
              }
              if (maleExists == true) {
                printf("the male name %s is ranked %d with a count of %d\n", decade1.maleName[rank], decade1.rank[rank], decade1.maleNumber[rank]);
              }else{
                printf("the male name %s is not ranked\n", answer);
              }
              if (femaleExists2 == true) {
                printf("And in %d, the female name %s is ranked %d with a count of %d and ", decade2.year, decade2.femaleName[rank3], decade2.rank[rank3], decade2.femaleNumber[rank3]);
              }else{
                printf("And in %d, the female name %s is not ranked and ", decade2.year, answer);
              }
              if (maleExists2 == true) {
                printf("the male name %s is ranked %d with a count of %d.\n", decade2.maleName[rank2], decade2.rank[rank2], decade2.maleNumber[rank2]);
              }else{
                printf("the male name %s is not ranked.\n", answer);
              }
            }else {
              printf("Only the numbers 0, 1, or 2 are acceptable.\n");
            }
          } while(genderChoice < 0 || genderChoice > 2);

        }else if (strcmp(choice, "top")==0) {

          k=0;
          for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
              if (strcmp(decade1.maleName[i], decade2.maleName[j]) == 0){
                for (l = 0; l < 20; l++) {
                commonNames[k][l] = decade1.maleName[i][l];
                }
                k++;
              }
            }
          }
          if (k==0) {
            printf("There are no male names that appear in both %d and %d.", decade1.year, decade2.year);
          }else if (k==1) {
            printf("Male names that appear in both %d and %d Top Tens: ", decade1.year, decade2.year);
            printf("%s", commonNames[0]);
          }else {
            printf("Male names that appear in both %d and %d Top Tens: ", decade1.year, decade2.year);
            for (i = 0; i < k-1; i++) {
              printf("%s, ", commonNames[i]);
            }
            printf("%s", commonNames[k-1]);
          }

          for (i = 0; i < 10; i++) {
            for (j = 0; j < 20; j++) {
              commonNames[i][j]='\0';
            }
          }

          k=0;
          for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
              if (strcmp(decade1.femaleName[i], decade2.femaleName[j]) == 0){
                for (l = 0; l < 20; l++) {
                commonNames[k][l] = decade1.femaleName[i][l];
                }
                k++;
              }
            }
          }

          if (k==0) {
            printf("\nThere are no female names that appear in both %d and %d.\n", decade1.year, decade2.year);
          }else if (k==1) {
            printf("\nFemale names that appear in both %d and %d Top Tens: ", decade1.year, decade2.year);
            printf("%s\n", commonNames[0]);
          }else {
            printf("\nFemale names that appear in both %d and %d Top Tens: ", decade1.year, decade2.year);
            for (i = 0; i < k-1; i++) {
              printf("%s, ", commonNames[i]);
            }
            printf("%s\n", commonNames[k-1]);
          }

          for (i = 0; i < 10; i++) {
            for (j = 0; j < 20; j++) {
              commonNames[i][j]='\0';
            }
          }

        }else {
          printf("%s\n", "Please type in rank, search, or top exactly as requested.");
        }
      } while(strcmp(choice, "rank")!=0 && strcmp(choice, "search")!=0 && strcmp(choice, "top")!=0);

      do {
        printf("Do you want to ask another question about %d and %d? [Y or N]:", decade1.year, decade2.year);
        scanf("%s", answer);
        if (strcmp(answer, "Y")!=0 && strcmp(answer, "y")!=0 && strcmp(answer, "N")!=0 && strcmp(answer, "n")!=0) {
          printf("Only single characters Y or N are acceptable.\n");
        }
      } while(strcmp(answer, "Y") && strcmp(answer, "y") && strcmp(answer, "N") && strcmp(answer, "n"));
      anotherQ=answer[0];


    }


    do {
      printf("Would you like to select other decades? [Y or N]:");
      scanf("%s", answer);
      if (strcmp(answer, "Y")!=0 && strcmp(answer, "y")!=0 && strcmp(answer, "N")!=0 && strcmp(answer, "n")!=0) {
        printf("Only single characters Y or N are acceptable.\n");
      }
    } while(strcmp(answer, "Y") && strcmp(answer, "y") && strcmp(answer, "N") && strcmp(answer, "n"));
    changeYear = answer[0];


  }

  printf("Thank you for using babiesQuery.\n");


  return 0;
}
