#include <iostream>
#include <string.h>
#include <stdio.h>
#include <array>
using namespace std;

int *ptArray(int *p, int size){
	
	int *q;
	q=p;
	
	for(int i=0; i <size;i++){
	*p = i;
	cout << *p << endl;
	p++;
	}
	
cout << p << endl;
	
	return q;
}

int globalV = 42;

void changePointerValue( int** ptr_ptr){
	*ptr_ptr = &globalV;
}

int main(){

int var = 23;
int *pointer2var = &var;
cout << "Value before passing: " << *pointer2var << endl;
changePointerValue(&pointer2var);
cout << "AFter: " << *pointer2var << endl;
return 0;

int SIZE = 9;
int *p, *q;
p = new int[SIZE];
q = p;
cout << p << endl;
for(int i=0; i <SIZE;i++){
	*p = i;
	cout << *p << endl;
	p++;
	
}

p = q;

cout << p << endl;
//returns address of pointer to p
p = ptArray(p, SIZE);
cout << p << endl;
p = q;

//address OF pointers: ----------------EXTRA---------------
cout << &p << endl; 
cout << &q << endl;
	
	cout << *(p+5) << endl;  //prints 5, the 5th element
}
