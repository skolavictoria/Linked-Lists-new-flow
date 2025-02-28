Errors and problems in the code:

1. Memory leak in **eject** - you remove a node from the list, but do not delete it. The computer remembers it forever, and this is bad.

2. **del** and **pop** do not check if the list is empty - if you call them when there is nothing in the list, the program simply does nothing. It is better to check in advance.

3. **insert** does not check large numbers - if you tell it to insert a number in a place that does not exist, it will not be inserted at all. It is more logical to add it to the end.

4. **get_len()** calculates the length too slowly - each time the program re-calculates all the elements, but you can simply remember the number of elements.

5. **sortLinkedList()** sorts slowly - you use bubble sort, which takes a long time. There is a faster method - merge sort.

6. **printList()** does not write that the list is empty - if there is nothing in the list, it is simply silent. It is better to add **List is empty**.

7. There is no destructor - when the program finishes working, it does not clear the memory. You need to make the list delete itself.