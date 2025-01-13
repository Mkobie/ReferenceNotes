# This is a situation where the strategy pattern could be applied.
# Notice:
#   - if else handles multiple delivery types
#   - adding a new delivery type means changing the shipping calc method
#   - coupling between calculating shipping costs and delivery type

def code_to_refactor():
    class ShippingCalculator:
        def calculate_shipping_cost(self, delivery_type, weight):
            if delivery_type == "standard":
                return 5 + weight * 1.5
            elif delivery_type == "express":
                return 10 + weight * 2.0
            elif delivery_type == "overnight":
                return 20 + weight * 3.0
            else:
                raise ValueError("Unknown delivery type")


    calculator = ShippingCalculator()
    print(calculator.calculate_shipping_cost("standard", 10))
    print(calculator.calculate_shipping_cost("express", 10))
    print(calculator.calculate_shipping_cost("overnight", 10))


#------------------------------------------
# Here is the strategy pattern solution:
#==========================================
# + Strict separation of concerns (each shipping implementation is completely isolated from the others)
# + Flexibility for complex behaviors (diff shipping implementations can use totally different algorithms)
# + Extensibility (add new delivery type? don't touch existing code)
# - Repetitive (since behaviour is the same in this example, classes look the same)

from abc import ABC, abstractmethod

def strategy_pattern_solution():
    class ShippingStrategy(ABC):
        @abstractmethod
        def calculate_cost(self, weight):
            pass

    class StandardShipping(ShippingStrategy):
        def calculate_cost(self, weight):
            return 5 + weight * 1.5

    class ExpressShipping(ShippingStrategy):
        def calculate_cost(self, weight):
            return 10 + weight * 2.0

    class OvernightShipping(ShippingStrategy):
        def calculate_cost(self, weight):
            return 20 + weight * 3.0

    class ShippingCalculator:
        def __init__(self, strategy: ShippingStrategy):
            self.strategy = strategy

        def set_strategy(self, strategy: ShippingStrategy):
            self.strategy = strategy

        def calculate_shipping_cost(self, weight):
            return self.strategy.calculate_cost(weight)


    standard_strategy = StandardShipping()
    express_strategy = ExpressShipping()
    overnight_strategy = OvernightShipping()

    calculator = ShippingCalculator(standard_strategy)  # Notice: constructor DI (explicit)
    print(calculator.calculate_shipping_cost(10))

    calculator.set_strategy(express_strategy)
    print(calculator.calculate_shipping_cost(10))

    calculator.set_strategy(overnight_strategy)
    print(calculator.calculate_shipping_cost(10))

#------------------------------------------
# Or with method dependency injection
#==========================================
# - Dependency between calculator and strategy is less visible

def strategy_pattern_solution_with_DI():
    class ShippingStrategy(ABC):
        @abstractmethod
        def calculate_cost(self, weight):
            pass

    class StandardShipping(ShippingStrategy):
        def calculate_cost(self, weight):
            return 5 + weight * 1.5

    class ExpressShipping(ShippingStrategy):
        def calculate_cost(self, weight):
            return 10 + weight * 2.0

    class OvernightShipping(ShippingStrategy):
        def calculate_cost(self, weight):
            return 20 + weight * 3.0


    class ShippingCalculator:
        def calculate_shipping_cost(self, strategy: ShippingStrategy, weight):
            return strategy.calculate_cost(weight)

    calculator = ShippingCalculator()
    print(calculator.calculate_shipping_cost(StandardShipping(), 10))
    print(calculator.calculate_shipping_cost(ExpressShipping(), 10))
    print(calculator.calculate_shipping_cost(OvernightShipping(), 10))


#-------------------------------------------------------------------
# Here is a different solution that felt "right" (parameterization)
#===================================================================
# - Coupled behaviour & poor separation of concerns (all delivery types depend on having the same algorithm always)
# - Not open/closed (might have to modify existing stuff if a new delivery types needs a different algorithm)
# + DRY
# + Dynamic type creation (easy to add / modify options without making new classes)

def initial_solution_attempt_parameterization():
    class DeliveryType:
        def __init__(self, base_price, multiplier):
            self.base_price = base_price
            self.multiplier = multiplier

        def get_cost(self, weight) -> int:
            return self.base_price + weight * self.multiplier


    class ShippingCalculator:
        def calculate_shipping_cost(self, delivery_type: DeliveryType, weight):
            return delivery_type.get_cost(weight)


    calculator = ShippingCalculator()
    std_delivery = DeliveryType(5, 1.5)
    express_delivery = DeliveryType(10, 2.0)
    overnight_delivery = DeliveryType(20, 3.0)

    print(calculator.calculate_shipping_cost(std_delivery, 10))
    print(calculator.calculate_shipping_cost(express_delivery, 10))
    print(calculator.calculate_shipping_cost(overnight_delivery, 10))


#------------------------------------------
# Or with constructor dependency injection
#==========================================
# - Less real world sensibility in this case (why have 3 sep calculators?)

def initial_solution_attempt_parameterization_with_DI():
    class DeliveryType:
        def __init__(self, base_price, multiplier):
            self.base_price = base_price
            self.multiplier = multiplier

        def get_cost(self, weight) -> int:
            return self.base_price + weight * self.multiplier

    class ShippingCalculator:
        def __init__(self, delivery_type: DeliveryType):
            self.delivery_type = delivery_type

        def calculate_shipping_cost(self, weight):
            return self.delivery_type.get_cost(weight)

    std_delivery = DeliveryType(5, 1.5)
    express_delivery = DeliveryType(10, 2.0)
    overnight_delivery = DeliveryType(20, 3.0)

    standard_calculator = ShippingCalculator(std_delivery)
    express_calculator = ShippingCalculator(express_delivery)
    overnight_calculator = ShippingCalculator(overnight_delivery)

    print(standard_calculator.calculate_shipping_cost(10))
    print(express_calculator.calculate_shipping_cost(10))
    print(overnight_calculator.calculate_shipping_cost(10))


if __name__ == "__main__":
    code_to_refactor()
    print("-------------")
    strategy_pattern_solution()
    print("-------------")
    strategy_pattern_solution_with_DI()
    print("-------------")
    initial_solution_attempt_parameterization()
    print("-------------")
    initial_solution_attempt_parameterization_with_DI()
