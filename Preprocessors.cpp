#include <iostream>
//preprocessors are executed during runtime, but when compiled
#define PI (3.14159) 
//my program will replace PI with 3.14159
//there is no variable in memory

//can use with strings too
#define SHM_NAME "mySharedMemory"

//arrays
#define MAX_SIZE (128)

//functions - not reccomended
#define square(a) a*a

//undefine
#define undefinedVar
#undef undefinedVar

//IF statements
#define TRIGGER

//For 2 header files that include eachother. Basicly says Include this ONCE so we dont loop "I include you & you include me"
//#pragma once

int main(){
	
	std::cout << PI << std::endl;
	
	std::cout << SHM_NAME << std::endl;

/*	int array1[MAX_SIZE];
	for(int i=0; i < MAX_SIZE; i++){
		array1[i] = i;
		std::cout << array1[i] << std::endl;
	} */
	
	int i = 5;
	std::cout << square(i) << std::endl;
	//CAN NOT DO i++ because it replaces a string
	std::cout << square(i++) << std::endl;
	
	//can do
	//#undef undefinedVar
	
	//IF statements
	#ifdef TRIGGER
	std::cout << "Trigger is defined \n";
	#endif
	//IF not defined
	#ifndef NIGGER
	#define NIGGER "The N word"
	#endif
	std::cout << NIGGER << std::endl;
	return 0;
	//nested if - this example is if LINUX & WINDOWS both are true
	#ifdef WIN64
	#ifdef LINUX
	#error
	#endif
	#endif
}

