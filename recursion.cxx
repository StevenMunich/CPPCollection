#include <string>
#include <iostream>

using namespace std;
string s;

int recurse(){
    
	if (s.length() > 9) //base case
	return 0;
	for(int i =0; i < 255; i++){
	    cout << s << endl;
	    s += i;
	    
	    if(i ==255)
	    recurse();
	    }
	    
}

int main(int argc, char *argv[])
{
    recurse();
}