<h1 align='center'>Reverse - Linked - List</h1>

## Problem Statement

**Problem URL :** [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)

![image](https://github.com/user-attachments/assets/e8f849be-0ad7-418f-b64b-f815fa117802)
![image](https://github.com/user-attachments/assets/007e30ca-c220-4b18-8206-f3b03830ce86)

## Problem Solution
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head -> next == NULL) return head;

        ListNode* previous = NULL;
        ListNode* current = head;

        while(current != NULL){
            ListNode* forward = current -> next;
            current -> next = previous;

            previous = current;
            current = forward;
        }

        return previous;
    }
};
```

## Problem Explanation

The problem "Reverse Linked List" on LeetCode asks you to reverse a singly linked list. Given the head of a singly linked list, your task is to reverse the list, such that the last node becomes the head and all nodes point in the opposite direction from their original state.

#### Example:
- Input: `1 -> 2 -> 3 -> 4 -> 5`
- Output: `5 -> 4 -> 3 -> 2 -> 1`

### Approach to Solve the Problem:

To reverse the linked list, we can use an iterative approach, where we adjust the `next` pointer of each node one by one to point to the previous node.

Here's a breakdown of the approach:

1. **Initialization**:
   - Start with two pointers: `previous` set to `NULL` (because the new tail will point to `NULL`) and `current` set to `head` (the starting node of the list).

2. **Reversing the Pointers**:
   - For each node in the linked list:
     - Save the next node (`forward = current -> next`) so you don’t lose access to the rest of the list.
     - Reverse the current node’s pointer (`current -> next = previous`) to point to the `previous` node.
     - Move the `previous` pointer to the `current` node (`previous = current`).
     - Move the `current` pointer to the saved `forward` node (`current = forward`).

3. **End Condition**:
   - Once `current` becomes `NULL` (end of the list), return the `previous` pointer, which will now be the new head of the reversed list.

## Problem Solution Explanation

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
```
- This is the function header for the `reverseList` function. It takes the `head` of a singly linked list as input and returns the new head of the reversed list.

```cpp
        if(head == NULL || head -> next == NULL) return head;
```
- **Base Case Check**: If the list is empty (`head == NULL`) or only has one node (`head -> next == NULL`), return the head as there’s nothing to reverse.

#### Example 1:
- Input: `head = NULL` (empty list)
- Output: `NULL` (no reversal needed)

#### Example 2:
- Input: `head = 1`
- Output: `1` (single node list doesn't change)

```cpp
        ListNode* previous = NULL;
        ListNode* current = head;
```
- **Pointer Initialization**: 
  - `previous = NULL`: This pointer will eventually be the tail of the reversed list (the new head).
  - `current = head`: This pointer will traverse through the original list node by node.

#### Example:
- Initial setup:
  - `head`: `1 -> 2 -> 3 -> 4 -> 5`
  - `previous = NULL`
  - `current = 1 -> 2 -> 3 -> 4 -> 5`

```cpp
        while(current != NULL){
```
- This is a loop that runs until `current` reaches the end of the list (i.e., `current == NULL`).

```cpp
            ListNode* forward = current -> next;
```
- **Save Next Node**: Before reversing the `next` pointer of `current`, save the next node in the list (`forward = current -> next`) to avoid losing access to the rest of the list.

#### Example (First Iteration):
- `current = 1 -> 2 -> 3 -> 4 -> 5`
- `forward = 2 -> 3 -> 4 -> 5`

```cpp
            current -> next = previous;
```
- **Reverse the Pointer**: Make the `next` of the `current` node point to `previous`, effectively reversing the link direction for this node.

#### Example (First Iteration):
- Original: `1 -> 2 -> 3 -> 4 -> 5`
- After reversing: `1 -> NULL` (the `next` of node `1` now points to `NULL`)
  
```cpp
            previous = current;
```
- **Move the `previous` Pointer**: Move `previous` to the current node, as the `previous` node now stores the reversed part of the list.

#### Example (First Iteration):
- `previous = 1 -> NULL` (node `1` is now part of the reversed list)

```cpp
            current = forward;
```
- **Move the `current` Pointer**: Move `current` to the `forward` node (saved earlier), which is the next node in the original list.

#### Example (First Iteration):
- `current = 2 -> 3 -> 4 -> 5`

This process continues until `current` becomes `NULL`.

#### Second Iteration:
- `current = 2 -> 3 -> 4 -> 5`
- `forward = 3 -> 4 -> 5`
- Reverse: `2 -> 1 -> NULL`
- Update pointers:
  - `previous = 2 -> 1 -> NULL`
  - `current = 3 -> 4 -> 5`

#### Final Iteration:
- When `current = 5`:
  - `previous = 5 -> 4 -> 3 -> 2 -> 1 -> NULL`
  - `current = NULL` (end of the list)

```cpp
        }
        return previous;
```
- Once the loop ends, `previous` will be the new head of the reversed list, so we return it.

### Example Walkthrough:

#### Example 1:
- Input: `head = 1 -> 2 -> 3 -> 4 -> 5`
- Iterations:
  1. Reverse `1 -> NULL`
  2. Reverse `2 -> 1 -> NULL`
  3. Reverse `3 -> 2 -> 1 -> NULL`
  4. Reverse `4 -> 3 -> 2 -> 1 -> NULL`
  5. Reverse `5 -> 4 -> 3 -> 2 -> 1 -> NULL`
- Output: `5 -> 4 -> 3 -> 2 -> 1 -> NULL`

#### Example 2:
- Input: `head = 7 -> 9 -> 12`
- Iterations:
  1. Reverse `7 -> NULL`
  2. Reverse `9 -> 7 -> NULL`
  3. Reverse `12 -> 9 -> 7 -> NULL`
- Output: `12 -> 9 -> 7 -> NULL`

This approach runs in O(n) time, where `n` is the number of nodes, and uses O(1) space, as no additional data structures are needed.
