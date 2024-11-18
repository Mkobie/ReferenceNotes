#include <iostream>
#include <queue>

void demo_queues() {
    // Container adapter type, based typically on the dequeue (double ended queue) data structure.
    // Use when:
    // - need FIFO order
    std::queue<std::string> my_queue;

    my_queue.push("apple");  //  O(1)
    my_queue.push("banana");
    my_queue.pop();  //  O(1) Remove the front element

    std::string front_queue = my_queue.front();  //  O(1). Access the front element without removing it
    std::string back_queue = my_queue.back();  //  O(1). Access the back element without removing it

    // Print and empty the queue
    std::cout << "Contents of the queue: ";  // O(n) to go through all elements
    while (!my_queue.empty()) {
        std::cout << my_queue.front() << " ";
        my_queue.pop();
    }
    std::cout << std::endl;

    // Other common fns
    std::size_t queue_size = my_queue.size();  // O(1). Size = number of elements
    std::cout << "Queue is empty? " << my_queue.empty();  // O(1)
    // No clear fn for queues - they are not intended to be emptied at once.
}


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "QUEUES" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_queues();
    std::cout << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
