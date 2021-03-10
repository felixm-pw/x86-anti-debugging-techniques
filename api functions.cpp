#include <iostream>
#include <windows.h>

bool example_1() {
    bool debugger_status = IsDebuggerPresent();
    return(debugger_status);
}

bool example_2() {
    BOOL debugger_exists = false;
    CheckRemoteDebuggerPresent(GetCurrentProcess(), &debugger_exists);
    return(debugger_exists);
}

int main() {
    while (true) {
        if (example_1() || example_2() == true) {
           return(0);
        }
    }
}