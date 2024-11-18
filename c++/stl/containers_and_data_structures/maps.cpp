#include <iostream>
#include <map>

void demo_maps() {
    // Associative container type, based on a self-balancing binary search tree data structure.
    // Use when:
    // - want key value pairs
    // - need efficient lookup and retrieval of data (search is O(log N))
    // - have unique identifiers (no duplicate keys)

    std::map<std::string, int> my_map;

    my_map["Maria"] = 29;  // O(log n). Insert or update a key-value pair
    my_map["Adam"] = 25;
    my_map["David"] = 27;
    my_map.erase("Alice");  // O(log n). Deletion

    int david_age = my_map["David"];  // O(log n). Return value if exists, else create with default value (eg 0 or "")

    std::cout << "Contents of the map:" << std::endl;
    for (std::map<std::string, int>::iterator it = my_map.begin(); it != my_map.end(); ++it) {  // Iterator-based loop O(n)
        std::cout << "Name: " << it->first << ", Age: " << it->second << std::endl;
    }

    // Other common fns
    std::size_t map_size = my_map.size();  // O(1). Size = number of elements
    std::cout << "Map is empty? " << my_map.empty();  // O(1)
    my_map.clear();  // O(n). Make the container empty.
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "MAPS" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_maps();
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
