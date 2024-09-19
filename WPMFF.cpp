#include <windows.h> 
#include <iostream> 

int main() {
	
	 DWORD baseAddress = 0x54E6C634;
   // DWORD offset = 0xA7;
   // DWORD ptrAddress = 0x5123C634;
    int newValue = 331;
	
    HWND hWnd = FindWindow(0, "STARFOX64 - Project64 Version 1.6");
    if (hWnd == 0) {
        std::cout << "Cannot find window." << std::endl;
    }
    DWORD pId;
    GetWindowThreadProcessId(hWnd, &pId);
    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
   
   if(pId == NULL){
   	std::cout << "Can not get process by ID " << std::endl;
   }else{
   	 WriteProcessMemory(hProc, (LPVOID)baseAddress, &newValue, sizeof(newValue), 0);
    std::cout << "Done. " << &baseAddress << std::endl;
    
    int readtest= 0;
   ReadProcessMemory(hProc, (void*)baseAddress, &readtest, sizeof(int), 0);
   std::cout << "Value is: " << readtest << std::endl;
   
   }
  
}
   

