<h1 align='center'>Merge - K Sorted - Lists</h1>

## Problem Statement

**Problem URL :** [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

![image](https://github.com/user-attachments/assets/b5d19c93-6807-4e16-8be7-40d355f8dfc8)
![image](https://github.com/user-attachments/assets/bc565118-e475-4628-aeb1-ac9636422268)

## Problem Explanation
Given `K` sorted linked lists, we need to merge them into a single sorted linked list. The final merged list should contain all nodes from the original lists in sorted order.

**Example**:  
Suppose we have the following 3 sorted linked lists:

- `List 1: 1 -> 4 -> 7`
- `List 2: 2 -> 5 -> 8`
- `List 3: 3 -> 6 -> 9`

After merging, the final sorted linked list should be:  
`1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9`

### Approach:

To solve this problem efficiently, we use a **Min-Heap (priority queue)**.

1. **Use a Min-Heap to Store List Heads**:
   - We add the head of each linked list to the min-heap.
   - The min-heap automatically sorts nodes based on their values, keeping the smallest value node at the top.

2. **Process the Heap Until Empty**:
   - Extract the smallest node from the heap and add it to the merged list.
   - If the extracted node has a next node, insert that next node into the min-heap.
   - Repeat this until all nodes have been processed, resulting in a fully merged sorted list.

This approach is efficient because the min-heap allows us to retrieve the smallest node in `O(log K)` time for each insertion and deletion.

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

class compare{
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a -> val > b -> val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq; 

        int k = lists.size();
        
        if(k == 0) return NULL;
        for(int i = 0; i < k; i++) if(lists[i] != NULL) pq.push(lists[i]);
        
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(pq.size() > 0){
            ListNode* top = pq.top();
            pq.pop();

            if(head == NULL){
                head = top;
                tail = top;
            }else{
                tail -> next = top;
                tail = top;
            }

            if(top -> next != NULL) pq.push(top -> next);
        }

        return head;
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

class compare{
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a -> val > b -> val;
        }
};
```

1. **Explanation**:
   - The `compare` class is a custom comparator for the min-heap.
   - The `operator()` overload function returns `true` if `a` has a greater value than `b`. This ensures the min-heap orders nodes based on increasing values.



```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
```

2. **Explanation**:
   - `mergeKLists` is the main function that merges `K` sorted lists.
   - A min-heap `pq` is created with `ListNode*` pointers, and the `compare` class as the comparator.



```cpp
        int k = lists.size();
        
        if(k == 0) return NULL;
        for(int i = 0; i < k; i++) if(lists[i] != NULL) pq.push(lists[i]);
```

3. **Explanation**:
   - `k` is the number of lists.
   - If `k` is 0 (i.e., there are no lists), we return `NULL`.
   - We iterate over each list and push its head node into the min-heap if it’s not `NULL`.



```cpp
        ListNode* head = NULL;
        ListNode* tail = NULL;
```

4. **Explanation**:
   - `head` will store the head of the merged list, and `tail` will help us append nodes to the merged list.



```cpp
        while(pq.size() > 0){
            ListNode* top = pq.top();
            pq.pop();
```

5. **Explanation**:
   - We process nodes in the min-heap until it’s empty.
   - `top` stores the smallest node in the min-heap, and we remove it from the heap using `pop()`.



```cpp
            if(head == NULL){
                head = top;
                tail = top;
            }else{
                tail -> next = top;
                tail = top;
            }
```

6. **Explanation**:
   - If `head` is `NULL`, it means this is the first node being added to our merged list, so we set both `head` and `tail` to `top`.
   - Otherwise, we append `top` to `tail->next` and update `tail` to point to this new node.



```cpp
            if(top -> next != NULL) pq.push(top -> next);
        }
```

7. **Explanation**:
   - If the node `top` has a next node, we push `top->next` into the min-heap.
   - This step ensures that the heap always has the next smallest element from any list.



```cpp
        return head;
    }
};
```

8. **Explanation**:
   - Finally, we return `head`, which points to the start of the fully merged sorted linked list.



### Step 3: Example Walkthrough

**Example**:  
Input:
```cpp
lists = [
    List 1: 1 -> 4 -> 7,
    List 2: 2 -> 5 -> 8,
    List 3: 3 -> 6 -> 9
]
```

Process:
1. Push the head of each list into the min-heap:
   - Min-heap contains: `[1, 2, 3]`

2. Pop the smallest element (`1`) from the heap, append it to the result list, and push its next node (`4`) to the heap:
   - Result list: `1`
   - Min-heap: `[2, 3, 4]`

3. Repeat until all nodes are processed:
   - After each step, the min-heap is rebalanced, and the smallest element is appended to the result list.

Final merged result:  
`1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9`

Output:  
`1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9`



### Step 4: Time and Space Complexity

1. **Time Complexity**:
   - Inserting and deleting nodes in a heap of size `K` takes `O(log K)` time.
   - There are `N` total nodes across all lists, so we perform `N` insertions and deletions.
   - The time complexity is therefore `O(N * log K)`.

2. **Space Complexity**:
   - The space complexity is `O(K)`, as the heap can contain up to `K` nodes at any time (one from each list).

### Step 5: Additional Recommendations

- **Understand the Priority Queue**: This solution is highly efficient because it leverages a min-heap. Practice using priority queues to get comfortable with their behavior.
- **Practice Edge Cases**: Ensure you handle edge cases such as empty lists, a single list, or lists with only one element.
- **Experiment with Larger Data Sets**: Testing with larger lists can give you a better sense of the efficiency of this approach and help identify potential optimizations.
- **NOTE :** [Approach 2](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/14%20-%20Linked%20List%20Data%20Structure%20Problems/01%20-%20Singly%20Linked%20List%20Problems/24%20-%20Merge%20K%20Sorted%20Linked%20Lists)

This explanation should provide a comprehensive understanding of the solution approach, code, and complexity analysis.
