Prerequisites:
    1) Leap Motion Developer Kit
        - you know where to get this, I presume
    2) SFML graphics library
        - this is being used only for its socket code
        - download it from http://www.sfml-dev.org/download.php
    3) Cygwin
        - make
        - gcc
        - g++
        - binutils

Build Instructions:
    *   Enter the OperationVR directory and type `make`. This will compile Tracker.cpp into the executable Tracker

Run Instructions:
    *   Enter the OperationVR directory and type `./Tracker`. This starts the program to track the input from the Leap Motion sensor. Note that this program opens a socket on port 10000.
