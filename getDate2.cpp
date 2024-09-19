#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string getDate();

int main() 
{

string date = getDate();
cout << date;

}

string getDate(){

   // current date and time on the current system
   time_t now = time(0);      
   tm *ltm = localtime(&now);

  //assign year,monthdate, from TM structure  
   int year = 1900 + ltm->tm_year;
   int month = 1 + ltm->tm_mon;
   int day = ltm->tm_mday ;
   
   //put into string
    stringstream ss;
	ss << day  << "-"<< month  << "-"<< year << ".txt";
	string str = ss.str();
	
	ss.str(""); // empties string stream
	
	return str;
}

