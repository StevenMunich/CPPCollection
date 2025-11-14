#include <iostream>
#include <memory>
// Toggle between circular and non-circular mode
//The preprocessor instructions for OS formatting of time is another rabbit hole.
#define USE_WEAK_PTR true

#include <chrono>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

// portable timestamp helper
static std::string timestamp() {
    using namespace std::chrono;
    auto now = system_clock::now();
    std::time_t tt = system_clock::to_time_t(now);

    std::tm tm{};
#if defined(_MSC_VER)            // MSVC
    localtime_s(&tm, &tt);       // note: (tm* , time_t*)
#elif defined(__unix__) || defined(__APPLE__) || defined(__MINGW32__)
    localtime_r(&tt, &tm);       // note: (time_t* , tm*)
#else
    std::tm* tmp = std::localtime(&tt); // fallback (not thread-safe)
    if (tmp) tm = *tmp;
#endif

    char buf[64];
    if (std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm)) {
        auto ms = duration_cast<milliseconds>(now.time_since_epoch()).count() % 1000;
        std::ostringstream oss;
        oss << buf << '.' << (ms / 100);
        return oss.str();
    }
    return std::string();
}


int nextID = 1;

class Child; // Forward declaration

class Parent {
public:
    std::shared_ptr<Child> child;
    std::string name;
    int id;

    Parent(const std::string& n) : name(n), id(nextID++) {
        std::cout << "[" << timestamp() << "] [+] Parent '" << name << "' (ID " << id << ") created\n";
    }

    ~Parent() {
        std::cout << "[" << timestamp() << "] [-] Parent '" << name << "' (ID " << id << ") destroyed\n";
    }
};

class Child {
public:
#if USE_WEAK_PTR
    std::weak_ptr<Parent> parent; //  avoids circular reference
#else
    std::shared_ptr<Parent> parent; // causes circular reference
#endif
    std::string name;
    int id;

    Child(const std::string& n) : name(n), id(nextID++) {
        std::cout << "[" << timestamp() << "] [+] Child '" << name << "' (ID " << id << ") created\n";
    }

    ~Child() {
        std::cout << "[" << timestamp() << "] [-] Child '" << name << "' (ID " << id << ") destroyed\n";
    }
};

int main() {
    std::cout << "\n=== ARC Sandbox Start ===\n";

    std::shared_ptr<Parent> p = std::make_shared<Parent>("P1");
    std::shared_ptr<Child> c = std::make_shared<Child>("C1");

    p->child = c;
    c->parent = p;

    std::cout << "\n[RefCounts]\n";
    std::cout << "Parent '" << p->name << "' use_count: " << p.use_count() << "\n";
    std::cout << "Child '" << c->name << "' use_count: " << c.use_count() << "\n";

    std::cout << "\n=== ARC Sandbox End ===\n";
    return 0;
}
