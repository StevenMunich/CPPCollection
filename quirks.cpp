

#include <iostream>
#include <windows.h>
using namespace std;


#define REPEAT(i,a,b) for (int i = a; i <= b; i++)

DWORD StrOcc(char *src, char ch)
{//Count occurrences of a char.
  DWORD i=0;
  if (!src) return 0;
  while (*src)
    if (*src++==ch) //checks if character is equal if so increment.
      i++;
  return i;
}
size_t StrOcc(const char *src, char ch) {
    size_t count = 0;
    if (src == nullptr) return 0;
    while (*src) {
        if (*src++ == ch) count++;
    }
    return count;
}


int main(int argc, char* argv[]){
	
	char* hiss = "hiss";
	char s = 's';
	int i = StrOcc(hiss,s);
	
	cout << s << " occurs in " << hiss << " " << i << " times";
	
	REPEAT(i, 1, 10) {
        cout << i << " is a and I = " << i << endl;
    }

	return 0;
}
