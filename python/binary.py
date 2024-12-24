def demo_bitwise_and():
    num1, num2 = 0b1010, 0b1100
    bitwise_and = num1 & num2
    print(f"{bin(num1)} & {bin(num2)} = {bin(bitwise_and)}")  # 0b1000 (int 8)

def demo_bitwise_or():
    num1, num2 = 0b1010, 0b1100
    bitwise_or = num1 | num2
    print(f"{bin(num1)} | {bin(num2)} = {bin(bitwise_or)}")  # 0b1110 (int 14)

def demo_binary_string_conversions():
    # String -> binary
    binary_string = "10101"
    binary_value = int(binary_string, 2)  # Convert to integer (from base 2)
    print(f"Binary string '{binary_string}' as integer: {binary_value}")

    # Binary -> string
    binary_string_converted = bin(binary_value)[2:]  # Convert to binary string (remove "0b" from front)
    print(f"Integer {binary_value} as binary string: '{binary_string_converted}'")

def demo_binary_int_conversions():
    # Integer -> binary
    integer_value = 42
    binary_representation = bin(integer_value)  # Convert to binary
    print(f"Integer {integer_value} in binary: {binary_representation}")

    # Binary -> integer
    binary_to_convert = 0b1111
    integer_from_binary = int(binary_to_convert)  # Convert to integer
    print(f"Binary {bin(binary_to_convert)} as integer: {integer_from_binary}")


if __name__ == "__main__":
    print("--------------------------")
    print("BINARY")
    print("==========================")

    demo_bitwise_and()
    demo_bitwise_or()
    demo_binary_string_conversions()
    demo_binary_int_conversions()

    print("--------------------------")