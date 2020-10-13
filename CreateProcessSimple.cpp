#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    PROCESS_INFORMATION pi;
    STARTUPINFO si = { sizeof(si) };
    TCHAR name[] = TEXT("cmd");
    BOOLEAN success = CreateProcess(nullptr, name, nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD code;
    GetExitCodeProcess(pi.hProcess, &code);
    return 0;
}
