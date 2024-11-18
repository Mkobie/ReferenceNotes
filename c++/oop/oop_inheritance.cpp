#include <string>
#include <iostream>

// Parent / base / superclass
class Animal {
private:
    int m_age;

protected:  // s.t. derived classes can interact with it
    std::string m_name;

public:
    void setName(std::string name) {
        m_name = name;
    }
    void print() {
        std::cout << "I am an animal named " << m_name << std::endl;
    }
};


// Child / derived / subclass
class Dog : public Animal {
public:
    void bark() {
        std::cout << "Woof!" << std::endl;
    }
    void print() {  // overrides base class print fn
        std::cout << "I am a dog and my name is: " << m_name <<  std::endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        std::cout << "Meow!" << std::endl;
    }
};


void demo_inheritance() {
    Animal fish;
    fish.setName("Nemo");
    fish.print();

    std::cout << std::endl;

    Dog dog;
    dog.setName("Barsik");
    dog.print();
    dog.bark();

    std::cout << std::endl;

    Cat cat;
    cat.setName("Murzik");
    cat.print();
    cat.meow();
}


class LandAnimal {
public:
    void move() {
        std::cout << "I am moving on land." << std::endl;
    }
};

class SwimmingAnimal {
public:
    void move() {
        std::cout << "I am swimming." << std::endl;
    }
};

class Seal : public Animal, public SwimmingAnimal {  // Inherit from both (careful!!)
public:
    void bark() {
        std::cout << "Bark!" << std::endl;
    }
    void print() {
        std::cout << "I am a seal and my name is " << m_name <<  std::endl;
    }
};


void demo_multiple_inheritance() {
    Seal seal;
    seal.setName("Sally");
    seal.print();
    seal.bark();
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "OOP INHERITANCE" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_inheritance();
    std::cout << std::endl;
    demo_multiple_inheritance();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}