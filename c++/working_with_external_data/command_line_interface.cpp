#include <iostream>
#include <getopt.h>

void demo_io_via_command_line() {
    std::cout << "Enter any integer: " << std::endl;
    int num = 1;
    // std::cin >> num;
    std::cout << "The square of this number is:" << num*num << std::endl;
}

void demo_interactive_menu() {
    int choice;
    do {
        std::cout << "1. Option 1" << std::endl;
        std::cout << "2. Option 2" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your choice: \n";
        // std::cin >> choice;
        choice = 3;
        std::cout << "###################" << std::endl;

        switch (choice) {
            case 1:
                std::cout << "You have chosen option 1" << std::endl;
            break;
            case 2:
                std::cout << "You have chosen option 2" << std::endl;
            break;
            case 3:
                // Exiting the program through while
                    break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    } while (choice != 3);
}

void demo_command_line_arguments(int argc, char *argv[]) {
    // argc : "argument count" contains  number of arguments passed, including the program name.
    // argv: "argument vector", an array of strings (char*) containing the arguments.
    //      Note, they're not const in the fn signature, but treat them like they are else might have OS specific issues.
    std::cout << "Arguments count: " << argc << std::endl << std::endl;

    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
}

void demo_getopt(int argc, char *argv[]) {
    char short_options[] = "hv";
    int opt;

    while ((opt = getopt(argc, argv, short_options)) != -1) {
        switch (opt) {
            case 'h':
                std::cout << "Usage: myprogram [options]\n\n"
                          << "Options:\n"
                          << "  -h    Print this help message\n"
                          << "  -v    Print the version number\n";
            break;
            case 'v':
                std::cout << "myprogram v1.0.0\n";
            break;
            default:
                std::cout << "Unknown option. Use '-h' for usage information.\n";
            break;
        }
    }

    if (argc == 1) {
        std::cout << "Use '-h' for usage information.\n";
    }
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "COMMAND LINE INTERFACE" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_io_via_command_line();
    std::cout << std::endl;
    demo_interactive_menu();
    std::cout << std::endl;
    // Eg "./prog_name 1 2 3" would pass:
    char* argv[] = {
        const_cast<char*>("prog_name"),
        const_cast<char*>("-h"),
        const_cast<char*>("-v"),
    };
    int argc = sizeof(argv)/sizeof(argv[0]);
    demo_command_line_arguments(argc, argv);
    std::cout << std::endl;
    demo_getopt(argc, argv);

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
