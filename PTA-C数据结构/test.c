#include <stdio.h>  
#include <stdlib.h>  
#include <time.h> 

int main( void )  
{  
	char s[100];
	char *a;
	a=s;
    scanf("%s",s);
	printf("%c",*a++);
	printf("%c",*a++);
	return 0;
} 
