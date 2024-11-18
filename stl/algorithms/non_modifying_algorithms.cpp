#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper_print_element(int val) {
    std::cout << val << " ";
}

void demo_non_modifying_algorithms(std::vector<int> numbers) {
    // Don't modify the elements in the container, just inspect / perform some operation on them
    // In C++ 11: std::all_of, std::any_of, std::none_of

    std::for_each(numbers.begin(), numbers.end(), helper_print_element);
    int count3 = std::count(numbers.begin(), numbers.end(), 3);
    std::vector<int>::iterator it = std::find(numbers.begin(), numbers.end(), -4);  // returns iterator to element, or numbers.end()
}

void demo_for_each(std::vector<int> nums) {
    std::cout << "For each: ";
    std::for_each(nums.begin(), nums.end(), helper_print_element);
}

void demo_count(std::vector<int> nums) {
    int count = std::count(nums.begin(), nums.end(), 10);
    std::cout << "Count: " << count;
}

void demo_find(std::vector<int> nums) {
    // linear search, O(n)
    std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), 20);

    if (it != nums.end()) {
        std::cout << "Found " << *it << " at position: " << std::distance(nums.begin(), it);
    } else {
        std::cout << "Not found!";
    }
}

void demo_binary_search(std::vector<int> nums) {
    // O(log n), more efficient than find for large sorted datasets
    bool found = std::binary_search(nums.begin(), nums.end(), 20);

    if (found) {
        std::cout << "Element found.";
    } else {
        std::cout << "Element not found.";
    }
}

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "NON MODIFYING ALGORITHMS" << std::endl;
    std::cout << "==========================" << std::endl;

    vector<int> numbers;  // C++ 11: vector<int> numbers = {10, 10, 20, 30};
    numbers.push_back(10);
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    demo_for_each(numbers);
    cout << endl;
    demo_count(numbers);
    cout << endl;
    demo_find(numbers);
    cout << endl;
    demo_binary_search(numbers);
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}