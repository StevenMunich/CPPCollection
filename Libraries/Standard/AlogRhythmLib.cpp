#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// All of these functions are from the algorithm library

int increment(int &num){
	
	num++;
	return num;
}

template <typename T>
void displayVec(vector<T> numbers){
	for_each(numbers.begin(), numbers.end(), [numbers](T n){
cout << "number element " << n << endl;
});
}

void SearchVec(){
	vector<int> numbers = {1, 7, 3, 5, 9, 2};
vector<int> target = {3, 5, 9};

if (search(numbers.begin(), numbers.end(), target.begin(), target.end()) != numbers.end()) {
  cout << "Target was found";
} else {
  cout << "The target was not found";
}
}

int main(){
	SearchVec();
	vector<string> cars;
cars.push_back("Volvo");
cars.push_back("BMW");
cars.push_back("Ford");
cars.push_back("Mazda");

// Sort cars alphabetically
sort(cars.begin(), cars.end());

displayVec(cars);


// Create a vector called numbers that will store integers
vector<int> numbers = {1, 7, 3, 5, 9, 2};


// Sort the vector in ascending order
sort(numbers.begin(), numbers.end());

// Find the first value that is greater than 5 in the sorted vector
auto it = upper_bound(numbers.begin(), numbers.end(), 5);

cout << "iter greater than five is " << *it << endl;


//for each - function runs a function on every element of a data range.
for_each(numbers.begin(), numbers.end(), increment );

//Anonymous function
for_each(numbers.begin(), numbers.end(), [](int n) {
	cout << n << endl;
	} );
	
for_each(numbers.begin(), numbers.end(), [numbers](int n){
n *= 2;
cout << "number element " << n << endl;
})	;
//Be cautious when capturing by reference in multi-threaded code—it can lead to race conditions if not handled properly.
// [=] capture all external variables by value
// [&t] capture all external variables by refrence
// [x] capture vairable by value
// [&x] capture variable x by refrenece



//Algo way to copy a vector or any other data structure in C++
//Transforms each element in a container and stores the result in another (or the same) container.
vector<int> doubled(numbers.size());

transform(numbers.begin(),numbers.end(),doubled.begin(), [](int n){
	return n * 2;
});

displayVec(numbers);

find_if(numbers.begin(),numbers.end(),[](int n){
	return n >15;
});

displayVec(numbers);

//filter out elements
remove_if(numbers.begin(),numbers.end(),[](int n){
	return n % 3 < 1;
});
displayVec(numbers);

	return 0;
}
