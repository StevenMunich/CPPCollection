#include <iostream>
#include <stack>
using namespace std;

//STACK is LIFO - Last In First Out

void print(std::stack<int> stk){
	while(!stk.empty()){ //while que is not empty
		cout << stk.top() << endl; //print from front of que
		stk.pop(); //Remove from the front
	}
}


int main(){
	
	std::stack<int> stk;
	
	for(int i=2; i< 5; i++)
	stk.push(i); // add to END of que
	
	print(stk);
	
	
}
