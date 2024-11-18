#include "_helper.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>


void demo_fundamental_aka_basic_parameter_types() {
    std::cout << "\nFundamental (basic) parameter types:" << std::endl;
    printBreak();

    bool boolean = true;
    char character = 'A';
    wchar_t wide_character = L'Ω';
    int integer = 42;
    float floating_point_float = 3.14f;
    double floating_point_double = 5.9;

    printSizeAndRangeHeader();
    printSizeAndRange("Boolean", boolean);
    printSizeAndRange("Character", character);
    printSizeAndRange("Wide Character", wide_character);
    printSizeAndRange("Integer", integer);
    printSizeAndRange("Float", floating_point_float);
    printSizeAndRange("Double", floating_point_double);
    printSizeAndRangeVoid("Void");
    printBreak();
    printSizeAndRangeFooter();
}

void demo_fixed_width_integer_types() {
    std::cout << "\nFixed width integer types:" << std::endl;
    printBreak();

    int8_t int8 = -120;
    uint8_t uint8 = 200;
    int16_t int16 = -32000;
    uint16_t uint16 = 65000;
    int32_t int32 = -2000000000;
    uint32_t uint32 = 4000000000U;
    int64_t int64 = -9223372036854775807LL;
    uint64_t uint64 = 18446744073709551615ULL;

    printSizeAndRangeHeader();
    printSizeAndRange("8-bit Int", int8);
    printSizeAndRange("8-bit UInt", uint8);
    printSizeAndRange("16-bit Int", int16);
    printSizeAndRange("16-bit UInt", uint16);
    printSizeAndRange("32-bit Int", int32);
    printSizeAndRange("32-bit UInt", uint32);
    printSizeAndRange("64-bit Int", int64);
    printSizeAndRange("64-bit UInt", uint64);
    printBreak();
}

void demo_built_in_derived_data_types() {
    std::cout << "\nBuilt in derived data types:" << std::endl;
    printBreak();

    int integer = 42;
    int *ptr_integer = &integer;
    int &ref_integer = integer;
    int array[5] = {1, 2, 3, 4, 5};
    char c_string[] = "C str";

    // User defined built in derived data types
    Color myColor = GREEN;
    MyUnion myUnion;
    myUnion.m_int = 1;
    myUnion.m_dbl = 2;  // Overwrites m_int
    MyStruct demo_struct = {10, 20.5};
    MyIntClass intClass(42);
    MyTwoIntsClass twoIntsClass(42, 43);

    printSizeAndRangeHeaderDerived();
    printSizeAndRangeNumber("Int", integer);
    printSizeAndRangeDerived("Pointer", ptr_integer);
    printSizeAndRangeReference("Reference (alias)", ref_integer);
    printSizeAndRangeArray("Array (int[5])", array);  // is this native, or a stl container?
    printSizeAndRangeCharArray("Char array", c_string);
    printSizeAndRangeEnum("Enum", myColor);
    printSizeAndRangeDerived("Union", myUnion);
    printSizeAndRangeNumber("- union m_int (1)", myUnion.m_int);
    printSizeAndRangeNumber("- union m_dbl (2)", myUnion.m_dbl);
    printSizeAndRangeDerived("Structure", demo_struct);
    printSizeAndRangeNumber("- struct m_int", demo_struct.m_int);
    printSizeAndRangeNumber("- struct m_dbl", demo_struct.m_dbl);
    printSizeAndRangeDerived("Class (1 int)", intClass);
    printSizeAndRangeNumber("- class int", intClass.m_int);
    printSizeAndRangeDerived("Class (2 ints)", twoIntsClass);
    printSizeAndRangeNumber("- class int1", twoIntsClass.m_int1);
    printSizeAndRangeNumber("- class int2", twoIntsClass.m_int2);
    printBreak();
}

void demo_stl_derived_data_types() {
    // Others include: Set, iterator, stack, queue, priority queue, pair
    std::cout << "\nSTL derived data types:" << std::endl;
    printBreak();

    std::string cpp_string = "C++ str";

    std::vector<int> myVector;
    myVector.push_back(42);

    std::map<int, std::string> myMap;
    myMap[1] = "one";
    myMap[2] = "two";
    std::map<int, std::string>::iterator it = myMap.begin();

    printSizeAndRangeHeaderDerived();
    printSizeAndRangeString("Char array", cpp_string);
    printSizeAndRangeDerived("Vector", myVector);  // on stack, lower address
    printSizeAndRangeNumber("- vector int1", myVector[0]);  // probably on heap due to dynamic allocation, higher address
    printSizeAndRangeDerived("Map", myMap);
    printSizeAndRangeNumber("- map begin first", it->first);
    printSizeAndRangeString("- map begin second", it->second);
    it = myMap.end(); --it;
    printSizeAndRangeNumber("- map end first", it->first);
    printSizeAndRangeString("- map end second", it->second);
    printBreak();
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "COMPARISON OF COMMON DATA TYPES" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_fundamental_aka_basic_parameter_types();
    demo_fixed_width_integer_types();
    demo_built_in_derived_data_types();
    demo_stl_derived_data_types();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
