# UnknownKiller

Process termination tool exploiting UnknownKiller.sys (eb.sys) vulnerable kernel driver.

## What is this

A signed kernel driver (UnknownKiller.sys, internal name eb.sys) exposes an IOCTL that allows any user to kill processes without security checks. This tool sends a PID to the driver which terminates it from kernel mode.

## Driver Information

- File: UnknownKiller.sys
- Device: \\.\eb
- Signer: Microsoft Windows Hardware Compatibility Publisher
- Signed: Tuesday, September 2, 2025 2:14:05 AM
- IOCTL: 0x222024
- Input: 4-byte PID (DWORD)

Despite being signed by Microsoft WHCP, this driver implements dangerous primitives with no access control.

## Technical Details

The driver uses KeStackAttachProcess to enter the target's context and calls ZwTerminateProcess(-1) to kill it from within. Works on any process the driver can open.

Kill chain:
1. PsLookupProcessByProcessId(pid)
2. KeStackAttachProcess(target)
3. ZwTerminateProcess(-1, 0)
4. KeUnstackDetachProcess()

## Build
```
cl.exe UnknownKiller.c
```

## Driver Installation

Load the driver (requires Administrator):
```cmd
sc create eb type= kernel binPath= C:\path\to\UnknownKiller.sys
sc start eb
```

Verify driver is loaded:
```cmd
sc query eb
```

## Usage

Kill by PID:
```
UnknownKiller.exe 1234
```

Kill by name:
```
UnknownKiller.exe notepad.exe
```

## Unload Driver
```cmd
sc stop eb
sc delete eb
```

## Requirements

- Driver must be loaded first
- Run as Administrator
- Windows 7+ x64

## Why this matters

BYOVD (Bring Your Own Vulnerable Driver) attacks abuse signed drivers with poor security. Even Microsoft-signed drivers can be exploited if they expose dangerous kernel primitives. This driver proves how a WHCP signature doesn't guarantee security.

## Detection

Monitor for:
- Driver load: UnknownKiller.sys or eb.sys
- Device object: \Device\eb
- Service: HKLM\SYSTEM\CurrentControlSet\Services\eb
- IOCTL activity: 0x222024

## Mitigation

Remove if found:
```cmd
sc stop eb
sc delete eb
del C:\Windows\System32\drivers\UnknownKiller.sys
```

Add driver hash to WDAC deny policy or use driver blocklist.

## Disclaimer

For authorized security testing only. Demonstrates BYOVD attack vector using legitimate signed driver.
