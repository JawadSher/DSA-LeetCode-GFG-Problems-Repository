<h1 align='center'>Remove - Duplicates - From the - Sorted - List</h1>

## Problem Statement

**Problem URL :** [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

![image](https://github.com/user-attachments/assets/58fadff4-8726-4f74-9fb9-6d722d6abf99)
![image](https://github.com/user-attachments/assets/840f6814-f7b3-4cd6-8a18-ecb2b336bd53)

## Problem Explanation

The problem is defined as follows:

- You are given the head of a **sorted** linked list.
- Your task is to **delete** all duplicate values such that each element appears **only once**.
- The final result should still be a sorted linked list.

**Example Inputs and Outputs:**

1. **Example 1:**
   - **Input:** `1 -> 1 -> 2`
   - **Output:** `1 -> 2`
   - **Explanation:** The number `1` appears twice, so we remove the duplicate.

2. **Example 2:**
   - **Input:** `1 -> 1 -> 2 -> 3 -> 3`
   - **Output:** `1 -> 2 -> 3`
   - **Explanation:** The number `1` appears twice, and the number `3` appears twice as well, so both duplicates are removed.

3. **Example 3:**
   - **Input:** `1 -> 2 -> 3`
   - **Output:** `1 -> 2 -> 3`
   - **Explanation:** There are no duplicates in this list, so it remains unchanged.

### Approach to Solve the Problem

To solve this problem, we can use either an iterative or a recursive approach. 

#### Iterative Approach:
1. **Traverse the List**: Start from the head of the list and iterate through each node.
2. **Check for Duplicates**: For each node, check if its value is the same as the next node's value.
3. **Remove Duplicates**: If they are the same, adjust the current node's `next` pointer to skip the duplicate node.
4. **Continue Traversing**: Move to the next node until you reach the end of the list.

#### Recursive Approach:
1. **Base Case**: If the current node is `nullptr` or if it is the last node, return.
2. **Check for Duplicates**: If the current node's value is the same as the next node's value, adjust the pointers to skip the next node and delete it.
3. **Recursion**: Call the function recursively on the next node until all duplicates are removed.

## Problem Solution
```cpp
class Solution {
private:
    void rDuplicates(ListNode* current){

        if(current == nullptr || current -> next == nullptr){
            return;
        }

        if(current->val == current -> next -> val){
            ListNode* nodeToDelete = current -> next;
            current -> next = current -> next -> next;
            delete nodeToDelete;
            rDuplicates(current);
        }else{
            rDuplicates(current->next);
        }
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        rDuplicates(head);

        return head;
    }
};
```

## Problem Solution Explanation
Here's a detailed line-by-line explanation of the provided recursive solution:

```cpp
class Solution {
private:
    void rDuplicates(ListNode* current) {
```
- **Definition**: The class `Solution` contains a private method `rDuplicates` that will handle the removal of duplicates.
- **Parameter**: `ListNode* current` is a pointer to the current node in the linked list.

```cpp
        if (current == nullptr || current->next == nullptr) {
            return;
        }
```
- **Base Case**: This checks if the `current` node is `nullptr` (i.e., we have reached the end of the list) or if `current` is the last node (i.e., `current->next` is `nullptr`). If either condition is true, we return from the function, as there's nothing more to process.

```cpp
        if (current->val == current->next->val) {
```
- **Check for Duplicates**: Here, we compare the value of the `current` node with the value of the next node (`current->next`). If they are equal, it means we have found a duplicate.

```cpp
            ListNode* nodeToDelete = current->next;
```
- **Node to Delete**: We create a pointer `nodeToDelete` to hold the reference of the duplicate node (`current->next`) that we want to remove.

```cpp
            current->next = current->next->next;
```
- **Skip the Duplicate**: We adjust the `next` pointer of the `current` node to point to the node after the duplicate, effectively skipping over the duplicate node.

```cpp
            delete nodeToDelete;
```
- **Delete the Duplicate Node**: We free the memory allocated for the duplicate node to prevent memory leaks.

```cpp
            rDuplicates(current);
```
- **Recursive Call**: We call the `rDuplicates` function recursively with the same `current` node to continue checking for any further duplicates that may follow.

```cpp
        } else {
            rDuplicates(current->next);
        }
```
- **Continue Traversal**: If the values are not equal (i.e., no duplicate), we simply call `rDuplicates` for the next node (`current->next`).

### Public Method: `deleteDuplicates`

```cpp
public:
    ListNode* deleteDuplicates(ListNode* head) {
```
- **Function Definition**: This is the public method `deleteDuplicates` which will be called by the user to start the duplicate removal process.

```cpp
        if (head == nullptr || head->next == nullptr) return head;
```
- **Check for Empty or Single Node**: If the linked list is empty (`head` is `nullptr`) or contains only one node (`head->next` is `nullptr`), we return the head directly, as there are no duplicates to remove.

```cpp
        rDuplicates(head);
```
- **Start Recursive Removal**: We call the `rDuplicates` function, passing the `head` node to start the duplicate removal process.

```cpp
        return head;
    }
};
```
- **Return the Modified List**: Finally, we return the head of the modified linked list, which now contains no duplicates.

### Summary of How a Beginner Can Approach This Problem

1. **Understand the Problem**: Make sure you understand the requirement to remove duplicates from a sorted linked list.
2. **Plan Your Approach**: Decide between an iterative or recursive solution. Start with the iterative approach if you are new to recursion.
3. **Implement and Test**: Write the code, and use various test cases (including edge cases) to verify that it works correctly.
4. **Debug and Optimize**: If there are any issues, debug the code step-by-step. Ensure memory management is handled properly, especially in languages like C++.

### Examples to Illustrate the Solution

1. **Example Input**: `1 -> 1 -> 2`
   - Start with the head at `1`.
   - First comparison: `1 == 1` (duplicate found). Remove the second `1`.
   - Resulting list: `1 -> 2`.

2. **Example Input**: `1 -> 1 -> 1 -> 2`
   - Start with the head at `1`.
   - First comparison: `1 == 1` (duplicate found). Remove the second `1`.
   - Continue with the next `1`: `1 == 1` (duplicate found). Remove the third `1`.
   - Resulting list: `1 -> 2`.

3. **Example Input**: `2 -> 2 -> 3 -> 4`
   - Start with the head at `2`.
   - First comparison: `2 == 2` (duplicate found). Remove the second `2`.
   - Move to `3`: `2 != 3` (no duplicate).
   - Continue to `4`: `3 != 4` (no duplicate).
   - Resulting list: `2 -> 3 -> 4`.

### Conclusion

This solution effectively removes duplicates from a sorted linked list using a recursive approach, allowing beginners to grasp both linked list manipulation and recursion. By following the explanations and examples, beginners should be able to understand the problem and the solution comprehensively.
