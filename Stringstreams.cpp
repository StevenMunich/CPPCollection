#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	
	string firstname = "Donald \n";
	ostringstream outSS;
	
	if(outSS.str() == "")
	cout << "not outSS1 \n"; //This
	else
	cout << "OUTSS1 \n";
	
	outSS << firstname; //after insertion
	
	if(outSS.str() == "")
	cout << "not outSS2 \n"<< endl;
	else
	cout << "OUTSS2 \n"<< endl; //THIS
	
	cout << outSS.str();
	outSS.flush();
	outSS.clear();
	
	cout << outSS.str();
	outSS << "hello bob3";
	cout << outSS.str()<< endl;
	outSS << "4hello\0 bob5";
	cout << outSS.str() << endl;
	outSS.flush();
	outSS.clear();
	outSS << "6hello\0 bob7" << endl;
	cout << outSS.str();


string s1;
cin >> s1;
cout << s1;



/*	
             _______           __________
            |       \         /          \
____________| BUFFER \_______/  Running  |
_O_L_L_E_H__          ________  Program  |
            \________/        \_________/
	
*/	
//As you type a buffer is being filled.
//When you press enter it sends from buffer to program running
//NOTHING Is sent until you hit ENTER, it takes buffer and sends to Program	
	
}
