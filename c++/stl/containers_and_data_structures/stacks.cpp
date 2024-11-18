#include <iostream>
#include <stack>

void demo_stacks() {
    // Container adapter type, based typically on the dequeue (double ended queue) data structure.
    // Use when:
    // - need LIFO order
    std::stack<int> my_stack;

    my_stack.push(1);  //  O(1)
    my_stack.push(2);
    my_stack.pop();  //  O(1) Remove the top element

    int top_stack = my_stack.top();  //  O(1). Access the top element without removing it
    // No bottom fn for stacks - they are not intended to provide access that way.

    // Print and empty the stack
    std::cout << "Contents of the stack: ";  // O(n) to go through all elements
    while (!my_stack.empty()) {
        std::cout << my_stack.top() << " ";
        my_stack.pop();
    }
    std::cout << std::endl;

    // Other common fns
    std::size_t stack_size = my_stack.size();  // O(1). Size = number of elements
    std::cout << "Stack is empty? " << my_stack.empty();  // O(1)
    // No clear fn for stacks - they are not intended to be emptied at once.
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "STACKS" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_stacks();
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
