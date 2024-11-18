#include <iostream>

void demo_variable_definition() {
    int my_var;  // declare a var
    my_var = 5;  // assign a value
    // doing both at the same time is "initialization"

    int a, b, c = 1;  // works but beware ony c is initialized here.
    std::cout << c << std::endl;
}

void demo_initialization_types() {
    int copy_initialization = 42;  // More familiar, allows implicit conversion
    int direct_initialization(43); // More efficient
    // int uniform_initialization{44};  // From C++11 onwards, is more uniform across data types.

    std::cout << "Value: " << copy_initialization   << std::endl;
    std::cout << "Value: " << direct_initialization << std::endl;
}

void demo_constants() {
    // Must be initialized at the time of declaration.
    // Not possible to change their values via assignment.
    const float pi = 3.1415;    //proper initialization of a constant
    // pi = 3.15;               //not allowed - compilation error.
    // const double grav;       //compilation error, the constant must be initialized.
}

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "INITIALIZATION" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_variable_definition();
    demo_initialization_types();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
