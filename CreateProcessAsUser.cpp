#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    PROCESS_INFORMATION pi;
    STARTUPINFO si = { sizeof(si) };
    TCHAR name[] = TEXT("cmd");
    TCHAR user[] = TEXT("JuanitoP");
    TCHAR pass[] = TEXT("SuperContraseña");

    BOOLEAN success = CreateProcessWithLogonW(user, NULL, pass, LOGON_WITH_PROFILE, nullptr, name, 0, nullptr, nullptr, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD code;
    GetExitCodeProcess(pi.hProcess, &code);
    return 0;
}
