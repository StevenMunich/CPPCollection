#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


class C {   

   
 public: C(char *s = "", int i = 420, double d = 69) //Constructor default is 420, and 69
  { 
          strcpy(dataMember1,s);          
		  dataMember2 = i;          
		  dataMember3 = d;
  }      
		        
 void memberFunction1() {         
	   cout << dataMember1 << ' ' << dataMember2 << ' '  << dataMember3 << endl; 
 }      
 void memberFunction2(int i, char *s = "unknown") {
    dataMember2 = i;
     cout << i << " received from " << s << endl;
 }
			protected:      char dataMember1[20];      
int dataMember2;     
 double dataMember3;    
 
 };
 
 
 int main(){
 	    C object1("object1",100,2000), object2("object2", 777), object3; //3 sepeerate Objects
 	   
 	   object1.memberFunction1();
 	   object2.memberFunction1();
 	   object3.memberFunction1();
 	   object1.memberFunction2(49, "Testing object1");
 	   object2.memberFunction2(75);
 	   
 	 
 	    
 	    
 	    int i = 77;
 	    int j = 89;
 	    int k = 33;
 	    int *p = &i; 
 	    
 	    cout << *p << " at " << p << " is supoosed to be at " <<&i << endl;
 	    p--;//MINUS MINUS INSTEAD OF PLUS PLUS +++++
 	   //p -= 2;
 	    cout << *p << " at " << p << " is supoosed to be at " <<&j << endl;
 	      p--;//MINUS MINUS INSTEAD OF PLUS PLUS +++++
 	    cout << *p << " at " << p << " is supoosed to be at " <<&k << endl;
 	    
 	    
 	    
 	    
 	    
 	    
 	    
 	    char *s = "Stringgy"; //String in C	   
 	   cout << s << endl;
 	   
 	   char charset[20];
		 cout << "working: enter a string: ";
 	    cin >> charset;
 	    return 0;
 	    
 	    
 }

