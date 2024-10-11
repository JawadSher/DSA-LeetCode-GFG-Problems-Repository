<h1 align='center'>Merge - Two - Sorted - Lists</h1>

## Problem Statement

**Problem URL :** [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

![image](https://github.com/user-attachments/assets/52f25b60-57e2-4fc4-9b5a-27bd1bb842f5)
![image](https://github.com/user-attachments/assets/55f22298-d94e-4047-8606-f0360287b051)

## Problem Explanation
The problem **"Merge Two Sorted Lists"** from LeetCode is about merging two sorted singly linked lists into one sorted linked list. Each of the two input lists is already sorted in non-decreasing order. The task is to combine these two lists into one sorted list while preserving the original order of the nodes.

### Approach for Beginners:
When a beginner first sees this problem, they may think about the following approaches:

1. **Using a New List (Extra Space)**:
   A beginner might think of creating a new linked list. They would iterate through both input lists and compare the values of the nodes. The node with the smaller value would be appended to the new list. This process continues until all nodes from both input lists are added. This approach requires extra space for the new list.

2. **In-Place Merge (Without Extra Space)**:
   A more optimized approach is to merge the two input lists in place, without creating a new list. This approach modifies the next pointers of the nodes in the existing lists to create a single sorted list. This method avoids using extra space and is more efficient in terms of memory.

The code provided follows the **second approach**, where the lists are merged in place.

## Problem Solution
```cpp
class Solution {
private:
    ListNode* solve(ListNode* list1, ListNode* list2){
        if(list1 -> next == NULL){
            list1 -> next = list2;
            return list1;
        }

        ListNode* curr1 = list1;
        ListNode* next1 = curr1 -> next;
        ListNode* curr2 = list2;
        ListNode* next2 = curr2 -> next;

        while(next1 != NULL && curr2 != NULL){
            if((curr2 -> val >= curr1 -> val) && (curr2 -> val <= next1 -> val)){
                next2 = curr2 -> next;
                curr1 -> next = curr2;
                curr2 -> next = next1;

                curr1 = curr2;
                curr2 = next2;
            }else{
                curr1 = next1;
                next1 = next1 -> next;

                if(next1 == NULL) {
                    curr1 -> next = curr2;
                    return list1;
                }

            }
        }

        return list1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1->val <= list2->val){
            return solve(list1, list2);
        }else{
            return solve(list2, list1);
        }

        
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
private:
    ListNode* solve(ListNode* list1, ListNode* list2){
```
- The function `solve` is a helper function that merges two sorted linked lists `list1` and `list2`. It handles the actual merging process, ensuring that the nodes are rearranged in non-decreasing order.

---

```cpp
        if(list1 -> next == NULL){
            list1 -> next = list2;
            return list1;
        }
```
- If `list1` has only one node (i.e., `list1 -> next == NULL`), we simply attach the remaining `list2` to the end of `list1`. This is a base case for merging where `list1` has no further nodes, and we can directly attach `list2`.

---

```cpp
        ListNode* curr1 = list1;
        ListNode* next1 = curr1 -> next;
        ListNode* curr2 = list2;
        ListNode* next2 = curr2 -> next;
```
- These pointers are initialized to track the current nodes and the next nodes in both `list1` and `list2`.
  - `curr1` and `next1` track the current and next nodes in `list1`.
  - `curr2` and `next2` track the current and next nodes in `list2`.

---

```cpp
        while(next1 != NULL && curr2 != NULL){
```
- The `while` loop continues as long as `list1` has more nodes (`next1 != NULL`) and `list2` has more nodes (`curr2 != NULL`). It compares the nodes of both lists and merges them in sorted order.

---

```cpp
            if((curr2 -> val >= curr1 -> val) && (curr2 -> val <= next1 -> val)){
                next2 = curr2 -> next;
                curr1 -> next = curr2;
                curr2 -> next = next1;

                curr1 = curr2;
                curr2 = next2;
            }
```
- This `if` block checks if `curr2` (the current node of `list2`) lies between `curr1` and `next1` (i.e., if `curr2->val` is greater than or equal to `curr1->val` and less than or equal to `next1->val`).
- If true, we insert `curr2` between `curr1` and `next1`.
  - `next2 = curr2 -> next` stores the next node of `list2` before modifying `curr2`'s `next` pointer.
  - `curr1 -> next = curr2` inserts `curr2` after `curr1`.
  - `curr2 -> next = next1` links `curr2` to `next1`.
  - Finally, the `curr1` pointer is updated to `curr2`, and `curr2` is moved to the next node (`next2`).

---

```cpp
            }else{
                curr1 = next1;
                next1 = next1 -> next;
                
                if(next1 == NULL) {
                    curr1 -> next = curr2;
                    return list1;
                }
            }
```
- If `curr2` does not fit between `curr1` and `next1`, we move the `curr1` and `next1` pointers one step forward in `list1`.
  - `curr1 = next1` updates `curr1` to the next node in `list1`.
  - `next1 = next1 -> next` updates `next1` to the node after the new `curr1`.
- If we reach the end of `list1` (`next1 == NULL`), we attach the remaining nodes of `list2` to `list1` by setting `curr1 -> next = curr2` and return the merged list.

---

```cpp
        return list1;
    }
```
- After completing the merging process, we return `list1` as the head of the newly merged list.

---

```cpp
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
```
- The `mergeTwoLists` function is the public function that the user calls. It takes the heads of two sorted linked lists (`list1` and `list2`) as inputs and returns the head of the merged list.

---

```cpp
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
```
- If either `list1` or `list2` is `NULL`, we simply return the non-`NULL` list. This handles the edge case where one of the lists is empty.

---

```cpp
        if(list1->val <= list2->val){
            return solve(list1, list2);
        }else{
            return solve(list2, list1);
        }
    }
};
```
- This conditional checks which list has the smaller value at the head. We always start merging with the list that has the smaller first element.
  - If `list1->val <= list2->val`, we call `solve(list1, list2)` to merge `list2` into `list1`.
  - If `list2->val < list1->val`, we call `solve(list2, list1)` to merge `list1` into `list2`.

---

### Example Walkthroughs:

#### Example 1:
**Input Lists**:
- `list1`: `1 -> 2 -> 4 -> NULL`
- `list2`: `1 -> 3 -> 5 -> NULL`

**Steps**:
1. Compare `1` (from `list1`) with `1` (from `list2`). Since both are equal, `list1` is chosen.
2. Now compare `2` (from `list1`) with `1` (from `list2`). Insert `1` from `list2` after `1` in `list1`.
3. Now compare `2` (from `list1`) with `3` (from `list2`). Insert `2` from `list1`.
4. Continue until the lists are merged.

**Output**: `1 -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL`

---

#### Example 2:
**Input Lists**:
- `list1`: `5 -> 10 -> 15 -> NULL`
- `list2`: `2 -> 3 -> 20 -> NULL`

**Steps**:
1. Compare `5` (from `list1`) with `2` (from `list2`). Insert `2` from `list2` into `list1`.
2. Now compare `5` (from `list1`) with `3` (from `list2`). Insert `3`.
3. Now compare `5` with `20`. Insert `5`, `10`, and `15` from `list1` sequentially.
4. Finally, attach the remaining node `20`.

**Output**: `2 -> 3 -> 5 -> 10 -> 15 -> 20 -> NULL`

---

### Time and Space Complexity:
- **Time Complexity**: `O(n + m)`, where `n` and `m` are the lengths of `list1` and `list2`. The algorithm traverses both lists once.
- **Space Complexity**: `O(1)` since no extra space is used, and the merging is done in place. Only a few pointers are used.

This approach efficiently merges two sorted linked lists in-place, making it both time- and space-efficient.
