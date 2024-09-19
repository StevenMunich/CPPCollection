#include <iostream>
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


class IntSLLNode {
public:
	IntSLLNode() {
		next = 0;
	}
	IntSLLNode(circle i, double d, IntSLLNode* in = 0) {
		info = i; next = in; info.setRadius(d);
	}
	circle info;
	IntSLLNode* next;

};


class IntSLList {
public:
	//constructors and isEmpty function
	IntSLList() {
		head = tail = 0;
	}
	int isEmpty() {
		return head == 0;
	}
	~IntSLList() {
		for (IntSLLNode* p; !isEmpty(); ) {
			p = head->next;
			delete head;
			head = p;
		}
	}

	//functions
	void addTohead(circle el, double d) {
		head = new IntSLLNode(el,d, head);
		if (tail == 0)
			tail = head;
	}
	void RemoveFromhead() {
		if(head != 0){
			IntSLLNode *tmp = head;
			head = head->next; 
			delete tmp;
		}	
	}
	void addToTail(circle el, double d) {
		if (tail != 0) {
			tail->next = new IntSLLNode(el, d);
			tail = tail->next;
		}

	}
	void RemoveFromTail() {
		if (tail != 0) {
			IntSLLNode *tmp = head;
			while(tmp->next != tail){
				tmp = tmp->next;
			}
				delete tmp->next;
				tail = tmp;
				
}
	}
	
	//inset other functions here

	void displayList() const {
		IntSLLNode* tmp;
	//	cout << head->info.getRadius() << endl;
		for (tmp = head; tmp->next != 0; tmp = tmp->next)
			cout << "Radius = " << tmp->info.getRadius() << " Area = " << tmp->info.getArea() << endl;

		cout << "Radius = " << tail->info.getRadius() << " Area = " << tail->info.getArea() << endl;
		//cout << tmp->next->info.getRadius() << endl; //nullPtr error
	}

private:
	IntSLLNode* head, * tail;


};

int main() 
{
	IntSLList linkedList;
	
	for (double i = 1; i < 5; i++) {
		circle* pCircle = new circle(i + .5);
		linkedList.addTohead(*pCircle, pCircle->getRadius());
		delete pCircle;
	}

	linkedList.displayList();
	cout << "Are the current Circles in the list." << endl;
	
	double input;
	do { //Main Loop
		
		cout << "Main Menu: type 999 to quit \n 1 to add to head \n 2 to add to tail \n 3 to display List \n 4 remove from head\n5 to remove from tail";
		
		cin >> input;
		if (input == 1) {
			cout << "Add to head: Enter a radius ";
			cin >> input;
			circle *AddingHeadCircle = new circle(input);
			linkedList.addTohead(*AddingHeadCircle, AddingHeadCircle->getRadius());
			cout << AddingHeadCircle->getRadius() << " added to front of list. \n";
			delete AddingHeadCircle;
		}
		else if (input == 2) {
			cout << "Add to tail: Enter a radius ";
			cin >> input;
			circle* AddingHeadCircle = new circle(input);
			linkedList.addToTail(*AddingHeadCircle, AddingHeadCircle->getRadius());
			cout << AddingHeadCircle->getRadius() << " added to back of list. \n";
			delete AddingHeadCircle;
		}
		else if (input == 3) {
			linkedList.displayList();
		}else if (input == 4) { linkedList.RemoveFromhead();
		}else if (input == 5) {	linkedList.RemoveFromTail();}	
	} while (input != 999);
} //End of Main




//---------------------------------Old Code inside of main
/*

/*
	circle circle1(1.11); //need help using pointers to use less memory, call Johnson.
	circle circle2(2.22);
	circle circle3(3.33);
	circle* circle4 = new circle(4.33);
	

	linkedList.addTohead(circle1, circle1.getRadius()); //becomes tail
	linkedList.addTohead(circle2, circle2.getRadius());
	linkedList.addTohead(circle3, circle3.getRadius());
	linkedList.addTohead(*circle4, circle4->getRadius());
	delete circle4;
	*/

	//linkedList.addToTail(circle1, circle1.getRadius());




//---------------------------------Unused Functions for this program
/*
	double deleteFromHead() {  //deletes and returns radius
		circle el = head->info;
		IntSLLNode* tmp = head;
		if (head == tail)
			head = tail = 0;
		else head = head->next;
		delete tmp;
		return el.getRadius();

	}

	//started here sunday

	double deleteFromTail() {
		circle el = tail->info;
		if (head == tail) {
			delete head;
			head = tail = 0;
		} else {
			IntSLLNode* tmp;
			for (tmp = head; tmp->next != tail; tmp = tmp->next);
			delete tail;
			tail = tmp->next;
			tail->next = 0;
		}
		return el.getRadius();
	}
	//This function may not work
	void deleteNode(circle el) {
		if(head !=0) //if non empty list
			if (head == tail && el.getRadius() == head->info.getRadius()) { //if only 1 node
				delete head;
				head = tail = 0;
			}
			else if (el.getRadius() == head->info.getRadius()) { //more than 1 node
				IntSLLNode* tmp = head;
				head = head->next;
				delete tmp; //old head is deleted
			}
			else //if more than one node in list
			{
				IntSLLNode* pred, * tmp;
				for (pred = head; tmp = head->next; //and a nonhead node
					tmp != 0 && !(tmp->info.getRadius() == el.getRadius()), //is deleted
					pred = pred->next, tmp = tmp->next);
				if (tmp != 0) {
					pred->next = tmp->next;
					if (tmp == tail)
						tail = pred;
					delete tmp;
				}
			}

	}
	bool isInList(circle el) const {
		IntSLLNode* tmp;
		for (tmp = head; tmp != 0 && !(tmp->info.getRadius() == el.getRadius()); tmp = tmp->next);
		return tmp != 0;
	}
	*/
