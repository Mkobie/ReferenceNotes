# Abstract factory pattern: Interface for making families of related or dependent objects.

from abc import ABC, abstractmethod

# Ingredient Classes
class Dough:
    pass

class ThinCrustDough(Dough):
    pass

class Sauce:
    pass

class MarinaraSauce(Sauce):
    pass

# ********************************************************************************************
# Abstract Factory - instead of grouping similar products (eg all dough), group a spread of products that are needed in different contexts.
class PizzaIngredientFactory(ABC):
    @abstractmethod
    def create_dough(self):
        pass

    @abstractmethod
    def create_sauce(self):
        pass

# Concrete factory is here. Context is NY: NY class returns NY spread of products.
class NYPizzaIngredientFactory(PizzaIngredientFactory):
    def create_dough(self):
        return ThinCrustDough()

    def create_sauce(self):
        return MarinaraSauce()
# ********************************************************************************************

# Pizza that uses the Factory
class Pizza:
    def __init__(self, ingredient_factory):
        self.ingredient_factory = ingredient_factory
        self.dough = None
        self.sauce = None

    def prepare(self):
        print(f"Preparing {self.__class__.__name__}")
        self.dough = self.ingredient_factory.create_dough()
        self.sauce = self.ingredient_factory.create_sauce()

class CheesePizza(Pizza):
    pass

class PizzaStore(ABC):
    @abstractmethod
    def create_pizza(self, pizza_type):
        pass

    def order_pizza(self, pizza_type):
        pizza = self.create_pizza(pizza_type)
        pizza.prepare()
        return pizza

# Concrete pizza store that orchestrates using the factory
class NYPizzaStore(PizzaStore):
    def create_pizza(self, pizza_type):
        ingredient_factory = NYPizzaIngredientFactory()
        if pizza_type == "cheese":
            return CheesePizza(ingredient_factory)
        else:
            raise ValueError(f"Unknown pizza type: {pizza_type}")


store = NYPizzaStore()
pizza = store.order_pizza("cheese")
