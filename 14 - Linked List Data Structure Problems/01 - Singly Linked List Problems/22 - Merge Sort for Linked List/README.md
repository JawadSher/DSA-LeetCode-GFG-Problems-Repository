<h1 align='center'>Merge - Sort - for - Linked - List</h1>

## Problem Statement

**Problem URL :** [Merge Sort for Linked List](https://www.geeksforgeeks.org/problems/sort-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/691676ac-c4c7-4ef1-9958-180c46b65ae5)
![image](https://github.com/user-attachments/assets/aaa977f6-fa86-4c6b-ad90-50b3ffa9d6b2)

## Problem Explanation
You are given a singly linked list, and the task is to sort this linked list using the **Merge Sort** algorithm.

#### Input:
- A linked list of `N` nodes where each node contains an integer value.

#### Output:
- A sorted version of the input linked list in ascending order.

#### Constraints:
- Time complexity should be `O(N log N)`, which means we need to use an efficient algorithm like **Merge Sort**.
- Merge Sort works by:
  1. Dividing the linked list into two halves recursively.
  2. Sorting each half.
  3. Merging the two sorted halves back together.

---

### Approach for Beginners

To solve this problem, we apply the **Merge Sort** algorithm specifically for linked lists. Let's break this down into **simple steps**:

1. **Divide the Linked List**:
   - Use the **"fast and slow pointer"** technique to find the middle of the linked list.
   - Break the list into two halves at the middle.

2. **Recursive Sorting**:
   - Recursively sort the two halves using the merge sort algorithm.

3. **Merge the Sorted Halves**:
   - Use the **merge step** of merge sort, where you merge two sorted linked lists into one sorted list.

## Problem Solution
```cpp
class Solution {
  private:
    Node* getMiddle(Node* head){
        if(head == NULL && head -> next == NULL) return head;
        
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
    
    Node* merge(Node* left, Node* right){
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(left != NULL && right != NULL){
            if(left -> data < right -> data){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }else{
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }
        
        if(left != NULL) temp -> next = left;
        if(right != NULL) temp -> next = right;
        
        return ans -> next;
    }
  public:
    Node* mergeSort(Node* head) {
        // base case
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node* middle = getMiddle(head);
        
        Node* right = middle -> next;
        middle -> next = NULL;
        
        Node* left = mergeSort(head);
        right = mergeSort(right);
        
        return merge(left, right);
    }
};
```

## Problem Solution Explanation

Let’s go through the code you shared and explain it in detail.

### 1. **Function 1: `getMiddle` - Finding the Middle of the List**

```cpp
Node* getMiddle(Node* head) {
    if (head == NULL || head -> next == NULL) return head;

    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}
```

#### Explanation:
- **Purpose**: This function finds the **middle** of a linked list using the **slow and fast pointer technique**.
  - The **slow pointer** moves one step at a time, while the **fast pointer** moves two steps at a time.
  - When the fast pointer reaches the end of the list, the slow pointer will be in the middle.
  
#### Example:
For the linked list:
```
5 -> 3 -> 8 -> 1 -> 2
```
1. Initially, `slow` is at `5` and `fast` is at `3`.
2. After the first iteration, `slow` is at `3` and `fast` is at `1`.
3. After the second iteration, `slow` is at `8` and `fast` is `NULL`.
4. The function returns the node with value `8` as the middle node.

---

### 2. **Function 2: `merge` - Merging Two Sorted Linked Lists**

```cpp
Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while (left != NULL && right != NULL) {
        if (left -> data < right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        } else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    if (left != NULL) temp -> next = left;
    if (right != NULL) temp -> next = right;

    return ans -> next;
}
```

#### Explanation:
- **Purpose**: This function merges two sorted linked lists (`left` and `right`) into a single sorted linked list.
- It iterates through both lists, picking the smaller element from either the `left` or `right` list and appending it to the result list.
- When one list is exhausted, it appends the remaining nodes of the other list.

#### Example:
Merging two sorted lists:
```
Left: 1 -> 3 -> 5
Right: 2 -> 4 -> 6
```
1. Compare `1` and `2`: Add `1` to the result.
2. Compare `3` and `2`: Add `2` to the result.
3. Compare `3` and `4`: Add `3` to the result.
4. Continue this until both lists are merged into:
```
1 -> 2 -> 3 -> 4 -> 5 -> 6
```

---

### 3. **Function 3: `mergeSort` - Recursive Merge Sort**

```cpp
Node* mergeSort(Node* head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    Node* middle = getMiddle(head);

    Node* right = middle -> next;
    middle -> next = NULL;

    Node* left = mergeSort(head);
    right = mergeSort(right);

    return merge(left, right);
}
```

#### Explanation:
- **Base Case**: If the list is empty or contains only one node (`head == NULL || head->next == NULL`), it is already sorted, so return the `head`.
  
- **Recursive Steps**:
  1. **Find the Middle**: Split the linked list into two halves using the `getMiddle` function.
  2. **Break the Link**: Set `middle->next = NULL` to break the linked list into two parts.
  3. **Recursively Sort Both Halves**: Sort the left and right halves using recursive calls to `mergeSort`.
  4. **Merge the Sorted Halves**: Merge the two sorted halves using the `merge` function.

#### Example:

Let's take a linked list:
```
5 -> 3 -> 8 -> 1 -> 2
```
1. **First Call to `mergeSort`**:
   - The list is split into:
     - Left: `5 -> 3`
     - Right: `8 -> 1 -> 2`
   
2. **Recursive Calls**:
   - For the left part `5 -> 3`, it splits into `5` and `3`, sorts them and merges to get `3 -> 5`.
   - For the right part `8 -> 1 -> 2`, it splits into `8` and `1 -> 2`, sorts them and merges to get `1 -> 2 -> 8`.

3. **Final Merge**:
   - Now, merge the two halves:
     - Left: `3 -> 5`
     - Right: `1 -> 2 -> 8`
   - The merged result is:
     ```
     1 -> 2 -> 3 -> 5 -> 8
     ```

---

### Conclusion

The `mergeSort` function recursively splits the linked list into smaller parts until each part contains a single node. Then, it merges these parts back together in sorted order using the `merge` function. This process ensures that the list is sorted in `O(N log N)` time complexity, which is optimal for sorting a linked list.
