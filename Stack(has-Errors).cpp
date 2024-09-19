#include <iostream>
#include <list>

using namespace std;

class circle {
public :
	circle(double r) { radius = r; }
	double getRadius() { return radius; }
	void setRadius(double d) { radius = d; }
	double getArea() { return radius * radius * 3.14; }
private:
	double radius;
};

template<class T>
class LLstack {
public:
	LLstack(){}
	void clear(){ 
		lst.clear();
	}
	bool isEmpty() const {
		return lst.empty();
	}
	T& topEl() {
		return lst.back();
	}
	T pop() {
		T el = lst.back();
		lst.pop_back();
		return el;
	}
	void push(const T& el) {
		lst.push_back(el);
		
	}
	int size = lst.size();

private:
	list<T> lst;
	
};


//template <class T>
void DisplayStackElement(const LLstack<circle>& q1) {

	LLstack<circle> q2 = q1;
	int counter = 0;
	
	while (!q2.isEmpty()) {
		counter++;
		cout << "Element number " << counter << ": Radius = " << q2.topEl().getRadius() << " : area = " << q2.topEl().getArea() << endl;
		q2.pop();
	}
}


void displayMenu() {
	cout << "MAIN MENU\n1. Add to Stack \n2. Display Contents of Stack \n3. Remove from Top of Stack \n Enter 999 to quit.\n";
}

int main() {
	circle* circle3 = new circle(3.33);
	circle* circle2 = new circle(2.22);
	circle* circle1 = new circle(1.11);
	//default elements of the stack
	LLstack<circle> stack1;
	stack1.push(*circle1);
	stack1.push(*circle2);
	stack1.push(*circle3);
	
	//main menu
	displayMenu();
	double i = 0;
	while (i != 999) {
		cin >> i;
		if (i == 1) {
			cout << "Enter radius of circle: ";
			cin >> i;
			circle* qcircle = new circle(i);
			stack1.push(i);
			cout << "New circle: radius = " << qcircle->getRadius() << " : area = " 
				<< qcircle->getArea() << " added to the top of stack\n";
			delete qcircle;
		}
		else if (i == 2) {
			DisplayStackElement(stack1);
		}
		else if (i == 3) {
			if (stack1.isEmpty()) break;
			circle* rcircle = new circle(stack1.pop());
			cout << "Contents: radius = " << rcircle->getRadius() << " : area = " 
				<< rcircle->getArea() << " removed from the top of the stack." << endl;
			delete rcircle;
		}

	}
	cout << "end of file reached";


	return 0;
}
