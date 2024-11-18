#include <iostream>
#include <vector>
#include <algorithm>

class Employee {
public:
    std::string name;
    int age;

    Employee(std::string personName, int personAge) { //Constructor
        name = personName;
        age = personAge;
    }

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Company {
private:
    std::vector<Employee*> employees;  // Vector lives on stack
public:
    void addEmployee(std::string name, int age) {
        Employee* newEmployee = new Employee(name, age); // Create the new Employee on the heap, cause don't know how many there will be
        employees.push_back(newEmployee); // Add it to the vector
    }

    void displayEmployees() {
        for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it) {
            (*it)->display();
        }
    }

    // Destructor to clean up heap-allocated Employees
    ~Company() {
        for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it) {
            delete *it;
        }
    }
};

void demo_vectors() {
    // Sequential container type, based on dynamic array data structure.
    // Use when:
    // - need fast random access to elements,
    // - mostly reading elements by index,
    // - want to minimize memory overhead (vectors have smaller memory footprint than lists due to contiguous storage).
    std::vector<int> my_vector;

    // my_vector.push_front(10);   // Doesn't exist. O(n) - would be terribly slow!!
    my_vector.push_back(10);   // Adds x to the end of the vector
    my_vector.push_back(20);   // O(1)
    my_vector.push_back(30);
    // my_vector.pop_front();  // Doesn't exist. O(n) - would be terribly slow!!
    my_vector.pop_back();  // Take element off end. O(1)

    int my_element_1 = my_vector[1];  // O(1)
    int my_element_2 = my_vector.at(1);  // O(1). Same as my_vector[1] but safer - has automatic bounds checking.

    std::cout << "Contents of the vector:" << std::endl;
    for (int i = 0; i < my_vector.size(); i++) {
        std::cout << "Element at index " << i << ": " << my_vector[i] << std::endl;
    }

    // Other common fns
    std::size_t vector_size = my_vector.size();  // O(1). Size = number of elements
    std::cout << "Vectory is empty? " << my_vector.empty();  // O(1)
    my_vector.clear();  // O(n). Make the container empty.
}

void demo_vectors_storing_elements_on_heap() {
    Company myCompany;  // Obj is on stack (tho elements in obj are on heap). Could also put obj on heap instead if might need lots of memory space.
    myCompany.addEmployee("John Doe", 30);
    myCompany.addEmployee("Jane Doe", 25);
    myCompany.displayEmployees();
}


class DynamicWords {
private:
    std::vector<std::string> m_vector_words;
    std::string* m_string_words;
    size_t m_string_size;

public:
    DynamicWords(const std::vector<std::string>& words) {
        m_vector_words = words;

        // Comparison with string approach:
        m_string_size = words.size();
        m_string_words = new std::string[m_string_size];

        for (size_t i = 0; i < m_string_size; i++) {
            m_string_words[i] = words[i];
        }
    }

    ~DynamicWords() {
        // Comparison with string approach:
        delete[] m_string_words;
    }

    void printStr() const {
        for (std::vector<std::string>::const_iterator it = m_vector_words.begin(); it != m_vector_words.end(); ++it) {
            std::cout << *it << std::endl;
        }

        // Comparison with string approach:
        for (size_t i = 0; i < m_string_size; i++) {
            std::cout << m_string_words[i] << std::endl;
        }
    }

    void addWord(const std::string& word) {
        m_vector_words.push_back(word);

        // Comparison with string approach:
        std::string* newWords = new std::string[++m_string_size];

        for (size_t i = 0; i < m_string_size - 1; i++) {
            newWords[i] = m_string_words[i];
        }
        delete[] m_string_words;
        newWords[m_string_size - 1] = word;
        m_string_words = newWords;
    }

};

void demo_dynamic_vector_string_comparison() {
    std::vector<std::string> initialWords;
    initialWords.push_back("A");
    initialWords.push_back("nice");
    initialWords.push_back("story");
    DynamicWords myWords(initialWords);
    myWords.printStr();
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "VECTORS" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_vectors();
    std::cout << std::endl;
    demo_vectors_storing_elements_on_heap();
    std::cout << std::endl;
    demo_dynamic_vector_string_comparison();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
