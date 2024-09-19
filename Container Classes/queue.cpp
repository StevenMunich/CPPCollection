#include <iostream>
#include <queue>
using namespace std;

//QUEUE is FIFO - First In First Out

void print(std::queue<int> que){
	while(!que.empty()){ //while que is not empty
		cout << que.front() << endl; //print from front of que
		que.pop(); //Remove from the front
	}
}


int main(){
	
	std::queue<int> que;
	
	for(int i=2; i< 5; i++)
	que.push(i); // add to END of que
	
	print(que);
	
	
}
