#include <iostream>
#include <vector>

void demo_dynamic_allocation() {
    int numGuests;
    std::cout << "How many guests are you expecting? ";
    //Commented out user input for ease of running
    // std::cin >> numGuests;
    numGuests = 2;

    // OPTION HEAP: Dynamically allocate an array on the heap
    std::string *guest_list_heap = new std::string[numGuests];  // `new` returns pointer to beginning of allocated space
    // OPTION STACK: Create a vector on the stack to hold the guest names
    std::vector<std::string> guest_list_stack(numGuests);


    for (int i = 0; i < numGuests; i++) {
        std::string name;
        std::cout << "Enter the name of guest " << i+1 << ": ";
        //Commented out user input for ease of running
        // std::cin >> name;
        name = "Someone";
        guest_list_heap[i] = name;
        guest_list_stack[i] = name;
    }

    std::cout << "Number of guests (wrong): " << sizeof(guest_list_heap) << std::endl;  // Actually,  is size of pointer to heap
    std::cout << "Number of guests (wrong): " << sizeof(guest_list_stack) << std::endl;  // Actually, is size of vector obj
    std::cout << "Number of guests (right for vector): " << guest_list_stack.size() << std::endl;
    std::cout << "Number of guests (right for heap): " << numGuests << std::endl;  // Have to track size manually for heap.

    std::cout << "\nGuest List:\n";
    for (int i = 0; i < numGuests; i++) {
        std::cout << guest_list_heap[i] << "\n";
        std::cout << guest_list_stack[i] << "\n";
    }

    delete[] guest_list_heap;
}

void demo_dynamic_resize() {
    int *numbers = NULL;  // Remember to be explicit about pointers not pointing at anything
    int size = 0;

    int input;
    char choice;

    do {
        std::cout << "Enter a number: ";
        //Commented out user input for ease of running
        // std::cin >> input;
        input = 2;

        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = numbers[i];
        }
        temp[size] = input;

        delete[] numbers; // Deallocate the old array
        numbers = temp; // Assign the new array (so don't need to delete temp)

        size++;

        std::cout << "Do you want to enter another number? (Y/N): ";
        //Commented out user input for ease of running
        // std::cin >> choice;
        choice = 'N';
    } while (choice == 'Y' || choice == 'y');

    // Calculate the average
    double sum = 0.0;
    for(int i = 0; i < size; i++){
        sum += numbers[i];
    }
    double average = sum / size;

    std::cout << "Average: " << average << std::endl;

    delete[] numbers; // Deallocate the dynamic array
}

void demo_dynamic_memory_student_example() {
    std::string *names = NULL;
    int *grades = NULL;
    int *count = NULL;

    int numStudents;
    std::cout << "Enter the number of students: ";
    //Commented out user input for ease of running
    // std::cin >> numStudents;
    numStudents = 2;

    names = new std::string[numStudents];
    grades = new int[numStudents];
    count = new int[numStudents];

    for (int i = 0; i < numStudents; i++) {
        std::cout << "Enter the name of student " << i + 1 << ": ";
        //Commented out user input for ease of running
        // std::cin >> names[i];
        names[i] = "Someone";

        std::cout << "Enter the grade for " << names[i] << ": ";
        //Commented out user input for ease of running
        // std::cin >> grades[i];
        grades[1] = 10;

        count[i] = i + 1;
    }

    std::cout << "\nEntered data:\n";
    for (int i = 0; i < numStudents; i++) {
        std::cout << "Student " << i + 1 << ": " << names[i] << ", Grade: " << grades[i] << std::endl;
    }

    delete[] names;
    delete[] grades;
    delete[] count;
}

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "DYNAMIC MEMORY" << std::endl;
    std::cout << "==========================" << std::endl;

    demo_dynamic_allocation();
    std::cout << std::endl;
    demo_dynamic_resize();
    std::cout << std::endl;
    demo_dynamic_memory_student_example();

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
