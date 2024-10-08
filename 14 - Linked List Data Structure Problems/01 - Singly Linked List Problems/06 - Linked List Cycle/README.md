<h1 align='center'>Linked - List - Cycle</h1>

## Problem Statement

**Problem URL :** [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

![image](https://github.com/user-attachments/assets/01defcf0-31c0-43c0-b95a-a934f9e7965d)
![image](https://github.com/user-attachments/assets/af949d64-fbb6-472e-9bda-08d0ffa6496f)

## Problem Explanation
The problem "Linked List Cycle" asks whether a given singly linked list contains a cycle (loop). A cycle in a linked list occurs if, at some point, a node in the list points back to one of the previous nodes instead of pointing to `NULL` (the end of the list). This means the list can be infinitely traversed without ever reaching the end.

### Example 1: List Without a Cycle
```
1 -> 2 -> 3 -> 4 -> NULL
```
In this list, each node points to the next one, and the last node points to `NULL`. There is no cycle here.

### Example 2: List With a Cycle
```
1 -> 2 -> 3 -> 4 -> 5
        ^           |
        |-----------|
```
In this list, node 5 points back to node 3, forming a cycle. If you traverse this list, you will never reach the end because the traversal loops indefinitely.

### Problem Task:
Write a function that takes the head of a singly linked list and returns `true` if there is a cycle in the list, and `false` otherwise.

---

### Approach: **Floyd’s Cycle Detection Algorithm (Tortoise and Hare)**

A beginner-friendly approach to solve this problem is to use **two pointers**: `slow` and `fast`. This is a famous technique known as **Floyd’s Cycle Detection Algorithm** (also called the Tortoise and Hare algorithm).

**How it works:**
1. You initialize two pointers, `slow` and `fast`, both starting at the head of the list.
2. `slow` moves one step at a time, while `fast` moves two steps at a time.
3. If there is no cycle, `fast` will eventually reach the end (`NULL`), meaning the list is acyclic.
4. If there is a cycle, at some point, `slow` and `fast` will meet at the same node inside the cycle.
5. If `slow` and `fast` meet, this confirms there is a cycle. Otherwise, the loop terminates and the function returns `false`.

This approach is efficient because:
- It uses **O(1) extra space** (no need for additional data structures).
- It runs in **O(n) time complexity**, where `n` is the number of nodes in the list.

## Problem Solution
```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){

            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) return true;
        }

        return false;
    }
};
```

## Problem Solution Explanation

1. **`bool hasCycle(ListNode *head)`**: This is the function that checks if there is a cycle in the linked list. It takes the head of the list as input and returns `true` or `false`.

2. **`if(head == NULL) return false;`**: This line handles an edge case. If the list is empty (`head == NULL`), there can't be a cycle, so the function returns `false`.

3. **`ListNode* slow = head;`**: This initializes the `slow` pointer to the head of the list.

4. **`ListNode* fast = head;`**: This initializes the `fast` pointer to the head of the list. The `fast` pointer will move two steps at a time.

5. **`while(fast != NULL && fast->next != NULL)`**: The loop runs as long as `fast` and `fast->next` are not `NULL`. If `fast` or `fast->next` becomes `NULL`, it means we've reached the end of the list (no cycle).

6. **`slow = slow -> next;`**: The `slow` pointer moves one step forward.

7. **`fast = fast -> next -> next;`**: The `fast` pointer moves two steps forward.

8. **`if(slow == fast) return true;`**: If at any point, `slow` and `fast` meet, it means there is a cycle. The function returns `true` to indicate that a cycle was detected.

9. **`return false;`**: If the loop ends without `slow` and `fast` meeting, it means there is no cycle in the list, so the function returns `false`.

---

### Example Walkthrough:

#### Example 1: List without a cycle
```
1 -> 2 -> 3 -> 4 -> NULL
```

- Initially, `slow` and `fast` both point to `1`.
- After the first loop iteration: `slow` moves to `2`, `fast` moves to `3`.
- After the second loop iteration: `slow` moves to `3`, `fast` moves to `NULL`.
- Since `fast` reaches `NULL`, the function returns `false`.

#### Example 2: List with a cycle
```
1 -> 2 -> 3 -> 4 -> 5
        ^           |
        |-----------|
```

- Initially, `slow` and `fast` both point to `1`.
- After the first iteration: `slow` moves to `2`, `fast` moves to `3`.
- After the second iteration: `slow` moves to `3`, `fast` moves to `5`.
- After the third iteration: `slow` moves to `4`, `fast` moves to `4`.
- Since `slow` and `fast` meet at node `4`, the function returns `true`, indicating a cycle is detected.

---

### Time and Space Complexity:

- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the linked list.
  - The slow pointer traverses each node at most once. The fast pointer moves twice as fast but still traverses a limited number of nodes before detecting a cycle or reaching the end.
  
- **Space Complexity**: `O(1)` since we only use two pointers (`slow` and `fast`) and no additional data structures.

---

### Summary:
- The **Floyd’s Cycle Detection Algorithm** is a beginner-friendly and efficient solution to check for cycles in a linked list.
- It uses **two pointers**: one moving slowly and the other moving quickly. If the pointers meet, a cycle exists.
- The solution has an optimal time complexity of **O(n)** and uses **O(1)** space, making it suitable for large lists.
