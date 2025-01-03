# Reference Notes

This repository contains notes and code examples collected while studying programming.


## C++
C++ notes are restricted to the C++98 version, since that's required at my workplace.

### Running the Code
To compile and run any one c++ example on Linux, use:
```bash
g++ -std=c++98 path/to/filename.cpp -o output && ./output
```
For examples with helper files, use:
```bash
g++ -std=c++98 path/to/*.cpp -o output && ./output
```
To compile and run all c++ examples, execute the run.sh script in a Unix-like environment (eg use Linux, or WSL2).

### Checklist
Concepts to double-check before submitting code, based on common mistakes:
- Method of passing parameters was selected intentionally?
  - _Value / reference / const reference / pointer / const pointer_
  - Eg. Pass str to fn by ref if won't be changed, to avoid copy.
  - Add const wherever the argument won't change.
- Set vector size at definition if possible (to avoid reallocation)?
- Every new has a delete?
- Didn't try to take size of a string pointer (or string array, which decays to pointer)?


## Resources
Concepts were learned from the following resources:

- [Hyperskill's Introduction to C++ course](https://hyperskill.org/courses/74-introduction-to-c)
- [Boot.Dev's back-end course](https://www.boot.dev/tracks/backend)
- Head First Design Patterns, by Eric and Elisabeth Freeman
