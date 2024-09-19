//Steven Munich

/* 
Find the complexity of the function used to find the kth smallest element in an 
unordered array of integers

page 76 #8

int selectkth(int a[], int k, int n){
	int i, j, mini, tmp;
	for(i=0; i < k; i++){
		mini = i;
		for(j = 1; j < n; j++)
			if(a[j] < a[mini])
			mini = j;
		tmp = a[i];
		a[i] = a[mini];
		a[mini] = tmp;		
	}
	return a[k-1];
}
*/


/* --------------HINT
"n" represents the number of elements in the array
Outer loop determines the "i+1" smallest element
The inner loop searches (entire array) for the smallest element
Do a simple example with small numbers (e.g. n = 5, k = 3)
count number of comparisons (i.e., inner loop)  for each iteration of "i"; express in terms of n
Answer generated from total number of comparisons. Show work & Big-O notation
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//My formula so far.
// 1+5n(k-i)
int selectkth(int a[], int k, int n){
	int i, j, mini, tmp; //O(1) - where the 1 before 5n comes from
	int jcomparrisons = 0; //added
	for(i=0; i < k; i++){  //each iteration assigns i, mini, tmp, a[i], and a[mini].  A For loop, which has a comparrision and assignment of mini
		mini = i;
		for(j = 1; j < n; j++){
		if(a[j] < a[mini])
			mini = j;
			jcomparrisons++; //added - InnerComparisons
		}
			
		tmp = a[i];
		a[i] = a[mini];
		a[mini] = tmp;		
	}
	cout << "number of outer comparrisions: " << i+1 << endl; //added
	cout << "Number of inner comparrisions: " << jcomparrisons << endl; //added
	return a[k-1];
}
/*
int example(){
	int j, i;
	int n = 5;
	int a[n];
	for(i=0; i < n; i++)
	a[i] = i;
	i=0;
	int sum = 0;
	
	//example starts here page 68
	for(i=4; i< n; i++){
		for(j = i-3; sum = a[i-4]; j <= 1; j++)
		sum += a[j]
	}
}
*/ 


//Jcomparrisons = (n-1) * k
int main(){
	
	int n = 7;
	int k = 4;
	int a[n];
	for(int i=0; i < n; i++) //filling array
	a[i] = i;
	
	int function1 = selectkth(a,k,n);
	
	cout << function1 << endl;
	
	cout << "O(n)=k * (n-1)";
	
	
}


/*
Hello Professor Johnson,

I am having trouble fully understanding this chapter. I have a feeling its not as hard as it looks(like pointers)

I've watched the video and will watch it again. I've been reading the chapter and this is what i currently know(or think i know):

Constant = O(1) = Flatline on a graph
Linear = O(n) = straight line from bottom corner to upper right. 
Quadratic = O(n^2) = curves upward

From what I understand constant gives better performance that quadratic for large data.
I am not sure if i'm making this project more complex than it is or if I just don't know where to start
*/
