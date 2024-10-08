<h1 align='center'>Return - Start - Node - of the - Loop - Linked - List</h1>

## Problem Statement

**Problem URL :** [None]()

ou are given a **singly linked list** where a loop (cycle) may exist. The task is to **find the node where the cycle begins**. This problem is an extension of detecting a loop in a linked list. Once a cycle is detected, you need to identify the node where the loop starts.

### Example 1: Linked List Without a Loop
```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```
There is no cycle in this list.

### Example 2: Linked List With a Loop
```
1 -> 2 -> 3 -> 4 -> 5
        ^           |
        |-----------|
```
In this list, node `5` points back to node `3`, creating a loop. The starting node of the loop is `3`.

### Problem Task:
- Detect whether a cycle exists in the linked list.
- If a cycle is present, find and return the node where the cycle starts.
- If there is no cycle, return `NULL`.

---

### Approach: **Floyd’s Cycle Detection Algorithm (Tortoise and Hare)**

To solve this problem efficiently, we can use **Floyd's Cycle Detection Algorithm** (also known as the Tortoise and Hare Algorithm). The approach can be broken down into two parts:

1. **Cycle Detection**: 
   - Use two pointers, `slow` and `fast`. `slow` moves one step at a time, while `fast` moves two steps at a time. If there is a cycle, these two pointers will eventually meet.
   
2. **Find the Start of the Cycle**: 
   - Once the cycle is detected (i.e., when `slow` and `fast` meet), reset the `slow` pointer to the head of the list. Now move both `slow` and `fast` one step at a time. The node where they meet again is the **starting point of the loop**.

### Time Complexity:
- **Time**: `O(n)` where `n` is the number of nodes in the linked list. Both `slow` and `fast` pointers traverse the list at most twice.
- **Space**: `O(1)` because no extra space is used apart from the pointers.

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

ListNode* startNode(ListNode* head){
  if(head == NULL || head -> next == NULL){
    cout<< "List List is Empty" <<endl;
    return NULL;
  }

  ListNode* slow = head;
  ListNode* fast = head;

  while(fast != NULL && fast -> next != NULL){
    slow = slow -> next;
    fast = fast -> next -> next;

    if(slow == fast){
      slow = head;

      while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
      }

      return slow;
    }
  }

  return NULL;
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

    printList(cyclicList);

    ListNode* sNode = startNode(cyclicList);

   if(sNode != NULL){
     cout << "\nStart Node of the loop is " << sNode -> val <<endl;  
   }else{
    cout << "No cycle dected" << endl;
   }

}

```

## Problem Solution Explanation

```cpp
#include <iostream>
using namespace std;

class ListNode {
    public:
      int val;                  // Value of the current node
      ListNode *next;           // Pointer to the next node
      ListNode(int x) : val(x), next(NULL) {} // Constructor to initialize node
};

// Function to create a cyclic linked list for demonstration purposes
ListNode* createCyclicLinkedList() {
    // Creating individual nodes
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    // Linking the nodes together
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Creating a cycle by pointing node 5's next to node 3
    node5->next = node3;

    return head; 
}
```

**Explanation:**
- We define the `ListNode` class, where each node contains a value (`val`) and a pointer to the next node (`next`).
- The `createCyclicLinkedList` function creates a linked list with 5 nodes, and a cycle is created by linking node 5 to node 3.

---

### Function to Find the Start of the Cycle:

```cpp
// Function to detect the start of the cycle in the linked list
ListNode* startNode(ListNode* head){
  // Edge case: If the list is empty or has only one node, no cycle can exist
  if(head == NULL || head -> next == NULL){
    cout<< "List is Empty or No Loop" <<endl;
    return NULL;
  }

  ListNode* slow = head;  // Slow pointer moves one step at a time
  ListNode* fast = head;  // Fast pointer moves two steps at a time

  // Loop to detect if there's a cycle in the linked list
  while(fast != NULL && fast -> next != NULL){
    slow = slow -> next;
    fast = fast -> next -> next;

    // When slow and fast meet, a cycle is detected
    if(slow == fast){
      slow = head;  // Reset the slow pointer to head

      // Find the start of the loop
      while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
      }

      // Both pointers meet at the starting node of the loop
      return slow;
    }
  }

  // If no cycle is found, return NULL
  return NULL;
}
```

**Explanation:**
- **Line 1-3**: Check if the list is empty or has only one node. If so, return `NULL` since no cycle is possible.
- **Line 5-11**: Use two pointers `slow` and `fast` to detect a cycle. `slow` moves one step, and `fast` moves two steps at a time.
- **Line 13-18**: Once a cycle is detected (when `slow` meets `fast`), reset `slow` to the head. Then move both `slow` and `fast` one step at a time until they meet again. This node is the starting point of the cycle.
- **Line 19**: If no cycle is detected, return `NULL`.

---

### Print and Test the Linked List:

```cpp
// Helper function to print the linked list up to a limit to avoid infinite loop in cyclic list
void printList(ListNode* head, int limit = 10) {
    ListNode* temp = head;
    while (limit-- > 0 && temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    ListNode* cyclicList = createCyclicLinkedList();  // Create a cyclic linked list

    printList(cyclicList);  // Print the list (limit 10 to avoid infinite loop)

    ListNode* sNode = startNode(cyclicList);  // Detect the start of the loop

    if(sNode != NULL){
        cout << "\nStart Node of the loop is " << sNode->val << endl;  
    } else {
        cout << "No cycle detected" << endl;
    }
}
```

**Explanation:**
- **Line 1-6**: `printList` prints the linked list but limits the number of nodes printed to avoid an infinite loop.
- **Line 10**: Create a cyclic linked list using the `createCyclicLinkedList` function.
- **Line 11**: Print the list (up to 10 nodes).
- **Line 12-17**: Detect the start of the loop and print the result. If no loop is found, print a message saying no cycle is detected.

---

### Example Walkthroughs:

#### Example 1: No Cycle
Input:
```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```
Output:
```
1 2 3 4 5
No cycle detected
```

#### Example 2: With a Cycle
Input:
```
1 -> 2 -> 3 -> 4 -> 5
        ^           |
        |-----------|
```
Output:
```
1 2 3 4 5 3 4 5 3 4 
Start Node of the loop is 3
```

---

### Complexity Analysis:
- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the linked list. We traverse the list once to detect the cycle, and another time to find the starting node of the cycle.
- **Space Complexity**: `O(1)` because no additional space is used, except for a few pointers.

This approach efficiently finds the starting node of the loop using constant space and linear time.
