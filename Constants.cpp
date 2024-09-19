#include <iostream>
using namespace std;

class Entity{
	private: int x;
	public:
		getX() const{ //makes read-only, can only do this with classes
		return x;
		}
};

int main(){
	const int MAX_AGE = 90;
	
	const int* a = new int; // pointer to a const, can change value of pointer but not contents it points to
	
//	*a = 2;
	a = (int*)&MAX_AGE; //can change what the pointer is pointing to, but not the contents
	cout << *a << endl;
	
	int* const b = new int; // a const pointer, can not change value of pointer
	
	
}
