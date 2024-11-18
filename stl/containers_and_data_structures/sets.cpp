#include <iostream>
#include <set>

void demo_sets() {
    // Associative container type, based on a self-balancing binary search tree data structure.
    // Use when:
    // - need to store a collection of unique elements
    // - need to find things quickly
    // - want to combine or compare multiple sets of data
    std::set<int> my_set;

    my_set.insert(1);  // O(log n)
    my_set.insert(5);
    my_set.insert(1);  // Won't insert, as it's a duplicate.
    my_set.erase(1);   // O(log n). Remove an element from the set.

    std::set<int>::iterator it = my_set.find(6);  // O(log n). Returns iterator to element, or .end()

    std::cout << "Contents of the set:";
    for (std::set<int>::iterator it = my_set.begin(); it != my_set.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Other common fns
    std::size_t set_size = my_set.size();  // O(1). Size = number of elements
    std::cout << "Set is empty? " << my_set.empty();  // O(1)
    my_set.clear();  // O(n). Make the container empty.
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "SETS" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_sets();
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
