#include <iostream>
#include <string>

class Painter {
public:
    // Draws a default shape (e.g., a circle)
    void draw() {
        std::cout << "Drawing a circle." << std::endl;
    }

    // Draws a shape with a specified number of sides (e.g., 3 for a triangle)
    void draw(int sides) {
        std::cout << "Drawing a shape with " << sides << " sides." << std::endl;
    }

    // Draws a colored shape, specifying sides and color
    void draw(int sides, const std::string &color) {
        std::cout << "Drawing a " << color << " shape with " << sides << " sides." << std::endl;
    }
};

void demo_method_overloading() {
    Painter picasso;

    // Calling the method without parameters to draw a circle
    picasso.draw();

    // Calling the method with an integer to draw a triangle
    picasso.draw(3);

    // Calling the method with an integer and a string to draw a red square
    picasso.draw(4, "red");
}


// Note: can't overload by changing only return type - gotta change param type.
class Geometry {
public:
    double calculateArea(double radius) {
        return 3.14159 * radius * radius; // Area of a circle
    }

    int calculateArea(int side) {
        return side * side; // Area of a square
    }
};

void demo_type_overloading() {
    Geometry g;
    std::cout << "Circle area: " << g.calculateArea(3.0) << std::endl;
    std::cout << "Square area: " << g.calculateArea(3) << std::endl;
}


class UserProfile {
public:
    void createProfile(std::string name, int age) {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    void createProfile(int age, std::string name) {
        std::cout << "Age: " << age << ", Name: " << name << std::endl;
    }
};

void demo_sequence_overloading() {
    UserProfile user;
    user.createProfile("Ada", 10);
    user.createProfile(11, "Adam");
}


class Instrument {
public:
    void sound() { std::cout << "Instrument playing" << std::endl; }
};

class Guitar : public Instrument {
public:
    void sound(int strings) { std::cout << "Guitar strumming with " << strings << " strings" << std::endl; }
};

void demo_class_inheritance_overloading() {
    Guitar g;
    // g.sound();  // Will cause error, cause sound(int) overshadows base class sound()
    g.Instrument::sound();  // Can call explicitly like this tho.
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "OOP POLYMORPHISM" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_method_overloading();
    std::cout << std::endl;
    demo_type_overloading();
    std::cout << std::endl;
    demo_sequence_overloading();
    std::cout << std::endl;
    demo_class_inheritance_overloading();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
