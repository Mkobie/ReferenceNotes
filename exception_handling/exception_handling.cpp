#include <iostream>

// Note STL has exception handling - these examples don't use it yet.

void demo_exception_handling_string_literal() {
    int numerator = 42;
    int denominator = 0;
    int result = 0;

    try  // Try
    {
        if (denominator == 0){
            throw "Division by zero is not allowed!";  // Throw
        }
        result = int(numerator / denominator);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const char* errorMessage)  // Catch
    {
        std::cout << "Error: " << errorMessage << std::endl;
    }
}

void demo_exception_handling_int() {
    int value = 99;
    std::cout << "Before entering the try block." << std::endl;

    try  // Try
    {
        std::cout << "Inside the try block." << std::endl;
        if (value < 100){
            throw value;  // Throw
            std::cout << "After the exception is thrown." << std::endl;
        }
    }
    catch (int errorValue)  // Catch
    {
        std::cout << "Exception caught in the catch block. The error value is: " << errorValue << std::endl;
    }
}

void demo_exception_handling_pointer() {
    try {
        int* myPointer = new int[1000000000];
        std::cout << "Memory allocated successfully." << std::endl;
        delete[] myPointer;
    }
    catch (const std::bad_alloc& e) {  // std:bad_alloc
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "EXCEPTION HANDLING" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_exception_handling_string_literal();
    std::cout << std::endl;
    demo_exception_handling_int();
    std::cout << std::endl;
    demo_exception_handling_pointer();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
