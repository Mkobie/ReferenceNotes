#include <iostream>

// Templates - for when operation is type independent

class DemoIntClass {
private:
    int data;
public:
    DemoIntClass(int value) : data(value) {}
    void print() const { std::cout << "Stored value: " << data << std::endl; }
};

template <typename T>
class DemoTemplateClass {
private:
    T data;
public:
    DemoTemplateClass(T value) : data(value) {}
    void print() const { std::cout << "Stored value: " << data << std::endl; }
};

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "TEMPLATE CLASSES" << std::endl;
    std::cout << "==========================" << std::endl;

    DemoIntClass onlyIntStorage(5);  // ONLY works for ints
    onlyIntStorage.print();

    DemoTemplateClass<int> intStorage(5);        // Class works with integers, and...
    intStorage.print();

    DemoTemplateClass<std::string> stringStorage("Hello!");  // ...Class works with strings
    stringStorage.print();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
