#include <iostream>
using namespace std;



class cat{

	public:
	int age;
	char* name;
	
	cat(int i, char* s ){
		age = i;
		name = s;
	}
};

int main(){
	
	cat *Cgull = new cat(3, "Larry");
	cat *ralph = new cat(7, "Ralph");
	
	//Output Cgull
	cout << "Object at: " << Cgull << endl;
	cout << "Age = " << Cgull->age << " at " << &Cgull->age << endl; //pointing to here first
	cout << "name = " << Cgull->name << " at " << &Cgull->name << endl;
	
	//Pointer ++
	Cgull++;
	cout << Cgull << endl;
	Cgull++;  
	cout << "Double increment: " << Cgull << endl; //ralph and cGull equal same address
	cout << "raplh at: " << ralph << endl;
	cout << "Age = " << ralph->age << " at " << &ralph->age << endl; //pointing to here first
	cout << "name = " << ralph->name << " at " << &ralph->name << endl;
	
	cout << "Loop: out of bounds into string literal in memory." << endl;
	for(int i=0; i < sizeof(ralph->name ) + 10; i++) // the +10 makes it leak to string literal at line 24 "Object at:"
		cout << ralph->name[i] << endl;
		
   cout << endl << "now plus 80" << endl;
   for(int i=0; i < sizeof(ralph->name ) + 80; i++) // the +10 makes it leak to string literal at line 24 "Object at:"
		cout << ralph->name[i] << endl;
	
	//
	cout << "cgull name = " << Cgull->name << endl;
		
		
	
	return 0;
}
