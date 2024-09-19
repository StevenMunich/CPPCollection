#include <iostream>

void pointer2pointer();

int main(){
	
//pointer2pointer();

const int SIZE = 5;
	int *array = new int[SIZE];
	*array = 555;
	std::cout << *array << std::endl;
	
	for(int i = 0; i < SIZE; i++){
		*array = i;
		std::cout << *array << std::endl;
		array++;
	}
	for(int i = 0; i < SIZE; i++)
	delete array;

}

void pointer2pointer(){
		//points to integers 
//	int* array = new int[50];	//allocation of memory: a pointer has 4 bytes, so does an int. When working with larger..
	//points to pointer			//datatypes(20byte struct) instead of allocating 1000bytes it allocates the pointers.
	int** a2d = new int*[50];  //no integers are created, instead 50 pointers are allocated in memory. 50x4=200bytes.
							  
//	array[0] = nullptr;	is invalid because its an integer					  
//	a2d[0] = nullptr; is a pointer

//a multideminesional array is an array of arrays.  
//Each pointer points to an array. The array is an array of memory adresses of the arrays.

	for(int i=0; i < 50; i++){
		a2d[i] = new int[50]; //allocated 50 arrays, the location of each array is stoed in a2d	
		
		*a2d[i] = i;
		std::cout << "address: " << a2d[i];
		std::cout << "value " << *a2d[i] << std::endl;
	}
	


	for(int i=0; i < 50; i++)
		delete a2d[i];


}
