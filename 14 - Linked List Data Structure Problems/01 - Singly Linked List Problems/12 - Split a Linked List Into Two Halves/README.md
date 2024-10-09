<h1 align='center'>Split - a Linked - List - Into Two - Halves</h1>

## Problem Statement

**Problem URL :** [Split a Linked List Into Two Halves](https://www.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/4a12d8e8-2bb5-4534-951d-7d4b3e7f30c2)
![image](https://github.com/user-attachments/assets/fc0a36f9-e645-437e-8b3b-73207f5c0651)

## Problem Explanation
**Description**: The problem is to split a circular linked list into two halves. A circular linked list is a variation of a linked list where all nodes are connected in a circular manner, meaning the last node points back to the first node instead of pointing to `nullptr`.

**Goal**: Given the head of a circular linked list, you need to split it into two halves and return the heads of the two resulting circular linked lists.

### Approach to Solve the Problem

To solve the problem, we can use the **Tortoise and Hare** algorithm (also known as the slow and fast pointer technique) to find the midpoint of the circular linked list. Here’s a step-by-step approach:

1. **Check for Edge Cases**: 
   - If the list is empty (`head` is `nullptr`), return two `nullptr` values.
   - If the list contains only one node (i.e., the `next` pointer of the head points to itself), return the head for both halves.

2. **Initialize Pointers**: 
   - Use two pointers: `slow` (moving one step at a time) and `fast` (moving two steps at a time) to find the midpoint of the circular list.

3. **Traverse the List**: 
   - Move the `slow` pointer one step and the `fast` pointer two steps until `fast` reaches the end of the list.
   - When the `fast` pointer can no longer move two steps without hitting the head again, the `slow` pointer will be at the midpoint.

4. **Split the List**: 
   - Set `head1` to the `head` of the list.
   - Set `head2` to the node following `slow` (the next node).
   - Adjust the pointers so that `slow` now points to `head1` to complete the first circular list.
   - Traverse from `head2` to find its last node and set its `next` pointer to `head2` to complete the second circular list.

5. **Return the Result**: 
   - Return the heads of the two circular linked lists.

## Problem Solution
```cpp
class Solution {
public:
    pair<Node *, Node *> splitList(struct Node *head) {
        if (!head) return {nullptr, nullptr}; 
        if (head->next == head) return {head, head}; 

        Node* slow = head;
        Node* fast = head;

        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;      
            fast = fast->next->next; 
        }

        Node* head1 = head;
        Node* head2 = slow->next;
 
        slow->next = head1; 

        Node* last = head2;
        while (last->next != head1 && last->next != head2) {
            last = last->next;
        }
        last->next = head2; 

        return {head1, head2};
    }
};
```

## Problem Solution Explanation
Here’s a detailed explanation of the provided solution:

```cpp
class Solution {
public:
    pair<Node *, Node *> splitList(struct Node *head) {
```
- **Class Definition**: Defines the class `Solution` with a public method to split the circular linked list.
- **Method Definition**: The method `splitList` takes the head of the circular linked list as input and returns a pair of pointers to the heads of the two resulting circular linked lists.

```cpp
        if (!head) return {nullptr, nullptr}; 
        if (head->next == head) return {head, head}; 
```
- **Edge Cases**: 
  - If `head` is `nullptr`, return two `nullptr` values.
  - If the list contains only one node (i.e., the `next` of the head points to itself), return the head for both halves.

```cpp
        Node* slow = head;
        Node* fast = head;
```
- **Pointer Initialization**: Initialize two pointers, `slow` and `fast`, both starting at the head of the list.

```cpp
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;      
            fast = fast->next->next; 
        }
```
- **Finding Midpoint**: Use a while loop to move the `slow` pointer one step at a time and the `fast` pointer two steps at a time.
  - The loop continues until `fast` reaches the end of the list or completes a full cycle.

```cpp
        Node* head1 = head;
        Node* head2 = slow->next;
```
- **Split the List**: 
  - `head1` is set to the current head of the list.
  - `head2` is set to the node following `slow`, which is the start of the second half.

```cpp
        slow->next = head1; 
```
- **Complete the First Circular List**: Set the `next` pointer of `slow` to `head1`, completing the first circular linked list.

```cpp
        Node* last = head2;
        while (last->next != head1 && last->next != head2) {
            last = last->next;
        }
```
- **Find Last Node of the Second Half**: Initialize a pointer `last` at `head2` and traverse to find the last node of the second half of the list. This node will need its `next` pointer updated.

```cpp
        last->next = head2; 
```
- **Complete the Second Circular List**: Set the `next` pointer of the last node of the second half to `head2`, completing the second circular linked list.

```cpp
        return {head1, head2};
    }
};
```
- **Return Result**: Return a pair containing the heads of the two circular linked lists.

### Examples to Illustrate the Code

1. **Example 1: Circular List with 6 Nodes**
   - **Input List:** `1 -> 2 -> 3 -> 4 -> 5 -> 6 -> (back to 1)`
   - **Execution Steps**:
     - Initialize `slow` and `fast` at `1`.
     - `slow` moves to `2`, `fast` moves to `3`; then `slow` moves to `3`, `fast` moves to `5`; finally, `slow` moves to `4`, and `fast` reaches `6`.
     - At this point, `slow` points to `4`, which is the midpoint.
     - Split:
       - `head1` becomes `1` and `head2` becomes `5`.
       - `slow->next` points to `1`, completing the first half.
       - `last` starts at `5` and moves to `6` and then back to `1`, completing the second half.
   - **Output:** 
     - **First Half:** `1 -> 2 -> 3 -> 4 -> (back to 1)`
     - **Second Half:** `5 -> 6 -> (back to 5)`

2. **Example 2: Circular List with 3 Nodes**
   - **Input List:** `A -> B -> C -> (back to A)`
   - **Execution Steps**:
     - `slow` and `fast` both start at `A`.
     - `slow` moves to `B`, and `fast` moves to `C`. 
     - Since `fast` cannot move two steps forward, the loop exits.
     - Split:
       - `head1` becomes `A` and `head2` becomes `B`.
       - `slow->next` points to `A`, completing the first half.
       - `last` starts at `B`, moves to `C`, and then to `A`, completing the second half.
   - **Output:** 
     - **First Half:** `A -> B -> (back to A)`
     - **Second Half:** `C -> (back to C)`

3. **Example 3: Circular List with 1 Node**
   - **Input List:** `X -> (back to X)`
   - **Execution Steps**:
     - The list contains only one node.
     - According to the edge case check, `head` is returned for both halves.
   - **Output:** 
     - **First Half:** `X -> (back to X)`
     - **Second Half:** `X -> (back to X)`

### Conclusion

The provided solution efficiently splits a circular linked list into two halves by leveraging the slow and fast pointer technique to find the midpoint. Understanding the mechanics of linked lists and pointer manipulation is crucial for solving this problem effectively. By following the explanation and examples, beginners should be able to grasp the concept and implement the solution successfully.
