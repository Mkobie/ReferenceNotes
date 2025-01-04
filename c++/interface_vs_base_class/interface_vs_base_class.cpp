#include <iostream>
#include <string>

//============================================
// Base Class
//============================================
class Animal {
public:
    Animal() : type("Generic Animal") {}  // Base class constructor
    virtual ~Animal() {}  // Virtual destructor for polymorphism safety

    virtual void make_sound() const {  // It's ok to override common methods
        std::cout << "This animal makes a generic sound" << std::endl;
    }

    // Instance-specific, can access instance-specific data. Can be overridden.
    // More common than static for base classes.
    void eat() const {  // Reusable behavior provided by the base class
        std::cout << "This animal is eating" << std::endl;
    }

    // Belongs to class not instance, can't access instance-specific data/methods.
    // Less common than non-static for base classes.
    static void drink() {  // Reusable behavior provided by the base class
        std::cout << "This animal is drinking" << std::endl;
    }

protected:
    std::string type;  // Just including to show pitfalls of overriding attributes
};

// Derived class
class Dog : public Animal {
public:
    Dog() {
        type = "Dog";  // WARNING: This causes weird behavior when working with `type` in base/derived class context
    }

    void make_sound() const {  // Specific behavior for the Dog class
        std::cout << "Bark!" << std::endl;
    }
};

//============================================
// Interface
//============================================

class Shape {
public:
    // No constructor - default is fine
    virtual ~Shape() {}  // Virtual destructor for polymorphism safety

    virtual void draw() const = 0;  // Pure virtual method, enforces subclass implementation
    virtual double area() const = 0;  // Another pure virtual method
};

// Derived class implementing the interface
class Circle : public Shape {
public:
    explicit Circle(const double radius) : Shape(), radius(radius) {}  // Optional to construct implementation
    void draw() const {
        std::cout << "Drawing a circle" << std::endl;
    }

    double area() const {
        return 3.14 * (5 * 5);  // Simplified area calculation for a circle with radius 5
    }

private:
    double radius;
};

//============================================
// Main Function (Example Usage)
//============================================

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Interface vs base class" << std::endl;
    std::cout << "==========================" << std::endl;

    // Example of Base Class
    const Animal* genericAnimal = new Animal();
    genericAnimal->make_sound();
    genericAnimal->eat();  // more common than non-static (drink)
    Animal::drink();       // less common than static (eat)
    delete genericAnimal;

    const Animal* dog = new Dog();
    dog->make_sound();
    dog->eat();
    delete dog;

    // Example of Interface
    const Shape* circle = new Circle(5);
    circle->draw();
    std::cout << "Circle area: " << circle->area() << std::endl;
    delete circle;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
