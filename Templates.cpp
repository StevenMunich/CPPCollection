#include <iostream>
#include <string.h>
#include <stdio.h>
#include <array>
using namespace std;

template<typename T> //template kinda works like generics.
void printType(T value){
	cout << value << endl;
}

int main(){
	
	printType("Hello templats");
	printType(12.5f);
	printType(68);
}
