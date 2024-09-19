#include <stdio.h>

typedef int age;
typedef int* ptrAge;

typedef struct {
    age age;
    char* name;
} Cat;

int main(int argc, char *argv[])
{
	age catsAge = 6;
	ptrAge catsAgePtr = &catsAge;
	printf("hello %d \n", *catsAgePtr);
	
	Cat seagull;
	seagull.age = 8;
	seagull.name = "Cgull";
	printf("cat named %s is %d years old", seagull.name, seagull.age);
}