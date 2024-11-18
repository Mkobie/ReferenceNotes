#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

using namespace std;


void demo_accumulate(vector<int> nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    cout << "Sum: " << sum;
}

void demo_inner_product(vector<int> nums1, vector<int> nums2) {
    int result = std::inner_product(nums1.begin(), nums1.end(), nums2.begin(), 0);
    cout << "Inner Product: " << result;
}

void demo_min_element(vector<int> nums) {
    std::vector<int>::iterator min_it = std::min_element(nums.begin(), nums.end());
    if (min_it != nums.end()) std::cout << "Min element: " << *min_it;
}

void demo_max_element(vector<int> nums) {
    std::vector<int>::iterator max_it = std::max_element(nums.begin(), nums.end());
    if (max_it != nums.end()) std::cout << "Max element: " << *max_it;
}

// C++ 11:
// void demo_iota(vector<int> nums) {
//     std::iota(nums.begin(), nums.end(), 1);
//     cout << "Iota values: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
// }


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "NUMERIC ALGORITHMS" << std::endl;
    std::cout << "==========================" << std::endl;

    vector<int> numbers;  // C++ 11: vector<int> numbers = {30, 10, 20, 10};
    numbers.push_back(30);
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(10);

    demo_accumulate(numbers);
    cout << endl;
    demo_inner_product(numbers, numbers);
    cout << endl;
    demo_min_element(numbers);
    cout << endl;
    demo_max_element(numbers);
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}