#include <string>
#include <iostream>

// Structure definition (blueprint)
struct Person {
    std::string name;
    int age;
    float height;
};

Person demo_structure_creation() {
    // Interact with struct via dot operator
    Person mike;
    mike.name = "Mike Wazowski";
    mike.age = 45;
    mike.height = 1.2;

    Person james = { "James P. Sullivan", 47};  // missing height gets default 0
    // C++ 11:
    // Person james { "James P. Sullivan", 47};

    return james;
}

void demo_structure_use(Person person) {
    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Age: " << person.age << std::endl;
    std::cout << "Height: " << person.height << std::endl;
}

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "STRUCTURES" << std::endl;
    std::cout << "==========================" << std::endl;

    // For storing heterogeneous data in one container

    Person james = demo_structure_creation();
    demo_structure_use(james);

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
