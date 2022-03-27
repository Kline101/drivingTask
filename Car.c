#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct containing all the information for the car
// The car object contains the year, number, colour and engine
typedef struct car {
  int year;
  char num[9];
  char colour[10];
  float engine;

} 
car_type;

int option;
int i;

// Part 4
void user_menu();
// int tax(car_type cars[],int i);

car_type cars[6];

int main() {
  FILE *indata;
  indata = fopen("indata.txt","r");

  for (i = 0; i < 6; ++i) {
    fscanf(indata , "%d %s %s %f", &cars[i].year, cars[i].num, cars[i].colour, &cars[i].engine);

    }
  printf("Welcome to the Car Registration and Taxation\n");
  user_menu();


fclose(indata);
  return 0;
}

void user_menu() {
  FILE* outdata;
  outdata = fopen("outdata.txt", "w");

  printf("Please choose one of the options below:\n");
  printf("1.To print the results to the screen only, press 1\n");
  printf("2.To print the results to the file only, press 2\n");
  printf("3.To print the results to both the screen and file, press 3\n");
  scanf("%d", &option);

  switch(option){
    case 1:
      if {
    
      }
      printf("You picked option 1, print the results to the screen only.\n");
      break;
    default:
      printf("You have made an illegal choice.\n");
      user_menu();
  }
  fclose(outdata);
}