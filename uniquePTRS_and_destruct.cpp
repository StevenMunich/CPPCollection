#include <iostream>
#include <utility>
#include <memory> 


//tells compiler to compute ahead of time imstead of at run time.
constexpr int sum(){
    return 2+2;
}

class baseClass{
    public:
    int basdDestroyed;
virtual void printBase(){ std::cout << "from base\n";}
    
virtual ~baseClass(){
    std::cout << "-ALSO baseClass destroyed\n\n";
//    std::cout << basdDestroyed++;
    };
 };
   
class childClass: baseClass{
   public:
static int amountdestroyed;
 childClass(){ std::cout << "chilfClass created 49\n";
 amountdestroyed++;
     std::cout << amountdestroyed << "\n";
 }
 void printBase(){ std::cout << "im still a noob\n";
}  //destructor for child class.
~childClass() override {
        std::cout << amountdestroyed;
       std::cout << " child destroyed\n";
    amountdestroyed--;
}; 
//End of class
};
int childClass::amountdestroyed=0;


/*
void uniquePointersFunc (std::unique_ptr<childClass> &p){
    p->printBase();
    }*/
int main(int argc, char *argv[])
{
	using namespace std;
	//std in func
	
	//endl flushes the buffer '\n' does not
cout << sum() << " s precompiled sum\n";
	
	childClass child; 
	child.printBase();
	
unique_ptr<childClass> child2(new childClass);
//uniquePointersFunc(child2);
 cout << "after\n";
//Unique pointers will be deleted when out of scope to prevent memory leaks.
//unique_ptr <int> p = make_unique<int>(42);cout << *p;


//memory leak
 cout << "\n Raw Pointers\n";
childClass *chClass = new childClass();
chClass->printBase();
cout << "end of chClass* usage\n";
cout << "enter q to delete:\n";
char q;
cin >> q;
//leak or not to leak
if(q=='q')
delete chClass; 
else
cout << "raw pointer leaked\n";

}


void default_vs_value_initialized(){
    //value is not zero
int x;
int *x2 = new int;
//value is zero
int y{};
int *y2 = new int();
int *y3 = new int{};
std::cout << y << '\n';

}
