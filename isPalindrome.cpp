//Steven Munich
//Project 8 Recursion
//Data Structures & Algorythms
//Dr. Johnson
//3/21/2023
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;



bool isPalindrome(string word) {

	int wordLength = word.length();

	if (wordLength == 0 || wordLength == 1) //base case.
		return true;

	//declarations after base case.
	int start = 0;
	char front = word.at(start);
	char back = word.at(wordLength - 1);

	//compares front and back, if true keep going. Else return false.
	if (front == back) { 
		string newString = word.substr(start + 1, wordLength - 2); //trims the string assigned to a new string to be passed.	
		return isPalindrome(newString); //trimmed string is called recursively
	}
	else 
		return false;
}

int main() {


	
	vector<string> Strings;

	string input;
	for (int i = 0; i < 10; i++) { //User enters 10 Strings
		cout << "please enter a string for element " << i +1 << endl;
		cin >> input;
		Strings.push_back(input);
	} 

	cout << endl; //seperate input from output

	for(int i=0; i < 10; i++) //checks for palindromes.

	if (isPalindrome(Strings.at(i) ) )                      
		  
			cout << Strings.at(i)  << "=true\n";
	else
		cout << Strings.at(i) << "=false\n";
}//----------------------------------End of Main-------------------------------------




//------------------------SCRAP CODE-------------------------------------

/* int main()
{	string input;
	cin >> input;
	int wordLength = input.length();
	//isPalindrome(input, wordLength, 0); //Strings.at(i);

	 //if (isPalindrome(input, wordLength, 0))


	 //displays elements
	//for (int i = 0; i < 10; i++)
	//	cout << Strings.at(i);
}
*/

//ERROR with 2, 5, 8 lengths. 1,3,4,6,7 work.
//But i think it is reversing and comparing both directions all the way to end 
//Instead of the middle.
/*
bool isPalindrome(string word, int wordLength, int start) {

	if (wordLength == 0 || wordLength == 1)
		return true;
	//int wordLength = word.length();
	char front = word.at(start);
	char back = word.at(wordLength -1);

	cout << "front is: " << front << "\nback is: " << back;

	if (front == back) {
		string newString = word.substr(start + 1, wordLength -2);
		cout << endl << newString << endl;
		cout << word.at(start + 1) << endl;
		//cout << word.at(newString.length()) << endl;
		return isPalindrome(newString, newString.length() -1, start + 1);
	}
	else return false;

}
*/