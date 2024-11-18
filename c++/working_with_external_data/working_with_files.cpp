#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <limits.h>

// The <filesystem> library added in C++17 is nice for interacting with directories

void helper_print_absolute_path(const std::string& filename) {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != 0) {
        std::cout << "Absolute path: " << cwd << "/" << filename << std::endl;
    } else {
        perror("getcwd() error");
    }
}

void demo_file_output() {
    std::ofstream outputFile;
    std::string filename = "working_with_external_data/SomeText.txt";

    outputFile.open(filename.c_str());  // C++98 quirk: requires c string not std::string
    outputFile << "Hello file world.";
    outputFile.close();
    helper_print_absolute_path(filename);
}

void demo_file_input() {
    std::ifstream inputFile;
    inputFile.open("SomeText.txt");

    std::string line;
    getline(inputFile, line);
    inputFile.close();
    std::cout << "Data from file: " << line << std::endl;
}

void demo_file_stream_modes() {
    // special built-in class std::ios has several modes:
    // - std::ios::in - for reading file
    // - std::ios::out - for writing to file
    // - std::ios::app - for appending data
    // - std::ios::binary - for opening in text mode, can combine with others
    // - std::ios::ate - add to end
    // - std::ios::trunc - if used with std::ios::out will clear contents of existing fil

    std::ofstream file("working_with_external_data/SomeText.txt", std::ios::ate | std::ios::out);
    file << "Append this.\n";
    file.close();

    std::ofstream file2("working_with_external_data/SomeText.txt", std::ios::trunc | std::ios::out);
    file2 << "Ooo previous text is gone.\n";
    file2.close();
}

void demo_move_or_rename_file() {
    // Move by renaming
    const char* oldFileName = "./working_with_external_data/SomeText.txt";
    const char* newFileName = "./some_dir/SomeTextNewName.txt";

    if (std::rename(oldFileName, newFileName) == 0) {
        std::cout << "File renamed successfully." << std::endl;
    } else {
        std::cerr << "Error renaming file!" << std::endl;
    }
}

void demo_remove_file() {
    // Delete file
    const char* newFileName = "SomeText.txt";

    if (std::remove(newFileName) == 0) {
        std::cout << "File deleted successfully." << std::endl;
    } else {
        std::cerr << "Error deleting file!" << std::endl;
    }
}

void demo_copy_file() {
    // Copy contents from src into dst
    std::ifstream src("source.txt", std::ios::binary);  // ie no transformation / interpretation of data
    std::ofstream dst("working_with_external_data/SomeText.txt", std::ios::binary);
    dst << src.rdbuf();  //src.rdbuf() returns a pointer to the io buffer of src, which is written to dst
}

void demo_file_seeking() {
    std::ofstream file("working_with_external_data/SomeText.txt", std::ios::ate | std::ios::out);
    file << "Enter some initial data.\n";
    file.close();

    std::ifstream inputFile("working_with_external_data/SomeText.txt");
    inputFile.seekg(9); // Move to the 10th character in the file
    char ch;
    inputFile.get(ch); // Read the character at the current position
    std::cout << "The character: " << ch << std::endl;
}

void demo_file_error_checking() {
    std::ifstream inputFile("nonexistent.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
    }

    std::ifstream anotherInputFile("data.txt");
    std::string line;
    while (getline(anotherInputFile, line)) {
        if (!anotherInputFile.eof()) {  // to avoid trying to process the EOF line
            // Process the line
        }
    }
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "WORKING WITH FILES" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_file_output();
    std::cout << std::endl;
    demo_file_input();
    std::cout << std::endl;
    demo_file_stream_modes();
    std::cout << std::endl;
    demo_move_or_rename_file();
    std::cout << std::endl;
    demo_remove_file();
    std::cout << std::endl;
    demo_copy_file();
    std::cout << std::endl;
    demo_file_seeking();
    std::cout << std::endl;
    demo_file_error_checking();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
