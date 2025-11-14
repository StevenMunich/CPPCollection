#include <iostream>
#include <atomic>
#include <utility>
#include <cassert>

// minimal RCObject base with public atomic counter for sandbox purposes
struct RCObject {
    std::atomic<int> ref{0};
    virtual ~RCObject() = default;
};

// rc_ptr with copy, move, bool conversion, reset, swap, and use_count()
template<typename T>
class rc_ptr {
    T* p = nullptr;

    void incref() noexcept {
        if (p) ++p->ref;
    }
    void decref() noexcept {
        if (p && --p->ref == 0) delete p;
    }

public:
    rc_ptr() noexcept = default;
    explicit rc_ptr(T* raw) : p(raw) { incref(); }
    rc_ptr(const rc_ptr& o) noexcept : p(o.p) { incref(); }

    rc_ptr(rc_ptr&& o) noexcept : p(o.p) { o.p = nullptr; }

    rc_ptr& operator=(const rc_ptr& o) noexcept {
        if (this == &o) return *this;
        if (o.p) ++o.p->ref; // increment before decrement for safety
        decref();
        p = o.p;
        return *this;
    }

    rc_ptr& operator=(rc_ptr&& o) noexcept {
        if (this == &o) return *this;
        decref();
        p = o.p;
        o.p = nullptr;
        return *this;
    }

    ~rc_ptr() { decref(); }

    T* get() const noexcept { return p; }
    T& operator*() const noexcept { assert(p); return *p; }
    T* operator->() const noexcept { return p; }

    explicit operator bool() const noexcept { return p != nullptr; }

    void reset(T* newp = nullptr) noexcept {
        if (newp) ++newp->ref;
        decref();
        p = newp;
    }

    void swap(rc_ptr& other) noexcept { std::swap(p, other.p); }

    // ---- new helper: return the current reference count ----
    int use_count() const noexcept {
        return p ? static_cast<int>(p->ref.load()) : 0;
    }
};

// factory to avoid raw new usage
template<typename T, typename... Args>
rc_ptr<T> make_rc(Args&&... args) {
    return rc_ptr<T>(new T(std::forward<Args>(args)...));
}

// Example managed type
struct Foo : RCObject {
    Foo() { std::cout << "Object created\n"; }
    ~Foo() { std::cout << "Object destroyed\n"; }
};

int main() {
    auto a = make_rc<Foo>();                // ref = 1
    std::cout << "a.use_count() = " << a.use_count() << "\n";

    {
        rc_ptr<Foo> b = a;                  // ref = 2
        std::cout << "after b = a; a.use_count() = " << a.use_count() 
                  << ", b.use_count() = " << b.use_count() << "\n";

        rc_ptr<Foo> c;                      // empty, ref unchanged
        c = b;                              // ref = 3
        std::cout << "after c = b; a.use_count() = " << a.use_count() << "\n";
    } // b and c destructors run; ref decremented back to 1

    std::cout << "after inner scope; a.use_count() = " << a.use_count() << "\n";

    rc_ptr<Foo> d = std::move(a);          // a becomes empty, d has ref=1
    std::cout << "after move; a.use_count() = " << a.use_count() 
              << ", d.use_count() = " << d.use_count() << "\n";

    d.reset();                              // deletes Foo, ref -> 0
    std::cout << "after d.reset(); d.use_count() = " << d.use_count() << "\n";

    return 0;
}
