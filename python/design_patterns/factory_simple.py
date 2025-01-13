# Simple factory - not actually a design pattern!
# Object creation is done in one place - a static method.

class Pizza:
    def prepare(self):
        print(f"Preparing {self.__class__.__name__}")

class CheesePizza(Pizza):
    pass

class PepperoniPizza(Pizza):
    pass

class ClamPizza(Pizza):
    pass

# Option 1: OOP.
# Why OOP? To convey design intent.
# Criticisms: Doesn't need to be a class (since is static), so should instead be a standalone fn in module.
class SimplePizzaFactory:
    @staticmethod  # interesting discussion on use of @staticmethod: https://www.reddit.com/r/learnpython/comments/1cfchb4/what_is_staticmethod_for/
    def create_pizza_from_class(pizza_type):
        if pizza_type == "cheese":
            return CheesePizza()
        elif pizza_type == "pepperoni":
            return PepperoniPizza()
        elif pizza_type == "clam":
            return ClamPizza()
        else:
            raise ValueError(f"Unknown pizza type: {pizza_type}")

# Option 2: Use namespaces
# Why no OOP? Doesn't abuse class structure when it's not needed.
# Downsides: Loses OOP intent.
def create_pizza_from_method(pizza_type):
    if pizza_type == "cheese":
        return CheesePizza()
    elif pizza_type == "pepperoni":
        return PepperoniPizza()
    elif pizza_type == "clam":
        return ClamPizza()
    else:
        raise ValueError(f"Unknown pizza type: {pizza_type}")


# Option 1 in action
factory = SimplePizzaFactory()
pizza = factory.create_pizza_from_class("cheese")  # context for pizza creation comes from class instance
pizza.prepare()

# # Option 2 example (commented out cause syntax doesn't work within this file!)
# pizza = factory_simple.create_pizza_from_method("cheese")  # context for pizza creation comes from module namespace (file name)
# pizza.prepare()
