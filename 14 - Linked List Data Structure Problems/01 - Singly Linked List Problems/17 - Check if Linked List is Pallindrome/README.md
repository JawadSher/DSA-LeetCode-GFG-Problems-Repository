<h1 align='center'>Check - If - Linked - List is - Pallindrome</h1>

## Problem Statement

**Problem URL :** [Check if Linked List is Pallindrom](https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/30dab5bc-4ae5-46ac-9c87-736a69e67220)
![image](https://github.com/user-attachments/assets/34b57aad-8b4a-4600-ae12-285b58876606)

## Problem Explanation
You are given the head of a singly linked list. You need to check if the linked list is a palindrome, i.e., if it reads the same forward as it does backward.

#### Example:
1. Input: `head = [1, 2, 3, 2, 1]`
   - The linked list is a palindrome because the sequence of values from left to right (`1, 2, 3, 2, 1`) is the same when read from right to left.
   - Output: `true`
   
2. Input: `head = [1, 2, 3]`
   - The linked list is not a palindrome because reading it backwards would give `[3, 2, 1]`, which is different from the original sequence.
   - Output: `false`

---

### **Beginner's Approach:**

When thinking about solving this problem, one simple approach is to reverse the second half of the linked list and then compare it with the first half. If both halves are identical, the list is a palindrome.

#### Approach Steps:
1. **Find the middle of the linked list**: Use two pointers (`slow` and `fast`). Move `slow` one step at a time and `fast` two steps at a time. When `fast` reaches the end, `slow` will be at the middle.
2. **Reverse the second half of the list**: Starting from the middle node, reverse the second half of the linked list.
3. **Compare both halves**: Compare the first half of the list with the reversed second half.
4. **Restore the list**: Reverse the second half back to its original form (this step is optional but useful if we want to avoid modifying the list).
5. **Return the result**: If both halves are the same, return `true`; otherwise, return `false`.
   
## Problem Solution
```cpp
class Solution {
  private:
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
  public:
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        // Step 1: Get the middle of the linked list
        Node* middle = getMid(head);
        
        // Step 2: Reverse the second half of the list starting from the middle
        Node* secondHalf = reverse(middle);
        
        // Step 3: Compare the first and second halves
        Node* firstHalf = head;
        Node* secondHalfCopy = secondHalf;

        while (secondHalf != NULL) {
            if (firstHalf->data != secondHalf->data) {
                // Step 4: Restore the list before returning false
                reverse(secondHalfCopy); 
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 5: Restore the list before returning true
        reverse(secondHalfCopy);

        return true;
    }
};
```

## Problem Solution Explanation

Let's break down the code step by step.

```cpp
class Solution {
  private:
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head;
```
- **Line 1-4**: The class `Solution` is defined with a private helper function `getMid`. This function uses two pointers (`slow` and `fast`) to find the middle of the linked list.

```cpp
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
```
- **Line 5-10**: The `while` loop moves the `slow` pointer one step at a time and the `fast` pointer two steps at a time.
  - When `fast` reaches the end of the list (`fast == NULL` or `fast->next == NULL`), `slow` will be at the middle of the list.
  - The function returns the `slow` pointer, which is now pointing to the middle node.

#### Example Walkthrough:
For `head = [1, 2, 3, 2, 1]`:
- After the loop, `slow` will point to the node with value `3`, which is the middle of the list.

---

```cpp
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
```
- **Line 11-14**: This function `reverse` reverses the linked list from the given head. Three pointers are used:
  - `curr`: points to the current node.
  - `prev`: keeps track of the previous node (initialized to `NULL`).
  - `next`: temporarily stores the next node to avoid losing track during reversal.

```cpp
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
```
- **Line 15-22**: The `while` loop reverses the linked list:
  - Save the next node (`next = curr->next`).
  - Change the `next` pointer of the current node to point to the previous node (`curr->next = prev`).
  - Move the `prev` and `curr` pointers one step forward.
- The loop continues until `curr` becomes `NULL`, meaning we have reached the end of the list.
- The function returns `prev`, which is now the head of the reversed list.

#### Example Walkthrough:
For the second half of the list `2 -> 1`, the reversed list becomes `1 -> 2`.

---

```cpp
  public:
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
```
- **Line 24-27**: The main function `isPalindrome` checks if the linked list is empty (`head == NULL`) or contains only one node (`head->next == NULL`).
  - If either is true, the list is trivially a palindrome, so we return `true`.

---

```cpp
        // Step 1: Get the middle of the linked list
        Node* middle = getMid(head);
        
        // Step 2: Reverse the second half of the list starting from the middle
        Node* secondHalf = reverse(middle);
```
- **Line 29-33**: 
  - **Step 1**: Call `getMid` to find the middle node of the linked list.
  - **Step 2**: Call `reverse` to reverse the second half of the list starting from the middle node.
  - The reversed second half is stored in `secondHalf`.

#### Example Walkthrough:
For `head = [1, 2, 3, 2, 1]`, `middle` points to the node with value `3`, and after reversing, `secondHalf` points to the list `1 -> 2`.

---

```cpp
        // Step 3: Compare the first and second halves
        Node* firstHalf = head;
        Node* secondHalfCopy = secondHalf;

        while (secondHalf != NULL) {
            if (firstHalf->data != secondHalf->data) {
                // Step 4: Restore the list before returning false
                reverse(secondHalfCopy); 
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
```
- **Line 35-45**: 
  - **Step 3**: Compare the first half of the list (starting from `head`) with the reversed second half (`secondHalf`).
  - If at any point the values don't match, we:
    - **Step 4**: Restore the reversed second half back to its original order by calling `reverse(secondHalfCopy)` before returning `false`.
  - If the values match, continue moving both pointers (`firstHalf` and `secondHalf`) to the next nodes.

#### Example Walkthrough:
For `head = [1, 2, 3, 2, 1]`:
- Compare `1 == 1`, then move both pointers.
- Compare `2 == 2`, then move both pointers.
- At this point, `secondHalf` becomes `NULL`, and we exit the loop.

---

```cpp
        // Step 5: Restore the list before returning true
        reverse(secondHalfCopy);
        
        return true;
    }
};
```
- **Line 47-51**: 
  - **Step 5**: If the loop completes and no mismatches were found, the linked list is a palindrome.
  - Before returning `true`, we restore the list to its original form by reversing the second half again (`reverse(secondHalfCopy)`).

---

### **Example 1 Walkthrough:**
Input: `head = [1, 2, 3, 2, 1]`

1. **Find the middle**: `middle` points to the node with value `3`.
2. **Reverse the second half**: The reversed second half is `1 -> 2`.
3. **Compare the halves**:
   - `1 == 1`
   - `2 == 2`
4. Since all values match, return `true`.

### **Example 2 Walkthrough:**
Input: `head = [1, 2, 3]`

1. **Find the middle**: `middle` points to the node with value `3`.
2. **Reverse the second half**: The reversed second half is `3`.
3. **Compare the halves**:
   - `1 != 3`
4. Restore the list and return `false`.

---

### **Time Complexity:**
- **Time Complexity**: `O(n)` where `n` is the number of nodes in the linked list. We traverse the list multiple times: once to find the middle, once to reverse the second half, and once to compare the two halves.
- **Space Complexity**: `O(1)` because we use a constant amount of extra space for pointers. Reversing the list is done in place, and no additional data structures like arrays are used.
