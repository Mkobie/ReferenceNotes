#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void demo_sort(vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    cout << "Sorted: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}

void demo_partial_sort(vector<int> nums) {
    std::partial_sort(nums.begin(), nums.begin() + 2, nums.end());
    cout << "Partially sorted: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}

void demo_nth_element(vector<int> nums) {
    std::nth_element(nums.begin(), nums.begin() + 1, nums.end());
    cout << "After sort n-th element: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}

void demo_binary_search(vector<int> nums) {
    bool found = std::binary_search(nums.begin(), nums.end(), 20);
    if (found) {
        std::cout << "Found!";
    } else {
        std::cout << "Not found!";
    }
}

void demo_merge(vector<int> nums, vector<int> nums2) {
    vector<int> merged(8);
    std::merge(nums.begin(), nums.end(), nums2.begin(), nums2.end(), merged.begin());
    cout << "Merged: "; for (size_t i = 0; i < merged.size(); ++i) cout << merged[i] << " ";
}

void demo_inplace_merge(vector<int> nums) {
    std::inplace_merge(nums.begin(), nums.begin() + 1, nums.end());
    cout << "In-place merged: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "SORTING ALGORITHMS" << std::endl;
    std::cout << "==========================" << std::endl;

    vector<int> numbers;  // C++ 11: vector<int> numbers = {30, 10, 20, 10};
    numbers.push_back(30);
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(10);

    demo_sort(numbers);
    cout << endl;
    demo_partial_sort(numbers);
    cout << endl;
    demo_nth_element(numbers);
    cout << endl;
    demo_binary_search(numbers);
    cout << endl;
    demo_merge(numbers, numbers);
    cout << endl;
    demo_inplace_merge(numbers);
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}