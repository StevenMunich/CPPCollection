#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class student{
	public: int age;
};

int displayLargest(vector<student> v1){
	int largest = 1;	
	for(int i=0; i < v1.size(); i++)
	if(v1[i].age > largest)
	largest = v1[i].age;	
	return largest;	//return v1[4].age
}

int displaySmallest(vector<student> v1){
	int smallest = v1[0].age;
	
	for(int i=0; i < v1.size(); i++)
	if(v1[i].age < smallest)
	smallest = v1[i].age;
	return smallest;//return v1[0].age
}

int sort(vector<student> v1){

//PREVIOUS WORK
/*
	for(int i=0; i < v1.size(); i++)
	if(v1[i].age > v1[i+1].age){
		int temp = v1[i].age;
		v1[i].age = v1[i+1].age;
		v1[i+1].age = temp;
	}
	
	for(int i=0; i < v1.size(); i++)
	cout << v1[i].age  << endl; */
	
	vector<int> age;
	for(int i=0; i < v1.size(); i++)
	age.push_back(v1[i].age);
	
	sort(age.begin(), age.end());
	for(auto x: age)
	cout << x << endl;
}


int main(){
	
	int input;
	
	
	vector<student> v1; //empty vector
	
	if(v1.empty())
	cout << "Enter the age for 5 students" << endl;
	
	
	for(int i =1; i <=5; i++){
		cout << "#" << i << ":";
		cin >> input;
	student myStudent;
	myStudent.age = input;
	v1.push_back(myStudent);
	
	
		
		
	}
	
	sort(v1);
//	for(int i = 0; i<v1.size(); i++)
//	cout << v1[i].age << endl;
	int smallest = displaySmallest(v1);
	cout << "Youngest Student: " << smallest << endl;	
	int largest = displayLargest(v1);
	cout << "Oldest Student: " << largest << endl;


	int total = 0;
	
	for(int i=0; i < v1.size(); i++)
		total += v1[i].age;
		
	cout << "Total is: " << total << endl;
	
	int average = total / v1.size();
	cout << "Average is: " << average << endl;
	
	cin.get();

}
