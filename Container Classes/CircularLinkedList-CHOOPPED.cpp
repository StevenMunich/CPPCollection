#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class CircularLinkedList {
private:
	Node* head;
public:
	CircularLinkedList() {
		head = nullptr;
	}

	void insert(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
			head->next = head;
			cout << "new head created\n";
		} else {
			Node* temp = head; 
			cout << "in Else Statement\n";
			int i = 0;
			while (temp->next != head) {
				temp = temp->next;
				cout << "in temp = temp->next loop# " << i << " temp value " << temp->data <<"\n";
				i++;
			}
			temp->next = newNode; 
			newNode->next = head;
		}
	}

	void print() {
		if (head == nullptr) {
			cout << "List is empty" << endl;
		} else {
			Node* temp = head;
			do {
				cout << temp->data << " points to ->" <<temp->next->data << endl;
				temp = temp->next;
			} while (temp != head);
			cout << endl;
		}
	}
};

int main() {
	CircularLinkedList cll;
	cll.insert(1);
	cll.insert(2);
	cll.insert(3);
	cll.insert(4);
	cll.insert(5);
	cll.print(); 
	return 0;
}

