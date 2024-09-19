#include <iostream>

using namespace std;


class IntSLLNode {
public:
	IntSLLNode() {
		next = 0;
	}
	IntSLLNode(int i, double d, IntSLLNode* in = 0) {
		info = i; next = in;
	}
	
	int info;
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
			//if(head != NULL)
			//delete head;
			head = p;
		}
	}

	//functions
	void addTohead(int el, double d) {
		head = new IntSLLNode(el, d, head);
		if (tail == 0)
			tail = head;
	}
	void addToTail(int el, double d) {
		if (tail != 0) {
			tail->next = new IntSLLNode(el, d);
			tail = tail->next;
		}

	}

	//insert other functions here

	void displayList() const {
		IntSLLNode* tmp;
		//	cout << head->info.getRadius() << endl;
		//for (tmp = head; tmp->next != 0; tmp = tmp->next)
		
	}

public:
	IntSLLNode* head, * tail;

	void CompareLL(IntSLList list1, IntSLList list2) {
		IntSLLNode* tmp = new IntSLLNode;
		IntSLLNode* tmp2 = new IntSLLNode;
		cout << "function called\n";
		for (tmp = list1.head; tmp->next != NULL; tmp = tmp->next) {
			for (tmp2 = list2.head; tmp2->next != NULL; tmp2 = tmp2->next) {

				cout << "Comparing: " << tmp->info << " and " << tmp2->info << endl;
				if (tmp->info == tmp2->info)
					cout << "Found a matcha at: " << tmp->info << endl;
			}
		}
		//Compare Tails
		for (tmp2 = list2.head; tmp2->next != NULL; tmp2 = tmp2->next)
			if (tmp2->info == list1.tail->info)
				cout << "Match at tail: " << list1.tail->info << endl;

		for (tmp = list1.head; tmp->next != NULL; tmp = tmp->next)
			if (tmp->info == list2.tail->info)
				cout << "Match at tail: " << list2.tail->info << endl;

		delete tmp;
		delete tmp2;
	}

};

//non member function
void CompareLL(IntSLList list1, IntSLList list2) {
	IntSLLNode* tmp;
	IntSLLNode* tmp2;
	cout << "function called\n";
	for (tmp = list1.head; tmp->next != NULL; tmp = tmp->next) {
		for (tmp2 = list2.head; tmp2->next != NULL; tmp2 = tmp2->next) {

			cout << "Comparing: " << tmp->info << " and " << tmp2->info << endl;
			if (tmp->info == tmp2->info)
				cout << "Found a matcha at: " << tmp->info << endl;
		}
	}
	//Compare Tails
	for (tmp2 = list2.head; tmp2->next != NULL; tmp2 = tmp2->next)
		if (tmp2->info == list1.tail->info)
			cout << "Match at tail: " << list1.tail->info << endl;

	for (tmp = list1.head; tmp->next != NULL; tmp = tmp->next)
		if (tmp->info == list2.tail->info)
			cout << "Match at tail: " << list2.tail->info << endl;
}




int main() {

	//use pointers and delete list.
	IntSLList List1;
	IntSLList List2;
	//List 1
	for (double x = 0; x < 5; x++)
		List1.addTohead(x, x / 10.0);
	//List 2
	for (double x = 2; x < 7; x++) {
		List2.addTohead(x, x / 10.0);
	//	cout << x << endl;
	}
		
	
	
	//CompareLL(List1, List2);

	List1.CompareLL(List1, List2);

	cout << "Everything Ran. AT return 0;" << endl; //Everything has run
	return 0;
}