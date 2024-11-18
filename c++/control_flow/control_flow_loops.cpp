#include <iostream>

void demo_while_loop() {
    // pre-test loop
    int i = 0;
    while (i < 5) {
        std::cout << "Count: " << i << std::endl;
        i++;
    }
}

void demo_do_while_loop() {
    // post-test loop
    int i = 0;
    do {
        std::cout << "Count: " << i << std::endl;
        i++;
    } while (i < 5);

    int value = 0; // would be user entered inputs irl
    do {
        std::cout << "Input is: " << value << std::endl;
    } while (value != 0);
}

void demo_for_loop() {
    for (int i = 0; i < 5; ++i) {
        std::cout << i << ' ';
    }

    // nesting example
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            std::cout << i * j << "\t";
        }
        std::cout << std::endl;
    }

    // initialization statement, condition, and modification are optional
    int my_int = 10;
    for (; my_int > 0; --my_int) {
        std::cout << my_int << " ";
    }
    for (;;) {
        // do something
        break; // do avoid actual infinite loop when executing this example!
    }
}

// // C++ 11 only
// void demo_range_based_for_loop() {
//     // aka foreach loop
//     int numbers[] = {1, 2, 3, 4, 5};
//
//     for (int number : numbers) {
//         std::cout << number << " ";
//     }
// }

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "CONTROL FLOW LOOPS" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_while_loop();
    std::cout << std::endl;
    demo_do_while_loop();
    std::cout << std::endl;
    demo_for_loop();
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
