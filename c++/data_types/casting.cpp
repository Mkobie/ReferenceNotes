#include <iostream>

void demo_casting() {
    double value = 3.14;
    const int const_val = 10;

    // C-style cast: Allows conversion but can lead to unsafe or confusing code
    int x = (int)value; // No indication of the purpose of the cast; no compile-time checks

    // Using static_cast (recommended). Has compile-time checks.
    int y = static_cast<int>(value); // Explicitly indicates intent to convert to int   <------------ use this one!

    // const_cast: Removes const qualifier
    int& modifiable_ref = const_cast<int&>(const_val); // Be cautious when modifying
    modifiable_ref = 20;

    std::cout << "C-style cast: " << x << std::endl;
    std::cout << "static_cast: " << y << std::endl;
    std::cout << "const_cast modified value: " << modifiable_ref << std::endl;
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "CASTING" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_casting();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
