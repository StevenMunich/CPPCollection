/*
Mark and Sweep Gargabge Collection
Head file is the pattern
main(this file) is the implementation.
It is used for cycles.

*/
#include "MSGC.h"
#include <string>

struct Node : GCObject {
    std::string name;
    GCObject* child = nullptr; // raw pointer; trace must report it

    Node(std::string n): name(std::move(n)) {}
    void trace(const std::function<void(GCObject*)>& visit) override {
        if(child) visit(child);
    }
};

int main() {
    GCHeap heap;

    // allocate nodes
    Node* a = heap.alloc<Node>("A");
    Node* b = heap.alloc<Node>("B");
    Node* c = heap.alloc<Node>("C");

    // build graph A -> B -> C -> A (cycle)
    a->child = b;
    b->child = c;
    c->child = a;

    // register root only A
    heap.addRoot(a);

    // nothing collected: A,B,C reachable from root
    heap.collect();
    std::cout << "After 1st collect: objects = " << heap.objects.size() << "\n";

    // remove root: cycle is unreachable and will be collected
    heap.removeRoot(a);
    heap.collect();
    std::cout << "After 2nd collect: objects = " << heap.objects.size() << "\n";
}
