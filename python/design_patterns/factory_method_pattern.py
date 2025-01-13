# Factory method pattern: Defines an interface for making an object, but lets a subclasses decide what class to instantiate.

from abc import ABC, abstractmethod

class Pizza:
    def prepare(self):
        print(f"Preparing {self.__class__.__name__}")
    def bake(self):
        print("Baking pizza")
    def cut(self):
        print("Cutting pizza")
    def box(self):
        print("Boxing pizza")

class NYStyleCheesePizza(Pizza):
    pass

class PizzaStore(ABC):
    @abstractmethod
    def create_pizza(self, pizza_type):  # This "is" the factory **************************
        pass

    def order_pizza(self, pizza_type):
        pizza = self.create_pizza(pizza_type)  # It's used here
        pizza.prepare()
        pizza.bake()
        pizza.cut()
        pizza.box()
        return pizza

class NYPizzaStore(PizzaStore):
    def create_pizza(self, pizza_type):
        if pizza_type == "cheese":
            return NYStyleCheesePizza()  # But the object type is "chosen" by the subclass here
        else:
            raise ValueError(f"Unknown pizza type: {pizza_type}")


# But really the client (the following code) is what causes a specific object type to be invoked.
store = NYPizzaStore()
pizza = store.order_pizza("cheese")
