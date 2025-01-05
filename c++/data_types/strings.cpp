#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <cstdio>

using namespace std;

// **********************************************************
// Printing string things (char* or const char*, char[], string)
// will automatically print the string it points to (i.e., "12345").
//
// This is different from other (eg int) pointer behaviour!
// **********************************************************
// There are two ways of representing strings:
// - C style strings: char arrays
// - std::string: std class

void demo_strings() {
    // Null-Terminated Character Arrays (C-style Strings)
    // char *ptr_to_str_lit1 = "12345";            // Mutable pointer to (immutable) string literal in read-only memory (usually). Not allowed in C++ due to undefined behaviour.
    const char *ptr_to_str_lit2 = "12345";      // Mutable pointer to const (immutable) string literal.
    char char_array1[6] = {'1', '2', '3', '4', '5', '\0'};  // Mutable 6 element array is created and filled in with these chars.
    char char_array2[] = "12345";               // Compiler copies str lit into mutable array with automatically-determined size. Identical to char_array1 in memory.
    const char char_array3[6] = {'1', '2', '3', '4', '5', '\0'};    // Immutable 6 element array is created and filled in with these chars.
    const char char_array4[] = "12345";         // Compiler copies str lit into immutable array with automatically-determined size. Identical to char_array3 in memory.

    // Extra details:
    char char_array6[] = {'1', '2', '3', '4', '5', '\0'};  // Same as char_array1, but the array size (6) is automatically inferred.
    char char_array5[7] = {'1', '2', '3', '4', '5', '\0'};  // Same as char_array1, but with array size 7 (extra space is unused here).

    // Dynamic Allocation (Flexible, mutable but requires manual memory management)
    char *dynamic_c_str = static_cast<char *>(malloc(7 * sizeof(char))); strcpy(dynamic_c_str, "12345"); free(dynamic_c_str);
    char *dynamic_cpp_str = new char[7]; strcpy(dynamic_cpp_str, "12345"); delete[] dynamic_cpp_str;

    // STD strings in C++ (Safer, more flexible)
    std::string std_string = "12345";
    std_string += "6789";  // Easy concatenation and modification

    // C++11 STD array of chars (Fixed-size, but safer and more readable than raw arrays)
    // std::array<char, 6> cpp_array = {'1', '2', '3', '4', '5', '\0'};  // C-style, but safer
}

void demo_dynamic_char_array_size_change() {
    char *dynamic_char_array_ptr = new char[5];
    strcpy(dynamic_char_array_ptr, "12345");

    char *temp_char_array = new char[6];  // Allocate new, larger memory block
    strcpy(temp_char_array, dynamic_char_array_ptr);
    strcat(dynamic_char_array_ptr, "6");
    delete temp_char_array;

    cout << "Array: " << dynamic_char_array_ptr << endl;  // 123456
    cout << "Size: " << strlen(dynamic_char_array_ptr) << endl;  // 6
    delete dynamic_char_array_ptr;
}

void demo_pointer_array_overlap() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;  // Ptr to first array element
    // int* ptr = &arr[0];  // same as line above

    cout << "Array 'arr' decays to ptr containing: " << arr << endl;  // under the hood array name `arr` changes into `&arr[0]` - it decays into a pointer to the first element
    cout << "Pointer 'ptr' contains: " << ptr << endl;

    // Can treat both as ptr or array
    cout << "1st element using `arr[0]` (proper): "   << arr[0] << endl;
    cout << "1st element using `*arr`   (improper): " << *arr << endl;
    cout << "1st element using `*ptr`   (proper): "   << *ptr << endl;
    cout << "1st element using `ptr[0]` (improper): " << ptr[0] << endl;

    cout << "2nd element using `arr[1]`     (proper): "   << arr[1] << endl;
    cout << "2nd element using `*(arr + 1)` (improper): " << *(arr + 1) << endl;
    cout << "2nd element using `*(ptr + 1`  (proper): "   << *(ptr + 1) << endl;
    cout << "2nd element using `ptr[1]`     (improper): " << ptr[1] << endl;
}

void demo_multi_dimensional_string_literals() {
    // What about multiple strings?

    // Array of char* pointers:
    const char *ptr_to_str_lit1 = "12345";      // Mutable pointer to const (immutable) string literal.
    const char* array_of_ptr_to_strings[] = { ptr_to_str_lit1, "argument1", "argument2" };
    // Each array entry is an address, each of which points to a string:
    cout << "Array of pointers to strings:" << endl;
    cout << "1st element: " << array_of_ptr_to_strings[0] << endl;
    cout << "2nd element: " << array_of_ptr_to_strings[1] << endl;
    // For curiosity...
    cout << "Array 'array_of_ptr_to_strings' decays to ptr containing: " << array_of_ptr_to_strings << endl;  // under the hood array name changes into `&arr[0]` - it decays into a pointer to the first element
    cout << "Dereferencing the decayed pointer yields: " << *array_of_ptr_to_strings << endl;

    // Pointer that points to the array_of_ptr_to_strings array:
    const char* (*pointer_to_array_of_ptr_to_strings)[3] = &array_of_ptr_to_strings;  // "address of" address of first element, to give address of array.
    cout << "\nPointer to array of pointers to strings:" << endl;
    cout << "Address of the array (pointer content): "              <<   pointer_to_array_of_ptr_to_strings << endl;
    cout << "Address of the first element (dereferencing once): "   <<  *pointer_to_array_of_ptr_to_strings << endl;
    cout << "First string in the array (dereferencing twice): "     << **pointer_to_array_of_ptr_to_strings << endl;
    cout << "Aka (accessing the first element): "                   << (*pointer_to_array_of_ptr_to_strings)[0] << endl;  // element 0, which has type *thing thus is printed as what it points to.
    // Could navigate through it using pointer arithmetic to access each of the three pointer addresses
    cout << "Address of the second element (using pointer arithmetic): "        <<  (*pointer_to_array_of_ptr_to_strings) + 1 << endl;
    // cout << "*Not to be confused with the address of the *next array*: "        << *( pointer_to_array_of_ptr_to_strings + 1) << endl;  // careful - commented cause can cause seg fault
    cout << "Second string in the array (dereferencing the second pointer): "   << *(*pointer_to_array_of_ptr_to_strings + 1) << endl;
    cout << "Aka (accessing the second element): "                              <<  (*pointer_to_array_of_ptr_to_strings)[1] << endl;
    // cout << "*Not to be confused with accessing the *next array*: "             << *( pointer_to_array_of_ptr_to_strings[1]) << endl;  // careful - commented cause can cause seg fault

    // pointer to the first element in the array_of_ptr_to_strings array
    const char** pointer_to_ptr = array_of_ptr_to_strings;
    cout << "\nPointer to first element of array of pointers to strings:" << endl;
    cout << "Address of the first element (pointer content): " << pointer_to_ptr << endl;
    cout << "First string in the array (dereferencing once): " << *pointer_to_ptr << endl;
    cout << "Second string in the array (pointer_to_ptr + 1): " << *(pointer_to_ptr + 1) << endl;  // pointer arithmetic
}

void demo_passing_arrays_of_strings(std::string *str) {
    // When passing array of strings to fn it automatically decays to a pointer.
    // So padding e.g. std::string str[10] will pass it as std::string* str.
    // Could put in signature: std::string str[], or std::string (&str)[], but * is most common convention (and more general)
}

void demo_std_strings() {
    // std::string
    // More flexible and convenient than char arrays:
    //  - Dynamic length.
    //  - Automatic memory management.
    //  - Wide range of built-in functions.

    std::string std_string = "12345";
    std_string[7] = '!';  // Mutable
    std_string += "!!";  // Extensible (or std_string.append("stuff"); )
    (std_string == "!!");  // Can be evaluated (1 if equal, 0 if not)
    const char one_char = std_string[0]; // Easy access

    // Lots of manipulation functions
    std_string.clear();
    std_string.append("!!");
    std_string.insert(1, "<3");
    std_string.erase(1,2);
    std_string.push_back('!'); // Adds char to end
    std_string.replace(0,1, "_");

    // More stuff
    std::cout << "String is empty? " << std_string.empty() << std::endl;
    std::cout << "Num characters: " << std_string.length() << std::endl;  // or .size()
    std::cout << "3rd char: " << std_string.at(2) << std::endl;  // or just [2] if you don't want it to check the index validity for you

    const std::size_t size = std_string.size();  // or std_string.length()
    std::string sub_string = std_string.substr(0, std_string.length()-1);
    const int index = std_string.find("123");  // See also: rfind (reverse find), find_first_of, find_last_of
    const int result = std_string.compare(sub_string);  // (0 = equal, 1 = 1st > 2nd, -1 = 1st < 2nd

    // Lots of conversions in c++11: to_string converts numbers to strings, stoi (int), stod (double)

    // lexical comparisons
    std::string fruit1 = "apple";
    std::string fruit2 = "banana";
    if (fruit1 < fruit2) {
        std::cout << "fruit1 comes before fruit2 in the dictionary" << '\n';
    }

    // Can't concatenate strings using the + operator with string literals directly, have to do it with a string object.
    // std::string does_not_work = "str literal" + " str literal";  // <-- error
    std::string does_work = std_string + " str literal";
}

void demo_conversion_to_string() {
    // Stringstream
    int num = 42;
    std::stringstream ss;
    ss << num;
    std::string stringstream_str = ss.str();
    std::cout << "stringstream_str: " << stringstream_str << std::endl;

    // sprintf
    char buffer[10];
    std::sprintf(buffer, "%d", num);
    std::string sprintf_str = buffer;
    std::cout << "sprintf_str: " << sprintf_str << std::endl;
}

void demo_conversion_from_string() {
    // Stringstream
    std:string str = "1"; int stringstream_num;
    std::stringstream ss(str);
    ss >> stringstream_num;
    if (ss.fail()) {
        // Handle conversion error if needed
        throw std::invalid_argument("Invalid input for conversion to int.");
    }
    std::cout << "Converted number: " << stringstream_num + 1 << std::endl;

    // atoi
    int atoi_num = std::atoi(str.c_str());
    std::cout << "Converted number: " << atoi_num << std::endl;
}

void demo_string_comparison() {
    // Comparison is based on lexicographic order
    string str1 = "apple";
    string str2 = "banana";
    bool result = (str1 < str2); // result is true
}

void demo_string_sizes() {
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                       'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int alphabetSize = sizeof(alphabet) / sizeof(alphabet[0]);
    cout << "sizeof(alphabet): " << sizeof(alphabet) << endl;  // size of char array
    cout << "size of letter" << sizeof(alphabet[0]) << endl; // side of one char
    cout << "number of letters: " << alphabetSize << endl; // number char entries in array
}

void demo_string_io() {
    std::string first;
    std::string second;
    cout << "Enter two words: ";
    // Commented out user input for ease of running
    // cin >> first;  // cin stops at the first whitespace
    // cin >> second;  // Would have been trouble if this line wasn't here to pick up remaining input
    first = "Jane";
    second = "Doe";
    cout << "Entered: " << first << " " << second << endl;

    // cin.ignore();  // Discard remaining characters (\n).  // Also commented out user input for ease of running

    std::string entry;
    cout << "Enter two words: ";
    // Commented out user input for ease of running
    // std::getline(cin, entry);  // getline reads a whole line of text
    entry = "Jane Doe";
    cout << "Entered: " << entry << endl;
}

void demo_loop_through_strings() {
    std::string text = "Hi!";

    // Traditional
    for (std::size_t i = 0; i < text.size(); ++i) {
        std::cout << "Character at index " << i << ": " << text[i] << std::endl;
    }

    // With iterators
    std::cout << "Using iterators:" << std::endl;
    for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "STRINGS" << std::endl;
    std::cout << "==========================" << std::endl;

    std::string names[] = {"John", "Alice", "Bob", "David", "Charlie"};
    demo_strings();
    cout << endl;
    demo_dynamic_char_array_size_change();
    cout << endl;
    demo_pointer_array_overlap();
    cout << endl;
    demo_multi_dimensional_string_literals();
    cout << endl;
    demo_passing_arrays_of_strings(names);
    cout << endl;
    demo_std_strings();
    cout << endl;
    demo_conversion_to_string();
    cout << endl;
    demo_conversion_from_string();
    cout << endl;
    demo_string_comparison();
    cout << endl;
    demo_string_sizes();
    cout << endl;
    demo_string_io();
    cout << endl;
    demo_loop_through_strings();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
