#include <iostream>

int demo_add_int(int a, int b) {
    return a + b;
}

template <typename T>
T demo_add_template(T a, T b) {
    return a + b;
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "TEMPLATE FUNCTIONS" << std::endl;
    std::cout << "==========================" << std::endl;

    std::cout << "Sum of integers: " << demo_add_int(5, 10) << std::endl;
    std::cout << "Sum of integers: " << demo_add_template(5, 10) << std::endl;        // Works for integers
    std::cout << "Sum of doubles: " << demo_add_template(3.5, 2.5) << std::endl;     // Works for doubles

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}