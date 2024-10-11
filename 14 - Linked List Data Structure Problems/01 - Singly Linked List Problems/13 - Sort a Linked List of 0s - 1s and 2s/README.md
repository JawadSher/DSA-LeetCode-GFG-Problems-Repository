<h1 align='center'>Sort - a Linked - List of - 0s - 1s - & 2s</h1>

## Problem Statement

**Problem URL :** [Sort a Linked LIst of 0s - 1s and 2s](https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)

![image](https://github.com/user-attachments/assets/5506ce03-7679-4d44-9960-702d8e5e2817)
![image](https://github.com/user-attachments/assets/956b0014-167d-4a0a-87f5-2c171542b8a0)

## Problem Explanation
The problem **"Sort Linked List of 0s, 1s, and 2s"** is about sorting a linked list that only contains the integers `0`, `1`, and `2` in an unsorted manner. The goal is to rearrange the nodes of the linked list such that all `0`s come first, followed by all `1`s, and then all `2`s, while preserving the original structure of the linked list. This problem is very similar to the Dutch National Flag problem.

### Approach for Beginners:
A beginner might think of multiple ways to solve this problem:

1. **Create 3 Separate Linked Lists**: 
   One straightforward approach is to traverse the linked list and create three separate linked lists for nodes with values `0`, `1`, and `2`. Then, merge these three lists together by connecting the tail of the `0` list to the head of the `1` list, and the tail of the `1` list to the head of the `2` list. This approach uses extra space for the new lists.

2. **Sort the Linked List (In-Place)**:
   Another approach is to count the occurrences of `0`s, `1`s, and `2`s while traversing the linked list. Once you have the counts, traverse the list again, overwriting the values in order. This approach is simple and works in-place, without using extra space for new lists.

The code provided follows the **second approach**.

---

## Problem Solution
```cpp
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        
        Node* temp = head;
        
        while(temp != NULL){
            if(temp -> data == 0){
                zeroCount++;
            }else if(temp -> data == 1){
                oneCount++;
            }else if(temp -> data == 2){
                twoCount++;
            }
            
            temp = temp -> next;
        }
        
        temp = head;
        while(temp != NULL){
            if(zeroCount != 0){
                temp -> data = 0;
                zeroCount--;
            }
             else if(oneCount != 0){
                temp -> data = 1;
                oneCount--;
            } else if(twoCount != 0){
                temp -> data = 2;
                twoCount--;
            }
            
            temp = temp -> next;
        }
        
        return head;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s, and 2s.
    Node* segregate(Node* head) {
```
- This is the beginning of the class definition. The function `segregate` is a member of the `Solution` class. It takes the head of the linked list as input (`Node* head`) and returns the head of the modified linked list after sorting it.

---

```cpp
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
```
- These three variables are initialized to count the number of nodes that contain the values `0`, `1`, and `2` in the linked list.
- Initially, all counts are set to `0`.

---

```cpp
        Node* temp = head;
```
- A temporary pointer `temp` is initialized to traverse the linked list. This pointer will be used to count the occurrences of `0`s, `1`s, and `2`s.

---

```cpp
        while(temp != NULL){
            if(temp -> data == 0){
                zeroCount++;
            }else if(temp -> data == 1){
                oneCount++;
            }else if(temp -> data == 2){
                twoCount++;
            }
            temp = temp -> next;
        }
```
- This `while` loop traverses the linked list once to count how many `0`s, `1`s, and `2`s are in the list.
- For each node, it checks the value (`temp -> data`). If the value is `0`, it increments `zeroCount`; if `1`, increments `oneCount`; and if `2`, increments `twoCount`.
- After processing each node, the `temp` pointer moves to the next node (`temp = temp -> next`) until the end of the list is reached (`temp != NULL`).

---

```cpp
        temp = head;
```
- The `temp` pointer is reset to point back to the head of the linked list to traverse the list again and modify the values.

---

```cpp
        while(temp != NULL){
            if(zeroCount != 0){
                temp -> data = 0;
                zeroCount--;
            } else if(oneCount != 0){
                temp -> data = 1;
                oneCount--;
            } else if(twoCount != 0){
                temp -> data = 2;
                twoCount--;
            }
            
            temp = temp -> next;
        }
```
- This `while` loop iterates through the linked list again.
- It first checks if `zeroCount` is not zero. If true, it sets the current node's value (`temp -> data`) to `0` and decrements `zeroCount`.
- If `zeroCount` is zero, it checks `oneCount` and similarly assigns the value `1` to the current node and decrements `oneCount`.
- If both `zeroCount` and `oneCount` are zero, it assigns the value `2` to the current node and decrements `twoCount`.
- After modifying the current node, the pointer moves to the next node (`temp = temp -> next`) until all nodes are processed.

---

```cpp
        return head;
    }
};
```
- Finally, the function returns the head of the modified linked list, which is now sorted with all `0`s, followed by `1`s, and then `2`s.

---

### Example Walkthroughs:

#### Example 1:
**Input Linked List**: `1 -> 0 -> 2 -> 1 -> 0 -> 2 -> NULL`

1. **Counting Phase**: 
   - The first loop will traverse the list and count `0`s, `1`s, and `2`s:
     - `zeroCount = 2` (since there are two `0`s),
     - `oneCount = 2` (since there are two `1`s),
     - `twoCount = 2` (since there are two `2`s).

2. **Modification Phase**:
   - The second loop will modify the values in the linked list based on the counts:
     - First 2 nodes will be assigned `0` (from `zeroCount`).
     - Next 2 nodes will be assigned `1` (from `oneCount`).
     - Last 2 nodes will be assigned `2` (from `twoCount`).

**Output Linked List**: `0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL`

---

#### Example 2:
**Input Linked List**: `2 -> 1 -> 0 -> NULL`

1. **Counting Phase**: 
   - `zeroCount = 1`, `oneCount = 1`, `twoCount = 1`.

2. **Modification Phase**:
   - First node will be assigned `0`.
   - Second node will be assigned `1`.
   - Third node will be assigned `2`.

**Output Linked List**: `0 -> 1 -> 2 -> NULL`

---

### Time and Space Complexity:
- **Time Complexity**: `O(n)` where `n` is the number of nodes in the linked list. The list is traversed twice, but this still results in linear time complexity.
- **Space Complexity**: `O(1)` since we are not using any extra space besides a few integer variables to store counts.

This approach is efficient and solves the problem in linear time while using constant extra space.
