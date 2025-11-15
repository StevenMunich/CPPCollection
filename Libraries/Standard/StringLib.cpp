#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string s = "HelloString";
	
	s.append("s");
	
	cout << s << endl;
	
	char ch3 = s.at(3);
	cout << ch3 << endl;
	
	const char* cString = s.c_str();
	
	cout << cString;
	
	s.replace(1,3,"311");
	cout << s << endl;
	
	string ss = s.substr(1,3);
	cout << "Lets play " << ss << endl;
	

	//find the first sequence of a char or substring
	int findF = s.find("o");
	cout << "o is at index " << dinfF << endl; 
	
	
	return 0;
}
