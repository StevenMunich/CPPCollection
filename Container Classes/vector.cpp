#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int passVect(vector<int> v1){ //BY VALUE
	
	cout << "Vector passed by value \n";
	
	for(int i=0; i < v1.size(); i++)
	v1[i] = 7;
	
	for(auto x: v1)
	cout << x << endl;
	
}

int passVectRef(vector<int> &v1){
	cout << "Vector passed by reference \n";
	
	for(int i=0; i < v1.size(); i++)
	v1[i] = 69;
	
	for(auto x: v1)
	cout << x << endl;
}

int passVectConst(const vector<int> &v1){ //makes it read only
	cout << "Vector passed by CONSTANT reference. v1 in main will not be modified \n";
//	for(int i=0; i < v1.size(); i++)
//	v1[i] = 420;
	
	for(auto x: v1)
	cout << x << endl;
}



int main(){
	
	vector<int> v1; //empty vector
	
	if(v1.empty())
	cout << "v1 is empty" << endl;
	
	for(int i =1; i <=5; i++)
	v1.push_back(i);
	
	for(int i = 0; i<v1.size(); i++)
	cout << v1.at(i) << endl;
	
	
/* 
//---------------------------EXPERIMENTS TO UNDERSTAND vector------------------------------
	
passVect(v1);
cout << "printing values of vector in main: ";
for(auto x: v1)
cout << x << " ";
cout << endl;

passVectRef(v1);
cout << "printing values of vector in main: ";
for(auto x: v1)
cout << x << " ";
cout << endl;

passVectConst(v1);
cout << "printing values of vector in main: ";
for(auto x: v1)
cout << x << " ";
cout << endl;

/*
	
}
