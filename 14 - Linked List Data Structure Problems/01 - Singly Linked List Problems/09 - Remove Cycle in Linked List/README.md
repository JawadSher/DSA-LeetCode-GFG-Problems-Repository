<h1 align='center'>Remove - Cycle in - Linked - List</h1>

## Problem Statement

**Problem URL :** [None]()

The task is to **remove the cycle** from a linked list if one exists. Given a singly linked list where a cycle might exist, the goal is to detect and remove the cycle, restoring the linked list to its linear form.

### Example 1: Linked List Without a Loop
```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```
This is a linear linked list with no loop.

### Example 2: Linked List With a Loop
```
1 -> 2 -> 3 -> 4 -> 5
        ^           |
        |-----------|
```
In this case, node `5` points back to node `3`, creating a loop. The task is to remove the loop so the linked list becomes:
```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```

---

### Approach: **Detect and Remove Cycle Using Two Pointers**

We use **Floyd's Cycle Detection Algorithm (Tortoise and Hare)** to detect the cycle, and then modify the list to remove the cycle.

1. **Cycle Detection**: 
   - Use two pointers, `slow` and `fast`. The `slow` pointer moves one step at a time, and the `fast` pointer moves two steps at a time. If a cycle exists, they will eventually meet.
   
2. **Find the Start of the Cycle**:
   - Once a cycle is detected, reset the `slow` pointer to the head and move both pointers one step at a time. The node where they meet again is the **starting point of the cycle**.
   
3. **Remove the Cycle**:
   - To remove the cycle, traverse the cycle until you reach the node whose `next` points back to the start of the cycle. Set this node’s `next` pointer to `NULL` to break the cycle.

## Problem Solution
```cpp
#include <iostream>
using namespace std;

class ListNode {
    public:
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createCyclicLinkedList() {
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node5->next = node3;

    return head; 
}


void removeCyclic(ListNode* head){
    if (head == NULL || head->next == NULL) {
        cout << "Empty or No Loop in the linked list" << endl;
        return;
    }

  ListNode* slow = head;
  ListNode* fast = head;

  while(fast != NULL && fast -> next != NULL){
    fast = fast -> next -> next;
    slow = slow -> next;

    if(slow == fast){
      ListNode* intersectionPoint = fast;
      slow = head;

      while(slow != intersectionPoint){
        slow = slow -> next;
        intersectionPoint = intersectionPoint -> next;
      }

      ListNode* temp = intersectionPoint;
      while(temp -> next != intersectionPoint){
        temp = temp -> next;
      }

      temp -> next = NULL;
      cout<< "Cycle removed successfully" <<endl;
      return;
    }
  }

  cout << "No cycle detected" <<endl;
}

void printList(ListNode* head, int limit = 10) {
    ListNode* temp = head;
    while (limit-- > 0 && temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    ListNode* cyclicList = createCyclicLinkedList();

    cout<< "Cyclic Linked list : ";
    printList(cyclicList);
    
    cout<<endl;
    removeCyclic(cyclicList);

    cout << "\nRemove Cyclic Linked list : ";
    printList(cyclicList);
}

```

## Problem Solution Explanation

```cpp
#include <iostream>
using namespace std;

class ListNode {
    public:
      int val; // Value of the node
      ListNode *next; // Pointer to the next node
      ListNode(int x) : val(x), next(NULL) {} // Constructor
};

// Function to create a linked list with a cycle
ListNode* createCyclicLinkedList() {
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    // Linking nodes together
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Creating a cycle by linking node5 to node3
    node5->next = node3;

    return head;
}
```

**Explanation:**
- **Lines 1-7**: We define the `ListNode` class, which represents a node in the linked list.
- **Lines 9-19**: The `createCyclicLinkedList` function creates a cyclic linked list. In this case, the list `1 -> 2 -> 3 -> 4 -> 5` is created, and a cycle is formed by making `node5` point back to `node3`.

---

### Function to Remove the Cycle:

```cpp
void removeCyclic(ListNode* head){
    // Edge case: If the list is empty or has only one node, no cycle can exist
    if (head == NULL || head->next == NULL) {
        cout << "Empty or No Loop in the linked list" << endl;
        return;
    }

    ListNode* slow = head;  // Slow pointer
    ListNode* fast = head;  // Fast pointer

    // Loop to detect the cycle in the list
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;  // Fast pointer moves 2 steps
        slow = slow->next;        // Slow pointer moves 1 step

        // If slow and fast meet, a cycle is detected
        if(slow == fast){
            ListNode* intersectionPoint = fast; // The meeting point
            slow = head; // Reset slow to the head

            // Find the start of the cycle
            while(slow != intersectionPoint){
                slow = slow->next;
                intersectionPoint = intersectionPoint->next;
            }

            // To remove the cycle, find the node just before the start of the cycle
            ListNode* temp = intersectionPoint;
            while(temp->next != intersectionPoint){
                temp = temp->next;
            }

            temp->next = NULL; // Break the cycle
            cout << "Cycle removed successfully" << endl;
            return;
        }
    }

    cout << "No cycle detected" << endl;
}
```

**Explanation:**
- **Lines 1-3**: Handle edge cases where the list is empty or contains only one node. In such cases, no cycle can exist.
- **Lines 5-11**: Use Floyd's Cycle Detection Algorithm. The `slow` pointer moves one step, and the `fast` pointer moves two steps. If they meet, a cycle is detected.
- **Lines 12-18**: Once a cycle is detected, move `slow` back to the head. Both `slow` and `fast` are now moved one step at a time. The point where they meet again is the **starting node of the cycle**.
- **Lines 20-24**: To remove the cycle, traverse the cycle until you reach the node just before the start of the cycle, and set its `next` pointer to `NULL`, thus breaking the loop.
- **Line 26**: If no cycle is detected, print a message saying "No cycle detected."

---

### Print and Test the Linked List:

```cpp
// Helper function to print the list (limit printing to avoid infinite loops)
void printList(ListNode* head, int limit = 10) {
    ListNode* temp = head;
    while (limit-- > 0 && temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

// Main function to test the code
int main() {
    ListNode* cyclicList = createCyclicLinkedList();  // Create a cyclic list

    cout << "Cyclic Linked list: ";
    printList(cyclicList);  // Print the cyclic list (limit 10 nodes to avoid infinite loop)
    
    cout << endl;

    removeCyclic(cyclicList);  // Remove the cycle from the list

    cout << "\nAfter Removing Cycle: ";
    printList(cyclicList);  // Print the list after removing the cycle
}
```

**Explanation:**
- **Lines 1-6**: The `printList` function prints the linked list up to a specified limit of nodes to avoid infinite loops in case of a cycle.
- **Lines 9-17**: In the `main` function:
  - A cyclic linked list is created using `createCyclicLinkedList`.
  - The list is printed, but printing is limited to avoid an infinite loop.
  - The `removeCyclic` function is called to remove the cycle.
  - Finally, the list is printed again after removing the cycle.

---

### Example Walkthroughs:

#### Example 1: Linked List Without a Loop
Input:
```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```
Output:
```
Cyclic Linked list: 1 2 3 4 5 
No cycle detected

After Removing Cycle: 1 2 3 4 5 
```
- The list has no cycle, so no modifications are made.

#### Example 2: Linked List With a Loop
Input:
```
1 -> 2 -> 3 -> 4 -> 5
        ^           |
        |-----------|
```
Output:
```
Cyclic Linked list: 1 2 3 4 5 3 4 5 3 4 
Cycle removed successfully

After Removing Cycle: 1 2 3 4 5 
```
- The cycle is detected and successfully removed, resulting in a linear linked list.

---

### Complexity Analysis:
- **Time Complexity**: `O(n)` where `n` is the number of nodes in the linked list. The list is traversed twice: once to detect the cycle and once to remove it.
- **Space Complexity**: `O(1)` since we only use a constant amount of space for the pointers.

This approach efficiently detects and removes the cycle from the linked list, restoring it to a linear structure.
