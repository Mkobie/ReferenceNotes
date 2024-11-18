#include <iostream>
using namespace std;

// C++11 introduced smart pointers
// Class version of pointers - does memory management for you

void demo_pointer_basics() {
    int number = 11; // Our variable
    int *ptr = &number; // Pointer to the address of our variable

    // & - "address of" operator
    // * - used to 1) declare and 2) dereference a pointer

    cout << "Value of number:   "                       << number           << endl;  // 11
    cout << "Address of number: "                       << &number          << endl;  // eg 0x3093cea98
    cout << "Pointer content:   "                       << ptr              << endl;  // eg 0x3093cea98
    cout << "Value at the address pointed to by ptr: "  << *ptr             << endl;  // 11
    cout << "Int size:          "                       << sizeof(number)   << endl;  // 4 (depends on arch)
    cout << "Ptr to int size:   "                       << sizeof(ptr)      << endl;  // 8 (depends on arch)

    // The pointer and the data it points at must have the same type (int* points to int).
}

void demo_reference_basics() {
    int number = 11;
    int &ref = number; // Reference, aka alias

    // ref and number are now just different names for the same block of memory

    cout << "Value of number:      "    << number      << endl;  // 11
    cout << "Address of number:    "    << &number     << endl; // eg 0x3093cea98
    cout << "Reference content:    "    << ref         << endl; // 11
    cout << "Address of reference: "    << &ref        << endl;  // eg 0x3093cea98
}

void demo_null_pointer() {
    int* ptr = NULL;

    // NULL - macro indicating pointer doesn't point somewhere valid.
    // nullptr - newer C++ preferred alternative.

    cout << "Pointer content: " << ptr << endl;
    cout << "Value pointed to (&ptr): jk, dereferencing it would crash the program." << endl;
}

void demo_resetting_dangling_pointers() {
    int* ptr = new int(42);
    std::cout << "Value before deletion: " << *ptr << std::endl;

    delete ptr;   // Deallocate the integer, ptr now becomes a dangling pointer
    ptr = NULL;   // Reset ptr to NULL to avoid dangling pointer issues

    if (ptr == NULL) {
        std::cout << "Pointer is now NULL, dereferencing it will now give a runtime error instead of accessing garbage data." << std::endl;
    } else {
        std::cout << "Value after deletion: " << *ptr << std::endl; // Would be unsafe if ptr wasn't reset
    }
}

void demo_array_pointer_navigation() {
    int numbers[] = {1, 2, 3, 4, 5};
    int *ptr = numbers;  // Assign the pointer to the array

    // Access the elements using pointer arithmetic
    cout << *ptr << endl;  // Output: value of numbers[0]
    cout << *(ptr + 1) << endl;  // Output: value of numbers[1]
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "POINTERS AND REFERENCES" << std::endl;
    std::cout << "==========================" << std::endl;

    cout << endl;
    demo_pointer_basics();
    cout << endl;
    demo_reference_basics();
    cout << endl;
    demo_null_pointer();
    cout << endl;
    demo_resetting_dangling_pointers();
    cout << endl;
    demo_array_pointer_navigation();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
