# Memory leaks

In main(), Node* are created via new, but delete is not called anywhere, which leads to memory leaks.
The LinkedList class does not have a destructor that would free all nodes.

# Violation of encapsulation

first_elem in LinkedList is public, which allows it to be modified from the outside. It is better to make it private and add get_first_elem().

# Error in insert()

The code only handles position == 0, but does not insert an element into other positions.

# Error in del()

If position is larger than the list size, current can be nullptr, which will cause a segmentation fault.

# Error in sort()

The sorting algorithm does not work correctly, since it incorrectly changes the next_member pointers.

# The Reverse() method is empty

Declared, but not implemented.