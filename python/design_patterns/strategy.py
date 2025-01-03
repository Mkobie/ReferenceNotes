from abc import ABC, abstractmethod

# Want to add a new fly behaviour? Setup encourages you to make add a new fly behaviour implementation
# (open/closed principle)

# Strategy interface for fly behaviour (encapsulation; programming to an interface)
class FlyBehavior(ABC):
    @abstractmethod
    def fly(self):
        pass

# Concrete Fly Behaviors
class FlyWithWings(FlyBehavior):  # FlyWithWings "is a" FlyBehaviour implementation (decoupled; single responsibility)
    def fly(self):
        return "I'm flying with wings!"

class FlyNoWay(FlyBehavior):
    def fly(self):
        return "I can't fly."


# Strategy interface for quack behaviour (encapsulated)
class QuackBehavior(ABC):
    @abstractmethod
    def quack(self):
        pass

# Concrete Quack Behaviors
class Quack(QuackBehavior):
    def quack(self):
        return "Quack!"

class Squeak(QuackBehavior):
    def quack(self):
        return "Squeak!"

class MuteQuack(QuackBehavior):
    def quack(self):
        return "<< Silence >>"


# Client
class Duck(ABC):
    # Duck "has a" fly behaviour and "has a" quack behaviour (composition over inheritance)
    def __init__(self, fly_behavior: FlyBehavior, quack_behavior: QuackBehavior):
        self.fly_behavior = fly_behavior
        self.quack_behavior = quack_behavior

    def perform_fly(self):
        return self.fly_behavior.fly()  # behaviour delegation (encapsulated behaviour)

    def perform_quack(self):
        return self.quack_behavior.quack()

    @abstractmethod
    def display(self):
        pass

    def set_fly_behavior(self, fly_behavior: FlyBehavior):  # runtime flexibility
        self.fly_behavior = fly_behavior

    def set_quack_behavior(self, quack_behavior: QuackBehavior):
        self.quack_behavior = quack_behavior

# Concrete Duck implementations
class MallardDuck(Duck):  # MallardDuck "is a" Duck
    def __init__(self):
        super().__init__(FlyWithWings(), Quack())

    def display(self):
        return "I'm a Mallard Duck!"

class RubberDuck(Duck):
    def __init__(self):
        super().__init__(FlyNoWay(), Squeak())

    def display(self):
        return "I'm a Rubber Duck!"

class DecoyDuck(Duck):
    def __init__(self):
        super().__init__(FlyNoWay(), MuteQuack())

    def display(self):
        return "I'm a Decoy Duck!"

# Using the pattern
if __name__ == "__main__":
    mallard = MallardDuck()
    rubber = RubberDuck()
    decoy = DecoyDuck()

    print(mallard.display())
    print(mallard.perform_fly())
    print(mallard.perform_quack())

    print(rubber.display())
    print(rubber.perform_fly())
    print(rubber.perform_quack())

    print(decoy.display())
    print(decoy.perform_fly())
    print(decoy.perform_quack())

    # Changing behavior at runtime
    print("\nChanging DecoyDuck's fly behavior...")
    decoy.set_fly_behavior(FlyWithWings())
    print(decoy.perform_fly())
