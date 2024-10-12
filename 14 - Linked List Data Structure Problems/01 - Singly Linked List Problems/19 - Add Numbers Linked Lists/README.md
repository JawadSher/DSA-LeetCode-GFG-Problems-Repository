<h1 align='center'>Add - Number - Linked - List</h1>

## Problem Statement

**Problem URL :** [Add Number Linked List](https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/b67f32f5-656e-45ca-905e-e605e0dfe366)
![image](https://github.com/user-attachments/assets/b5c630fd-2bdd-464c-ab4e-e9830459a052)

## Problem Explanation

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **normal order** (not reversed), and each node contains a single digit. You need to add the two numbers and return the sum as a linked list.

Unlike the previous problem, the digits are stored in their **normal** order. For example, if the input linked lists represent the numbers `342` and `465`, they will be stored as:
- `num1` = [3 → 4 → 2] (which represents the number 342)
- `num2` = [4 → 6 → 5] (which represents the number 465)

The sum of `342 + 465 = 807`, and the result will be represented as [8 → 0 → 7].

### Beginner Approach to Solve the Problem

1. **Linked Lists as Numbers in Normal Order**:  
   In this problem, the digits are stored in normal order, meaning the first node of the list represents the most significant digit.

2. **Reverse the Lists**:  
   Since it's easier to add the numbers from least significant digit (rightmost digit) to most significant (leftmost digit), you reverse both linked lists first to treat them like the previous "reverse order" problem.

3. **Add the Reversed Lists**:  
   After reversing, you perform digit-by-digit addition, simulating how we add numbers manually, handling the carry.

4. **Reverse the Result**:  
   Once the addition is complete, reverse the result list to restore the original order of digits.

## Problem Solution
```cpp
class Solution {
  private:
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
    
    
    void insertAtTail(Node* &head, Node* &tail, int val){
        
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            
            return;
        }else{
            tail -> next = temp;
            tail = temp;
        }
        
    }
    Node* add(Node* num1, Node* num2){
        int carry = 0;
        
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(num1 != NULL && num2 != NULL){
            int sum = carry + num1 -> data + num2 -> data;
            int digit = sum%10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            
            num1 = num1 -> next;
            num2 = num2 -> next;
        }
        
        while(num1 != NULL ){
            int sum = carry + num1 -> data ;
            int digit = sum%10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            
            num1 = num1 -> next;
        }
        
        while(num2 != NULL){
            int sum = carry + num2 -> data;
            int digit = sum%10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            
            num2 = num2 -> next;
        }
        
        while(carry != 0){
            int sum = carry;
            int digit = sum%10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
        }
        
        return ansHead;
    }
  public:
    
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node* ans = add(num1, num2);
        
        ans = reverse(ans);
        
        
        return ans;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
```

The `Solution` class contains methods to solve the problem.

---

#### `reverse` Function

```cpp
private:
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
```

The `reverse` function reverses a singly-linked list. This is a helper function that is used to reverse both input linked lists and later the result list.

**Explanation:**
1. **curr = head**: Start from the head of the list.
2. **prev = NULL**: No previous node at the start.
3. **next = NULL**: This variable stores the next node during traversal.
4. **while(curr != NULL)**: Loop through the list:
    - Store the next node (`next = curr -> next`).
    - Reverse the `next` pointer of the current node (`curr -> next = prev`).
    - Move `prev` and `curr` forward.
5. **return prev**: Return the new head of the reversed list.

---

#### `insertAtTail` Function

```cpp
    void insertAtTail(Node* &head, Node* &tail, int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        } else {
            tail -> next = temp;
            tail = temp;
        }
    }
```

This function inserts a new node with value `val` at the end of the list.

**Explanation:**
1. **temp = new Node(val)**: Create a new node with the value `val`.
2. **if(head == NULL)**: If the list is empty, initialize `head` and `tail` to point to the new node.
3. **tail -> next = temp**: Otherwise, link the current tail to the new node.
4. **tail = temp**: Update the tail to point to the new last node.

---

#### `add` Function

```cpp
    Node* add(Node* num1, Node* num2){
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(num1 != NULL || num2 != NULL || carry != 0){
            int val1 = 0;
            if(num1 != NULL) val1 = num1 -> data;
            
            int val2 = 0;
            if(num2 != NULL) val2 = num2 -> data;
    
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            
            if(num1 != NULL) num1 = num1 -> next;
            if(num2 != NULL) num2 = num2 -> next;
        }
        
        return ansHead;
    }
```

The `add` function adds two linked lists `num1` and `num2` digit by digit and handles any carry from previous additions.

**Explanation:**
1. **carry = 0**: Initialize the carry to 0.
2. **ansHead = NULL, ansTail = NULL**: These will store the result linked list.
3. **while loop**: Continue while there are nodes in either `num1`, `num2`, or carry is non-zero.
    - **val1, val2**: Set the value from the current nodes of `num1` and `num2` (if they exist), otherwise use 0.
    - **sum = carry + val1 + val2**: Add the values along with any carry.
    - **digit = sum % 10**: Get the last digit of the sum to store in the current node.
    - **insertAtTail**: Insert this digit into the result list.
    - **carry = sum / 10**: Calculate the carry for the next iteration.
    - **num1 = num1 -> next** and **num2 = num2 -> next**: Move to the next nodes in `num1` and `num2`.
4. **return ansHead**: Return the head of the result list.

---

#### `addTwoLists` Function

```cpp
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node* ans = add(num1, num2);
        
        ans = reverse(ans);
        
        return ans;
    }
};
```

The `addTwoLists` function is the main function that adds the two linked lists and returns the result.

**Explanation:**
1. **Reverse both lists**: Since the input lists are in normal order, reverse both `num1` and `num2` to make it easier to add them digit by digit (from least significant to most significant).
2. **Add the reversed lists**: Use the `add` function to add the reversed linked lists.
3. **Reverse the result list**: After adding, reverse the result list to restore the original digit order.
4. **Return the result**: Return the head of the result list.

---

### Example Walkthrough:

**Example 1:**

`num1` = [1 → 2 → 3] (represents 123),  
`num2` = [4 → 5 → 6] (represents 456)

1. Reverse the linked lists:
   - `num1` becomes [3 → 2 → 1] (321)
   - `num2` becomes [6 → 5 → 4] (654)

2. Add the reversed lists:
   - `321 + 654 = 975`
   - This is stored as [5 → 7 → 9] (since we store the sum in reverse order).

3. Reverse the result list:
   - [5 → 7 → 9] becomes [9 → 7 → 5].

Final result: [9 → 7 → 5] (which represents 579).

**Example 2:**

`num1` = [9 → 9 → 9] (represents 999),  
`num2` = [1] (represents 1)

1. Reverse the linked lists:
   - `num1` becomes [9 → 9 → 9]
   - `num2` becomes [1]

2. Add the reversed lists:
   - `999 + 1 = 1000`
   - This is stored as [0 → 0 → 0 → 1].

3. Reverse the result list:
   - [0 → 0 → 0 → 1] becomes [1 → 0 → 0 → 0].

Final result: [1 → 0 → 0 → 0] (which represents 1000).
