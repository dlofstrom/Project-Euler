# Project-Euler
My solutions to the Project Euler problems.

Problems solved in problems directory.

For now only compiled and tested on macOS (10.12.5, clang) and Linux (Ubuntu, gcc).

Dependencies: [libcurl](https://curl.haxx.se/libcurl), [libtidy](http://www.html-tidy.org/developer)

To build and run:
```bash
make #build all problems
make all #build all problems
make run-all #build and run all problems
make problemX #build problem X
make run-problemX #build and run problem X
bin/problemX #run problem X
gdb bin/problemX #debug problem X
```