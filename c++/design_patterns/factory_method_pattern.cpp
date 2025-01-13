#include <iostream>
#include <string>

// Product Interface
class Pizza {
public:
    virtual void prepare() const = 0;
    virtual void bake() const = 0;
    virtual void cut() const = 0;
    virtual void box() const = 0;
    virtual ~Pizza() {}
};

// Concrete Products
class NYStyleCheesePizza : public Pizza {
public:
    void prepare() const { std::cout << "Preparing NY Style Cheese Pizza\n"; }
    void bake() const { std::cout << "Baking NY Style Cheese Pizza\n"; }
    void cut() const { std::cout << "Cutting NY Style Cheese Pizza\n"; }
    void box() const { std::cout << "Boxing NY Style Cheese Pizza\n"; }
};

class NYStylePepperoniPizza : public Pizza {
public:
    void prepare() const { std::cout << "Preparing NY Style Pepperoni Pizza\n"; }
    void bake() const { std::cout << "Baking NY Style Pepperoni Pizza\n"; }
    void cut() const { std::cout << "Cutting NY Style Pepperoni Pizza\n"; }
    void box() const { std::cout << "Boxing NY Style Pepperoni Pizza\n"; }
};

// Creator
class PizzaStore {
public:
    virtual Pizza* createPizza(const std::string& type) const = 0;  // factory fn

    Pizza* orderPizza(const std::string& type) const {
        Pizza* pizza = createPizza(type);  // local client of factory fn
        if (pizza) {
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
        }
        return pizza;
    }

    virtual ~PizzaStore() {}
};

// Concrete Creator
class NYPizzaStore : public PizzaStore {
public:
    Pizza* createPizza(const std::string& type) const {  // child class implements factory fn
        if (type == "cheese") {
            return new NYStyleCheesePizza();
        } else if (type == "pepperoni") {
            return new NYStylePepperoniPizza();
        } else {
            std::cerr << "Unknown pizza type: " << type << "\n";
            return NULL;
        }
    }
};

// Client Code
int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Factory method pattern" << std::endl;
    std::cout << "==========================" << std::endl;

    PizzaStore* nyStore = new NYPizzaStore();
    Pizza* pizza = nyStore->orderPizza("cheese");
    delete pizza;

    pizza = nyStore->orderPizza("pepperoni");
    delete pizza;

    delete nyStore;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
