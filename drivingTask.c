#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <stdbool.h>

//Structure
typedef struct car {
int year;
char registration[9];
char colour[10];
float engine;
int tax;
char reg_check;
} car_type;

int option;
int i;

void usermenu();
int tax(car_type cars[],int i);

car_type cars[6];

int reg_check(car_type cars[],int i) {
    // If year is greater than or equal 2013, then it should have 8 or 9 digits
    if (cars[i].year >= 2013 && (((strlen(cars[i].registration))) == 8) || ((strlen(cars[i].registration)) == 9)) {
      cars[i].reg_check = true; // change to full sentence
    }

    // If year is less than 2013, then it should have 7 or 8
    else if ((cars[i].year < 2013) && (strlen(cars[i].registration) == 7) || strlen(cars[i].registration) == 8) {
      return cars[i].reg_check = true;
    } 

    // // This is for reg with 7 digits
    // else if (strlen(cars[i].registration) == 7) {
    //   // First two digits cannot be letters
    //   if (isdigit(&cars[i].registration[0]) == "False") {
    //     "This car does not have a valid registration. The first two digits of the registration number are not numbers";
    //   }
    // }
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
    for (i=0;i<6;i++)
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
	// printf(" Input the file name to be opened : ");
	// scanf("%s",fname);

  fptr = fopen(fname, "r");


  for (c = getc(fptr); c != EOF; c = getc(fptr))
    if (c == '\n') // Increment count if this character is newline
      ctr = ctr + 1;
  fclose(fptr);


  int counter = ctr + 1;

    switch(option){
        // For option 1: To print the results to the screen only
        case 1:
        for (i=0; i < counter; ++i) {
            if(reg_check(cars,i) == true) {
              printf("\n Car %d has a VALID registration. Its reg number is %s \n",i+1, cars[i].registration);
            }
            else {
              printf("\n Car %d has an INVALID registration. Its reg number is %s \n",i+1, cars[i].registration);
            }
        }
        break;
    
      case 2:
        for (i=0; i < counter; ++i){
          if(reg_check(cars,i) == true) {
            fprintf(outdata, "\n Car %d has a VALID registration. Its reg number is %s \n",i+1, cars[i].registration);
          }
          else {
            fprintf(outdata, "\n Car %d has an INVALID registration. Its reg number is %s \n",i+1, cars[i].registration);
          }
        }
        break;
      case 3:
        for (i=0; i < counter; ++i){
          if(reg_check(cars,i)) {
            printf("\n Car %d has a valid registration. Its reg number is %c \n",i+1, cars[i].reg_check);
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



//   if(cars[i].year > 2014){
//     if(cars[i].engine <= 1.6){
//       cars[i].tax = 150;
//     }
//     else{
//       cars[i].tax = 300;
//     }
//   }
//   else{
//     if(cars[i].engine < 1.4){
//       cars[i].tax = 200;
//     }
//     else if(cars[i].engine > 1.6){
//       cars[i].tax = 600;
//     }
//     else{
//       cars[i].tax = 400;
//     }
//   }
//   return cars[i].tax;

