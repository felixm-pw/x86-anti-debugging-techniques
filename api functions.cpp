#include <iostream>
#include <Windows.h>
#include <vector>
#include <winnt.h>
#include <winternl.h>

bool example_1() {
    bool debugger_status = IsDebuggerPresent();
    return(debugger_status);
}

bool example_2() {
    std::vector <LPCWSTR> program_list(1, (L"notepad"));

    for (int i = 0; i < int(program_list.size()); i++) {
        HWND window = FindWindow(program_list[i], NULL);
        if (window != NULL) {         
            return(true);
        }
    }
    return(false);
}

int main()
{
    while (true) {
        bool case_1 = example_1();
        bool case_2 = example_2();

        if (case_1 || case_2 == true) {
           return(0);
        }
    }
}