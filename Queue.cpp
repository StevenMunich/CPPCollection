//#ifdef DLL_QUEUE
//#define DLL_QUEUE

#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

using namespace std;


class circle {
public:
	circle(double r) {
		radius = r;
	}
	circle() {
		radius = 0;
	}; //count++; idNum = count;

	double getRadius() { return radius; }
	void setRadius(double r) { radius = r; }
	double getArea() { return radius * radius * 3.14; }

private:
	double radius;
	int idNum;
};

template<class T>
class Queue {
public:
	Queue(){} //empty constructor
	void clear() { 
		first.clear();
	}
	bool isEmpty() const {
		return first.empty();
	}
	T& front() {
		return first.front();
	}
	T dequeue() {
		T el = first.front();
		first.pop_front();
		return el;
	}
	void enqueue(const T el) {
		first.push_back(el);
	}

private:
	list < T> first;
};

//template <class T>
void DisplayQueue(const Queue<circle> q1) {

	Queue<circle> q2 = q1;
	int counter = 0;
	while (!q2.isEmpty()) {
		counter++;
		cout << "Element number " << counter << ": " << q2.front().getRadius() << endl;
		q2.dequeue();
	}
}

void displayMenu() {
	cout << "1. Add to Queue \n2. Display Contents of Queue \n3. Remove from Queue \n Enter 999 to quit.\n";
}

int main() {
	circle *circle3 = new circle(3.33);
	circle *circle2 = new circle(2.22);
	circle *circle1 = new circle(1.11);

	Queue<circle> queue1;
	queue1.enqueue(*circle1);
	queue1.enqueue(*circle2);
	queue1.enqueue(*circle3);
	
	DisplayQueue(queue1);
	cout << "is the current queue. \n";

	//main menu
	displayMenu();
	double i = 0;
	while (i != 999) {
		cin >> i;
		if (i == 1) {
			cout << "Enter radius of circle: ";
			cin >> i;
			circle *qcircle = new circle(i);
			queue1.enqueue(i);
			cout << "New circle " << qcircle->getRadius() << " added to queue\n";
			delete qcircle;
		} else if (i==2) { 
			DisplayQueue(queue1); 
		}
		else if (i == 3) {
			if (queue1.isEmpty()) break;
			circle* rcircle = new circle(queue1.dequeue());

			cout << "Contents: " << rcircle->getRadius() << " removed from queue" << endl;
			delete rcircle;
		}
		
	}
	cout << "end of file reached";
	return 0;


}

//#endif