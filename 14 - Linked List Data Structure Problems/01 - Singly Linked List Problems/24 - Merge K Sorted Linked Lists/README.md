<h1 align='center'>Merge - K Sorted - Linked - Lists</h1>

## Problem Statement

**Problem URL :** [Merge K Sorted Linked Lists](https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/f332843f-9091-43a1-81a9-37d793c2261a)
![image](https://github.com/user-attachments/assets/cffa6b9a-0c20-4c56-8708-ea9fda1e91be)

## Problem Explanation
Given `K` sorted linked lists, we need to merge them into a single sorted linked list. The merged linked list should contain all elements from the original lists, in sorted order.

**Example**:
Suppose we have the following 3 sorted linked lists:

- `List 1: 1 -> 4 -> 7`
- `List 2: 2 -> 5 -> 8`
- `List 3: 3 -> 6 -> 9`

After merging, the final sorted linked list should be:  
`1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9`

### Approach:

To solve this problem, we can use a **Divide and Conquer** approach:

1. **Divide** the lists into two halves recursively until each half contains only one list.
2. **Conquer** by merging two lists at a time until we obtain one final merged list.

In each merge operation:
   - We compare elements from two lists (`l1` and `l2`) and attach the smaller element to the merged list.  
   - We continue this process until all elements from both lists are merged in sorted order.

## Problem Solution
```cpp
class Solution {
  public:
    Node* mergeTwoLists(Node* l1, Node* l2){
        Node* temp = new Node(0);
        Node* current = temp;
        
        while(l1 != NULL && l2 != NULL){
            if(l1 -> data < l2 -> data){
                current -> next = l1;
                l1 = l1 -> next;
            }else{
                current -> next = l2;
                l2 = l2 -> next;
            }
            
            current = current -> next;
        }
        
        if(l1 != NULL) current -> next = l1;
        if(l2 != NULL) current -> next = l2;
        
        return temp -> next;
    };
    
    Node* mergeKListsHelper(vector<Node*>& arr, int left, int right){
        if(left == right) return arr[left];
        
        int mid = left + (right - left) / 2;
        
        Node* leftMerge = mergeKListsHelper(arr, left, mid);
        Node* rightMerge = mergeKListsHelper(arr, mid+1, right);
        
        return mergeTwoLists(leftMerge, rightMerge);
    };
    
    Node* mergeKLists(vector<Node*>& arr) {
        if(arr.empty()) return NULL;
        
        return mergeKListsHelper(arr, 0, arr.size() -1);
    }
};
```

## Problem Solution Explanation

The solution is structured with helper functions to divide and merge the lists. Here’s the code with detailed explanations:

```cpp
class Solution {
  public:
    Node* mergeTwoLists(Node* l1, Node* l2){
        Node* temp = new Node(0);
        Node* current = temp;
```

1. **Explanation**:
   - The `mergeTwoLists` function takes two sorted linked lists (`l1` and `l2`) and merges them.
   - A temporary node `temp` is created to serve as the starting point for the merged list.
   - `current` is a pointer that will traverse and build the merged list.



```cpp
        while(l1 != NULL && l2 != NULL){
            if(l1 -> data < l2 -> data){
                current -> next = l1;
                l1 = l1 -> next;
            }else{
                current -> next = l2;
                l2 = l2 -> next;
            }
            
            current = current -> next;
        }
```

2. **Explanation**:
   - We iterate through both lists while both have elements.
   - In each iteration:
     - If the `data` of `l1` is less than `l2`, we attach `l1` to the `current` node.
     - Otherwise, we attach `l2` to `current`.
   - We move `current` to the newly attached node.



```cpp
        if(l1 != NULL) current -> next = l1;
        if(l2 != NULL) current -> next = l2;
        
        return temp -> next;
    };
```

3. **Explanation**:
   - After the loop, if either list has remaining elements, we attach it to the end of the merged list.
   - Finally, we return `temp -> next` (skipping the initial placeholder node) as the head of the merged sorted list.



```cpp
    Node* mergeKListsHelper(vector<Node*>& arr, int left, int right){
        if(left == right) return arr[left];
        
        int mid = left + (right - left) / 2;
        
        Node* leftMerge = mergeKListsHelper(arr, left, mid);
        Node* rightMerge = mergeKListsHelper(arr, mid+1, right);
        
        return mergeTwoLists(leftMerge, rightMerge);
    };
```

4. **Explanation**:
   - `mergeKListsHelper` is a recursive helper function to merge lists in the range `left` to `right`.
   - **Base case**: If there is only one list in the range, return it directly.
   - **Recursive case**:
     - Find the middle index, `mid`, to divide the range.
     - Recursively merge the left half (`leftMerge`) and right half (`rightMerge`).
     - Merge the results of the left and right halves using `mergeTwoLists` and return the merged result.



```cpp
    Node* mergeKLists(vector<Node*>& arr) {
        if(arr.empty()) return NULL;
        
        return mergeKListsHelper(arr, 0, arr.size() -1);
    }
};
```

5. **Explanation**:
   - The main function `mergeKLists` starts the merging process.
   - If `arr` (the vector of linked list heads) is empty, it returns `NULL`.
   - Otherwise, it calls `mergeKListsHelper` with the full range of lists (`0` to `arr.size() - 1`) and returns the merged result.



### Step 3: Example Walkthrough

**Example**:  
Input:
```cpp
arr = [
    List 1: 1 -> 4 -> 7,
    List 2: 2 -> 5 -> 8,
    List 3: 3 -> 6 -> 9
]
```

Process:
1. We divide the lists using `mergeKListsHelper`:
   - First, split `[List 1, List 2, List 3]` into `[List 1]` and `[List 2, List 3]`.
   - Then, further split `[List 2, List 3]` into `[List 2]` and `[List 3]`.

2. Begin merging back:
   - Merge `List 2` and `List 3` to get `2 -> 3 -> 5 -> 6 -> 8 -> 9`.
   - Merge `List 1` with the merged result from the previous step.

Final merged result:  
`1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9`

Output:  
`1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9`



### Step 4: Time and Space Complexity

1. **Time Complexity**:
   - Merging two lists of combined length `N` takes `O(N)`.
   - With `K` lists, we’re performing `log K` levels of merge operations.
   - Each level involves merging `K/2`, `K/4`, etc., lists.
   - The total time complexity is `O(N * log K)`, where `N` is the total number of nodes in all lists.

2. **Space Complexity**:
   - The space complexity is `O(log K)` for the recursion stack in `mergeKListsHelper`.
   - Additionally, `O(K)` space is required for storing the list heads in the `arr` vector.

### Step 5: Additional Recommendations

- **Practice Similar Problems**: Understanding merging in linked lists is essential. Try merging two sorted lists or merging arrays to strengthen your concepts.
- **Understand Divide and Conquer**: This problem is a good example of the divide-and-conquer technique. Understanding this will help you tackle similar problems more efficiently.
- **Test Edge Cases**: Handle cases with empty lists, single-element lists, or all elements being the same. This helps in creating robust solutions.
  
This detailed breakdown should provide a thorough understanding of the solution, from problem approach to code execution.
