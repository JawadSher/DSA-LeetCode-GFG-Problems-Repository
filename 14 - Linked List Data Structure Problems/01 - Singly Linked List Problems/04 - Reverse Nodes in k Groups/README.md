<h1 align='center'>Reverse - Nodes in - K Groups</h1>

## Problem Statement

**Problem URL :** [Reverse Nodes in K Groups](https://leetcode.com/problems/reverse-nodes-in-k-group/)

![image](https://github.com/user-attachments/assets/98adb753-1910-4403-b176-d6982e053d31)
![image](https://github.com/user-attachments/assets/88cf8b3b-8b7c-44f8-a9a3-aeb4966267ea)

## Problem Explanation
The problem "Reverse Nodes in k-Group" on LeetCode asks you to reverse the nodes of a linked list in groups of `k`. The key points to consider are:

- If the number of nodes in the group is less than `k`, the nodes are not reversed and remain in their original order.
- If the number of nodes in the group is exactly `k`, those nodes should be reversed.
- This process continues for the entire linked list.

For example, if the input linked list is:
```
1 -> 2 -> 3 -> 4 -> 5
```
and `k = 2`, the output should be:
```
2 -> 1 -> 4 -> 3 -> 5
```
If `k = 3`, the output would be:
```
3 -> 2 -> 1 -> 4 -> 5
```

### Approach to Solve the Problem

1. **Count Nodes:** First, count the number of nodes in the linked list. If the number of nodes is less than `k`, return the head of the list as it is.

2. **Reverse k Nodes:** If the count is at least `k`, reverse the first `k` nodes.

3. **Recursion:** After reversing the first `k` nodes, recursively call the function for the rest of the linked list starting from the next node after the `k` reversed nodes.

4. **Connect Parts:** Finally, connect the reversed part with the rest of the list and return the new head of the reversed list.

## Problem Solution
```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count < k){
            temp = temp -> next;
            count++;
        }

        if(count < k){
            return head;
        }

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        count = 0;

        while(curr != NULL && count < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != NULL){
            head -> next = reverseKGroup(next, k);
        }

        return prev;
    }
};
```

## Problem Solution Explanation

Here is the provided code with a detailed line-by-line explanation:

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
```
- **Class Declaration:** This defines a class `Solution` which contains the method `reverseKGroup`.
- **Method Signature:** The method takes two parameters: the head of the linked list and an integer `k`.

```cpp
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count < k){
            temp = temp -> next;
            count++;
        }
```
- **Initialize Temp and Count:** A pointer `temp` is initialized to `head`, and a `count` variable is set to 0.
- **Count Nodes:** A while loop is used to traverse the list until either `temp` is `NULL` or `count` reaches `k`. This counts the number of nodes in the list up to `k`.

### Example Walkthrough
For a linked list: `1 -> 2 -> 3 -> 4 -> 5` and `k = 2`:
- Initially, `count` will be `2` when the loop terminates, and `temp` will point to the node with value `3`.

```cpp
        if(count < k){
            return head;
        }
```
- **Check Count:** If the counted nodes are less than `k`, return the head of the list as no reversal is needed.

```cpp
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        count = 0;
```
- **Initialize Pointers:** Three pointers are initialized:
  - `next`: to keep track of the next node.
  - `curr`: starts at the head of the list for the reversal process.
  - `prev`: initialized to `NULL` to become the new end of the reversed list.

```cpp
        while(curr != NULL && count < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
```
- **Reverse k Nodes:** This while loop iterates `k` times to reverse the nodes:
  - `next` stores the next node.
  - The `next` pointer of the current node (`curr`) is set to `prev` (reversing the link).
  - Move `prev` and `curr` one step forward for the next iteration.

### Example Walkthrough
For `1 -> 2 -> 3 -> 4 -> 5` and `k = 2`:
- After the first iteration:
  - `next` points to `3`
  - `curr` points to `2` and its next points to `1`
  - `prev` points to `1`

After completing the loop, the first two nodes are reversed:
```
2 -> 1 -> NULL (prev points to this)
```

```cpp
        if(next != NULL){
            head -> next = reverseKGroup(next, k);
        }
```
- **Recursive Call:** If there are more nodes left (`next` is not `NULL`), call `reverseKGroup` recursively for the remaining list starting from `next`. Link the original head of this segment to the head of the reversed segment from the recursive call.

```cpp
        return prev;
    }
};
```
- **Return New Head:** Finally, return `prev`, which is the new head of the reversed group of `k` nodes.

### Complete Example
Consider a linked list: `1 -> 2 -> 3 -> 4 -> 5` and `k = 2`:

1. First call:
   - Reverse `1` and `2`: `2 -> 1`
   - Call `reverseKGroup` on `3 -> 4 -> 5`.
  
2. Second call:
   - Reverse `3` and `4`: `4 -> 3`
   - Call `reverseKGroup` on `5`, which has fewer than `2` nodes, so it returns `5`.

3. Connect: 
   - The final result is `2 -> 1 -> 4 -> 3 -> 5`.

This process continues recursively, reversing the list in groups of `k`, resulting in the desired output.

### Conclusion
The `reverseKGroup` method effectively reverses nodes in groups of `k` by counting, reversing, and recursively connecting the segments. By understanding each part of the code and the process, beginners can grasp how to manipulate linked lists in this way.
