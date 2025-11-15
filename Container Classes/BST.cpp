//Steven Munich
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

//Circle Object
class circle {
public:
	//constructors
	circle(double r) { radius = r; }
	circle() { radius = 0; };
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
	BSTNode(const T& e, BSTNode<T>* l = 0, BSTNode<T>* r = 0) {
		el = e; left = l; right = r;
	}
	//variables of Node
	T el;
	BSTNode<T>* left, * right;
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
		if (root == 0)
			root = new BSTNode<circle>(el);
		else if (el.getRadius() < prev->el.getRadius())
			prev->left = new BSTNode<circle>(el);
		else
			prev->right = new BSTNode<circle>(el);

	}

	BSTNode<circle>* search(circle el) {
		BSTNode<circle>* p = root;
		if (root == 0) return 0; //empty tree

		while (p != 0) { //loop to traverse tree

			if (p->el.getRadius() == el.getRadius()) return p; //element found

			if (el.getRadius() < p->el.getRadius())
				p = p->left; //go to the left
			if (el.getRadius() > p->el.getRadius())
				p = p->right; //go to the right
		}
		//if we go through loop and nothing is found we return false
		return 0;
	}


	BSTNode<circle>* deleteR(BSTNode<circle>* p, double data) {
		if (p == NULL) return p;

		if (data < p->el.getRadius()) {
			p->left = deleteR(p->left, data);
		}
		else if (data > p->el.getRadius()) {
			p->right = deleteR(p->right, data);
		}
		else {
			if (p->left == NULL) { 
				return p->right;
			}
			if (p->right == NULL) {
				return p->left;
			}
			p->el.setRadius(findSmallestInRightSubTree(p->right));
			p->right = deleteR(p->right, data);			
		}
		return p;
	} //helper function for delete, finds the smallest element in right sub tree.
	double findSmallestInRightSubTree(BSTNode<circle>* p) {
		double d = p->el.getRadius();
		while (p->left != NULL) {
			d = p->left->el.getRadius();
			p = p->left;
		}
		return d;
	}

	void findAndDelete(double el) {
		BSTNode<circle>* node = root, * prev = 0;
		while (node != 0) {
			if (node->el.getRadius() == el) break;
			prev = node;
			if (el < node->el.getRadius()) node = node->left;
			else node = node->right;
		}
		if (node != 0 && node->el.getRadius() == el)
			if (node == root) deleteFromBook(root);
			else if (prev->left == node) deleteFromBook(prev->left);
			else deleteFromBook(prev->right);
		else if (root != 0) cout << el << " is not in tree\n";
		else cout << "Tree is empty\n";
	}
	//HelperFunction
	void deleteFromBook(BSTNode<circle>* node) {
		BSTNode<circle>* tmp = node;
		if (node != 0) {
			if (!node->right)
				node = node->left;
			else if (node->left == 0)
				node = node->right;
			else {
				tmp = node->left;
				while (tmp->right != 0)
					tmp = tmp->right;
				tmp->right = node->right;
				tmp = node;
				node = node->left;
			}
			cout << tmp->el.getRadius() << " deleted";
			delete tmp;
			
		}
	}


	void preorder(BSTNode<circle>* p) { // Figure 6.11
		if (p != 0) {
			visit(p);
			preorder(p->left);
			preorder(p->right);
		}
	}
	void inorder(BSTNode<circle>* p) {   // Figure 6.11
		if (p != NULL) {		
			inorder(p->left);
			visit(p);
			inorder(p->right);
		}
	}
	void postorder(BSTNode<circle>* p) {		 // Figure 6.11
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

	//circles added as default for debugging
	tree1.insert(2.22); //is ROOT NODE
	tree1.insert(3.11);
	tree1.insert(4.44);
	tree1.insert(3.33);
	tree1.insert(5.55);
	tree1.insert(1.22); //can delete and 2.22 will point to 1.11
	tree1.insert(1.11);
	//added to debug when there is only a right child
	tree1.insert(1.12);
	
	cout << "By default values in Binary Tree:\n";
	tree1.inorder(tree1.root);
	//Main Loop
	double i = 0;
	while (i != 999) {
		cout << "\nMain menu: \n1. Add to Binary tree \n2. Search for Element \n3. Display Tree(preorder)";
		cout << "\n4. Display Tree(inorder)\n5. Display Tree(postorder)\n6. Delete Node\n 7. to delete with recursion\n999 to quit\nInput:";
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
			BSTNode<circle>* found = tree1.search(i);
			if (found == 0) cout << i << " was not found in Tree.\n";
			else
				cout << i << " was found in Tree.\n Object Reference" << found->el.getRadius();// << "\n right pointer: "
				//<< found->right << "with value of: " << found->right->el.getRadius();
		}
		else if (i == 3) {
			cout << "preorder: ";
			tree1.preorder(tree1.root);
		}
		else if (i == 4) {
			cout << "\ninorder: ";
			tree1.inorder(tree1.root);
		} else if (i==5){
			cout << "\npostorder: ";
			tree1.postorder(tree1.root);
		}
		else if (i == 6) {
			cout << "Enter radius of circle to delete: ";
			cin >> i;
			tree1.deleteR(tree1.root, i);			
		}//END IF
	}//END WHILE
	return 0;
}

/* ------------------------------OLD & FAILED CODE-----------------------------
 //test - includes find parent
	int deleteNodeTest(circle el) {
		BSTNode<circle>* p = search(el);
		BSTNode<circle>* parent = findParent(el);
		if (p == 0) { //element not found.
			cout << "can not delete because it does not exist\n";
			return 0; 
		}
		//if element is found how do we handle it?

		//Element to delete has no children
		if (p->left == 0 && p->right == 0) {
			//assign zero to parent left so we do not get NUllPtr error from "inorder" function
			
			if (parent->left->el.getRadius() == p->el.getRadius()) {
				parent->left = 0;
				delete p;
			}			
			cout << "object has been deleted\n";
			return 0;
		}

		//Element has one child to the left
		if (p->left != 0 && p->right == 0) {
			//assign zero to parent left so we do not get NUllPtr error from "inorder" function
			if (parent->left->el.getRadius() == p->el.getRadius()) {
				parent->left = p->left;
				delete p;
			}
			cout << "object has been deleted\n";
			return 0;
		}
		
		//Element has one child to the right
		//if (p->left== 0 && p->right != 0) {
			//assign zero to parent left so we do not get NUllPtr error from "inorder" function
		//	if (parent->right->el.getRadius() == p->el.getRadius()) {
		//		parent->right = p->right;
		//		delete p;
		//	}
		//	cout << "object has been deleted\n";
		//	return 0;
		//} //END IF
		
	}
	//Find parent for Test
	BSTNode<circle>* findParent(circle el) {
		BSTNode<circle>* p = root;
		if (root == 0) return 0; //empty tree

		while (p != 0) { //loop to traverse tree

			if (p->left->el.getRadius() == el.getRadius()) return p; //element found
			if (p->right->el.getRadius() == el.getRadius()) return p; //element found
			if (el.getRadius() < p->el.getRadius())
				p = p->left; //go to the left
			if (el.getRadius() > p->el.getRadius())
				p = p->right; //go to the right
		}
		//if we go through loop and nothing is found we return false
		return 0;
	}
	//END OF DEKETE TEST


*/
