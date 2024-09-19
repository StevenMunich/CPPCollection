#include <iostream>

using namespace std;

int PtrFun(int a){ cout << "magic access: to" << &PtrFun << endl << "Value passed is: " << a;
}

int Pointer2Pointer(){
	int var = 300;
	int *ptr;
	int **pptr;
}

int Func(){
	 const int SIZE = 8;
	 int array[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};
	 int leaks = 69;
	 int *numPtr = nullptr;
	 int count;
	 
	 //cout << "pointers address is: " << &numPtr << endl;
	 //cout << *numPtr << " dereffed. value is: " << numPtr << endl;
	 numPtr = array;
	 
	  cout << *numPtr << " dereffed. value is: " << numPtr << endl;
	  //display address of first element
	 cout << numPtr << endl;
	 
	 //use pointer to display array's contents
	 for(count = 0; count < SIZE; count++){
	 	cout << *numPtr << " is the value, address is: " << numPtr << endl;
	 	numPtr++;
	 }
	 //Going out of bounds on array to access "leaks" variable in memory
	 for(count = 0; count < 4; count++){
	 
	 cout << *numPtr << " is dereferenced, address is: " << numPtr << endl;
	 numPtr++;
	}
	cout << "Address of leaks is: "  << &leaks << endl;
	auto PtrFun1 = PtrFun;
	cout << &PtrFun1;
}

