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
		} else {
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
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
				cout << temp->data << " ";
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
	cll.print(); 
	return 0;
}

