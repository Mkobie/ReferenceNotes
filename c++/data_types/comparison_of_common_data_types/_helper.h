#ifndef _HELPER_H
#define _HELPER_H

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

// Fixed-width integer types are available in C++11, but not C++98.
// They are represented here using typedefs.
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;

enum Color {
    RED, GREEN, BLUE
};

union MyUnion {
    int m_int;
    double m_dbl;
};

struct MyStruct {
    int m_int;
    double m_dbl;
};

class MyIntClass {
public:
    MyIntClass(const int val) : m_int(val) {}
    int m_int;
};

class MyTwoIntsClass {
public:
    MyTwoIntsClass(const int val1, const int val2) : m_int1(val1), m_int2(val2) {}
    int m_int1;
    int m_int2;
};

void printBreak();
void printSizeAndRangeHeader();
void printSizeAndRangeFooter();

template <typename T>
void printSizeAndRange(const std::string& label, T value) {
    std::cout << std::setw(20) << label
              << std::setw(25) << value
              << std::setw(15) << sizeof(value)
              << std::setw(25) << std::numeric_limits<T>::min()
              << std::setw(25) << std::numeric_limits<T>::max()
              << std::endl;
}

void printSizeAndRangeVoid(const std::string& label);
void printSizeAndRangeHeaderDerived();
void printSizeAndRangeNumber(const std::string& label, const int& value);
void printSizeAndRangeNumber(const std::string& label, const double& value);
void printSizeAndRangeReference(const std::string& label, const int& value);
void printSizeAndRangeArray(const std::string& label, const int (&array)[5]);
void printSizeAndRangeCharArray(const std::string& label, const char c_string[]);
void printSizeAndRangeEnum(const std::string& label, const Color& value);
void printSizeAndRangeString(const std::string& label, const std::string& value);

// Pass by reference to get original memory address
template <typename T>
void printSizeAndRangeDerived(const std::string& label, T*& value) {
    std::cout << std::setw(20) << label
              << std::setw(25) << value
              << std::setw(15) << sizeof(value)
              << std::setw(25) << &value
              << std::setw(25) << *value
              << std::endl;
}

// Overload for types that don't have pointer and dereference semantics (Union, struct, vector, map, ...)
template <typename T>
void printSizeAndRangeDerived(const std::string& label, const T& value) {
    std::cout << std::setw(20) << label
              << std::setw(25) << "-"  // Non-applicable for general types
              << std::setw(15) << sizeof(value)
              << std::setw(25) << &value
              << std::setw(25) << "-"
              << std::endl;
}

#endif //_HELPER_H
