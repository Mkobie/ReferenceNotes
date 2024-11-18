#include <iostream>
#include <cstring>

class ShallowCopyExample {
private:
    char* m_data;
public:
    ShallowCopyExample(const char* data) {
        m_data = new char[strlen(data) + 1];
        strcpy(m_data, data);
    }

    // Default copy constructor (shallow copy)
    ShallowCopyExample(const ShallowCopyExample& other) : m_data(other.m_data) {}

    ~ShallowCopyExample() {
        delete[] m_data; // Leads to double deletion in shallow copy
    }

    void display() const {
        std::cout << m_data << std::endl;
    }
};


class DeepCopyExample {
private:
    char* m_data;
public:
    DeepCopyExample(const char* data) {
        m_data = new char[strlen(data) + 1];
        strcpy(m_data, data);
    }

    // Copy constructor (deep copy)
    DeepCopyExample(const DeepCopyExample& other) {
        m_data = new char[strlen(other.m_data) + 1];
        strcpy(m_data, other.m_data);
    }

    // Assignment operator (deep copy)
    DeepCopyExample& operator=(const DeepCopyExample& other) {
        if (this != &other) { // Avoid self-assignment
            delete[] m_data; // Free old memory
            m_data = new char[strlen(other.m_data) + 1];
            strcpy(m_data, other.m_data);
        }
        return *this;
    }

    ~DeepCopyExample() {
        delete[] m_data;
    }

    void display() const {
        std::cout << m_data << std::endl;
    }
};


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "OOP COPY DEPTH" << std::endl;
    std::cout << "==========================" << std::endl;

    ShallowCopyExample obj1("Hello");
    obj1.display();
    {
        // ShallowCopyExample obj2 = obj1; // Shallow copy: both objects share the same memory. Commented out cause actually causes error.
        // obj2.display();
    }
    obj1.display();  // Obj2 deleted (and shared m_data memory deallocated) when exiting above, leaving obj1 with a dangling pointer!


    DeepCopyExample obj3("Hello");
    obj3.display();
    {
        DeepCopyExample obj4 = obj3; // Deep copy: independent memory
        obj4.display();
    }
    obj3.display();

    {
        DeepCopyExample obj4 = obj3; // Deep copy: independent memory
        obj3 = obj4; // Deep copy via assignment operator
        obj3.display();
    }
    obj3.display();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}