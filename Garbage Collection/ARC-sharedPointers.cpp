#include <iostream>
#include <memory>

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
