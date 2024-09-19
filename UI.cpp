#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;
void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}

int main(){
	
	gotoxy(0,0); cout << "Start";
 	gotoxy(50,50); cout << "STOP!!!!";
    for(int i=0; i <50; i++){
	    gotoxy(i,i); 
	    printf("a");
		}
    int j = 0;
    for(int i=50; i >0; i--){ //x goes from 50 and goes down to 0
        gotoxy(i,j); 
        printf("b");
        j++; // Y coordinate
			}
		
	gotoxy(15,15); 	printf("Main Menu");
		
    return 0;	
 }
	
 

