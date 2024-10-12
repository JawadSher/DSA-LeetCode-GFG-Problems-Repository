<h1 align='center'>Add - Two - Numbers</h1>

## Problem Statement

**Problem URL :** [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

![image](https://github.com/user-attachments/assets/0b8d9f62-8732-4667-b8c8-e4c76d1467b9)
![image](https://github.com/user-attachments/assets/72c59a7e-8b74-44ca-a644-a03da650f531)

## Problem Explanation

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

**Example:**

If the input linked lists represent the numbers `342` and `465`, they are stored in reverse order as:
- `l1` = [2 → 4 → 3] (which represents the number 342)
- `l2` = [5 → 6 → 4] (which represents the number 465)

The sum of `342 + 465 = 807`, which in reverse order is represented as [7 → 0 → 8].

### Beginner Approach to Solve the Problem

1. **Think of Linked Lists as Numbers:**  
   The problem gives you two numbers represented as linked lists, where each node holds a single digit of the number. These digits are given in reverse order, so the first node in the list represents the least significant digit.

2. **Digit-by-Digit Addition (Like Elementary School Addition):**  
   We need to simulate how we add numbers manually:
   - Add the digits at corresponding positions (starting from the least significant digit).
   - If the sum of two digits is 10 or more, carry the 1 over to the next addition.

3. **Handle Different List Lengths and Carry:**  
   - The two linked lists may have different lengths, so we need to handle when one list is longer.
   - Also, if the sum of digits at any position exceeds 9, we carry over the `carry` (just like in manual addition).

## Problem Solution
```cpp
class Solution {
private:
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
            tail = temp;

            return;
        }

        tail -> next = temp;
        tail = temp;
    }

    ListNode* add(ListNode* l1, ListNode* l2){
        int carry = 0;

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = 0;
            if(l1 != NULL) val1 = l1 -> val;
            
            int val2 = 0;
            if(l2 != NULL) val2 = l2 -> val;

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;

            if(l1 != NULL) l1 = l1 -> next;
            if(l2 != NULL) l2 = l2 -> next;
        }


        return ansHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = add(l1, l2);

        return ans;
    }
};
```

## Problem Solution Explanation

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
```

This defines the structure of a node in a singly-linked list. Each node contains:
- `val`: an integer representing the value of the node.
- `next`: a pointer to the next node in the list.

---

```cpp
class Solution {
```

The `Solution` class contains methods to solve the problem.

---

#### `insertAtTail` Function

```cpp
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
            tail = temp;

            return;
        }

        tail -> next = temp;
        tail = temp;
    }
```

This function adds a new node with value `val` to the end (tail) of a linked list.

**Explanation:**
1. **temp = new ListNode(val)**: Create a new node with value `val`.
2. **if(head == NULL)**: If the list is empty, initialize `head` and `tail` to point to the new node.
3. **tail -> next = temp**: Otherwise, link the current tail to the new node.
4. **tail = temp**: Update the tail to point to the new last node.

---

#### `add` Function

```cpp
    ListNode* add(ListNode* l1, ListNode* l2){
        int carry = 0;

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = 0;
            if(l1 != NULL) val1 = l1 -> val;
            
            int val2 = 0;
            if(l2 != NULL) val2 = l2 -> val;

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;

            if(l1 != NULL) l1 = l1 -> next;
            if(l2 != NULL) l2 = l2 -> next;
        }

        return ansHead;
    }
```

This function adds two linked lists `l1` and `l2` digit by digit, handling the carry from previous additions.

**Explanation:**
1. **carry = 0**: Initialize a variable to store carry from the addition.
2. **ansHead = NULL, ansTail = NULL**: These will store the result linked list.
3. **while loop**: Continue the addition as long as there are nodes in either `l1`, `l2`, or carry is non-zero.
    - **val1, val2**: Set the value from the current nodes of `l1` and `l2` (if they exist), otherwise use 0.
    - **sum = carry + val1 + val2**: Add the values along with any carry.
    - **digit = sum % 10**: Get the last digit of the sum to store in the current node.
    - **insertAtTail**: Insert this digit into the result list.
    - **carry = sum / 10**: Calculate the carry for the next iteration.
    - **l1 = l1 -> next** and **l2 = l2 -> next**: Move to the next nodes in `l1` and `l2`.
4. **return ansHead**: Return the head of the result list.

---

#### `addTwoNumbers` Function

```cpp
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = add(l1, l2);

        return ans;
    }
```

The `addTwoNumbers` function is the main function that the user will call. It simply calls the `add` function to get the sum of `l1` and `l2`.

---

### Example Walkthrough:

**Example 1:**

`l1` = [2 → 4 → 3] (represents 244),  
`l2` = [5 → 6 → 4] (represents 564)

1. Add the digits in the first position: `2 + 5 = 7` → result so far: `[7]`.
2. Add the digits in the second position: `4 + 6 = 10`, carry the `1` → result so far: `[7 → 0]`, carry = 1.
3. Add the digits in the third position: `3 + 4 + 1(carry) = 8` → result so far: `[7 → 0 → 8]`.

Final result: `[7 → 0 → 8]` (which represents 708).
