/*
 * C Program to Extract Last two Digits of a given Year
 */
#include <stdio.h>
 
int main()
{
    int year, yr;
 
    printf("Enter the year ");
    scanf("%d", &year);
    yr = year % 100;
    printf("Last two digits of year is: %02d\n", yr);
    return 0;
}