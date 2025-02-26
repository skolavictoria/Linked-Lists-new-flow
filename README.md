# Student Assignment Review System

This repository template is designed to facilitate peer code reviews among students. It automates the process of tracking completed assignments and assigning peer reviewers.

## Workflow

1. **Setup**: 
   - The instructor creates a repository from this template
   - Students are added as developers to the repository (as a team)

2. **Assignment Submission**:
   - Each student creates a branch named `dev-<student-name>`
   - Students push their code to their respective branches
   - GitHub Actions automatically runs tests on each push
   - If all tests pass, the student is added to the review pool

3. **Peer Review**:
   - When the deadline arrives, each student in the review pool is assigned 3 random reviewers
   - Reviewers submit their reviews by creating a pull request from their branch to the student's branch
   - The PR should include a review file named `review-for-<student-name>.md`

# C++ Linked List Implementation Assignment

This assignment requires you to implement a singly linked list data structure in C++ from scratch. You will create a comprehensive implementation that includes all common linked list operations, as well as additional algorithms for searching, sorting, and reversing the list.

## Learning Objectives

- Understand the fundamental concepts of linked data structures
- Implement dynamic memory management in C++
- Develop algorithms for common linked list operations
- Gain experience with pointer manipulation
- Practice writing efficient search and sort algorithms

## Assignment Requirements

### 1. Basic Linked List Structure

You must implement a singly linked list with the following basic structure:

```cpp
// Node structure for the linked list
struct Node {
    int data;           // Data stored in the node
    Node* next;         // Pointer to the next node
    
    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head;         // Pointer to the first node
    int size;           // Number of nodes in the list

public:
    // Constructor and destructor
    LinkedList();
    ~LinkedList();
    
    // Basic operations
    // To be implemented by you...
};
```

### 2. Required Operations

Your implementation must include the following operations:

#### Basic Operations
- `void insertAtBeginning(int value)` - Insert a node at the beginning of the list
- `void insertAtEnd(int value)` - Insert a node at the end of the list
- `void insertAtPosition(int value, int position)` - Insert a node at a specific position
- `bool deleteFromBeginning()` - Delete the first node
- `bool deleteFromEnd()` - Delete the last node
- `bool deleteFromPosition(int position)` - Delete a node from a specific position
- `bool deleteValue(int value)` - Delete the first occurrence of a value
- `int getSize()` - Return the number of elements in the list
- `bool isEmpty()` - Check if the list is empty
- `void display()` - Print all elements in the list

#### Advanced Operations
- `Node* search(int value)` - Search for a value and return its node
- `void reverse()` - Reverse the linked list in-place
- `void sort()` - Sort the linked list (implement any efficient sorting algorithm)
- `void removeDuplicates()` - Remove duplicate values from the list
- `Node* getMiddleNode()` - Find the middle node of the list
- `bool detectLoop()` - Detect if the list contains a cycle
- `void clear()` - Remove all nodes from the list

### 3. Project Structure

Your submission should follow this structure:
```
dev-your-name/
├── src/
│   ├── linked_list.h     // Header file with class declaration
│   └── linked_list.cpp   // Implementation file
└── main.cpp              // Demo program showing usage of your linked list
```


## Repository Structure

- `.github/workflows/`: GitHub Actions workflow files
- `scripts/`: Automation scripts for managing the review process
- `review_pool.json`: Tracks students who have passed all tests
- `reviews/`: Directory where reviews are stored
- `tests/`: Test files to verify student submissions

## For Students

## Testing Your Implementation

Your code will be tested using pytest with a C++ extension. The tests will verify:
1. Correctness of all implemented operations
2. Memory management (no memory leaks)
3. Edge case handling
4. Performance for large lists

### What the Tests Will Check

The automated tests expect:
- Your linked list implementation to be in `src/linked_list.h` and `src/linked_list.cpp`
- The `LinkedList` class to have all the required methods with exactly the signatures specified
- Proper memory management (no memory leaks)
- Correct handling of edge cases (empty list, single element, etc.)

### Example Test Cases

The tests will check scenarios like:
- Creating an empty list and verifying it's empty
- Adding elements and checking the size
- Removing elements and verifying they're gone
- Searching for elements that exist and don't exist
- Sorting a list and verifying it's in order
- Reversing a list and checking the new order
- Handling edge cases like deleting from an empty list

## How to Submit

1. Clone this repository
2. Create your branch: `git checkout -b dev-your-name`
3. Implement your solution following the project structure
4. Push your code to your branch
5. If your code passes all tests, you'll be added to the review pool for peer review

## Tips for Success

1. Start by implementing the basic operations and test them thoroughly
2. Use proper memory management to avoid memory leaks
3. Consider edge cases in your implementation
4. Document your code with comments explaining your approach
5. Test your implementation with various inputs before submission

## Grading Criteria

Your implementation will be evaluated based on:
- Correctness (50%)
- Code quality and style (20%)
- Efficiency of algorithms (15%)
- Memory management (15%)

Good luck!
