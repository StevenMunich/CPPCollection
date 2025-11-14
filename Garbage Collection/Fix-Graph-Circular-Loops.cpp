#include <iostream>
#include <memory>

//C++ doesn't have ARC(automatic refrence counting) like Objective-C, but it achieves the same effect using smart pointers from the <memory>
//std::shared_ptr<T>: reference-counted smart pointer (ARC-like).
//std::weak_ptr<T>: non-owning reference to avoid circular references.
//std::unique_ptr<T>: exclusive ownership (not reference-counted).



class MyObject {
public:
    MyObject() { std::cout << "MyObject created\n"; }
    ~MyObject() { std::cout << "MyObject destroyed\n"; }

    void sayHello() {
        std::cout << "Hello from MyObject!\n";
    }
};

int main() {
    std::shared_ptr<MyObject> ptr1 = std::make_shared<MyObject>();
    {
        std::shared_ptr<MyObject> ptr2 = ptr1;  // Reference count increases to 2
        std::cout << "Reference count: " << ptr1.use_count() << "\n";
        ptr2->sayHello();
    } // ptr2 goes out of scope, reference count decreases to 1

    std::cout << "Reference count after inner scope: " << ptr1.use_count() << "\n";
    // ptr1 goes out of scope here, object is destroyed

    return 0;
}

//If two objects hold s to each other, their reference counts never reach zero — causing a memory leak.  solves this by holding a non-owning reference that doesn’t increment the count.

class Child; // Forward declaration

class Parent {
public:
    std::shared_ptr<Child> child;

    ~Parent() {
        std::cout << "Parent destroyed\n";
    }
};

class Child {
public:
    std::weak_ptr<Parent> parent; // weak_ptr avoids circular reference

    ~Child() {
        std::cout << "Child destroyed\n";
    }
};

void solve_Circular_reference(){
	
	std::shared_ptr<Parent> p = std::make_shared<Parent>();
    std::shared_ptr<Child> c = std::make_shared<Child>();

    p->child = c;
    c->parent = p; // weak_ptr: doesn't increase ref count

    std::cout << "Parent use_count: " << p.use_count() << "\n"; // Should be 1
    std::cout << "Child use_count: " << c.use_count() << "\n";   // Should be 1

    return 0; // Both objects destroyed cleanly


	
}


