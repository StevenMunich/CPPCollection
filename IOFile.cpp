#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;



int loadSystem();
void writeAllFiles(int numOfElements);
//Limbs
int addFile(int numOfElements, string temp);

string indvElements[1000];
int numberOfElements =	loadSystem();

int loadSystem(){ //---------------------LOAD FILES
	int index = 0;	
	ifstream open_data; //File stream - input.	
	open_data.open("mylog.txt");

	while(!(open_data.eof())) 	//loop for "Load data" function - return numOfElements
	{	
	getline(open_data, indvElements[index]);
		index++;	
	}
	
	//Switch for addFile function(Adds 1 extra string to array when first item is created, second time does not create extra variable).
	
	
		return index;
}


void writeAllFiles(int numOfElements){ //-------------------SAVE FILE
	
	ofstream data_out;
	
	data_out.open("mylog.txt");
	int index;
	for (index=0; index < numOfElements; index++){
	
		data_out << indvElements[index] << endl;
	}

}

int addFile(int numOfElements, string temp){
indvElements[numOfElements - 1 ] = temp;
	

	cout << "Enter name of File: ";
	cin >> indvElements[numOfElements];
	cout << "item in array nunber: " << numOfElements << " Value is " << indvElements[numOfElements] << endl;
	writeAllFiles(numOfElements);
	
}

int main(){
	while(1){
		addFile(numberOfElements, indvElements[numberOfElements - 1 ]); // Add File
		numberOfElements++;
	}
	
}
