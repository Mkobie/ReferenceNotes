#include <iostream>
#include <string>

// prototype / declaration
void demo_function(int parameter, int param_with_default_value=1);

int demo_overload_add(int a, int b);
double demo_overload_add(double a, double b);  // overload by type
int demo_overload_add(int a, int b, int c);  // overload by count
// cannot overload by return type

// definition
void demo_function(int parameter, int param_with_default_value) {
    // When to think of functions:
    // - code appears more than once in program
    // - code is used for sorting
    // - refactoring large / complex / unclear code

    // Single-responsibility principle (SRP):
    // A computer programming principle that states that...
    // "A module should be responsible to one, and only one, actor."
}

int demo_overload_add(int a, int b) {
    return a + b;
}

double demo_overload_add(double a, double b) {
    return a + b;
}

int demo_overload_add(int a, int b, int c) {
    return a + b + c;
}


// --- Pass by...  ---------------------------------------------------------------------------------

void demo_pass_by_value(int a) {
    // fn gets a copy of the original var.
    // use when working with value without altering original data.
    // don't use when working with large data.
    // don't need const since not capable of modding original value.
}

void demo_pass_by_reference(int &a) {
    // fn gets reference to argument, can mod directly.
    // use when need to alter original data, and to avoid copying big stuff.
}

void demo_pass_by_reference(const int &a) {
    // `const` reference prevents modification of `a` inside this function.
    // Use when the function does not need to modify `a`, but you still want to avoid copying.
}

void demo_pass_by_pointer(int *a) {
    // fn gets address of argument, can mod via dereferencing.
    // use if passing arrays or memory buffers st can do pointer arithmetic for array navigation
    // address and value might change
}

void demo_pass_by_pointer2(const int *a) {
    // `const` pointer to int prevents modifying the value at the address `a`.
    // const value, address might change
}

void demo_pass_by_pointer3(int *const a) {
    // Non-const pointer to int allows modifying the value at the address `a`.
    // const address, value might change
}

void demo_pass_by_pointer4(const int *const a) {
    // Both `a` and its pointed-to value are const.
    // const address and value, why not use a const ref instead?
}

void demo_pass_array_by_pointer(int *arr, int size) {
    // only first element is passed, instead of copying large array.
    for (int i = 0; i < size; ++i) {
        arr[i] += 10;
    }
}

void demo_pass_array_by_const_pointer(const int *arr, int size) {
    // const pointer since not modifying the array elements
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


// --- Return by...  ---------------------------------------------------------------------------------

// Return by Value: returns a copy of the string
std::string return_by_value() {
    std::string s = "Hello from return_by_value"; // local string
    return s;  // returns a copy of `s`. Can be inefficient for large objects.
}

// Returning a reference usually implies that the function itself manages the lifetime of the object, so no dynamic mem allocation plz.
// when a function concludes, it discards local variables. So don't return reference to local vars!
int &return_by_reference_no_local_vars(int &a, int &b) {
    return (a > b) ? a : b;  // ok cause all not local.
}

// Exception: this is ok cause string is `static` so persists between calls
std::string& return_by_reference() {
    static std::string s = "Hello from return_by_reference";
    return s;  // returns a reference to `s`. Always ref to same string, can cause errors if not intended, ie not thread safe.
}

// Returning a pointer can imply that the caller is responsible for managing the memory, so no static objects plz.
// when a function concludes, it discards local variables. So don't return pointers to local vars!
int* return_by_pointer_no_local_vars(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return &arr[i];
        }
    }
    return NULL; // If element is not found
}

// Exception: this is ok cause string is dynamically allocated, ie created on heap.
std::string* return_by_pointer() {
    std::string* s = new std::string("Hello from return_by_pointer"); // dynamically allocated string
    return s; // returns a pointer to `s`. Beware of memory leaks.
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "FUNCTIONS" << std::endl;
    std::cout << "==========================" << std::endl;

    int argument = 0;
    demo_function(argument);  // invocation passing arguments

    demo_overload_add(1, 2);
    demo_overload_add(1.0, 2.0);
    demo_overload_add(1, 2, 3);

    // --- Pass by...  ---------------------------

    // Pass by which?
    // - won't mod argument? const ref
    // - will mod? ref
    demo_pass_by_value(argument);
    demo_pass_by_reference(argument);
    demo_pass_by_pointer(&argument);

    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    demo_pass_array_by_pointer(numbers, size);
    demo_pass_array_by_const_pointer(numbers, size);

    // --- Return by...  ---------------------------

    // Return by Value
    {
        std::string s1 = return_by_value();
        std::cout << "String received by value: " << s1 << std::endl;
    } // `s1` goes out of scope here, no manual cleanup required.

    // Return by Reference
    {
        std::string& s2 = return_by_reference();
        std::cout << "String received by reference: " << s2 << std::endl;
        s2 = "Modified in main"; // Modifying the static string
        std::cout << "Modified string in returnByReference: " << return_by_reference() << std::endl;
    } // `s2` is a reference to a static object, so no cleanup is needed


    // Return by Pointer
    int *result = return_by_pointer_no_local_vars(numbers, size, 2);

    {
        std::string* s3 = return_by_pointer();
        std::cout << "String received by pointer: " << *s3 << std::endl;
        delete s3; // Important to delete to avoid memory leak
    }

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}