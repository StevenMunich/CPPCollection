#include <iostream>
#include <list>
using namespace std;

class User{
    public: 
 virtual void getPermission(){
        cout << "you hVe limited permission" << endl;
        } //end function
    };//end class
    
    //child
    class Superuser: public User{
        public:
        void getPermission(){
            cout << "you have all permission" << endl;
            } //end function
        }; //end class

int main(int argc, char *argv[])
{
	cout << "hello" << endl;
	User u;
	Superuser s;
	
	
	list<User*> users; // #include <list> 
	users.push_back(&u); //adds to users
	users.push_back(&s);
	users.push_back(&u);
	
	for(User* usPtr : users)
	usPtr->getPermission();
	
	cin.get();
	
}