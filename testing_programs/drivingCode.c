#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <stdbool.h>
#include <assert.h>

//Structure
typedef struct car {
int year;
char registration[10];
char colour[10];
float engine;

char reg_check;
} car_type;

int option;
int i;

void usermenu();
int tax(car_type cars[],int i);

car_type cars[100];


int firstTwo(number) {
  char firstTwo[9];
  memcpy(firstTwo, number , 2);
  
}


bool reg_check(car_type cars[],int i) {
    // If year is greater than or equal 2013, then it should have 8 or 9 digits
    if (cars[i].year >= 2013 && ((((strlen(cars[i].registration))) == 8) || ((strlen(cars[i].registration)) == 9))) {
      cars[i].reg_check = true; // change to full sentence
    }

    // If year is less than 2013, then it should have 7 or 8
    else if ((cars[i].year < 2013) && ((strlen(cars[i].registration) == 7) || strlen(cars[i].registration) == 8)) {
      cars[i].reg_check = true;
    }

    // checking last 2 of .year and last 2 or 3 with year over 2000
    else if (cars[i].year >= 2013) {
      // if year matches first 2 digits of registration
      if (cars[i].year % firstTwo((cars[i].registration) == 0)) {
        cars[i].reg_check = true;
        // printf("\t For YEAR > 2000 the last two digits are \n %d", cars[i].year);
      }
    }


    else if (cars[i].year < 2013) {
      if (cars[i].year == (cars[i].year - 1900)) {
        printf("\t  For YEAR < 2000 the last two digits are \n %d", cars[i].year);
      }
    }

    else {
      cars[i].reg_check = false;
    }

    return cars[i].reg_check;
}




int main() {
// Opening Files
    char name[100];  /* name of the file to use  */
    FILE *in_file;    /* file for input */
    // For file-related processing functions. e.g. fgets, fopen, fclose
    printf("Name of the File (e.g indata.txt) ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';
    in_file = fopen(name, "r");
    if (in_file == NULL) {
        fprintf(stderr, "Could not open file\n");
        exit(8);
    }
    for (i=0;i<100;i++)
{
  fscanf(in_file , "%d %s %s %f", &cars[i].year, cars[i].registration, cars[i].colour, &cars[i].engine);


// Car Registration
}
printf("\n\nDriving Task by Jahz\n\n");
  usermenu();


fclose(in_file);
  return 0;
}

void usermenu() {
  FILE* outdata;
  outdata = fopen("outdata.txt", "w");

  printf("Please choose one of the options below:\n");
  printf("1.To print the results to the screen only, press 1\n");
  printf("2.To print the results to the file only, press 2\n");
  printf("3.To print the results to both the screen and file, press 3\n");
  scanf("%d", &option);

  #define FSIZE 100
  FILE *fptr;
  int ctr = 0;  
  char fname[FSIZE] = "indata.txt";
  char c;

  fptr = fopen(fname, "r");


  for (c = getc(fptr); c != EOF; c = getc(fptr))
    if (c == '\n') // Increment count if this character is newline
      ctr = ctr + 1;
  fclose(fptr);


  int counter = ctr + 1;

    switch(option){
        // For option 1: To print the results to the screen only
        case 1:
        for (i=0; i < counter; i++) {
            if(reg_check(cars,i) == true) {
              printf("\n Car %d has a VALID registration. Its reg number is %s \n",i+1, cars[i].registration);
            }
            else {
              printf("\n Car %d has an INVALID registration. Its reg number is %s \n",i+1, cars[i].registration);
            }
        }
        break;
   
      case 2:
        for (i=0; i < counter; i++){
          if(reg_check(cars,i) == true) {
            fprintf(outdata, "\n Car %d has a VALID registration. Its reg number is %s \n",i+1, cars[i].registration);
          }
          else {
            fprintf(outdata, "\n Car %d has an INVALID registration. Its reg number is %s \n",i+1, cars[i].registration);
          }
        }
        break;
      case 3:
        for (i=0; i < counter; i++){
          if(reg_check(cars,i) == true) {
            printf("\n Car %d has a valid registration. Its reg number is %s \n",i+1, cars[i].registration);
            fprintf(outdata, "\n Car %d has a valid registration. Its reg number is %s \n",i+1, cars[i].registration);
          }
          else {
            printf("\n Car %d has a valid registration. Its reg number is %c \n",i+1, cars[i].reg_check);
            fprintf(outdata, "\n Car %d has a valid registration. Its reg number is %s \n",i+1, cars[i].registration);
          }
        }
        break;
      default:
        printf("\n\nYou have made an illegal choice.\n");
          usermenu();
    }
    fclose(outdata);
}