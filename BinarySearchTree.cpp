//Steven Munich
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

//Circle Object
class circle {
public:
	//constructors
	circle(double r) {radius = r;	}
	circle() {radius = 0;	}; 
	//basic functions
	double getRadius() { return radius; }
	void setRadius(double r) { radius = r; }
	double getArea() { return radius * radius * 3.14; }
private:
	double radius;
};

//Binary Search Node
template<class T>
class BSTNode {
public:   
	BSTNode() { //Constructors
		left = right = 0;
	} 
	  BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
		  el = e; left = l; right = r;
	  }
	  //variables of Node
	  T el;    
	  BSTNode<T> *left, *right;
};

template<class T>
class BST {
public:
	
	BST() { root = 0; }
	~BST() { clear(); }
	void clear() { 
		//clear(root);  // CODE: C2660 Description: 'BST<circle::clear':function does not tke 1 arguments
		root = 0; 
	}
	void clearAll(BSTNode<T> *p) {
		//postorder(root);   // Figure 6.11
		if (p != 0) {
			postorder(p->left);
			postorder(p->right);
			visit(p);
		}
	}
	bool isEmpty() const {
		return root == 0; 
	}

	void insert(circle el) {
		BSTNode<circle>* p = root, * prev = 0;

		while (p != 0) { //find a place for inserting a new node;
			prev = p;
			if (el.getRadius() < p->el.getRadius())
				p = p->left;
			else p = p->right;
		}
		//creates the new node
		if(root == 0)
			root = new BSTNode<circle>(el);
		else if (el.getRadius() < prev->el.getRadius())
			prev->left = new BSTNode<circle>(el);
		else 
			prev->right = new BSTNode<circle>(el);

	}

	bool search(circle el) {
		BSTNode<circle>* p = root;
		if (root == 0) return false; //empty tree

		while (p != 0) { //loop to traverse tree

			if (p->el.getRadius() == el.getRadius()) return true; //element found

			if (el.getRadius() < p->el.getRadius()) 
				p = p->left; //go to the left
			if (el.getRadius() > p->el.getRadius()) 
				p = p->right; //go to the right
		}
		//if we go through loop and nothing is found we return false
		return false;
	}

	
	void preorder(BSTNode<circle> *p) { // Figure 6.11
	//preorder(root); 
		if (p != 0) {
			visit(p);
			preorder(p->left); //if p=0 recursive function returns and checks right
			preorder(p->right);
		}
	}
	
	void inorder(BSTNode<circle> *p) {
		//inorder(root);  // Figure 6.11
		if (p != 0) {
			inorder(p->left);
			visit(p);
			inorder(p->right);
		}
	}
	
	void postorder(BSTNode<circle> *p) {
		//postorder(root);   // Figure 6.11
		if (p != 0) {
			postorder(p->left);
			postorder(p->right);
			visit(p);
		}

	}

	//ROOT NODE
	BSTNode<circle>* root;
	//prints the contents of nodes
	void visit(BSTNode<circle>* p) { cout << p->el.getRadius() << endl; }
};
//End of BST


int main() {
	
	//creates a tree of circles 
	BST<circle> tree1;

	//Main Loop
	double i = 0;
	while (i != 999) {
		cout << "\nMain menu: \n1. Add to Binary tree \n2. Search for Element \n3. Display Tree\n999 to quit\nInput:";
		cin >> i;
		if (i == 1) {
			cout << "Enter radius of circle: ";
			cin >> i;
			circle* qcircle = new circle(i);
			tree1.insert(*qcircle); //Node is created in function
			cout << "New circle " << qcircle->getRadius() << " added to the tree\n";
		}
		else if (i == 2) {
			cout << "Enter radius of circle: ";
			cin >> i;
			bool found = tree1.search(i);
			if (found == 0) cout << i << " was not found in Tree.\n";
			if (found == 1) cout << i << " was found in Tree.\n";
		}
		else if (i == 3) {
			cout << "preorder: ";
			tree1.preorder(tree1.root);
			cout << "\ninorder: ";
			tree1.inorder(tree1.root);
			cout << "\npostorder: ";
			tree1.postorder(tree1.root);
		}
		else if (i==4){
			BSTNode<circle> *p = tree1.root;
			BSTNode<circle> *l = tree1.root->left;	
			BSTNode<circle> *r = tree1.root->right;
			//cout << "\nDeleting tree with no leaks: root=" << *p << ". left=" << *l << ". right=" << *r << endl; //endl flushes stream
			
		} //END IF

	}//END WHILE

	return 0;
} 
