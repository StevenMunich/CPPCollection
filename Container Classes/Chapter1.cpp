#include <iostream>
#include <string.h>
#include <stdio.h>
#include <array>
using namespace std;

//Question 4.1
void sumArray(int intArray[], int arraySize){
	int *p = intArray;
	int sum = 0;
	
	for(int i=0; i < arraySize; i++){
		sum += *p;
		p++;
	}
	cout << sum;
	delete p;
}

void removeOdds(int intArray[], int arraySize){
	int *p = intArray;
	int counterForNewArray = 0;
	
	//turns value of odds to zero
	for(int i=0; i < arraySize; i++){
		if(*p %2 !=0){
			*p = 0;
			//*(p+1) = 0;
			counterForNewArray++;
		}
		cout << *p << endl;
		p++;
		
	}
	counterForNewArray--;
	//create new array to store evens and remove zeros
	int newArray[counterForNewArray];
	int *p2 = newArray;
	p = intArray;
		for(int i=0; i < arraySize; i++){

		if(*p !=0){
			*p2 = *p;
			p2++;
		}
		//cout << *p2 << endl;
		p++;	
		
	}
	//displays content of new array
	p2 = newArray;
	for(int i=0; i < counterForNewArray; i++){
		cout << *p2 << endl;
		p2++;
	}
	
	//cout << counterForNewArray;
	//return pointer for new array
}

int *ptArray(int *p, int size){
	
	int *q;
	q=p;
	
	for(int i=0; i <size;i++){
	*p = i;
	cout << *p << endl;
	p++;
	}
	
cout << p << endl << q << endl;
	
	return q;
}

int main(){

/* //QUESTION 1
	int i, *p, *q;
	p = &i; //A
	i = *&*p; //D	
	p = &*&i; //G
	
	q = *&p; //J
	q = &*p; //K
*/

 // QUESTIOn 2
/*
string s2 = "hello";
char *s1;
//cout << strlen(s2);
s1 = new char[strlen(s2)];
strcpy(s1, s2);

*/


/*
 //QUESTION 3
int intArray[] = {1, 2, 3}, *p = intArray;
cout << p << endl;
	*p++;
	(*p)++; //must use parenthesis to derefrence
	
	cout << intArray[0] << endl;
	cout << intArray[1] << endl;
	cout << intArray[2] << endl;
	cout << p;
	
	
*/	
	
	
	/* QUESTION 4-1
	int SIZE = 9;
	int intArray[SIZE] = {1, 2,3,4,5,6,7,8,9};
	sumArray(intArray, SIZE);

	

	const int SIZE = 9;
	int intArray[SIZE] = {1, 2,3,4,5,6,7,8,9};
//	removeOdds(intArray, SIZE);

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

delete p;
delete q;

//address OF pointers: ----------------EXTRA---------------
//cout << &p << endl; 
//cout << &q << endl;
	
//	cout << *(p+10) << endl;


*/
//QUESTION 6

int i = 7;
int j = 7;

int *p = &i;
int *q = &j;

if(p==q) //compares the values of the pointers, which is a memory address.
cout << " compares the values of the pointers, which is a memory address";
if(*p==*q) //compares the values of the variable the pointers are pointing too.
cout << " compares the values of the variable the pointers are pointing too.";



 //CUT FOR QUESTION 2	
}
