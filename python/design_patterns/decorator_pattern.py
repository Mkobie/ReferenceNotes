from abc import ABC, abstractmethod

# Component Interface
class Beverage(ABC):
    @abstractmethod
    def get_description(self):
        pass

    @abstractmethod
    def cost(self):
        pass


# Concrete Components
class Espresso(Beverage):
    def get_description(self):
        return "Espresso"

    def cost(self):
        return 1.99

class HouseBlend(Beverage):
    def get_description(self):
        return "House Blend Coffee"

    def cost(self):
        return 0.89


# Decorator Base Class
class CondimentDecorator(Beverage, ABC):
    def __init__(self, beverage):
        self.beverage = beverage

    @abstractmethod
    def get_description(self):
        pass


# Concrete Decorators
class Mocha(CondimentDecorator):
    def get_description(self):
        return f"{self.beverage.get_description()}, Mocha"

    def cost(self):
        return self.beverage.cost() + 0.20

class Soy(CondimentDecorator):
    def get_description(self):
        return f"{self.beverage.get_description()}, Soy"

    def cost(self):
        return self.beverage.cost() + 0.15

class Whip(CondimentDecorator):
    def get_description(self):
        return f"{self.beverage.get_description()}, Whip"

    def cost(self):
        return self.beverage.cost() + 0.10


if __name__ == "__main__":
    # Order an Espresso with Mocha and Whip
    beverage = Espresso()
    print(f"{beverage.get_description()} ${beverage.cost():.2f}")

    beverage = Mocha(beverage)
    beverage = Whip(beverage)
    print(f"{beverage.get_description()} ${beverage.cost():.2f}")

    # Order a House Blend with Soy, Mocha, and Whip
    beverage2 = HouseBlend()
    beverage2 = Soy(beverage2)
    beverage2 = Mocha(beverage2)
    beverage2 = Whip(beverage2)
    print(f"{beverage2.get_description()} ${beverage2.cost():.2f}")
