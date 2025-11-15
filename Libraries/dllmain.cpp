/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>

extern "C" __declspec(dllexport) int add(int a, int b) {
    return a + b;
}
