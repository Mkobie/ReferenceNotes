#include <iostream>
#include <cstdlib>

void demo_goto(int value) {
    // Goto is good for making spaghetti

    if (value < 0) {
        goto negative;
    } else {
        goto positive;
    }

    negative:
        std::cout << "Negative value entered!" << std::endl;
        return;  // return is also a jump statement

    positive:
        std::cout << "Positive value entered!" << std::endl;
        return;
}

void demo_exit(int value) {
    // Exit terminates the program without exiting the function

    if (value == 0) {
        exit(0);  // typ 0 for successful termination, non-zero for abnormal termination
    }
}

void demo_continue() {
    // Jumps to the increment/decrement/condition of a loop

    for (int i = 0; i < 5; ++i) {
        if (i == 2) {
            continue;  // continues to ++i
        }
        std::cout << i << " ";  // prints 0 1 3 4
    }
    std::cout << std::endl;
}

void demo_break() {
    // Breaks out of the current loop, or terminate a switch case

    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
        if (sum > 15) {
            break;  // breaks the for loop
        }
    }
    std::cout << "Sum: " << sum << std::endl;

    // only breaks the loop it is in
    for (int i = 0; i < 10; i++) {  // not broken, executes 10 times
        for (int j = 0; j < 10; j++) {  // does get broken, executes a changing number of times
            std::cout << j << " ";
            if (i == j) {
                break;
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "JUMP STATEMENTS" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_goto(1);
    std::cout << std::endl;
    demo_goto(-1);

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
