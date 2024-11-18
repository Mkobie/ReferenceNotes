#include "_helper.h"
#include <iostream>
#include <iomanip>
#include <string>

void printBreak(){
    std::cout << std::string(110, '-') << std::endl;
}

void printSizeAndRangeHeader() {
    std::cout << std::setw(20) << "Data Type"
              << std::setw(25) << "Value"
              << std::setw(15) << "Size (B)"
              << std::setw(25) << "Min"
              << std::setw(25) << "Max"
              << std::endl;
    printBreak();
}

void printSizeAndRangeFooter() {
    std::cout << "Note: The size of some fundamental data types can vary depending on system architecture." << std::endl;
}

void printSizeAndRangeVoid(const std::string& label) {
    std::cout << std::setw(20) << label
              << std::setw(25) << "-"
              << std::setw(15) << "-"
              << std::setw(25) << "-"
              << std::setw(25) << "-"
              << std::endl;
}

void printSizeAndRangeHeaderDerived() {
    std::cout << std::setw(20) << "Data Type"
              << std::setw(25) << "Value"
              << std::setw(15) << "Size (B)"
              << std::setw(25) << "Address (&)"
              << std::setw(25) << "Pointing at (*)"
              << std::endl;
    printBreak();
}

void printSizeAndRangeNumber(const std::string& label, const int& value) {
    std::cout << std::setw(20) << label
              << std::setw(25) << value
              << std::setw(15) << sizeof(value)
              << std::setw(25) << &value
              << std::setw(25) << "-"
              << std::endl;
}

void printSizeAndRangeNumber(const std::string& label, const double& value) {
    std::cout << std::setw(20) << label
              << std::setw(25) << value
              << std::setw(15) << sizeof(value)
              << std::setw(25) << &value
              << std::setw(25) << "-"
              << std::endl;
}

void printSizeAndRangeReference(const std::string& label, const int& value) {
    std::cout << std::setw(20) << label
              << std::setw(25) << value
              << std::setw(15) << sizeof(value)
              << std::setw(25) << &value
              << std::setw(25) << "-"
              << std::endl;
}

void printSizeAndRangeArray(const std::string& label, const int (&array)[5]) {
    std::cout << std::setw(20) << label
              << std::setw(25) << array
              << std::setw(15) << sizeof(array)
              << std::setw(25) << &array
              << std::setw(25) << *array
              << std::endl;
}

// Silence warning about sizeof printing size of pointer, not string length
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsizeof-array-argument"
void printSizeAndRangeCharArray(const std::string& label, const char c_string[]) {
    std::cout << std::setw(20) << label
              << std::setw(25) << c_string
              << std::setw(15) << sizeof(c_string)
              << std::setw(25) << &c_string
              << std::setw(25) << *c_string
              << std::endl;
}
#pragma GCC diagnostic pop

void printSizeAndRangeEnum(const std::string& label, const Color& value) {
    std::cout << std::setw(20) << label
              << std::setw(25) << static_cast<int>(value)
              << std::setw(15) << sizeof(value)
              << std::setw(25) << &value
              << std::setw(25) << "-"
              << std::endl;
}

void printSizeAndRangeString(const std::string& label, const std::string& value) {
    std::cout << std::setw(20) << label
              << std::setw(25) << value
              << std::setw(15) << sizeof(value)
              << std::setw(25) << &value
              << std::setw(25) << "-"
              << std::endl;
}
