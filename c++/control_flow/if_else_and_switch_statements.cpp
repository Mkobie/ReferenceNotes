#include <iostream>


void demo_if_else_and_switch_statements() {
    // use switch instead of if/else if chain gets too long
    int choice = 1;

    std::cout << "Game Menu\n";
    std::cout << "1. New Game\n";
    std::cout << "2. Continue Game\n";
    std::cout << "3. Settings\n";
    std::cout << "4. Quit\n";
    std::cout << "Choose an option: ";
    // std::cin >> choice;

    // if/else implementation:
    if (choice == 1) {
        std::cout << "Starting a new game...\n";
    } else if (choice == 2) {
        std::cout << "Continuing the game...\n";
    } else if (choice == 3) {
        std::cout << "Opening settings...\n";
    } else if (choice == 4) {
        std::cout << "Exiting the game...\n";
    } else {
        std::cout << "Invalid choice. Please try again.\n";
    }

    // switch implementation:
    switch (choice) {  // single variable only. No expressions, and no strings.
        case 1:
            std::cout << "Starting a new game..." << std::endl;
        break;  // break exits the switch statement. Optional - could fall through instead.
        case 2:
            std::cout << "Continuing the game..." << std::endl;
        break;
        case 3:
            std::cout << "Opening settings..." << std::endl;
        break;
        case 4:
            std::cout << "Exiting the game..." << std::endl;
        break;
        default:  // execute if none of the others do
            std::cout << "Invalid choice. Please try again.\n";
        break;
    }
}

void demo_ternary_operator() {
    int a = 2; int b = 3; int max;

    // written in full:
    if (a > b) {
        max = a;
    } else {
        max = b;
    }

    // ternary operator shorthand:
    max = a > b ? a : b;
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "IF ELSE AND SWITCH STATEMENTS" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_if_else_and_switch_statements();
    std::cout << std::endl;
    demo_ternary_operator();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
