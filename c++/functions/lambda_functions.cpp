// /* NOTE: C++11 only!
// // Lambda (aka anonymous) function syntax:
//
// [capture] (parameters_list) -> return_type {
//     // Statements
// }
//
// // Can store them in variables:
// auto variable_name {[capture] (parameters_list) -> return_type {
//     // Statements
// }};
//
// */
//
// #include <iostream>
//
// void demo_non_lambda_greeting() {
//     std::cout << "Hello world!" << std::endl;
// }
//
// void demo_lambda_greeting() {
//     []() {
//         std::cout << "Hello world!" << std::endl;
//     }();
// }
//
// int helper_non_lambda_multiply(int x) {
//     return x * 10;
// }
//
// void demo_non_lambda_and_lambda_multiply_main() {
//     bool show_lambda = true;
//     int number {};
//     int result {};
//
//     std::cout << "Please type a number: ";
//     std::cin >> number;
//
//     if (show_lambda) {
//         // Defining the lambda function
//         auto lambda_multiply {[](int x) {
//             return x * 10;
//         }};
//
//         // Using the lambda function
//         result = lambda_multiply(number);
//     } else {
//         result = helper_non_lambda_multiply(number);
//     }
//
//     std::cout << "The result is: " << result << std::endl;
// }
//
// void demo_lambda_capture_by_value() {
//     std::string word {};
//     std::cout << "Please type a word: ";
//     std::cin >> word;
//
//     // Defining the lambda function
//     auto compare { [word](std::string other_word) {
//         return word == other_word; // Note, word is read only. (captured by value)
//     }};
//
//     // Using the lambda function
//     // Compare against "Hi"
//     if (compare("Hi")) {
//         std::cout << "Congrats! Your word is Hi" << std::endl;
//     } else {
//         std::cout << "Bad luck, try again" << std::endl;
//     }
// }
//
// void demo_lambda_capture_by_reference() {
//     int count {};
//
//     auto counter {[&count]() { // Capturing by reference
//         ++count;
//         std::cout << "Count: " << count << std::endl;
//     }};
//
//     // Call counter three times
//     for (int i = 0; i < 3; ++i) {
//         counter();
//     }
//
//     std::cout << "Final count: " << count << std::endl;
// }
//
// auto helper_demo_dangling_reference_dangers() {
//     int x = 10;
//     return [&]() { std::cout << x << std::endl; };  // Dangling reference
// }
//
// void demo_dangling_reference_dangers() {
//     auto myLambda = helper_demo_dangling_reference_dangers();
//     myLambda();  // Undefined behavior
// }
//
// void demo_capture_all_variables() {
//         std::string firstWord {};
//         std::string secondWord {};
//
//         // Getting the two words from the user
//         std::cout << "Type the first word: ";
//         std::cin >> firstWord;
//         std::cout << "Type the second word: ";
//         std::cin >> secondWord;
//
//         auto writeSentence{[=]() { // Capture all variables by value. Use [&] instead to get all by ref
//             std::cout << firstWord << " " << secondWord << std::endl;
//         }};
//
//         writeSentence();
//
//     auto changeValue {[&value](){
//         value *= 2;
//     }};
// }
//
// int main() {
//     std::cout << "--------------------------" << std::endl;
//     std::cout << "LAMBDA FUNCTIONS" << std::endl;
//     std::cout << "==========================" << std::endl;
//
//     demo_non_lambda_greeting();
//     demo_lambda_greeting();
//     std::cout << std::endl;
//     demo_non_lambda_and_lambda_multiply_main();
//     std::cout << std::endl;
//     demo_lambda_capture_by_value();
//     std::cout << std::endl;
//     demo_lambda_capture_by_reference();
//     std::cout << std::endl;
//     demo_dangling_reference_dangers();
//
//     std::cout << "--------------------------" << std::endl << std::endl;
//     return 0;
// }