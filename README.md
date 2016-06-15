# Operation VR - Leap Motion Integration



## Instructions for Use

### Prerequisites
    1. [Leap Motion Developer Kit](developer.leapmotion.com)
    2. [SFML graphics library](www.sfml-dev.org/download.php)
    3. [Cygwin](www.cygwin.com)
        * make
        * gcc
        * g++
        * binutils

### Build Instructions
    1. Enter the OperationVR directory and type `make`. This will compile Tracker.cpp into the executable Tracker

### Run Instructions
    1. Connect the Leap Motion sensor and make sure it's running
    2. Enter the OperationVR directory and type `./Tracker`. This starts the program to track the input from the Leap Motion sensor. Note that this program opens a socket on port 10000. Keep this program running (or move it into the background using CTRL-Z and `bg`).
    3. Use LeapMotionInput.cs as a regular component on whichever game object in Unity you wish to animate


## Issues
Compilation only happens out of the box for macOS. For Linux/Windows, it is necessary to edit the supplied makefile.
