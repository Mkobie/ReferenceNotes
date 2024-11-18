#include <iostream>
#include <vector>
#include <map>

void demo_iterators(std::vector<int> numbers) {
    std::vector<int>::iterator it; // Declare an iterator

    it = numbers.begin(); // it points at first element
    it = numbers.end(); // it points just past the last element

    for (it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " "; // Dereference the iterator to access the element
    }
}

void demo_iterators_with_map(std::map<int, std::string> my_map){
    std::cout << "Contents of the map:" << std::endl;

    // traversal
    for (std::map<int, std::string>::iterator it = my_map.begin(); it != my_map.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    // finding something specific
    int key_to_find = 2;
    std::map<int, std::string>::iterator find_it = my_map.find(key_to_find);

    if (find_it != my_map.end()) {
        std::cout << "Found key " << key_to_find << " with value: " << find_it->second << std::endl;
    } else {
        std::cout << "Key " << key_to_find << " not found in the map." << std::endl;
    }
}

 // NOTE:
// it->first and it->second for map


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "ITERATORS" << std::endl;
    std::cout << "==========================" << std::endl;

    // pointers that allow you to traverse and manipulate elements
    // in containers like vectors, arrays, and lists

    std::vector<int> numbers;  // C++ 11: vector<int> numbers = {10, 10, 20, 30};
    numbers.push_back(10);
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::map<int, std::string> my_map;
    my_map.insert(std::make_pair(1, "One"));
    my_map.insert(std::make_pair(2, "Two"));
    my_map.insert(std::make_pair(3, "Three"));

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}