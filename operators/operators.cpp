#include <cmath>
#include <iostream>

void demo_unary_operators() {
    // plus and minus
    int positive = +15; // positive remains 15
    int negative = -15; // negative becomes -15

    // increment and decrement. Order matters!
    int num = 1;
    int two = ++num; // increment num to 2, then assign it. Prefix is more efficient (no temp copy)
    int also_two = num--; // assign, then decrement num to 1

    // Beware of undefined behavior - Don't modify the same variable multiple times within one expression.
    int secondNum = num++ + num++;  // not sure what order things happen
}

void demo_binary_operators() {
    // arithmetic operators
    int num = 5;
    int sum = num + 3;
    int difference = 7 - 2;
    int product = 4 * 6;
    int quotient = 10 / 3;
    int remainder = 10 % 3;
}

void demo_ternary_operator() {
    int x = 10, y = 5;
    int max = (x > y) ? x : y; // max becomes 10
}

void demo_operator_precedence() {
    // Operator precedence according to ISO/IEC 14882:
    // ()
    // ++, --
    // *, /
    // +, -
    // <, <=, >, >=
    // ==, !=
    // ? :
    // =
}

void demo_associativity() {
    // Whether operators of the same precedence are evaluated left to right or right to left
    int x = 11, y = 6, z = 3;
    int result;

    // Most are left-to-right
    result = x - y - z;
    std::cout << "Result with left-associative: " << result << std::endl;

    // Only = and unary + and - are right-to-left
    result = x = y = z;
    std::cout << "Result with right-associative: " << result << std::endl;
}

void demo_epsilon_comparison() {
    double num1 = 0.1 + 0.1 + 0.1;
    double num2 = 0.3;
    bool direct_equality = (num1 == num2); // issue - might be false due to precision issues

    // More reliable: epsilon comparison
    double epsilon = 1e-9;
    bool approx_equality = std::abs(num1 - num2) < epsilon;
}

void demo_int_float_arithmetic() {
    int firstNum = 16;
    int secondNum = 3;
    float thirdNum = 3.0;

    int int_division = firstNum / secondNum; // result will be 5, not 5.33 since int math ignores decimals
    float cast_division = static_cast<float>(firstNum) / secondNum; // 3.3333, and not 3
    float mixed_division = firstNum / thirdNum;  // 5.33333, not 5 sing mixed math does implicit conversion
}

void demo_overflow() {
    int num = 2147483647; // Maximum value for a 32-bit integer
    int result = num + 1; // The result will be -2147483648 due to overflow
    std::cout << "Result with overflow: " << result << std::endl;
}

void demo_logical_operators() {
    bool weatherIsRainy = true;
    bool hasRaincoat = true;
    bool hasUmbrella = false;

    if (weatherIsRainy && hasUmbrella) {  // and
        std::cout << "You can go outside with an umbrella.";
    } else {
        std::cout << "It's rainy, but you don't have an umbrella.";
    }

    if (hasRaincoat || hasUmbrella) {  // or
        std::cout << "You can handle the rain with a raincoat or umbrella.";
    } else {
        std::cout << "You might get wet since you don't have a raincoat or umbrella.";
    }

    if (!weatherIsRainy) {  // not
        std::cout << "It's not rainy, so you don't need an umbrella.";
    } else {
        std::cout << "It's rainy, so consider taking an umbrella.";
    }
}

void demo_boolalpha() {
    bool myBool = true;

    std::cout << "Default output: " << myBool << std::endl; // Outputs: 1
    std::cout << std::boolalpha; // Apply boolalpha manipulator
    std::cout << "boolalpha output: " << myBool << std::endl; // Outputs: true
}

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "OPERATORS" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_unary_operators();
    std::cout << std::endl;
    demo_binary_operators();
    std::cout << std::endl;
    demo_ternary_operator();
    std::cout << std::endl;
    demo_operator_precedence();
    std::cout << std::endl;
    demo_associativity();
    std::cout << std::endl;
    demo_epsilon_comparison();
    std::cout << std::endl;
    demo_int_float_arithmetic();
    std::cout << std::endl;
    demo_overflow();
    std::cout << std::endl;
    demo_logical_operators();
    std::cout << std::endl;
    demo_boolalpha();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
