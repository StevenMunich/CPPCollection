// rc.h — minimal RC
#include <atomic>
#include <iostream>

using namespace std;

struct RCObject {
    std::atomic<int> ref{0};
    virtual ~RCObject() = default;
};

template<typename T>
class rc_ptr {
    T* p = nullptr;
    void incref() { if(p) ++p->ref; }
    void decref() { if(p && --p->ref == 0) delete p; }
    
public:
    rc_ptr() = default;
    
    explicit rc_ptr(T* raw): p(raw) { incref(); }
    rc_ptr(const rc_ptr& o): p(o.p) { incref(); }
    
    //Assignment override for copy
	rc_ptr& operator=(const rc_ptr& o) {
       
	    if(o.p == p) return *this;
        decref();
        p = o.p;
        incref();
        return *this;
    }
    ~rc_ptr(){ decref(); }
    
    //utilities
    T* get() const { return p; }
    int getRef() const {return p->ref;}
    T& operator*() const { return *p; }
    T* operator->() const { return p; }
    
    explicit operator bool() const noexcept { return p != nullptr; }

    void reset(T* newp = nullptr) noexcept {
        if (newp) ++newp->ref;
        decref();
        p = newp;
    }

    void swap(rc_ptr& other) noexcept { 
	std::swap(p, other.p); 
	
	cout << "swapping " << p << " with " << other.p << endl;
	
	}


};


template<typename T, typename... Args>
rc_ptr<T> make_rc(Args&&... args) {
    return rc_ptr<T>(new T(std::forward<Args>(args)...));
}



int main(){
	RCObject* raw = new RCObject();
	rc_ptr <RCObject>p1(raw); // is the raw pointer
	
	
	
	std::cout << "adress " << p1.get() << endl;
	
	cout << "getRef: " << p1.getRef() << endl;
	
	rc_ptr <RCObject>p2 = p1; // copy increments the ref count
	
	cout << "getRef: " << p1.getRef() <<" NOTE: this is still p1!" << endl;
	
	std::cout << "adress " << p2.get() << endl;
	
	std::cout << "intss " << p1.operator->();
	
	if(p2.get() == p1.get()){
		cout << "operator works\n";
	}
	if(p2) cout << "boolean operator works " << endl;
	
	// when p2 and p1 go out of scope, ref count will drop and delete raw when it reaches 0

//To Avoid raw you can make a helper function that does it.
// Add a small factory so callers don’t write raw new:
    auto p3 = make_rc<RCObject>(); // cleaner and less error-prone
    auto p4 = p3;
    
    	cout << "getRef: " << p1.getRef() <<" NOTE: this is still p1!" << endl;
    
    
    p1.swap(p3);
    
    	cout << "getRef: " << p1.getRef() <<" NOTE: this is still p1!" << endl;
    
    return 0;


}

