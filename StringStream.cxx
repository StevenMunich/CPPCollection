#include <iostream>
#include <sstream>
using namespace std;

class cat{

	public:
    int age;
    
    void meow(){
        cout << "meow" << endl;
    }
    
 };
    
//sizeof functionz
int sub1(){
    //4 bytes
    for(int i=0; i <= 100; i++){
        if (i % 3 == 0)
        cout << "fizz";
        if(i % 5 == 0)
        cout << " buzz";
        if(i % 3 != 0 && i % 5 !=0)
        cout << i;
        cout << endl;
    }
}
int sub2(){
    //4 bytes
    return 0;
x}
int sub3(){
    //4 bytes
    int i = 9;
}
    
int sub4(){
    //4 bytes
    int i = 9;
    int j = 11;
}
    
int sub5(){
    //4 bytes
    int i;
    int j;
    char c;
    
}
//adding
int sub6(int array1[]){
    //4 bytes
    for(int i=0; i < 2; i++)
    cout << array1[i] << endl;
}
    
int stremz(){
    string firstname, lastname, userinfo = "donald duck";
    istringstream inSS(userinfo);
        inSS >> firstname;
        inSS >> lastname;
        cout << firstname << endl << userinfo;
        cout << endl << "Lastname = " << lastname; 
 		 inSS.str(""); inSS.clear();
        getline(inSS, userinfo);
        cout << endl << userinfo;
        return 0;
    }
    
void sub7(){
    int *ptr;
    int size;
     cout << "enter size of array \n";
     cin>>size;
     ptr = new int[size];
     for(int i=0; i<size;i++)
     cin>>ptr[i];
     for(int i=0; i<size;i++)
     cout << ptr[i] << endl;
     delete[] ptr;
    }
    
void ternOp(){
//ternary operator
	int i = 5;
	int i2;
	cout << "enter a number: ";
	cin >> i2;
	// if i2 > 5 then i = 7 else i = 69
	i = i2  > 5 ? 7 : 69;
	cout << endl << i;
	//if i2 < 5 --69. between 5&10--7. >10 :4
	//true true, true false, false false.
	i = i2 > 5 ?  i2 < 10 ? 7 : 4 : 69;
	cout << endl << i;
}
    

int main(int argc, char *argv[])
{
	//sub7();
	stremz();
	
	/* //ends at line 119
	struct munster{ //1 byte
	    };
	 struct ninja{ //4 bytes
	     int attack = 7;
	     };
	  struct dragon{ //8 bytes
	     int attack = 70;
	     int health = 1000;
	     };
	     
	typedef int num; 
	//num is now a datatype
	num h = 3;
	
	//all 4 bytes
	int i = 4;
	int* ip = &i;
	signed int j = 5;
	unsigned int k = 6;
	
	bool flag1 = true; //1 byte
	short s = 2; //2 bytes
	long L = 8; // 8 byted
	long long LL = 9; //still 8 bytes
	
	char name[] = "steven";
	char char1;
	
	cout << sizeof(name) << endl;
	cout << sizeof(char1) << endl;
	
	
	cout << sizeof(s) << endl;
	cout << sizeof(L) << endl;
		
	cout << sizeof(LL) << endl;
	cout << sizeof(num) << endl;
	cout << sizeof(ip) << endl;
	cout << sizeof(flag1) << endl;
	
	
	//structs
	cout << sizeof(munster) << endl;
	cout << sizeof(ninja) << endl;
	cout << sizeof(dragon) << endl;
	
	//classses: this one 4 bytes
	cout << sizeof(cat) << endl;
	cat seagull;
	seagull.age = 7;
	seagull.meow();
	
	//functions, all 4 bytes
	cout << sizeof(seagull) << endl;
	cout << sizeof(sub1()) << endl;
	cout << sizeof(sub2()) << endl;
	cout << sizeof(sub3()) << endl;
	cout << sizeof(sub4()) << endl;
	sub4();
	cout << sizeof(sub4()) << endl;
	cout << sizeof(sub5()) << endl;
	cout << sizeof(sub6()) << endl;
	int ifun = sub6();
	sizeof(ifun);
	
	*/
	
	//pass array to function
	int array1[3] = {3, 2, 1};
	sub6(array1);
	
	
	enum color{
	    GREEN,
	    RED,
	    BLUE,
	    };
	    color r = RED;
	    color b = BLUE;
	cout << r;
	cout << b;
	
	
	
	
}
