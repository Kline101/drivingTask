#include <stdio.h> 
#include<string.h> 
 
int main(void)  
{ 
	char c[100]; 
	scanf("%s",c); 
	/*strlen(c) gives total length of string . string index starts from 0 
	last index of character is strlen(c)-1*/ 
	int l = strlen(c)-1; 
	printf("%c %c\n",c[0],c[1]); 
	return 0; 
}             