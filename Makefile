OS := $(shell uname)
ARCH := $(shell uname -m)

ifeq ($(OS), Linux)
  ifeq ($(ARCH), x86_64)
    LEAP_LIBRARY := lib/x64/libLeap.so -Wl,-rpath,lib/x64
  else
    LEAP_LIBRARY := lib/x86/libLeap.so -Wl,-rpath,lib/x86
  endif
else
  # OS X
  LEAP_LIBRARY := lib/libLeap.dylib
endif

Tracker: Tracker.cpp
	$(CXX) -Wall -g -Iinclude Tracker.cpp -o Tracker $(LEAP_LIBRARY) -lsfml-network -lsfml-system
ifeq ($(OS), Darwin)
	install_name_tool -change @loader_path/libLeap.dylib lib/libLeap.dylib Tracker
endif

clean:
	rm -rf Tracker Tracker.dSYM
