#include <iostream>
#include <string>

// Abstract Component
class Beverage {
public:
    virtual ~Beverage() {}
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete Components
class Espresso : public Beverage {
public:
    std::string getDescription() const {
        return "Espresso";
    }

    double cost() const {
        return 1.99;
    }
};

// Abstract Decorator
class CondimentDecorator : public Beverage {
public:
    virtual ~CondimentDecorator() {}
    virtual std::string getDescription() const = 0;  // Pure virtual, to be implemented by concrete decorators
};

// Concrete Decorators
class Mocha : public CondimentDecorator {
private:
    Beverage* beverage;  // Pointer to the wrapped Beverage

public:
    explicit Mocha(Beverage* b) : beverage(b) {}

    ~Mocha() {
        delete beverage;  // Clean up the wrapped object
    }

    std::string getDescription() const {
        return beverage->getDescription() + ", Mocha";
    }

    double cost() const {
        return 0.20 + beverage->cost();
    }
};

class Soy : public CondimentDecorator {
private:
    Beverage* beverage;

public:
    explicit Soy(Beverage* b) : beverage(b) {}

    ~Soy() {
        delete beverage;
    }

    std::string getDescription() const {
        return beverage->getDescription() + ", Soy";
    }

    double cost() const {
        return 0.15 + beverage->cost();
    }
};

class Whip : public CondimentDecorator {
private:
    Beverage* beverage;

public:
    explicit Whip(Beverage* b) : beverage(b) {}

    ~Whip() {
        delete beverage;
    }

    std::string getDescription() const {
        return beverage->getDescription() + ", Whip";
    }

    double cost() const {
        return 0.10 + beverage->cost();
    }
};

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Decorator pattern" << std::endl;
    std::cout << "==========================" << std::endl;

    Beverage* beverage = new Espresso();
    std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

    beverage = new Mocha(beverage);
    std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

    beverage = new Whip(beverage);
    std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

    delete beverage;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
