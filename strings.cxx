#include <iostream>
#include <string>
#include <vector>

using namespace std;

void functionP(int a){
    cout << "pointer function: " << a <<endl;
    }
void printValues(int value){
    cout << value << endl;
}
void ForEach(const vector<int>& values, void(*func)(int)){
    for(int value : values)
     func(value);
}


int main(int argc, char *argv[])
{
	string hello = "hello steven";
//	cout << hello.substr(1, 3);
	

	//backwards
	int i = hello.length(); //5
	string rev;
	int ac = 0; //array counter
	
	do{
	    rev +=hello.substr(i, 1);
	    i--;
	    
	    } while (i != -1);
cout << rev << endl;


cout << "loop gone";

//pointers
int* pt1 = &i;
int b = 9;
*pt1 = 7;
cout << endl << i;
cout << endl << &i << endl << *pt1 << endl;
*pt1 = b;
cout << i << endl;

cout << "pointers with function" << endl;
//pointers with functions
//can use & symbol or not
auto pttFun = functionP; 
pttFun(5);
void(*pt2Fun)(int);
pt2Fun = functionP;
pt2Fun(7);
typedef void(*pt3Fun)(int) ;
pt3Fun varFun = &functionP;
varFun(8);


//why we would use function pointers
vector<int> myNumbers { 2, 5, 9};
ForEach(myNumbers, printValues);
//lambda w/ function pointer in ForEach. no need for PrintValues function
ForEach(myNumbers, [] (int value){
    cout << value << endl;
    });
//more lamdas
auto lamda = [] (int value){ 
         cout << value << endl;
};
ForEach(myNumbers, lamda);

cout << "lamda 1 & 2\n";
//pass a byval and b byref
int a = 7;
b = 3;
cout << a << endl << b << endl;
auto lamda1 = [a, &b] (){
    // can not re-assign a
    b++;
    cout << a << endl << b << endl;
};
lamda1();
auto lambda2 = [a, &b] () mutable {
    a++;
    b--;
    cout << a << endl << b << endl;
    };
lambda2();
cout << a << endl << b << endl;

}
