#include <iostream>
#include <string.h>
#include <stdio.h>
#include <array>

using namespace std;

//page 21
class Class1{
	public:
		virtual void f(){
			cout << "function f() in class1" << endl;
		}
		void g(){
				cout << "function g() in class1" << endl;
		}
};

class Class2{
	public:
		virtual void f(){
			cout << "function f() in class2" << endl;
		}
		void g(){
				cout << "function g() in class2" << endl;
		}
};
class Class3{
	public:
		virtual void h(){
				cout << "function h() in class3" << endl;
		}
};

double f(double x){
	return 2*x;
}
double *f1(double i){
	//returns a pointer
}

double sum(double (*f)(double), int n, int m){
	double result = 0;
	for(int i=n; i<=m; i++)
	result += f(i);
	return result;
}

int main(){
	
//	cout << f(3); // pointer to function
	//cout << (*f)(7); // function call
//	cout << *f; // the function itself
//cout << sum(f,1,5) << endl;

//page 21 Objects and polymorphism
Class1 object1, *p;
Class2 object2;
Class3 object3;

p= &object1;
p->f();
p->g();
p = (Class1*) &object2;
p->f();
p->g();
//possible abnormal behaviour with class3
p = (Class1*) &object3;
p->f(); //abnormal behaviour, function h from class 3 is called.
p->g();
//p->h(); //there is no h function in class1

}
