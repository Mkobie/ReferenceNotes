#include <iostream>

using namespace std;

void demo_array_creation() {
    int numbers1[5]; // Can declare, size required. Filled with garbage.
    numbers1[0] = 1; // Can assign values individually

    int numbers2[5] = {1, 2, 3, 4, 5}; // Can declare and defined (aka initialize it)

    int numbers3[] = {1, 2, 3, 4, 5}; // Size can be determined automatically if initialized

    int* numbers4 = new int[5];  // Here's how to declare and assign values for a dynamic array on the heap.
    numbers4[0] = 1;
    numbers4[1] = 2;
    numbers4[2] = 3;
    numbers4[3] = 4;
    numbers4[4] = 5;
    delete[] numbers4;
}

void demo_array_loose_bounds() {
    // C++ doesn't prevent going past end of array - careful!
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << numbers[5] << std::endl; // undefined behavior (potential error)
}

void demo_array_pointer_navigation() {
    int numbers[] = {1, 2, 3, 4, 5};
    int *ptr = numbers;  // Assign the pointer to the array

    // Access the elements using pointer arithmetic
    cout << *ptr << endl;  // Output: value of numbers[0]
    cout << *(ptr + 1) << endl;  // Output: value of numbers[1]
}

void demo_multi_dimensional_arrays() {
    int matrix[3][4] = {  // has 3 rows and 4 columns
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
}

void demo_array_size_and_length() {
    // size = amount of memory allocated for it (bytes)
    // length = number of elements it can hold
    //        = length in bytes / size of one element in bytes
    int arr[] = {1, 2, 3, 4, 5};

    int size = sizeof(arr); // note: sizeof only indicates stack memory, so works for array but not vector, map, etc.
    std::cout << "Size of the array: " << size << std::endl; // Output: 20

    int length = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Length of the array: " << length << std::endl; // Output: 5
}

bool demo_iterating_through_array(const int sortedArray[], int size, int target) {
    // C++98 arrays don't have iterators

    for (int i = 0; i < size; ++i) {
        if (sortedArray[i] == target) {
            return true;
        }
    }
    return false;
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "ARRAYS" << std::endl;
    std::cout << "==========================" << std::endl;

    // Array features:
    // - Contiguous memory (elements one after another)
    // - Fixed size (set at declaration)
    // - Homogeneous elements (all have same size and type)
    // - Random access (can access any element directly using its index)

    demo_array_creation();
    cout << endl;
    demo_array_loose_bounds();
    cout << endl;
    demo_array_pointer_navigation();
    cout << endl;
    demo_multi_dimensional_arrays();
    cout << endl;
    demo_array_size_and_length();
    cout << endl;
    int ex_array[] = {1, 2, 3};
    demo_iterating_through_array(ex_array, 3, 2);

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
