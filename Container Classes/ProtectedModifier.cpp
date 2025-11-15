#include <iostream>
using namespace std;

class BaseClass{
	public:
		int age = 33;
               void passBaseClass(BaseClass &joint)
               {
				joint.level = 77;
				cout << joint.level << endl << this->level << endl;
				}
				int getLevel(){
				return this->level;}
protected:
int level = 55;
};
class ChildClass : public BaseClass{
	int getage (){ return this->age;
	}
	
};
int main(){
BaseClass b, passMe;
b.passBaseClass(passMe);
cout << passMe.getLevel() << endl;

ChildClass c;
cout << c.age;
}

