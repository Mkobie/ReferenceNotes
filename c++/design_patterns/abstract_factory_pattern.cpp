#include <iostream>
#include <string>

// REMEMBER ALL NEWS NEED DELETES
// Be conscientious about which class "owns" each pointer, and is responsible for deleting it.

// Abstract Products
class Dough {
public:
    virtual std::string getDescription() const = 0;
    virtual ~Dough() {}
};

class Sauce {
public:
    virtual std::string getDescription() const = 0;
    virtual ~Sauce() {}
};

// Concrete Products
class ThinCrustDough : public Dough {
public:
    std::string getDescription() const { return "Thin Crust Dough"; }
};

class MarinaraSauce : public Sauce {
public:
    std::string getDescription() const { return "Marinara Sauce"; }
};

class ThickCrustDough : public Dough {
public:
    std::string getDescription() const { return "Thick Crust Dough"; }
};

class PlumTomatoSauce : public Sauce {
public:
    std::string getDescription() const { return "Plum Tomato Sauce"; }
};

// Abstract Factory
class PizzaIngredientFactory {
public:
    virtual Dough* createDough() const = 0;
    virtual Sauce* createSauce() const = 0;
    virtual ~PizzaIngredientFactory() {}
};

// Concrete Factories
class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    Dough* createDough() const { return new ThinCrustDough(); }  // Dynamically allocated (new) s.t. can hand them around
    Sauce* createSauce() const { return new MarinaraSauce(); }  // But be sure there's a corresponding "delete"!
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    Dough* createDough() const { return new ThickCrustDough(); }
    Sauce* createSauce() const { return new PlumTomatoSauce(); }
};

// Abstract Product
class Pizza {
protected:
    Dough* dough;
    Sauce* sauce;

public:
    virtual void prepare() = 0;
    virtual ~Pizza() {
        delete dough;
        delete sauce;
    }
};

class CheesePizza : public Pizza {
    PizzaIngredientFactory* ingredientFactory;

public:
    CheesePizza(PizzaIngredientFactory* factory) : ingredientFactory(factory) {}

    ~CheesePizza() {
        delete ingredientFactory;
    }

    void prepare() {
        std::cout << "Preparing Cheese Pizza\n";
        dough = ingredientFactory->createDough();  // Immediate client to the factory
        sauce = ingredientFactory->createSauce();
        std::cout << "Using " << dough->getDescription() << " and " << sauce->getDescription() << "\n";
    }
};

// Concrete Creator
class PizzaStore {
public:
    virtual Pizza* createPizza(const std::string& type) const = 0;

    Pizza* orderPizza(const std::string& type) const {
        Pizza* pizza = createPizza(type);
        if (pizza) {
            pizza->prepare();
            std::cout << "Baking, cutting, and boxing pizza...\n";
        }
        return pizza;
    }

    virtual ~PizzaStore() {}
};

class NYPizzaStore : public PizzaStore {
public:
    Pizza* createPizza(const std::string& type) const {
        PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory();
        Pizza* pizza = NULL;
        if (type == "cheese") {
            pizza = new CheesePizza(ingredientFactory);  // Specific pizza "has" the factory, so the specific pizza is in charge of deleting the factory.
        }
        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore {
public:
    Pizza* createPizza(const std::string& type) const {
        PizzaIngredientFactory* ingredientFactory = new ChicagoPizzaIngredientFactory();
        Pizza* pizza = NULL;
        if (type == "cheese") {
            pizza = new CheesePizza(ingredientFactory);
        }
        return pizza;
    }
};

// Client Code
int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Abstract factory pattern" << std::endl;
    std::cout << "==========================" << std::endl;

    PizzaStore* nyStore = new NYPizzaStore();
    Pizza* nyPizza = nyStore->orderPizza("cheese");
    delete nyPizza;
    delete nyStore;

    PizzaStore* chicagoStore = new ChicagoPizzaStore();
    Pizza* chicagoPizza = chicagoStore->orderPizza("cheese");
    delete chicagoPizza;
    delete chicagoStore;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
