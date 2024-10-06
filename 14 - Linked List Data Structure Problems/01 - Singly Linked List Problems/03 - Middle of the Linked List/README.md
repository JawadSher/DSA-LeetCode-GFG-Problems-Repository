<h1 align='center'>Middle - of the - Linked - List</h1>

## Problem Statement

**Problem URL :** [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)

![image](https://github.com/user-attachments/assets/abb0d9ed-2c20-4462-a58b-910a5e507f02)

## Problem Explanation
You are given a singly linked list, where each node contains an integer value. Your task is to find and return the middle node of the linked list. If there are two middle nodes (i.e., the linked list has an even number of nodes), return the second middle node.

For example:
- **Input**: `1 -> 2 -> 3 -> 4 -> 5`
  - **Output**: Node with value `3`
  
- **Input**: `1 -> 2 -> 3 -> 4 -> 5 -> 6`
  - **Output**: Node with value `4`

### Approach to Solve the Problem

To solve this problem, the goal is to determine the middle node in a linked list. One of the simplest approaches is:
1. **Calculate the total length of the list**: Traverse the linked list to find the total number of nodes.
2. **Determine the middle index**: Once we have the length, the middle node can be found by dividing the length by 2 (using integer division). If the list has `n` nodes, the middle node will be at position `n/2`.
3. **Traverse to the middle node**: Start from the head and move `n/2` steps to reach the middle node.

## Problem Solution
```cpp

class Solution {
private:
    int getlength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }

        return len;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int len = getlength(head);
        int ans = (len/2);

        int count = 0;
        while(ans != 0){
            head = head -> next;
            ans--;
        }

        return head;
    }
};
```

## Problem Solution Explanation

Let's go through the code step by step.

```cpp
class Solution {
private:
    int getlength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }

        return len;
    }
```

#### 1. `getlength(ListNode* head)` function:
- **Purpose**: This function calculates the total number of nodes (the length of the linked list).
- **How it works**:
  - **Line 1**: A variable `len` is initialized to `0` to keep track of the number of nodes.
  - **Line 2**: The function enters a `while` loop, which runs until `head` becomes `NULL` (end of the list).
  - **Lines 3-4**: In each iteration of the loop, `len` is incremented, and `head` is moved to the next node (`head = head->next`).
  - **Line 6**: Once the loop ends, the function returns the length of the list.
  
#### Example for `getlength()`:
- **Input**: `1 -> 2 -> 3 -> 4 -> 5`
  - First iteration: `head = 1`, `len = 1`
  - Second iteration: `head = 2`, `len = 2`
  - Third iteration: `head = 3`, `len = 3`
  - Fourth iteration: `head = 4`, `len = 4`
  - Fifth iteration: `head = 5`, `len = 5`
  - End of loop: `head = NULL`
  - **Output**: `len = 5` (total length of the list)

---

```cpp
public:
    ListNode* middleNode(ListNode* head) {
        int len = getlength(head);
        int ans = (len/2);
```

#### 2. `middleNode(ListNode* head)` function:
- **Line 1**: The function `middleNode()` is the main function called to find the middle node of the linked list.
- **Line 2**: It first calls `getlength(head)` to calculate the total length of the linked list and stores it in the variable `len`.
- **Line 3**: The middle position (or index) is calculated by dividing the length `len` by 2. This is stored in the variable `ans`.

#### Example of calculating middle position:
- If the linked list has `5` nodes (`1 -> 2 -> 3 -> 4 -> 5`), then `len = 5`, and `ans = len/2 = 5/2 = 2` (integer division).
- The 2nd index corresponds to the middle node with value `3`.

---

```cpp
        int count = 0;
        while(ans != 0){
            head = head -> next;
            ans--;
        }
```

#### 3. Traverse to the middle node:
- **Line 1**: The variable `count` is initialized to 0 (though not used in this version of the code).
- **Line 2-5**: The `while` loop moves the `head` pointer to the middle node:
  - The loop continues until `ans` becomes `0`.
  - In each iteration, `head` is moved to the next node (`head = head->next`), and `ans` is decremented by `1`.
  
This traversal effectively moves `head` to the middle node.

#### Example of traversing:
- For the list `1 -> 2 -> 3 -> 4 -> 5`, initially `ans = 2`:
  1. First iteration: `head = 2`, `ans = 1`
  2. Second iteration: `head = 3`, `ans = 0` (end of loop, `head` now points to the middle node with value `3`).

---

```cpp
        return head;
    }
};
```

#### 4. Return the middle node:
- **Line 1**: After exiting the loop, the `head` pointer now points to the middle node, and the function returns this node.

---

### Full Example Walkthrough:

#### Example 1: Odd Length List
- **Input**: `1 -> 2 -> 3 -> 4 -> 5`
  - Step 1: Calculate the length of the list (`len = 5`).
  - Step 2: Find the middle position (`ans = 5/2 = 2`).
  - Step 3: Move the `head` pointer 2 steps forward (`head = 3`).
  - **Output**: The middle node is `3`.

#### Example 2: Even Length List
- **Input**: `1 -> 2 -> 3 -> 4 -> 5 -> 6`
  - Step 1: Calculate the length of the list (`len = 6`).
  - Step 2: Find the middle position (`ans = 6/2 = 3`).
  - Step 3: Move the `head` pointer 3 steps forward (`head = 4`).
  - **Output**: The middle node is `4`.

### Time and Space Complexity:

- **Time Complexity**: O(n), where `n` is the number of nodes in the linked list. This is because we traverse the list twice: once to calculate the length and once to find the middle node.
- **Space Complexity**: O(1), since no additional data structures are used, and only a few variables are maintained.

This solution is straightforward, but it can be optimized to traverse the list only once, as in the two-pointer approach. However, this solution is simple and easy to understand.
