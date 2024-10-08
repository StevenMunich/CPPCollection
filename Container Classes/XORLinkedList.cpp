/* C++ Implementation of Memory 
efficient Doubly Linked List */
#include <bits/stdc++.h>
#include <cinttypes> 
using namespace std;

// Node structure of a memory 
// efficient doubly linked list 
class Node 
{ 
    public:
    int data; 
    Node* npx; /* XOR of next and previous node */
}; 

/* returns XORed value of the node addresses */
Node* XOR (Node *a, Node *b) 
{ 
    return reinterpret_cast<Node *>(
      reinterpret_cast<uintptr_t>(a) ^ 
      reinterpret_cast<uintptr_t>(b)); 
} 

/* Insert a node at the beginning of the 
XORed linked list and makes the newly 
inserted node as head */
void insert(Node **head_ref, int data) 
{ 
    // Allocate memory for new node 
    Node *new_node = new Node(); 
    new_node->data = data; 

    /* Since new node is being inserted at the 
    beginning, npx of new node will always be 
    XOR of current head and NULL */
    new_node->npx = *head_ref; 

    /* If linked list is not empty, then npx of 
    current head node will be XOR of new node 
    and node next to current head */
    if (*head_ref != NULL) 
    { 
        // *(head_ref)->npx is XOR of NULL and next. 
        // So if we do XOR of it with NULL, we get next 
        (*head_ref)->npx = XOR(new_node, (*head_ref)->npx); 
    } 

    // Change head 
    *head_ref = new_node; 
} 

// prints contents of doubly linked 
// list in forward direction 
void printList (Node *head) 
{ 
    Node *curr = head; 
    Node *prev = NULL; 
    Node *next; 

    cout << "Following are the nodes of Linked List: \n"; 

    while (curr != NULL) 
    { 
        // print current node 
        cout<<curr->data<<" "; 

        // get address of next node: curr->npx is 
        // next^prev, so curr->npx^prev will be 
        // next^prev^prev which is next 
        next = XOR (prev, curr->npx); 

        // update prev and curr for next iteration 
        prev = curr; 
        curr = next; 
    } 
} 

// Driver code 
int main () 
{ 
    /* Create following Doubly Linked List 
    head-->40<-->30<-->20<-->10 */
    Node *head = NULL; 
    insert(&head, 10); 
    insert(&head, 20); 
    insert(&head, 30); 
    insert(&head, 40); 

    // print the created list 
    printList (head); 

    return (0); 
} 

// This code is contributed by rathbhupendra
/*

In the previous post, we discussed how a Doubly Linked can be created using only one space for the address field with every node. In this post, we will discuss the implementation of a memory-efficient doubly linked list. We will mainly discuss the following two simple functions.

A function to insert a new node at the beginning.
A function to traverse the list in a forwarding direction.

In the following code, insert() function inserts a new node at the beginning. We need to change the head pointer of Linked List, that is why a double pointer is used (See this). Let us first discuss a few things again that have been discussed in the previous post. We store XOR of the next and previous nodes with every node and we call it npx, which is the only address member we have with every node. When we insert a new node at the beginning, npx of the new node will always be XOR of NULL and the current head. And npx of the current head must be changed to XOR of the new node and node next to the current head.
printList() traverses the list in a forwarding direction. It prints data values from every node. To traverse the list, we need to get a pointer to the next node at every point. We can get the address of next node by keeping track of the current node and previous node. If we do XOR of curr->npx and prev, we get the address of next node. 

*/
