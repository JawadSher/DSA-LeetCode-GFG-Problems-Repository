<h1 align='center'>Merge - Two - BST's - Best - Approach</h1>


## Source Code Explanation
### **1. Node Class**

```cpp
class Node {
public:
    int data;           // Data value of the node
    Node* left;         // Pointer to the left child
    Node* right;        // Pointer to the right child

    // Constructor to initialize a node with given value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
```

- **Explanation:**  
  This defines a `Node` class that represents the basic building block for both the **Binary Search Tree (BST)** and the **Doubly Linked List (DLL)**.
  - Each `Node` contains:
    - `data`: The value of the node (integer).
    - `left`: Points to the left child in a BST or the previous node in a DLL.
    - `right`: Points to the right child in a BST or the next node in a DLL.
  - **Constructor:** Initializes the `data` field with the passed value and sets `left` and `right` to `nullptr`.
  
- **Example:**
  For a `Node` with value 10:
  ```cpp
  Node* n = new Node(10);
  ```
  This creates a node with value `10` and both `left` and `right` pointers set to `nullptr`.

---

### **2. Inserting Node into BST**

```cpp
Node* insertBST(Node* root, int val) {
    if (root == nullptr) return new Node(val);  // If tree is empty, create node
    if (val < root->data) 
        root->left = insertBST(root->left, val);  // Insert into left subtree if value is smaller
    else 
        root->right = insertBST(root->right, val);  // Insert into right subtree if value is larger
    return root;
}
```

- **Explanation:**  
  This function inserts a value into a Binary Search Tree (BST). The BST property is maintained: left subtree contains smaller values, and right subtree contains larger values.
  - **Base Case:** If the root is `nullptr`, create a new node with the value `val`.
  - **Recursive Case:** Compare `val` with the `root->data` and insert `val` into the left or right subtree accordingly.
  - The function returns the root of the tree.

- **Example:**  
  For a sequence of values: `3`, `1`, `5`:
  ```cpp
  Node* root = nullptr;
  root = insertBST(root, 3);  // Tree: 3
  root = insertBST(root, 1);  // Tree: 1 -> 3
  root = insertBST(root, 5);  // Tree: 1 -> 3 -> 5
  ```

- **Time Complexity:**  
  - In the worst case (unbalanced tree), the time complexity is `O(n)` where `n` is the number of nodes in the tree.
  - In the average case (balanced tree), it is `O(log n)` because we divide the tree approximately in half each time.

- **Space Complexity:**  
  - `O(n)` for the recursion stack in the worst case.

---

### **3. Convert BST to Sorted DLL**

```cpp
void convertIntoSortedDLL(Node* root, Node* &head) {
    if (root == nullptr) return;  // Base case

    convertIntoSortedDLL(root->right, head);  // Process right subtree first

    root->right = head;  // Link current node's right to the head of the DLL
    if (head != nullptr) head->left = root; // Set head's left to current node

    head = root;  // Update head to current node

    convertIntoSortedDLL(root->left, head);  // Process left subtree
}
```

- **Explanation:**  
  This function converts a Binary Search Tree (BST) into a **sorted Doubly Linked List (DLL)** using an in-order traversal:
  - **In-order Traversal:** Left subtree → Node → Right subtree. This ensures the nodes are processed in sorted order.
  - **Base Case:** If `root` is `nullptr`, return.
  - **Recursive Case:**
    - First, it processes the **right** subtree.
    - Then, it links the current node to the DLL by setting its `right` pointer to the `head` of the DLL and setting the head's `left` pointer to the current node.
    - Finally, it updates `head` to point to the current node and processes the **left** subtree.
  
- **Example:**  
  For a BST:
  ```
      3
     / \
    1   5
  ```
  The in-order traversal produces: `1, 3, 5`, and the resulting DLL will be:
  ```
  1 <-> 3 <-> 5
  ```

- **Time Complexity:**  
  - Since each node is visited exactly once, the time complexity is `O(n)` where `n` is the number of nodes in the BST.

- **Space Complexity:**  
  - The space complexity is `O(h)` where `h` is the height of the tree due to the recursion stack.

---

### **4. Merge Two Sorted DLLs**

```cpp
Node* mergeLinkedList(Node* head1, Node* head2) {
    Node* head = nullptr;
    Node* tail = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            if (head == nullptr) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if (head == nullptr) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != nullptr) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != nullptr) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}
```

- **Explanation:**  
  This function merges two sorted Doubly Linked Lists (`head1` and `head2`) into a single sorted DLL.
  - **Base Case:** If either list is `nullptr`, the other list is returned directly.
  - The function iterates through both DLLs, compares the `data` of the nodes, and appends the smaller node to the merged list (`head`).
  - After the main loop, any remaining nodes in `head1` or `head2` are appended to the merged list.

- **Example:**  
  Merging:
  ```
  head1: 1 <-> 3 <-> 5
  head2: 2 <-> 4 <-> 6
  ```
  Results in:
  ```
  merged: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
  ```

- **Time Complexity:**  
  - Each list is traversed exactly once, so the time complexity is `O(n + m)` where `n` and `m` are the lengths of the two DLLs.

- **Space Complexity:**  
  - The space complexity is `O(1)` because we're only manipulating pointers and not using additional space for new nodes.

---

### **5. Count Nodes in DLL**

```cpp
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->right;
    }
    return count;
}
```

- **Explanation:**  
  This function counts the number of nodes in a given Doubly Linked List.
  - It starts from the `head` and iterates through the list, incrementing a `count` for each node.
  - The loop terminates when `temp` is `nullptr` (end of the list).

- **Example:**  
  For the DLL `1 <-> 2 <-> 3`, the function will return `3`.

- **Time Complexity:**  
  - The time complexity is `O(n)`, where `n` is the number of nodes in the DLL.

- **Space Complexity:**  
  - The space complexity is `O(1)` because we are not using any extra space other than the `count` variable.

---

### **6. Convert Sorted DLL to Balanced BST**

```cpp
Node* sortedLLToBST(Node* &head, int n) {
    if (n <= 0 || head == nullptr) return nullptr;

    Node* left = sortedLLToBST(head, n / 2);

    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}
```

- **Explanation:**  
  This function converts

 a **sorted Doubly Linked List (DLL)** into a **balanced Binary Search Tree (BST)**.
  - **Base Case:** If `n <= 0` or `head` is `nullptr`, return `nullptr` (empty subtree).
  - **Recursive Case:**  
    - First, it recursively builds the left subtree by passing `n / 2`.
    - Then, it selects the `head` as the root node for the current subtree.
    - The current `head` is updated to `head->right` before constructing the right subtree.
  - The tree is balanced because it chooses the middle element of the DLL as the root at each recursive step.

- **Example:**  
  For a sorted DLL:
  ```
  1 <-> 2 <-> 3 <-> 4 <-> 5
  ```
  The resulting balanced BST would be:
  ```
      3
     / \
    1   5
     \  /
      2 4
  ```

- **Time Complexity:**  
  - The time complexity is `O(n)` because each node is processed exactly once.

- **Space Complexity:**  
  - The space complexity is `O(h)` where `h` is the height of the BST due to the recursion stack.

---

### **7. In-Order Traversal of BST**

```cpp
void printInOrder(Node* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    std::cout << root->data << " ";
    printInOrder(root->right);
}
```

- **Explanation:**  
  This function performs an **in-order traversal** of the BST:
  - Traverse the left subtree.
  - Print the root node.
  - Traverse the right subtree.

- **Example:**  
  For the BST:
  ```
      3
     / \
    1   5
     \  /
      2 4
  ```
  The in-order traversal will print:
  ```
  1 2 3 4 5
  ```

- **Time Complexity:**  
  - The time complexity is `O(n)` because each node is visited once.

- **Space Complexity:**  
  - The space complexity is `O(h)` due to the recursion stack, where `h` is the height of the tree.

---

## Dry-Run

### **1. Insert Node into BST**

```cpp
Node* insertBST(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else 
        root->right = insertBST(root->right, val);
    return root;
}
```

#### **Dry Run Example:**
Insert values `3`, `1`, `5` into an initially empty BST.

**Initial call:**
- `root = nullptr`
- `val = 3`

**First recursion:**
- `root == nullptr`, so create a node with value `3`.

**Second call:**
- `root = 3`
- `val = 1`
- Since `val < root->data`, the function calls `insertBST(root->left, 1)`.

**Third recursion:**
- `root = nullptr` (left of node `3` is empty)
- Create a new node with value `1`.

**Return to Second recursion:**
- Link node `1` as the left child of node `3`.

**Fourth call:**
- `root = 3`
- `val = 5`
- Since `val > root->data`, the function calls `insertBST(root->right, 5)`.

**Fifth recursion:**
- `root = nullptr` (right of node `3` is empty)
- Create a new node with value `5`.

**Return to Fourth recursion:**
- Link node `5` as the right child of node `3`.

**Final Tree:**
```
    3
   / \
  1   5
```

---

### **2. Convert BST to Sorted DLL**

```cpp
void convertIntoSortedDLL(Node* root, Node* &head) {
    if (root == nullptr) return;

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if (head != nullptr) head->left = root;
    head = root;
    convertIntoSortedDLL(root->left, head);
}
```

#### **Dry Run Example:**
Convert the BST:
```
    3
   / \
  1   5
```
into a sorted DLL.

**Initial call:**
- `root = 3`, `head = nullptr`

**First recursion (right subtree):**
- `root = 5`
- `head = nullptr`
- Recursively call `convertIntoSortedDLL(root->right, head)` (right of node `5` is `nullptr`).

**Second recursion:**
- `root = nullptr`
- Return.

**Return to First recursion:**
- Set `root->right = head`, which is `nullptr`, so `5->right = nullptr`.
- Set `head->left = 5`, but `head` is still `nullptr`, so this doesn't apply.
- Update `head = 5`.
- Recursively call `convertIntoSortedDLL(root->left, head)` (left of node `5` is `nullptr`).

**Third recursion:**
- `root = nullptr`
- Return.

**Return to Initial recursion:**
- Now, `root = 3`:
  - Set `root->right = head` (link node `3` to node `5`), so `3->right = 5`.
  - Set `head->left = 3` (link node `5` to node `3`), so `5->left = 3`.
  - Update `head = 3`.
- Recursively call `convertIntoSortedDLL(root->left, head)` (left of node `3` is `1`).

**Fourth recursion (left subtree):**
- `root = 1`
- Recursively call `convertIntoSortedDLL(root->right, head)` (right of node `1` is `nullptr`).

**Fifth recursion:**
- `root = nullptr`
- Return.

**Return to Fourth recursion:**
- Set `root->right = head` (link node `1` to node `3`), so `1->right = 3`.
- Set `head->left = 1` (link node `3` to node `1`), so `3->left = 1`.
- Update `head = 1`.
- Recursively call `convertIntoSortedDLL(root->left, head)` (left of node `1` is `nullptr`).

**Sixth recursion:**
- `root = nullptr`
- Return.

**Final DLL:**
```
1 <-> 3 <-> 5
```

---

### **3. Merge Two Sorted DLLs**

```cpp
Node* mergeLinkedList(Node* head1, Node* head2) {
    Node* head = nullptr;
    Node* tail = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            if (head == nullptr) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if (head == nullptr) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != nullptr) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != nullptr) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}
```

#### **Dry Run Example:**
Merge two sorted DLLs:
- `head1 = 1 <-> 3 <-> 5`
- `head2 = 2 <-> 4 <-> 6`

**Initial call:**
- `head = nullptr`, `tail = nullptr`
- `head1 = 1`, `head2 = 2`

**First iteration:**
- `head1->data = 1`, `head2->data = 2`
- Since `1 < 2`, append `1` to merged list. Now `head = 1`, `tail = 1`, `head1` moves to `3`.

**Second iteration:**
- `head1->data = 3`, `head2->data = 2`
- Since `2 < 3`, append `2` to merged list. Now `head = 1`, `tail = 2`, `head2` moves to `4`.

**Third iteration:**
- `head1->data = 3`, `head2->data = 4`
- Since `3 < 4`, append `3` to merged list. Now `head = 1`, `tail = 3`, `head1` moves to `5`.

**Fourth iteration:**
- `head1->data = 5`, `head2->data = 4`
- Since `4 < 5`, append `4` to merged list. Now `head = 1`, `tail = 4`, `head2` moves to `6`.

**Fifth iteration:**
- `head1->data = 5`, `head2->data = 6`
- Since `5 < 6`, append `5` to merged list. Now `head = 1`, `tail = 5`, `head1` moves to `nullptr`.

**Final iteration:**
- `head1 = nullptr`, append remaining `6` to merged list. Now `head = 1`, `tail = 6`, `head2` moves to `nullptr`.

**Final merged DLL:**
```
1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
```

---

### **4. Convert Sorted DLL to Balanced BST**

```cpp
Node* sortedLLToBST(Node* &head, int n) {
    if (n <= 0 || head == nullptr) return nullptr;

    Node* left = sortedLLToBST(head, n / 2);
    Node* root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}
```

#### **Dry Run Example:**
Convert the sorted DLL:
```
1 <-> 2 <-> 3 <-> 4 <-> 5
```
to a balanced BST.

**Initial call:**
- `head = 1`, `n = 5`
- `n / 2 = 2` → first recursive call: `sortedLLToBST(head, 2)`.

**First recursion:**
- `head = 1`, `n = 2`
- `n / 2 = 1` → second recursive call: `sortedLLToBST(head, 1)`.

**Second recursion:**
- `head = 1`, `n = 1`
- `

n / 2 = 0` → third recursive call: `sortedLLToBST(head, 0)`.

**Third recursion:**
- `head = nullptr`, return `nullptr`.

**Return to Second recursion:**
- Set `root = 1`, move `head` to `2`.
- Link node `1` as root.
- Recursively call `sortedLLToBST(head, 0)`.

**Fourth recursion:**
- `head = 2`, `n = 0`
- Return `nullptr`.

**Return to First recursion:**
- Set `root = 3`, move `head` to `4`.
- Link node `2` as left child, node `3` as root.
- Recursively call `sortedLLToBST(head, 1)`.

**Fifth recursion:**
- `head = 4`, `n = 1`
- Set `root = 4`, move `head` to `5`.
- Return node `4` as root.

**Final BST:**
```
    3
   / \
  1   5
   \ /
    2 4
```

---

These dry runs should give a clear picture of how each recursive step works and the state of the relevant variables at each stage.

### **Conclusion**

This approach effectively demonstrates how to convert BSTs to DLLs, merge two DLLs, and then convert the merged DLL into a balanced BST. Each function has been broken down to show its purpose and behavior, with time and space complexities provided to help in performance analysis.

