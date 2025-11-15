#include <iostream>
#include <string.h>
#include <stdio.h>
#include <array>
#include <memory> //for delete operator overload
using namespace std;

class Student{
	public: string name;
	void print(){ cout << name << endl;
	}
	Student(string name) : name(name){	}
	
};

//overide new operator to keep track of memory
void* operator new(size_t size){
	cout << "Allocating " << size << "bytes\n";
	return malloc(size);
}

void operator delete(void* memory, size_t size){
	cout << "freeing " << size << endl;
	free(memory);
}

int main(){
	int x = 4; //on the stack, in functions local variables are automaticly cleaned
	
	int *p = new int(5); // now using memory on the heap	
	//*p = 5; 

	//data on the heap needs to be deleted.
	delete p;
	//if you change p wihout freeing the 5 it will cause a memory leak. You can no longer clear that space.
	//example
//	int *p = new int(5);
//	p = new int(10);
//	delete p;

double *array = new double[4]; //a block
//can use like an array
array[0] = 5;
array[1] = 6;
array[2] = 7;
array[3] = 8;
delete array;

//Object created on the heap
Student *student	= new Student("joseph"); // the keyword "new" calls the constructor

(*student).print();

(*student).name = "John";
(*student).print();

student->name = "Mary";
student->print();

delete student; // the "delete" keyword calls the destructor
	
	
	//old C -- malloc() , calloc() , free
	
	
//when a block of memory is too large
/*
try{
	double *big_array = new double [9999999999999999999999];
}	catch (bad_alloc& exp){
	cout << "bad_alloc_caught: " << exp.what() << endl;
}
	
	

	double *big_again = new(nothrow) double [9999999999999999999999];
	
	if(big_again == NULL)
cout << "failed to allocate again." << endl;
	*/
		
	double *mydouble = new double(12.2);
	cout << *mydouble << endl;
	double *specific = new(mydouble) double(20.5); // re-using existing allocated memory
	cout << *mydouble << endl;
	
}



//------------------------------------------THIS IS A MEMORY LEAK----------------------------

int memoryLeak(){
	int *p = new int(5);
	//if you change p wihout freeing the 5 it will cause a memory leak. You can no longer clear that space.
	
	//NOTICE: p is using the keyword "new" while not being initialized.
	p = new int(10);
	 //now we can'd delete '5'
	delete p; 
}

//Does this fix it?
int fixLeak(){
	int *p = new int(5);
	// assign another pointer to '5'.
	int *q = p;
	//NOTICE: p is using the keyword "new" while not being initialized.
	p = new int(10); //now we can'd delete '5'
	delete p; 
	//then delete that.
	delete q; 
}



//STACK    
//------ know how much data we are going to be working with
//
//                  memory 
// Variable        Address            Value
//
//  x             0x0001                4
//    p           0x0002              0x9901
//
//
//
// HEAP       
//-------to allocate memory dynamiccly
//            
//                0x9901                5
//       		  0x9902
//                0x9903
