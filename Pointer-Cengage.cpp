#include <iostream>

#include <cstddef>
//allows named constant NULL
using namespace std;


int passArray(int i[], int arraySize){
	//int arraySize = sizeof(i) / sizeof(i[0]) +3;
	for(int j = 0; j < arraySize; j++)
	cout << i[j] << endl;
	cout << "list count = " << arraySize;
}

int point2int(){
	int *p, i;
	i = 100;
	p = &i;
	cout << "current value: " << i << endl;
	*p = 124;
	cout << "changed with pointer: " << i << endl;
	return 0;
}

int initializeArray(){
	int arraySize;
	
	cout << "enter array size: ";
	cin >> arraySize;
	int integerArray[arraySize];
	cout << "Enter the elements: ";
	for(int x=0; x < arraySize; x++)
	cin >> integerArray[x];	
	int *pIA = &integerArray[0];	
	cout << "Value= " << *pIA << endl << "Adress of pointer" << &pIA << endl << "pointing to: " << pIA << endl;
	
	passArray(integerArray, arraySize);
	return arraySize;
}

//structures are same as classes but members are public
struct studentType{
	char name[26];
	double gpa;
	int sID;
	char grade;
};

void pointersNstructs(){
		//Pointers and Structs.
	studentType student;
	studentType *studentPtr;
	studentPtr = &student;
	/*The expression (*studentPtr).gpa is a mixture of pointer dereferencing and the class component selection. In C++, the dot operator, ., has a higher precedence than the dereferencing operator.

Let us elaborate on this a bit. In the expression (*studentPtr).gpa, the operator * evaluates first, so the expression *studentPtr evaluates first. Because studentPtr is a pointer variable of type studentType, *studentPtr refers to a memory space of type studentType, which is a struct. Therefore, (*studentPtr).gpa refers to the component gpa of that struct.

Consider the expression *studentPtr.gpa. Let us see how this expression gets evaluated. Because . (dot) has a higher precedence than *, the expression studentPtr.gpa evaluates first. The expression studentPtr.gpa would result in a syntax error, as studentPtr is not a struct variable, so it has no such component as gpa.

As you can see, in the expression (*studentPtr).gpa, the parentheses are important. However, typos can be problematic. Therefore, to simplify the accessing of class or struct components via a pointer, C++ provides another operator called the member access operator arrow, ->. The operator -> consists of two consecutive symbols: a hyphen and the “greater than” sign.

The syntax for accessing a class (struct) member using the operator -> is:

Thus, the statement: */
	(*studentPtr).gpa = 3.3;
	//Accessing class (struct) components via pointers using the operator -> thus eliminates the use of both parentheses and the dereferencing operator. Because typos are unavoidable and missing parentheses can result in either an abnormal program termination or erroneous results, when accessing class (struct) components via pointers, this book uses the arrow notation.
	studentPtr->sID = 7;	
}

void nullPtr(){
	
	/* 
	Because C++ does not automatically initialize variables, pointer variables must be initialized if you do not want them to point to anything. Pointer variables are initialized 
	using the constant value 0, called the null pointer. Thus, the statement p = 0; stores the null pointer in p, that is, p points to nothing. 
	Some programmers use the named constant NULL to initialize pointer variables. The named constant NULL is defined in the header file cstddef. 
	The following two statements are equivalent:
	*/
	
	int *p;
	p = NULL;
	p = 0;

}

int dynoVar(){
	//dynamic variables
	
	int *p;
	char *name;
	string *str;
	//int x;
//	p = &x; creates new variable
//	cout << p << endl << &p << endl << &x << endl;

	p = new int; //can only be accessed by pointer
	*p = 28; //assigns 28 yo allocated memory	
	cout << p <<  endl << &p << endl << *p << endl;
	
	name = new char[5]; //allocates memory for an array of 5 elements of type char
						// stores base address in name	
	//strcpy(name, "John");
	
	str = new string;
	*str = "Sunny day";	
	cout << *str << endl; // << str << endl << &str; 
	
	
	
	//Now p is pointing to new memory without deleting 28 stored in first adress pointed too
	p = new int;
	*p = 73; //this is called memory leaking. not deleteing memory.
	cout << p <<  endl << &p << endl << *p << endl;
	//deletes values in stored memory
	//However, pointers still point to same address	
	delete p;
	delete [] name;
	delete str;		
	// set pointers to null
	p = 0;
	name = NULL;
	str = NULL;
	
}

void incByByte(){
	int *p; //4 bytes of memory
	double *q; //8 bytes
	char *chPtr; //1 byte
	studentType *stdPtr; // 40 bytes

	cout << p << endl;
//The increment operator increments the value of a pointer variable by the size of the data type or structure to which it is pointing. Similarly, the decrement operator decrements the value of a pointer variable
//by the size of the data type or structure to which it is pointing.
	

	//increments the value of p by 4 bytes because p is a pointer of type int. 
	p++;
	cout << p << endl;
	//increment the value of q by 8 bytes and the value of chPtr by 1 byte
	q++;
	chPtr++;
	//increments the value of stdPtr by 40 bytes.
	stdPtr++;
	//increments the value of p (an int pointer) by 8 bytes.
	p = p + 2;
	cout << p  << endl;
	//Thus, when an integer is added to a pointer variable, the value of the pointer variable is incremented by the integer times the size of the data type or structure to which the pointer is pointing. 
	//Similarly, when an integer is subtracted from a pointer variable, the value of the pointer variable is decremented by the integer times the size of the data type or structure to which the pointer is pointing
	
	
}

void ptrArray(){
	int *p;
	//allocates 10 contiguous memory locations, each of type int, and stores the address of the first memory location into p.
 p = new int[10];
 
 //stores 25 into the first memory location
  *p = 25;
  cout << p[0] << " " << p[1] << endl;
  //Increment is used to access compenents of array.
  p++; //next memory location. (THIS DOES NOT WORK)
   
  *p = 35; //p[1] assigned value of 35.
 cout << p[0] << " " << p[1] << endl;
 
 for(int j = 0; j < 10; j++){
 	p[j] = j;
 	cout << &p[j] << " " << p[j] << endl;
 }
  
  
}

int main(){
	
//	point2int();

//	initializeArray();
//	int retAS = initializeArray(); //returns size of array and calls function

//	pointersNstructs();

// nullPtr();

// dynoVar(); //allocate & dallocate memory

//incByByte();
ptrArray();

}
