#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	vector<int> values = {1,2,3,4,5};
	
	for(int value: values)
	cout << value;
	cout << endl;
	
	for(vector<int>::iterator it = values.begin(); it < values.end(); it++)
	cout << *it << endl;
	
	
	//Iterators can be used to insert stuff into Linked-List.
	
	//unordered_map map<char[], int> map;
	
	return 0;
}
