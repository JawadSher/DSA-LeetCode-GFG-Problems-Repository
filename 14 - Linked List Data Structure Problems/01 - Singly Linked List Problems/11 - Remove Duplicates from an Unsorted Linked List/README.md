<h1 align='center'>Remove - Duplicates - From an - Unsorted - Linked - List</h1>

## Problem Statement

**Problem URL :** [Remove Duplicates from an Unsorted Linked List](https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/a7b129df-a656-4f2e-973e-c5c3fb5ed7f2)


## Problem Explanation
The problem is defined as follows:

- You are given the head of a **linked list** that may contain **duplicates**. The linked list is **not necessarily sorted**.
- Your task is to remove all duplicate elements from the linked list, ensuring that each value appears **only once**.
- The final linked list should maintain the original order of the first occurrences of the values.

#### Example Inputs and Outputs:

1. **Example 1:**
   - **Input:** `1 -> 2 -> 3 -> 2 -> 1`
   - **Output:** `1 -> 2 -> 3`
   - **Explanation:** The values `2` and `1` appear twice; we keep the first occurrence and remove the duplicates.

2. **Example 2:**
   - **Input:** `4 -> 5 -> 6 -> 5 -> 4 -> 7`
   - **Output:** `4 -> 5 -> 6 -> 7`
   - **Explanation:** The values `4` and `5` appear twice; we remove their duplicates.

3. **Example 3:**
   - **Input:** `5 -> 5 -> 5 -> 5`
   - **Output:** `5`
   - **Explanation:** All values are the same, so we keep just one occurrence.

### Approach to Solve the Problem

To solve this problem, we can utilize a data structure like a hash map (or unordered set) to keep track of the values we've already encountered while iterating through the linked list. Here’s how to approach the problem step-by-step:

1. **Initialize a Hash Map**: Use a map (or set) to store the unique values you encounter.
2. **Traverse the List**: Start from the head of the list and move through each node.
3. **Check for Duplicates**:
   - If the current node’s value is already in the map, it means it's a duplicate, so you should remove that node.
   - If it's not in the map, add it to the map and move to the next node.
4. **Update Pointers**: When removing a duplicate node, ensure that the previous node's `next` pointer skips the duplicate node.
5. **Return the Head**: Once you've processed the entire list, return the head of the modified linked list.

## Problem Solution
```cpp
class Solution {
  private:
   Node* removeDuplicatesHelper(Node* head){
       if(!head) return head;
       
       Node* current = head;
       
       map<int, bool> seen;
       
       seen[current->data] = true;
       
       while(current->next != NULL){
           
           if(seen[current->next->data]){
               Node* temp = current -> next;
               current -> next = current -> next -> next;
               delete temp;
           }else{
               seen[current->next->data] = true;
                current = current -> next;
           }
       }
       
       return head;
   }
  public:
    Node *removeDuplicates(Node *head) {
        if(!head || !head -> next) return head;

        return removeDuplicatesHelper(head);
    }
};

```

## Problem Solution Explanation

Here’s a detailed line-by-line explanation of the provided solution:

```cpp
class Solution {
```
- **Class Definition**: This defines a class named `Solution` that contains methods for removing duplicates from a linked list.

```cpp
private:
   Node* removeDuplicatesHelper(Node* head){
```
- **Private Method**: This is a private helper function called `removeDuplicatesHelper`, which takes the head of the linked list as an argument and returns the head of the modified linked list without duplicates.

```cpp
       if(!head) return head;
```
- **Base Case**: If the `head` is `nullptr` (i.e., the list is empty), return `head` as there are no duplicates to remove.

```cpp
       Node* current = head;
```
- **Current Node Pointer**: Initialize a pointer `current` to keep track of the current node as we traverse the linked list, starting from `head`.

```cpp
       map<int, bool> seen;
```
- **Hash Map Initialization**: Create a hash map named `seen` to keep track of the values that have been encountered. The key is the node's data, and the value is a boolean indicating whether we've seen this data before.

```cpp
       seen[current->data] = true;
```
- **Mark First Value**: Store the data of the head node in the map, indicating that we have seen this value.

```cpp
       while(current->next != NULL){
```
- **Traverse the List**: Start a while loop that continues until the `current` node's next pointer is `nullptr`, indicating the end of the list.

```cpp
           if(seen[current->next->data]){
```
- **Check for Duplicate**: For each node, check if the data of the next node (`current->next->data`) is already in the `seen` map.

```cpp
               Node* temp = current -> next;
```
- **Node to Delete**: If the data is already in the map (meaning it is a duplicate), create a temporary pointer `temp` to store the reference to the duplicate node (`current->next`) that needs to be removed.

```cpp
               current -> next = current -> next -> next;
```
- **Skip the Duplicate**: Update the `next` pointer of the `current` node to skip the duplicate node, effectively removing it from the list.

```cpp
               delete temp;
```
- **Delete the Duplicate Node**: Free the memory allocated for the duplicate node to prevent memory leaks.

```cpp
           }else{
```
- **Else Clause**: If the value is not a duplicate (not in the map), we execute the following code block:

```cpp
               seen[current->next->data] = true;
```
- **Mark as Seen**: Add the data of the current node’s next node to the `seen` map, indicating we have now encountered this value.

```cpp
               current = current -> next;
```
- **Move to Next Node**: Move the `current` pointer to the next node in the list.

```cpp
       }
```
- **End of While Loop**: The loop continues until all nodes are processed.

```cpp
       return head;
```
- **Return Modified Head**: After traversing the list and removing all duplicates, return the head of the modified linked list.

### Public Method: `removeDuplicates`

```cpp
public:
    Node *removeDuplicates(Node *head) {
```
- **Public Method**: This is the public method `removeDuplicates`, which will be called by the user to start the duplicate removal process.

```cpp
        if(!head || !head -> next) return head;
```
- **Check for Empty or Single Node**: If the linked list is empty (`head` is `nullptr`) or contains only one node (`head->next` is `nullptr`), we return the head directly, as there are no duplicates to remove.

```cpp
        return removeDuplicatesHelper(head);
```
- **Start Removal Process**: We call the `removeDuplicatesHelper` function, passing the `head` node to start the duplicate removal process.

```cpp
    }
};
```
- **End of Class**: This closes the `Solution` class definition.

### Summary of How a Beginner Can Approach This Problem

1. **Understand the Problem**: Ensure that you understand that you need to remove duplicates from an unsorted linked list.
2. **Plan Your Approach**: Decide to use a hash map (or set) to track the unique values as you traverse the list.
3. **Implement and Test**: Write the code based on the approach, and test it using various cases to ensure it behaves as expected.
4. **Debug and Optimize**: If issues arise, debug the code to check where things might be going wrong. Optimize memory usage and ensure that the solution is efficient.

### Examples to Illustrate the Solution

1. **Example Input:** `1 -> 2 -> 3 -> 2 -> 1`
   - Start with `current` at `1`.
   - First value `1` is added to `seen`.
   - Move to `2`: add `2` to `seen`.
   - Move to `3`: add `3` to `seen`.
   - Move to `2`: found in `seen`, skip this node and delete it.
   - Move to `1`: found in `seen`, skip this node and delete it.
   - **Resulting List:** `1 -> 2 -> 3`.

2. **Example Input:** `4 -> 5 -> 6 -> 5 -> 4 -> 7`
   - Start with `current` at `4`.
   - First value `4` is added to `seen`.
   - Move to `5`: add `5` to `seen`.
   - Move to `6`: add `6` to `seen`.
   - Move to `5`: found in `seen`, skip and delete.
   - Move to `4`: found in `seen`, skip and delete.
   - Move to `7`: add `7` to `seen`.
   - **Resulting List:** `4 -> 5 -> 6 -> 7`.

3. **Example Input:** `5 -> 5 -> 5 -> 5`
   - Start with `current` at `5`.
   - First value `5` is added to `seen`.
   - Move to `5`: found in `seen`, skip and delete.
   - Move to `5`: found in `seen`, skip and delete.
   - Move to `5`: found in `seen`, skip and delete.
   - **Resulting List:** `5`.

### Conclusion

This solution effectively removes duplicates from an unsorted linked list using a helper method and a hash map to track values. This allows beginners to grasp linked list manipulation and the concept of using auxiliary data structures like hash maps. Following the explanations and examples, beginners should be able to understand the problem and the solution thoroughly.
