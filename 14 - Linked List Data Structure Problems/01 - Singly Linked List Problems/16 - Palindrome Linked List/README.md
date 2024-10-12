<h1 align='center'>Palindrome - Linked - List</h1>

## Problem Statement

**Problem URL :** [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

![image](https://github.com/user-attachments/assets/7f20b14a-c7e1-4be7-ab5e-984b16332776)

## Problem Explanation
A linked list is a **palindrome** if the sequence of values in the list is the same when read forwards and backwards. You are given the head of a singly linked list and need to return `true` if it is a palindrome, otherwise `false`.

#### Example:
1. Input: `head = [1,2,2,1]`
   - The linked list is a palindrome because reading the values from left to right gives `[1,2,2,1]`, which is the same as reading them from right to left.
   - Output: `true`
   
2. Input: `head = [1,2]`
   - The linked list is not a palindrome because reading it backwards would give `[2,1]`, which is different from the original sequence.
   - Output: `false`

---

### **Beginner's Approach:**

When a beginner looks at this problem, they can think of solving it by checking whether the list, when read forward, is the same as when read backward. Since linked lists don't have direct random access like arrays, you need to convert the list into an array or something similar, where accessing elements by index becomes easy. Then, comparing the array elements from the beginning and the end would help us identify if the linked list is a palindrome.

#### Approach Steps:
1. Traverse the linked list and store all its values in an array.
2. Check if the array is a palindrome by comparing the first and last elements, then the second and second-to-last, and so on.
3. If any mismatch occurs, return `false`.
4. If the entire array matches, return `true`.

#### Why this approach?
- This approach is simple and easy to understand because arrays offer direct index-based access, which makes it easy to compare values from both ends.

## Problem Solution
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
class Solution {
private:
    bool pallindrome(ListNode* head){
        vector<int> list_arr(0);

        while(head != NULL){
            list_arr.push_back(head->val);
            head = head -> next;
        }

        int s = 0; 
        int e = list_arr.size() -1;

        while(s < e){
            if(list_arr[s] != list_arr[e]){
                return false;
            }
            s++;
            e--;
        }

        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(pallindrome(head)){
            return true;
        }

        return false;
    }
};
```

## Problem Solution Explanation
Now, let's break down the code step by step.

```cpp
class Solution {
private:
    bool pallindrome(ListNode* head){
        vector<int> list_arr(0);
```
- **Line 1-3**: A class `Solution` is defined with a private helper function `pallindrome` that checks if the linked list is a palindrome. Inside this function, we declare a vector `list_arr` to store the values of the linked list.

```cpp
        while(head != NULL){
            list_arr.push_back(head->val);
            head = head -> next;
        }
```
- **Line 4-7**: We start a loop to traverse the linked list. As long as the `head` node is not `NULL` (end of the list), we:
  - Append the value of the current node (`head->val`) to the `list_arr` vector.
  - Move the `head` pointer to the next node (`head = head->next`) until we reach the end of the list (`head == NULL`).
- By the end of this loop, `list_arr` will contain all the node values from the linked list, in the same order.

#### Example Walkthrough:
For `head = [1, 2, 2, 1]`, `list_arr` will store: `[1, 2, 2, 1]`.

```cpp
        int s = 0; 
        int e = list_arr.size() - 1;
```
- **Line 8-9**: Two pointers `s` (start) and `e` (end) are initialized. `s` points to the first element of `list_arr`, and `e` points to the last element (`size - 1`).

```cpp
        while(s < e){
            if(list_arr[s] != list_arr[e]){
                return false;
            }
            s++;
            e--;
        }
```
- **Line 10-15**: A `while` loop is used to check if the array is a palindrome:
  - As long as the start pointer (`s`) is less than the end pointer (`e`), compare the values at these positions.
  - If `list_arr[s] != list_arr[e]`, return `false` because this means the linked list is not a palindrome.
  - If the values match, move the start pointer forward (`s++`) and the end pointer backward (`e--`).
- The loop continues until the pointers cross each other (i.e., `s >= e`), meaning we've compared all corresponding pairs.

#### Example Walkthrough (continued):
For `list_arr = [1, 2, 2, 1]`:
- First iteration: `list_arr[0] == list_arr[3] (1 == 1)`, move `s++` and `e--`.
- Second iteration: `list_arr[1] == list_arr[2] (2 == 2)`, move `s++` and `e--`.
- Now, `s >= e`, so the loop stops, and since all pairs matched, the function returns `true`.

```cpp
        return true;
    }
```
- **Line 16**: If the entire array was successfully checked without any mismatches, return `true` because the list is a palindrome.

```cpp
public:
    bool isPalindrome(ListNode* head) {
        if(pallindrome(head)){
            return true;
        }

        return false;
    }
};
```
- **Line 18-23**: The main function `isPalindrome` calls the helper function `pallindrome` to check if the linked list is a palindrome. If `pallindrome(head)` returns `true`, it returns `true`, otherwise it returns `false`.

---

### **Example 1 Walkthrough:**
Input: `head = [1, 2, 2, 1]`

1. We traverse the linked list and store its values in `list_arr = [1, 2, 2, 1]`.
2. We compare:
   - `list_arr[0] == list_arr[3] (1 == 1)`
   - `list_arr[1] == list_arr[2] (2 == 2)`
3. Since all values match, the function returns `true`.

### **Example 2 Walkthrough:**
Input: `head = [1, 2]`

1. We traverse the linked list and store its values in `list_arr = [1, 2]`.
2. We compare:
   - `list_arr[0] != list_arr[1] (1 != 2)`
3. Since there is a mismatch, the function returns `false`.

---

### **Time Complexity:**
- **Time Complexity**: `O(n)` where `n` is the number of nodes in the linked list. We traverse the list once to store the values in an array and once more to compare the elements.
- **Space Complexity**: `O(n)` because we use a vector to store all the node values. 

For larger linked lists, more optimized solutions (e.g., reversing the second half of the list in-place) could reduce space usage, but this beginner-friendly approach prioritizes simplicity.
