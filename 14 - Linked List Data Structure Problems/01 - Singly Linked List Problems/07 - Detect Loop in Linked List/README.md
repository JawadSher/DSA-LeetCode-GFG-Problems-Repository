<h1 align='center'>Detect - Loop in - Linked - List</h1>

## Problem Statement

**Problem URL :** [Detect Lopp in Linked List](https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/f890e5e8-a33c-4fdc-bb19-2baecbcedeae)
![image](https://github.com/user-attachments/assets/d4f9a89c-adf1-4bc0-af40-13897add9381)

## Problem Explanation

The task in this problem is to determine if a **singly linked list** contains a loop (cycle). A loop exists if, at some point, a node in the linked list points back to one of the previous nodes instead of pointing to `NULL`. This can lead to infinite traversal of the list.

### Example 1: Linked List Without a Loop
```
1 -> 2 -> 3 -> 4 -> NULL
```
In this list, each node points to the next one, and the last node points to `NULL`. There is no loop here.

### Example 2: Linked List With a Loop
```
1 -> 2 -> 3 -> 4 -> 5
        ^           |
        |-----------|
```
In this list, node 5 points back to node 3, creating a cycle or loop.

### Problem Task:
Write a function to detect if a loop exists in the given linked list. If a loop is found, return `true`; otherwise, return `false`.

---

### Approach: **Using Hash Map (Visited Nodes)**

A simple approach to solve this problem is to use a **hash map (or unordered map)** to store the nodes as we traverse the linked list. The key idea is to keep track of whether we have seen a node before. If we revisit a node, it means there is a cycle.

**Steps:**
1. Create a map to store visited nodes.
2. Start traversing the linked list from the head.
3. For each node:
   - If the node is already in the map, it means we've seen it before, so a loop exists. Return `true`.
   - If the node is not in the map, mark it as visited and move to the next node.
4. If you reach the end of the list (`NULL`), return `false` as there is no loop.

**Time Complexity**: `O(n)`, where `n` is the number of nodes in the linked list.
- We visit each node once and store them in a hash map.

**Space Complexity**: `O(n)` because we need extra space to store all the visited nodes.

## Problem Solution
```cpp
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        if(head == NULL) return false;
        
        map<Node*, bool> visited;
        
        Node* temp = head;
        
        while(temp != NULL){
            if(visited[temp] == true){
                return true;
            }
            
            visited[temp] = true;
            temp = temp -> next;
        }
        return false;
    }
};
```

## Problem Solution Explanation

1. **`bool detectLoop(Node* head)`**: This function checks if there is a loop in the linked list. It takes the head of the linked list as input and returns a boolean (`true` or `false`).

2. **`if(head == NULL) return false;`**: This line checks if the list is empty. If the list is empty (`head == NULL`), it can't have a loop, so return `false`.

3. **`map<Node*, bool> visited;`**: This creates a hash map (or dictionary) to store whether a node has been visited. The keys in the map are node addresses, and the values are `true` (visited) or `false` (not visited).

4. **`Node* temp = head;`**: This initializes a pointer `temp` to traverse the linked list, starting from the head.

5. **`while(temp != NULL)`**: This loop traverses the linked list until `temp` becomes `NULL` (end of the list).

6. **`if(visited[temp] == true)`**: If the current node `temp` is already marked as visited in the hash map, it means we’ve encountered this node before, so a loop exists. Return `true`.

7. **`visited[temp] = true;`**: If the node is not in the hash map, mark it as visited by setting `visited[temp] = true`.

8. **`temp = temp -> next;`**: Move the pointer to the next node in the linked list.

9. **`return false;`**: If the loop terminates and no cycle is found, return `false`.

---

### Example Walkthrough:

#### Example 1: Linked List Without a Loop
```
1 -> 2 -> 3 -> 4 -> NULL
```
- We start at node `1`, mark it as visited.
- Move to node `2`, mark it as visited.
- Move to node `3`, mark it as visited.
- Move to node `4`, mark it as visited.
- Finally, we reach `NULL`, so the list has no loop, and the function returns `false`.

#### Example 2: Linked List With a Loop
```
1 -> 2 -> 3 -> 4 -> 5
        ^           |
        |-----------|
```
- We start at node `1`, mark it as visited.
- Move to node `2`, mark it as visited.
- Move to node `3`, mark it as visited.
- Move to node `4`, mark it as visited.
- Move to node `5`, mark it as visited.
- Move back to node `3` (because of the loop). This node has already been visited, so we return `true` as a loop is detected.

---

### Time and Space Complexity:

- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the linked list. We traverse each node at most once.

- **Space Complexity**: `O(n)` because we are storing each visited node in the hash map.

---

### Alternate Approach: Floyd’s Cycle Detection (Tortoise and Hare)

Instead of using extra space, we can also solve this problem using **Floyd’s Cycle Detection Algorithm** (explained in the previous response), where we use two pointers (`slow` and `fast`) to detect a cycle in **O(1) space** and **O(n) time**.

In this case, the map-based approach is easier to understand and implement, but it uses extra space. Floyd's cycle detection is more space-efficient and is preferred in terms of optimizing space.
