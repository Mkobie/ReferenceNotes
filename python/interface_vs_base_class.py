from abc import ABC, abstractmethod

class Animal(ABC):
    @abstractmethod
    def make_sound(self):  # <-- interface-esque: enforces a contract for this
        pass


    def eat(self):  # <-- base-class-esque: provides reusable behaviour for this
        print("Eating food")

#============================================
# Base class
#============================================
# Base class properties:
# - Purpose: shared functionality & behaviour based on a hierarchy.
# - relates to its derived classes via some hierarchy
# - can contain common implementation (methods / attributes)
#   - overriding common methods is generally ok - this is how we achieve polymorphism and specialization
#       - but beware of violating the LSP
#   - but beware of overriding common attributes - they are not inherently polymorphic.
# - establishes shared behaviour
# - can be an ABC, or have abstract methods, but doesn't have to be
# - it's about reuse

class Animal:
    def __init__(self):
        self.type = "Generic Animal"  # doesn't need the init to be a base class; including to show attribute pitfall in Dog

    def eat(self):
        print("This animal is eating")

    def make_sound(self):
        print("This animal makes a generic sound")

class Dog(Animal):
    def __init__(self):
        super().__init__()  # Here's a warning already - we're going to override this, making this line useless
        self.type = "Dog"  # BAD - lose the logic of d = Dog(); d.type --> no longer "animal"! Weird behaviour ahoy!

    def make_sound(self):
        print("Bark!")  # behaviour specific to subclass - ok!

# ---------------------------------------------------------

#============================================
# Interface
#============================================
# Interface properties:
# - Purpose: Specifies a contract for implementation.
# - purely abstract, NO implementation.
# - contains methods ALL subclasses must implement
# - it's about consistency across implementations
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def draw(self):
        pass

    @abstractmethod
    def area(self):
        pass

class Circle(Shape):
    def draw(self):
        print("Drawing a circle")

    def area(self):
        return 3.14 * (5 ** 2)
