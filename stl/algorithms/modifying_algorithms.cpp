#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int helper_square(int x) {
    return x * x;
}

// Available in C++ 11: std::generate

void demo_copy(vector<int> source) {
    vector<int> destination(5);
    copy(source.begin(), source.end(), destination.begin());
    cout << "Copied: "; for (size_t i = 0; i < destination.size(); ++i) cout << destination[i] << " ";
}

void demo_transform(vector<int> nums) {
    transform(nums.begin(), nums.end(), nums.begin(), helper_square);
    cout << "Transformed: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}

void demo_replace(vector<int> nums) {
    std::replace(nums.begin(), nums.end(), 10, 11);
    cout << "Replaced: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}

void demo_remove(vector<int> nums) {
    std::vector<int>::iterator new_end = std::remove(nums.begin(), nums.end(), 10);
    nums.erase(new_end, nums.end());
    cout << "Removed: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}

void demo_fill(vector<int> nums) {
    std::fill(nums.begin(), nums.end(), 7);
    cout << "Filled: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}

void demo_unique(vector<int> nums) {
    // Eliminates consecutive duplicates from a sorted range.
    // Moves the duplicate elements to the end of the range, and returns an iterator pointing to the last element of the unique sequence.
    // You can use the erase method to remove the excess elements.
    std::vector<int>::iterator new_end = std::unique(nums.begin(), nums.end());
    nums.erase(new_end, nums.end());
    cout << "Unique: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}

void demo_reverse(vector<int> nums) {
    std::reverse(nums.begin(), nums.end());
    cout << "Reversed: "; for (size_t i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
}

void demo_merge(vector<int> first, vector<int> second){
    // Merges two sorted datasets into a single range.
    // Doesn't care about duplicates - does not filter them out
    std::vector<int> result;
    std::merge(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(result));
    cout << "Merged: "; for (size_t i = 0; i < result.size(); ++i) cout << result[i] << " ";
}

void demo_set_union(vector<int> first, vector<int> second){
    // Compute the union of two sets and store the result in another container.
    // O(n + m)
    // Does care about duplicates - does filter them out
    first.push_back(40);
    std::set<int> union_set;
    std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::inserter(union_set, union_set.begin()));
    cout << "Set union: "; for (std::set<int>::iterator it = union_set.begin(); it != union_set.end(); ++it) std::cout << " " << *it;
}

void demo_set_intersection(vector<int> first, vector<int> second){
    // Compute the overlap between two sets and store the result in another container.
    // O(n + m)
    // Does care about duplicates - does filter them out
    first.push_back(40);
    std::set<int> intersection_set;
    std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::inserter(intersection_set, intersection_set.begin()));
    cout << "Set intersection: "; for (std::set<int>::iterator it = intersection_set.begin(); it != intersection_set.end(); ++it) std::cout << " " << *it;
}

void demo_vector_merge_and_unique_exercise(std::vector<int> vector1, std::vector<int> vector2) {
    // You are working on a project where the use of sets is restricted.
    // Create a sortedUnion function that takes two sorted vectors, vector1 and vector2,
    // and computes their union without using the std::set_union algorithm.
    // The resulting vector should contain unique elements in sorted order.

    std::vector<int> result;
    result.reserve(vector1.size() + vector2.size());

    std::merge(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), std::back_inserter(result));
    std::vector<int>::iterator unique_end = std::unique(result.begin(), result.end());
    result.erase(unique_end, result.end());
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "MODIFYING ALGORITHMS" << std::endl;
    std::cout << "==========================" << std::endl;

    vector<int> numbers;  // C++ 11: vector<int> numbers = {10, 10, 20, 30};
    numbers.push_back(10);
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    demo_copy(numbers);
    cout << endl;
    demo_transform(numbers);
    cout << endl;
    demo_replace(numbers);
    cout << endl;
    demo_remove(numbers);
    cout << endl;
    demo_fill(numbers);
    cout << endl;
    demo_unique(numbers);
    cout << endl;
    demo_reverse(numbers);
    cout << endl;
    demo_merge(numbers, numbers);
    cout << endl;
    demo_set_union(numbers, numbers);
    cout << endl;
    demo_set_intersection(numbers, numbers);
    cout << endl;
    demo_vector_merge_and_unique_exercise(numbers, numbers);

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}