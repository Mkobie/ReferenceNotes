#include <iostream>
#include <list>
#include <string>

void demo_lists() {
    // Sequential container type, based on a doubly linked list data structure.
    // Use when:
    // - need efficient insert and delete in middle,
    // - want to minimize memory reallocation.

    std::list<int> my_list;

    my_list.push_front(10);   // O(1)
    my_list.push_back(20);    // O(1)
    my_list.push_back(30);
    my_list.push_back(30);
    my_list.push_back(30);
    my_list.push_back(30);
    my_list.pop_front();        // O(1)
    my_list.pop_back();         // O(1)

    // Lists aren't ideal if you need to access the nth element, since it's a pain and slow O(n):
    std::list<int>::iterator it = my_list.begin();
    std::advance(it, 2);
    std::cout << "The 3rd element is: " << *it << std::endl;

    // But inserting/removing an element at the nth position is easier than for vectors:
    // - traversal to reach the position is O(n)
    // - but once there, inserting / deleting is O(1)
    my_list.insert(it, 99); // Insert 99 at the 3rd position
    std::advance(it, 1); // Move iterator one forward
    my_list.erase(it); // Erase element at the 4th position

    std::cout << "Elements in the list:" << std::endl;
    for (std::list<int>::iterator it = my_list.begin(); it != my_list.end(); ++it) {  // Iterator-based loop O(n)
        std::cout << *it << std::endl;
    }

    // Other common fns
    std::size_t vector_size = my_list.size();  // O(1). Size = number of elements
    std::cout << "List is empty? " << my_list.empty();  // O(1)
    my_list.clear();  // O(n). Make the container empty.
}

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "LISTS" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_lists();
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
