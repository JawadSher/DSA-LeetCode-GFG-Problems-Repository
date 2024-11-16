<h1 align='center'>QUEUE - DATA STRUCTURE - PROBLEMS</h1>

<p align='center'>A <b>Qeueu</b> is a linear data structure that follows the **First In, First Out (FIFO)** principle. This means that the first element added to the queue will be the first one to be removed, similar to how people line up at a ticket counter — the person who arrives first is the first to be served.
</p>

### Repository Content
| No  | Problem Name                                 | Description |
| --- | -------------------------------------------- | ----------- |
| 01  | [Linear Queue Problems](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/16%20-%20Queue%20Data%20Structure%20Problems/01%20-%20Linear%20Queue%20Problems) | A collection of problems focused on basic operations of a **Linear Queue**, such as enqueue, dequeue, and checking if it's empty. |
| 02  | [Circular Queue Problems](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/16%20-%20Queue%20Data%20Structure%20Problems/02%20-%20Circular%20Queue%20Problems) | Problems related to **Circular Queues**, where the last element is connected to the first, optimizing space usage. |
| 03  | [Deque (Doubly Ended Queue) Problems](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/16%20-%20Queue%20Data%20Structure%20Problems/03%20-%20%28Deque%29%20Doubly%20Ended%20Queue%20Problems) | Problems on **Deque** (Double-Ended Queue) where elements can be added or removed from both ends. |

### Key Operations of a Queue

1. **Enqueue**: Adds an element to the back (rear) of the queue.
2. **Dequeue**: Removes the element from the front of the queue.
3. **Front/Peek**: Returns the element at the front of the queue without removing it.
4. **isEmpty**: Checks whether the queue is empty or not.
5. **Size**: Returns the number of elements currently in the queue.

### Types of Queues

1. **Simple Queue**: The basic form of a queue, where elements are added at the rear and removed from the front.
2. **Circular Queue**: A queue where the last position is connected back to the first position, forming a circle. This avoids wasted space when the front elements are dequeued but the rear still has space.
3. **Priority Queue**: A queue where each element is assigned a priority. The element with the highest priority is dequeued first, regardless of its position in the queue.
4. **Deque (Double-ended Queue)**: A queue where elements can be added or removed from both the front and the rear.

### Real-World Applications of Queues

- **Order Processing**: In systems like customer support or ticketing, requests are processed in the order they arrive.
- **Task Scheduling**: Operating systems use queues to schedule tasks, especially in multi-tasking environments, where processes are handled in the order they are ready for execution.
- **Breadth-First Search (BFS)**: In graph traversal, queues are used in BFS to explore nodes level by level.
- **Printer Queue**: A queue is used to manage print jobs in a printer, where documents are printed in the order they were submitted.

### Implementation of Queues

Queues can be implemented using two primary data structures:

1. **Array**: A queue can be implemented using an array, where elements are added at the end and removed from the front.
2. **Linked List**: A queue can also be implemented using a linked list, where elements are added to the tail and removed from the head.

---
Happy Coding 😊 
