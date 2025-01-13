# This is a situation where one of the factory patterns could be applied.
# Combos of things per car type will vary - new stuff expected!
# Tight coupling between CarFactory and Engine and Chassis subclasses
# SRP - CarFactory responsible for deciding which components to use PLUS building the car
# Open/closed - have to modify CarFactory if new car combo needed.

from abc import abstractmethod, ABC

def code_to_refactor():
    class Engine:
        def start(self):
            print("Starting a generic engine.")

    class V6Engine(Engine):
        def start(self):
            print("Starting a V6 engine.")

    class V8Engine(Engine):
        def start(self):
            print("Starting a V8 engine.")

    class Chassis:
        def assemble(self):
            print("Assembling a generic chassis.")

    class SportChassis(Chassis):
        def assemble(self):
            print("Assembling a sport chassis.")

    class LuxuryChassis(Chassis):
        def assemble(self):
            print("Assembling a luxury chassis.")

    class CarFactory:
        def build_car(self, car_type):
            if car_type == "sport":
                engine = V8Engine()
                chassis = SportChassis()
            elif car_type == "luxury":
                engine = V6Engine()
                chassis = LuxuryChassis()
            else:
                raise ValueError(f"Unknown car type: {car_type}")

            engine.start()
            chassis.assemble()
            print(f"{car_type.capitalize()} car built successfully!")


    # Example usage
    factory = CarFactory()
    factory.build_car("sport")
    factory.build_car("luxury")

#------------------------------------------
# Abstract factory pattern solution:
#==========================================
# Open/closed
# assembler doesn't know anything about the assembly type (beyond what the client class passes it)
# Good SRP

def abstract_factory_pattern_solution():
    class Engine(ABC):
        @abstractmethod
        def start(self):
            pass

    class V6Engine(Engine):
        def start(self):
            print("Starting a V6 engine.")

    class V8Engine(Engine):
        def start(self):
            print("Starting a V8 engine.")

    class Chassis(ABC):
        @abstractmethod
        def assemble(self):
            pass

    class SportChassis(Chassis):
        def assemble(self):
            print("Assembling a sport chassis.")

    class LuxuryChassis(Chassis):
        def assemble(self):
            print("Assembling a luxury chassis.")


    class CarFactory(ABC):
        @abstractmethod
        def make_engine(self):
            pass

        @abstractmethod
        def make_chassis(self):
            pass

    class SportsCarFactory(CarFactory):
        def make_engine(self):
            return V8Engine()

        def make_chassis(self):
            return SportChassis()

    class LuxuryCarFactory(CarFactory):
        def make_engine(self):
            return V6Engine()

        def make_chassis(self):
            return LuxuryChassis()

    class CarAssembler:
        def __init__(self, factory: CarFactory):
            self.factory = factory

        def build_car(self):
            engine = self.factory.make_engine()
            chassis = self.factory.make_chassis()
            engine.start()
            chassis.assemble()
            print(f"Car built successfully!")


    sports_car_factory = SportsCarFactory()
    luxury_car_factory = LuxuryCarFactory()

    assembler = CarAssembler(sports_car_factory)
    assembler.build_car()

    assembler = CarAssembler(luxury_car_factory)
    assembler.build_car()


if __name__ == "__main__":
    code_to_refactor()
    print("-------------")
    abstract_factory_pattern_solution()
