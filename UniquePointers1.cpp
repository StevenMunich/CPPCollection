// C++ Program to implement unique_ptr 
#include <iostream> 
#include <memory> 
using namespace std; 

struct A { 
	void printA() { cout << "A struct...." << endl; } 
}; 

class Cat{
	public:
		int age = 8;
		char* name;
		
		Cat(){
			cout << "Meow: "  << endl;
		}

		~Cat(){
			cout << "deleted\n"; 
		}
};

int main() 
{ 
	unique_ptr<A> p1(new A); 
	unique_ptr<Cat> *seagull = new unique_ptr<Cat>;
	cout << 
	p1->printA(); 

	// displays address of the containing pointer 
	cout << p1.get() << endl; 
	return 0; 
}

