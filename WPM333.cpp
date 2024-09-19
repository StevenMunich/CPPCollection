#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

	DWORD pid;
DWORD Ammo = 0x54E6C634;
int myAmmo = 345;

int main(){
	


	
	HWND hWnd = FindWindowA(0, ("STARFOX64-Project64 Version 1.6"));
	
	GetWindowThreadProcessId(hWnd , &pid);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	
	WriteProcessMemory(pHandle, (LPVOID)Ammo, &myAmmo, sizeof(myAmmo), 0);
}
