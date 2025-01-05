# The @property decorator in Python allows you to define a method that can be accessed like an attribute. It is commonly used to encapsulate and control access to attributes while maintaining a clean and intuitive interface for users of the class.
# How @property Works
#
#     Encapsulation:
#         Instead of directly exposing an attribute, you define a method to calculate or validate the value when accessed.
#     Read-Only Attributes:
#         You can make attributes appear read-only by defining only a getter.
#     Dynamic Behavior:
#         The value of the "attribute" can depend on other internal states or calculations.
#
# Basic Usage
#
# Here’s how it works:
#
# class Circle:
#     def __init__(self, radius):
#         self._radius = radius  # Use a private attribute to store the value
#
#     @property
#     def radius(self):
#         """Getter for radius"""
#         return self._radius
#
#     @radius.setter
#     def radius(self, value):
#         """Setter for radius with validation"""
#         if value < 0:
#             raise ValueError("Radius cannot be negative")
#         self._radius = value
#
#     @radius.deleter
#     def radius(self):
#         """Optional deleter for radius"""
#         print("Deleting radius...")
#         del self._radius
#
#
# # Usage
# circle = Circle(5)
# print(circle.radius)  # Access radius like an attribute, calls the getter
#
# circle.radius = 10  # Set radius, calls the setter
# print(circle.radius)  # 10
#
# del circle.radius  # Deletes the radius, calls the deleter
#
# How @property Works Internally
#
# The @property decorator turns a method into a property object, which manages the following:
#
#     Getter:
#         The method decorated with @property acts as a getter. Accessing the property calls this method.
#
#     Setter:
#         By defining a method with the same name and decorating it with @property_name.setter, you add a setter for the property.
#
#     Deleter:
#         Similarly, you can define a deleter with @property_name.deleter.
#
# Key Features of @property
#
#     Cleaner Syntax:
#         Access and modify "attributes" without the need for explicit method calls.
#         Compare:
#
# circle.set_radius(10)  # Old way
# print(circle.get_radius())
#
# With:
#
#         circle.radius = 10  # New way
#         print(circle.radius)
#
#     Encapsulation:
#         Protect internal data by using logic in the getter and setter.
#         Prevent direct modification or enforce validation.
#
#     Compatibility:
#         @property maintains backward compatibility. A public attribute can later become a property without changing the class's external interface.
#
# Example: Read-Only Property
#
# If you want a property that can only be read but not modified:
#
# class Rectangle:
#     def __init__(self, width, height):
#         self._width = width
#         self._height = height
#
#     @property
#     def area(self):
#         """Read-only property for the area"""
#         return self._width * self._height
#
#
# # Usage
# rect = Rectangle(5, 10)
# print(rect.area)  # 50
# rect.area = 100  # Raises AttributeError: can't set attribute
#
# Use Cases of @property
#
#     Validation:
#         Ensure values meet certain conditions before being set.
#
# @radius.setter
# def radius(self, value):
#     if value <= 0:
#         raise ValueError("Radius must be positive")
#
# Dynamic Calculation:
#
#     Calculate a value on the fly based on other attributes.
#
#     @property
#     def perimeter(self):
#         return 2 * 3.14159 * self._radius
#
#     Backward Compatibility:
#         Transition a class attribute to a method without breaking existing code.
#
# Comparison with Regular Methods
#
# Using methods for getter and setter:
#
# class Circle:
#     def __init__(self, radius):
#         self._radius = radius
#
#     def get_radius(self):
#         return self._radius
#
#     def set_radius(self, value):
#         if value < 0:
#             raise ValueError("Radius cannot be negative")
#         self._radius = value
#
# With @property:
#
# class Circle:
#     def __init__(self, radius):
#         self._radius = radius
#
#     @property
#     def radius(self):
#         return self._radius
#
#     @radius.setter
#     def radius(self, value):
#         if value < 0:
#             raise ValueError("Radius cannot be negative")
#         self._radius = value
#
# The @property version is cleaner and makes the attribute feel like a regular field while still providing control over its access.
# Key Takeaways
#
#     Use @property to add logic when accessing or modifying attributes while keeping a clean interface.
#     It is particularly useful for validation, dynamic calculations, or making attributes read-only.
#     Avoid direct manipulation of internal attributes and prefer @property for better encapsulation.