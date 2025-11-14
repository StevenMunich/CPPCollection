// gc.h
#include <vector>
#include <unordered_set>
#include <functional>
#include <iostream>
#include <algorithm>  


// Base for GC-managed objects.
// Derived classes must implement trace() to visit contained GCObject* pointers.
struct GCObject {
    bool marked = false;
    virtual ~GCObject() = default;
    virtual void trace(const std::function<void(GCObject*)>&) = 0;
};

struct GCHeap {
    std::vector<GCObject*> objects;                 // all allocated
    std::vector<GCObject*> roots;                   // registered roots (simple model)

    ~GCHeap() {
        for(auto* o : objects) delete o;
    }

    template<typename T, typename... Args>
    T* alloc(Args&&... args) {
        T* obj = new T(std::forward<Args>(args)...);
        objects.push_back(obj);
        return obj;
    }

    void addRoot(GCObject* r) { roots.push_back(r); }
    void removeRoot(GCObject* r) {
        auto it = std::find(roots.begin(), roots.end(), r);
        if(it != roots.end()) roots.erase(it);
    }

    void mark() {
        std::vector<GCObject*> stack = roots;
        while(!stack.empty()) {
            GCObject* cur = stack.back(); stack.pop_back();
            if(!cur || cur->marked) continue;
            cur->marked = true;
            cur->trace([&](GCObject* child){
                if(child && !child->marked) stack.push_back(child);
            });
        }
    }

    void sweep() {
        auto it = objects.begin();
        while(it != objects.end()) {
            GCObject* obj = *it;
            if(!obj->marked) {
                delete obj;
                it = objects.erase(it);
            } else {
                obj->marked = false; // reset for next GC
                ++it;
            }
        }
    }

    void collect() {
        mark();
        sweep();
    }
};
