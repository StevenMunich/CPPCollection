#include <stdio.h>
#include <stdbool.h>  
// allows booleans 

struct{ 
int age = 7;
char *name = "cgull";
    } cat;

int doublenum(int i){ return i * 2;}

int main(int argc, char *argv[])
{
	
	printf("age is %d \n", cat.age);
	printf("name is %s \n", cat.name);
	printf("%d \n", doublenum(4));
}