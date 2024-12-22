<h1 align='center'>DEQUE - DATA STRUCTURE - PROBLEMS</h1>

<p align='center'>A <b>Circular Deque</b> is an advanced version of the double-ended queue (Deque) that behaves like a circular buffer. Unlike a linear deque, which allows insertion and deletion of elements from both ends (front and rear), the circular deque links the last position to the first position, creating a loop. This allows for more efficient use of space and ensures that the queue can be used in continuous cycles without the risk of unused memory.</p>

In a circular deque, when either the front or the rear pointer reaches the ends of the queue, it automatically wraps around to the beginning if there is available space. This property is particularly useful in applications where continuous and efficient data processing is needed, such as in task scheduling, resource management, and buffering data streams.

Key operations in a circular deque include:
- **Insert Front**: Adds an element at the front of the deque.
- **Insert Rear**: Adds an element at the rear of the deque.
- **Delete Front**: Removes an element from the front.
- **Delete Rear**: Removes an element from the rear.
- **Get Front**: Returns the front element without removing it.
- **Get Rear**: Returns the rear element without removing it.
- **IsEmpty**: Checks if the deque is empty.
- **IsFull**: Checks if the deque is full.

Circular deques are widely used in scenarios such as:
- Buffering and streaming data
- Task scheduling with fixed time slots
- Implementing efficient queues in operating systems

### Repository Content

<p>
<img src="https://img.shields.io/badge/problems%20count-01-orange?logo=leetcode" alt="LeetCode">
<img src="https://img.shields.io/badge/problems%20count-00-darkgreen?logo=geeksforGeeks" alt="GeeksforGeeks">
<img src="https://img.shields.io/badge/total%20problems%20count-02-blue" alt="Problem Count"> 
</p>

| No | Problem Name | Description | LeetCode | GFG |
| --- | ------------ | ----------- | -------- | ----- |
| 01 | [Example](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/16%20-%20Queue%20Data%20Structure%20Problems/03%20-%20(Deque)%20Doubly%20Ended%20Queue%20Problems/01%20-%20Example) | Implement a circular deque using arrays with basic operations. | Non | Non |
| 02 | [Design Circular Deque](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/16%20-%20Queue%20Data%20Structure%20Problems/03%20-%20(Deque)%20Doubly%20Ended%20Queue%20Problems/01%20-%20Example) | Design a circular deque supporting insertions and deletions from both ends. | [Link](https://leetcode.com/problems/design-circular-deque/description/) | Non |

---
Happy Coding 😊
