#include <iostream>
#include <string>
# include <iomanip>

using namespace std;

struct menu{
    float price;
    string item;
};

menu shrinkwrap(int price, string name){
    menu temp;
    temp.price = price;
    temp.item = name;
    return temp;
}
   void printRec(menu item[ ]){
       
}

int printCheck(int x, menu menu1[]){
    int sum = 0;
    for(int i =0; i < x-1; i++)
    sum += menu1[i].price;
    
    return sum;
    }

int main(int argc, char *argv[])
{
	menu item[6];
	int input;
	int x = 0;
	cout << "enter an item 1-3" << endl;
	
	while(input  != 999){
	cin >> input;
	if(input ==1)
	item[x] = shrinkwrap(3, "coffee");
	if(input==2)
	item[x] = shrinkwrap(4, "bagel");
	if(input==3)
		item[x] = shrinkwrap(5, "pancake");
	x++;
	}
	
for(int i=0; i < x-1; i++)
cout << item[i].price << " " << endl;
int sum = printCheck(x, item);
	cout << "total: $" << sum;
}