# Operation VR - Leap Motion Integration



## Instructions for Use

### Prerequisites
1. [Leap Motion Developer Kit](https://developer.leapmotion.com)

2. [SFML Graphics Library](http://www.sfml-dev.org)

3. Standard Development Tools
    * GCC and friends on Linux/macOS
    * Visual Studio on Windows (Cygwin _may_ work, but it's dangerous territory; we're linking to DLLs compiled with VC++ here)

### Build Instructions
1. Enter the OperationVR directory and type `make`. This will compile Tracker.cpp into the executable Tracker.

### Run Instructions
1. Connect the Leap Motion sensor and make sure it's running.

2. Enter the OperationVR directory and type `./Tracker`. This starts the program to track the input from the Leap Motion sensor. Note that this program opens a socket on port 10000. Keep this program running (or move it into the background using CTRL-Z and `bg`).

3. Use LeapMotionInput.cs as a regular component on whichever game object in Unity you wish to animate.


## Issues
Compilation only happens out of the box for macOS. For Linux, it is necessary to edit the supplied makefile and indicate the paths of the LeapMotion libraries for Linux.

For Windows, it is probably better to use the .sln file in the Leap Motion samples for Windows, instead of `make`. Add Tracker.cpp into the project, then add the headers and DLLs for both the Leap Motion and SFML to it.

