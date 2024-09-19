#include <iostream>
#include <string>
using namespace std;

class Cat{
    public:
    int age;
    string name;
   
  virtual  void meow(){
        cout << endl;
        cout << ('mao"');
    }
 
 };// end of Cat

class kitten : Cat{
    
    public:
    void meow(){
        cout << "mew";
        }
    };

int main(int argc, char *argv[])
{
	
	Cat cGull;
	cGull.age = 7;
	cout << "gg" << cGull.age << endl;
	
	kitten K;
	K.meow();
	
}