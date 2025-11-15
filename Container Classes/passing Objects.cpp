#include <iostream>
using namespace std;

class classf{
	public:
		classf(){}
		double operator ()(double x){
			return 2*x;
		}
		
	int age;
};

//does powers
double sum2(classf f, int n, int m){
	double result=0;
	for(int i=n; i<= m; i++)
	result += f(i);
	return result;
}

int func1(classf f, int i){
	cout << f.age << endl;
	return i;
}

int main(){
	classf f;
	f.age = 7;
	cout << func1(f, 3) << endl;
	
	
	//function object
	
	classf cf;
	cout << sum2(cf,2,7) << endl;
	cout << sum2(classf(),2,7) << endl;
}
