
To compile & run the system just open the assignment2 directory and run make command in terminal.  
Then run the executable as ./lab2.

There are three hpp files("cStack.hpp","deque.hpp","heap.hpp") .

The use of various functionalities are mentioned in the comments.

cStack:
cStack is a data structure which uses one single array of size N to simulate two stacks. Size of these two stacks combined can be at most capacity either given by the user or default value of 100. One of the two stacks, Red stack, starts from start  of the array while the other stack, Blue stack, starts from the end. All the standard: push, pop, is empty, size, operations take O(1) time.

Deque:
Deque is a data structure similar to a queue with additional functionality that elements can be added or removed from both ends. In this problem, a deque was simulated using two cStacks. The first cStack, que, is the cStack containing the deque elements, while the other complimentry is used to optimize the deque operations. In que, insertion or deletion from the front takes place in the Red stack, whereas insertion and deletion from the back takes place in the Blue stack.
Whenever either of the stack is empty, and the other stack has more than one element, the elements are split equally in both the stacks, while maintaing their order. This balancing property helps us achieve all deque operations: insert front, delete front, insert back, delete back, front, back, size, is empty, in an average time complexity of O(1).

In the worst case, either of the stacks, say Red has N elements, while the other stack, say Blue stack is empty, and we want to delete from the Blue stack. Lets say we want to remove N elements from the back, and blue stack (responsible for rear operations) is empty.
For first removal it will take N operations to split the stack equally.
For the next N/2 operations, each removal will take 1 operation.
For the next removal, it will take N/2 operations to split the stack.
For the next N/4 operations, each removal will take 1 operation.
This will continue. Hence for N removals, total operations would be:
N + N + N/2 + N/2 + N/4 + N/4 + N/8 + N/8 ......

= N(2*(1 + 1/2 + 1/4 + 1/8 .... )) = 4N.

Hence average case for one operation would take 4N/N = 4 operations which is a constant. Hence average time complexity is O(1).

Heap:

Heap is a tree based data structure that satisfies "heap-based" property, that is a parent has a higher priority than its children.
Insertions and Deletion in Heap takes O(logn) time, since we have to iterate through the height to heapify, as well as, to update our last pointer. The build-heap function takes an array of elements in the input. Using the bottom up approach, build heap takes O(n) time. 
The traverse function, converts the heap binary tree into an array with the in-order representation of the heap. Using the in-order function, the heap is converted into an array of elements. Using this function, while merging two heaps, both the heaps are converted into two arrays, later merged into one and made into one binary heap by calling the buildHeap function. These processes take O(n) time, O(n) for conversion to array, O(n) to merge and O(n) to build the heap. Total time = 3 O(n) which is O(n).
The utility functions are made for convieneince of other interface functions and are kept public.The all utility functions take constant amount of time. 