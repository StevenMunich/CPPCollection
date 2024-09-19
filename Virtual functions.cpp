#include <iostream>
#include <stdlib.h>
using namespace std;


class Enemy{
	public: //virtual is for polymorphism. each child has attack funtion that will overwrite.
	//it knows to look into specific class to user function instead of this one right here.
		virtual void attack()	{	}	
};

class Ninja: public Enemy{
	public:
		void attack(){
			cout << "ninja attack!" << endl;
		}
};

class Monster: public Enemy{
	public:
		void attack(){
			cout << "monster attack!" << endl;
		}
};

int main(){
	Ninja n;
	Monster m;
	Enemy *enemy1 = &n;
	Enemy *enemy2 = &m;
	enemy1->attack();
	enemy2->attack();
	
}
