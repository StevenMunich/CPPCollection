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
	
	for(int i=0; i < arraySize; i++){
		if(*p %2 !=0){
			*p = 0;
			//*(p+1) = 0;
		}
		cout << *p << endl;
		p++;
		
	}
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

/* // QUESTIOn 2
char *s2 = "hello";
char *s1;
cout << strlen(s2);
s1 = new char[strlen(s2)];
strcpy(s1, s2);
*/
/* //QUESTION 3
int intArray[] = {1, 2, 3}, *p = intArray;
cout << p << endl;
	*p++;
	(*p)++;
	
	cout << intArray[0] << endl;
	cout << intArray[1] << endl;
	cout << intArray[2] << endl;
	cout << p;
	*/
	
	/* QUESTION 4-1
	int SIZE = 9;
	int intArray[SIZE] = {1, 2,3,4,5,6,7,8,9};
	sumArray(intArray, SIZE);
	*/
	int SIZE = 9;
	int intArray[SIZE] = {1, 2,3,4,5,6,7,8,9};
//	removeOdds(intArray, SIZE);
	
}
