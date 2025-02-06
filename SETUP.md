# Project Setup Instructions
# It's not mandatory to follow the below steps only to setup your project. 
# You can use package managersin windows or setup everything manually also.

1. Install WSL (Windows Subsystem for Linux):
   Follow the official guide: https://learn.microsoft.com/en-us/windows/wsl/install

2. Install WSL via Command:
   wsl --install

3. Restart the System:
   After installation, restart your system for the changes to take effect.

4. Set Up WSL:
   Open WSL and set up your username and password.

5. Launch Ubuntu (via WSL):
   After setting up, you can directly launch Ubuntu using command: wsl

6. Install VS Code Extension for WSL:
   It’s recommended to install the WSL extension for Visual Studio Code. This allows you to run VS Code within the WSL environment.
   Reference: https://code.visualstudio.com/docs/remote/wsl-tutorial

7. Update Package List:
   Run the following command to refresh the package list:
   sudo apt update

8. Install Necessary Tools:
   Open the Ubuntu shell in VS Code and run the following commands one by one:

   - Install the C++ compiler:
     sudo apt install g++

   - Check installation:
     g++ --version

   - Install SFML (Simple and Fast Multimedia Library):
     sudo apt-get install libsfml-dev

   - Install CMake:
     sudo apt install cmake

   - Navigate to gTest directory:
     cd /usr/src/gtest

   - Configure the build using CMake:
     sudo cmake CMakeLists.txt

   - Build using make:
     sudo make

   - Copy static libraries:
     sudo cp lib/*.a /usr/lib

9. Useful Linux Commands:
   - cd /mnt    :  Navigates to the /mnt directory, typically used for external devices.

10. Navigate to Your Project Directory:

11. Clean Build Directory (if it exists):
    mkdir build

12. Generate Build Files Using CMake:
    cmake ..

13. Compile the Code Using Make:
    make

14. Run the compiled executable:
    ./CarProject

