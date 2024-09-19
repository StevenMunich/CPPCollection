#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main() 
{
   // current date and time on the current system
   time_t now = time(0);      
   tm *ltm = localtime(&now);
   // print various components of tm structure.
   cout << "Year:" << 1900 + ltm->tm_year<<endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<< ltm->tm_mday << endl;
   
   int year = 1900 + ltm->tm_year;
   int month = 1 + ltm->tm_mon;
   int day = ltm->tm_mday ;
   
   
    stringstream ss;
	ss << day  << "-"<< month  << "-"<< year << ".txt";
	string str = ss.str();
	
	ss.str(""); // empties string stream
	
	cout << str;
	return 0;
}

/* -------Checks if file exist ---DOES NOT WORK
ifstream ifile;
	ifile.open(str);
	if(ifile){
		cout << "file exist\n";
		ifile.close();
	} else {
		ifile.close();
		cout<< "File does not exist\n";
	ofstream myfile(str);
	cout << "wirting to : " << str << endl;
//	myfile.open(str);
	myfile << "wirint to file \n";
	myfile.close();
	}

*/
