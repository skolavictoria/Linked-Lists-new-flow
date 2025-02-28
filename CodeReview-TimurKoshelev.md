# 1. Memory leaks

+ In the main Node objects deleted with new, but nowhere is deleted, which leads to memory destruction.

+ LinkedList does not have a destructor that would save all the memory.

# 2. Violation of encapsulation

+ The variable first_elem is public in LinkedList, which allows it to be directly modified from the outside, violating the principle of encapsulation.

+ The get_value() and get_next_member() methods from Node can be replaced with public variables, or left, but made const.

# 3. The sort() method is empty

+ It is proposed, but not implemented.