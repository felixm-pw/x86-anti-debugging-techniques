#include <iostream>
#include <windows.h>

bool find_window() {
    // Array of window class names
    LPCWSTR program_list[1] = { L"OLLYDBG" };
    for (int i = 0; i < 1; i++) {
        // Find window using Class Name
        HWND window = FindWindow(program_list[i], NULL);
        // If a handle to window is found return true
        if (window != NULL) {
            return(true);
        }
    }
    return(false);
}

int main() {
    while (true) {
        // If find_window returns true, exit
        if (find_window()) {
            return(0);
        }
        Sleep(500);
    }
}