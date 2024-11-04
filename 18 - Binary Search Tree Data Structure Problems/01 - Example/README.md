<h1 align='center'>Binary - Search - Tree - Example</h1>

## Binary Search Tree 
A **Binary Search Tree (BST)** is a binary tree data structure that has the following properties:
1. Each node has at most two children, referred to as the **left** and **right** child.
2. For any node in the tree:
   - All nodes in its **left subtree** have values **less than** the node’s value.
   - All nodes in its **right subtree** have values **greater than** the node’s value.

These properties make BSTs particularly useful for **efficient searching**, **insertion**, and **deletion** of elements.

#### Example of a Binary Search Tree

Consider the following sequence of numbers: `15, 10, 20, 8, 12, 16, 25`

If we insert these numbers into a BST, we get a tree that looks like this:

```
       15
     /    \
   10      20
  /  \    /   \
 8   12  16   25
```

Here's how it meets the BST properties:
- `10` is less than `15` and is placed in the left subtree.
- `20` is greater than `15` and is placed in the right subtree.
- Similarly, `8` and `12` are placed in the left subtree of `10`, and so on.

#### Time Complexity of Basic Operations
- **Search**: \(O(h)\)
- **Insertion**: \(O(h)\)
- **Deletion**: \(O(h)\)

Where \(h\) is the height of the tree. For a balanced tree, \(h \approx \log n\) (where \(n\) is the number of nodes), so operations take \(O(\log n)\) time.


## Source Code
```cpp
#include <iostream>
#include <queue>
using namespace std;

class Node{
  public:
    int data;
    Node* right;
    Node* left;

    Node(int data){
      this -> data = data;
      this -> left = NULL;
      this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
  // base case
  if(root == NULL){
    root = new Node(data);
    return root;
  }

  if(data > root -> data){
    // right part insertion
    root -> right = insertIntoBST(root -> right, data);
  }else{
    // left part insertion
    root -> left = insertIntoBST(root -> left, data);
  }

  return root;
}

void takeInput(Node* &root){
  int data;
  cin >> data;

  while (data != -1){
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void inOrderTraversal(Node* root){
    if(root == NULL) return;
    
    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void preOrderTraversal(Node* root){
    if(root == NULL) return;
    
    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root){
    if(root == NULL) return;
    
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}

void SearchBST(Node* root, int value){
    if(root == NULL) {
        cout << "Value not Present" << endl;
        return;
    }
    
    if(root -> data == value) {
        cout << "Value is Present" << endl;
        return;
    }
    
    if(root -> data < value) return SearchBST(root -> right, value);
    else return SearchBST(root -> left, value);
}

Node* minValue(Node* root){
    if(root == NULL) {
        cout << "Tree is Empty" << endl;
        return NULL;
    }
    while(root -> left != NULL){
        root = root -> left;
    }
    
    cout << "Minimum Value is : " << root -> data << endl;
    return root;
}

Node* maxValue(Node* root){
    if(root == NULL){
        cout << "Tree is Empty" << endl;
        return NULL;
    }
    
    while(root -> right != NULL){
        root = root -> right;
    }
    
    cout << "Maximum value is : "<< root -> data << endl;
    return root;
}

Node* inOrderPredecessor(Node* root, Node* target){
    Node* predecessor = NULL;
    
    while(root != NULL){
        if(target -> data > root -> data){
            predecessor = root;
            root = root -> right;
        }else{
            root = root -> left;
        }   
    }
    
    return predecessor;
}

Node* inOrderSuccessor(Node* root, Node* target){
   if(target->right != NULL) {
        Node* current = target->right;
        while(current->left != NULL) {
            current = current->left;
        }
        return current;
    } else {
        Node* successor = NULL;
        Node* ancestor = root;

        while(ancestor != target) {
            if(target->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

Node* deleteFromBST(Node* root, int value) {
    // Base case: If the root is NULL, return NULL
    if (root == NULL) return root;
    
    // If the node to be deleted is found
    if (root->data == value) {
        // Case 1: Node with 0 children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        // Case 2: Node with 1 child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        // Case 3: Node with 2 children
        if (root->left != NULL && root->right != NULL) {
            // Find the minimum value in the right subtree
            int mini = minValue(root->right)->data;
            // Replace root's data with the minimum value
            root->data = mini;
            // Recursively delete the minimum node in the right subtree
            root->right = deleteFromBST(root->right, mini);
        }
    } 
    // If the value is less than root's data, go to the left subtree
    else if (root->data > value) {
        root->left = deleteFromBST(root->left, value);
    } 
    // If the value is greater than root's data, go to the right subtree
    else {
        root->right = deleteFromBST(root->right, value);
    }
    
    return root;
}


int main() {
  Node* root = NULL;

  cout << endl << "Enter data to create BST" <<endl;
  takeInput(root);
  
  cout << endl << "Printing the BST" << endl;
  levelOrderTraversal(root);
  
  cout << endl << "Printing In-Order Traversal" << endl;
  inOrderTraversal(root);
  
  cout << endl << "Printing Pre-Order Traversal" << endl;
  preOrderTraversal(root);
  
  cout << endl << "Printing Post-Order Traversal" << endl;
  postOrderTraversal(root);
 
  cout << endl << "Searching in BST" << endl;
  SearchBST(root, 2);
  SearchBST(root, 50);
  
  cout << endl << "Searching minimum value" << endl;
  minValue(root);
  
  cout << endl << "Searching maximum value" << endl;
  maxValue(root);
  
  cout << endl << "Searching the Predecessor" << endl;
    int targetValue = 5;
    Node* targetNode = root;
    
    // Find the target node in the BST
    while (targetNode != NULL && targetNode->data != targetValue) {
        if (targetValue < targetNode->data) {
            targetNode = targetNode->left;
        } else {
            targetNode = targetNode->right;
        }
    }
  
    if (targetNode != NULL) {
        Node* predecessor = inOrderPredecessor(root, targetNode);
        if (predecessor != NULL) {
            cout << "Predecessor of " << targetValue << " is : " << predecessor->data << endl;
        } else {
            cout << "No predecessor found for " << targetValue << endl;
        }
    } else {
        cout << "Target node not found in the tree." << endl;
    }
    
    cout << endl << "Searching the Successor" << endl;
    int value = 5;
    Node* target = root;

    // Find the target node in the BST
    while(target != NULL && target->data != value) {
        if(value < target->data) {
            target = target->left;
        } else {
            target = target->right;
        }
    }

    if(target != NULL) {
        Node* successor = inOrderSuccessor(root, target);
        if(successor != NULL) {
            cout << "Successor of " << value << " is : " << successor->data << endl;
        } else {
            cout << "No Successor found for " << value << endl;
        }
    } else {
        cout << "Target node not found in the tree." << endl;
    }
    
    root = deleteFromBST(root, 90);
    
    cout << endl << "Printing the BST" << endl;
    levelOrderTraversal(root);
    
  return 0;
}
```

## Source Code Explanation

#### 1. `Node` Class Definition
```cpp
class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
```
The `Node` class defines a structure for a single node in the BST:
- Each node contains an integer `data`.
- `left` and `right` pointers point to the left and right child nodes, respectively.
- The constructor initializes a node with a given value and sets the `left` and `right` pointers to `NULL`.

#### 2. `insertIntoBST` Function
```cpp
Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}
```

- This function **inserts** a new node with the given `data` into the BST.
- The base case is when `root` is `NULL`, meaning an empty tree or position where the new node should be placed.
- If `data` is greater than `root->data`, it recursively inserts into the right subtree; otherwise, it inserts into the left subtree.

#### 3. `takeInput` Function
```cpp
void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
```

- This function reads multiple integers from the user to construct the BST.
- Each value is inserted into the BST using `insertIntoBST`.
- `-1` serves as a terminator, stopping the input process.

#### 4. `levelOrderTraversal` Function
```cpp
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}
```

- This function performs a **level-order traversal** (also known as breadth-first traversal).
- Nodes are printed level by level, and a new line is printed after each level.
- The queue `q` helps keep track of nodes in each level, using `NULL` as a marker to indicate the end of a level.

#### 5. `inOrderTraversal`, `preOrderTraversal`, and `postOrderTraversal` Functions
These functions perform **depth-first traversals** on the BST:

- **In-order**: `left -> root -> right`
- **Pre-order**: `root -> left -> right`
- **Post-order**: `left -> right -> root`

For example, the `inOrderTraversal` function:
```cpp
void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
```

#### 6. `SearchBST` Function
```cpp
void SearchBST(Node* root, int value) {
    if (root == NULL) {
        cout << "Value not Present" << endl;
        return;
    }
    
    if (root->data == value) {
        cout << "Value is Present" << endl;
        return;
    }
    
    if (root->data < value) return SearchBST(root->right, value);
    else return SearchBST(root->left, value);
}
```

- This function searches for a `value` in the BST.
- If the value matches `root->data`, it prints a message that the value is present.
- It recursively searches the left or right subtree based on the value comparison with `root->data`.

#### 7. `minValue` and `maxValue` Functions
These functions find the **minimum** and **maximum** values in the BST, respectively.

- **Minimum value** is found by traversing as far left as possible.
- **Maximum value** is found by traversing as far right as possible.

Example for `minValue`:
```cpp
Node* minValue(Node* root) {
    if (root == NULL) {
        cout << "Tree is Empty" << endl;
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    
    cout << "Minimum Value is : " << root->data << endl;
    return root;
}
```

#### 8. `inOrderPredecessor` and `inOrderSuccessor` Functions
These functions find the **in-order predecessor** (largest value smaller than a target) and **in-order successor** (smallest value larger than a target).

Example for `inOrderPredecessor`:
```cpp
Node* inOrderPredecessor(Node* root, Node* target) {
    Node* predecessor = NULL;
    
    while (root != NULL) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }   
    }
    
    return predecessor;
}
```

#### 9. `deleteFromBST` Function
```cpp
Node* deleteFromBST(Node* root, int value) {
    if (root == NULL) return root;
    
    if (root->data == value) {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        if (root->left != NULL && root->right != NULL) {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
        }
    } else if (root->data > value) {
        root->left = deleteFromBST(root->left, value);
    } else {
        root->right = deleteFromBST(root->right, value);
    }
    
    return root;
}
```

- This function deletes a node with a specified `value`.
- **Case 1**: Node has no children (leaf) — delete the node and return `NULL`.
- **Case 2**: Node has one child — replace the node with its child and delete it.
- **Case 3**: Node has two children — find the minimum node in the right subtree, replace the node’s data with this minimum value, and delete the minimum node in the right subtree.

### Example Execution and Time Complexity
- **Insertion**, **searching**, and **deletion** all have average time complexity of \(O(\log n)\) in a balanced BST and \(O(n)\) in a skewed tree.

Let’s assume our BST code includes a `main` function that:
1. Constructs a BST by taking input from the user.
2. Demonstrates traversal functions.
3. Searches for a specific value.
4. Finds minimum and maximum values.
5. Finds the in-order predecessor and successor.
6. Deletes a value from the BST.

We'll walk through each function and include sample outputs based on the input sequence: `15, 10, 20, 8, 12, 16, 25`. This would create the following BST:

```
       15
     /    \
   10      20
  /  \    /   \
 8   12  16   25
```

### `main` Function Execution and Sample Output

The `main` function can be set up like this:

```cpp
int main() {
    Node* root = NULL;
    cout << "Enter values to insert into BST (end with -1): ";
    takeInput(root);

    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\nIn-Order Traversal: ";
    inOrderTraversal(root);
    cout << "\nPre-Order Traversal: ";
    preOrderTraversal(root);
    cout << "\nPost-Order Traversal: ";
    postOrderTraversal(root);

    int searchValue = 16;
    cout << "\n\nSearching for value " << searchValue << " in BST:\n";
    SearchBST(root, searchValue);

    cout << "\nMinimum value in BST:\n";
    minValue(root);
    cout << "Maximum value in BST:\n";
    maxValue(root);

    Node* target = root->left;  // Assuming target node is 10
    cout << "\nIn-Order Predecessor of " << target->data << ": ";
    Node* pred = inOrderPredecessor(root, target);
    if (pred) cout << pred->data << endl;
    else cout << "No predecessor found.\n";

    cout << "In-Order Successor of " << target->data << ": ";
    Node* succ = inOrderSuccessor(root, target);
    if (succ) cout << succ->data << endl;
    else cout << "No successor found.\n";

    int deleteValue = 10;
    cout << "\nDeleting value " << deleteValue << " from BST:\n";
    root = deleteFromBST(root, deleteValue);
    cout << "Level Order Traversal after deletion:\n";
    levelOrderTraversal(root);

    return 0;
}
```

### Function-by-Function Explanation with Example Outputs

1. **Inserting Nodes into BST (`insertIntoBST` and `takeInput`):**
   Input values: `15, 10, 20, 8, 12, 16, 25, -1`

   **Output:**
   ```
   Enter values to insert into BST (end with -1): 15 10 20 8 12 16 25 -1
   ```

   The BST is constructed with the structure shown above.

2. **Level Order Traversal (`levelOrderTraversal`):**

   **Output:**
   ```
   Level Order Traversal:
   15
   10 20
   8 12 16 25
   ```

   Each level of the tree is printed on a new line.

3. **In-Order Traversal (`inOrderTraversal`):**

   **Output:**
   ```
   In-Order Traversal: 8 10 12 15 16 20 25
   ```

   This output lists the nodes in ascending order, confirming the BST property.

4. **Pre-Order Traversal (`preOrderTraversal`):**

   **Output:**
   ```
   Pre-Order Traversal: 15 10 8 12 20 16 25
   ```

   The root node is visited first, followed by the left and right subtrees.

5. **Post-Order Traversal (`postOrderTraversal`):**

   **Output:**
   ```
   Post-Order Traversal: 8 12 10 16 25 20 15
   ```

   The nodes are visited left-right-root, with the root printed last.

6. **Searching for a Value (`SearchBST`):**
   Searching for `16` in the BST.

   **Output:**
   ```
   Searching for value 16 in BST:
   Value is Present
   ```

   Since `16` exists in the tree, the function confirms its presence.

7. **Finding Minimum Value (`minValue`):**

   **Output:**
   ```
   Minimum value in BST:
   Minimum Value is : 8
   ```

   By traversing the leftmost path, `8` is found as the smallest value.

8. **Finding Maximum Value (`maxValue`):**

   **Output:**
   ```
   Maximum value in BST:
   Maximum Value is : 25
   ```

   The rightmost path yields `25` as the largest value.

9. **Finding In-Order Predecessor (`inOrderPredecessor`):**
   Assuming the target node is `10`, we find its in-order predecessor.

   **Output:**
   ```
   In-Order Predecessor of 10: 8
   ```

   In the in-order sequence, `8` is the predecessor of `10`.

10. **Finding In-Order Successor (`inOrderSuccessor`):**
    Assuming the target node is `10`, we find its in-order successor.

    **Output:**
    ```
    In-Order Successor of 10: 12
    ```

    In the in-order sequence, `12` is the successor of `10`.

11. **Deleting a Node from BST (`deleteFromBST`):**
    Deleting the node with value `10` from the BST.

    **Output:**
    ```
    Deleting value 10 from BST:
    Level Order Traversal after deletion:
    15
    12 20
    8 16 25
    ```

    After deletion, `10` is removed, and the BST structure is adjusted accordingly.

### Full Example Output

With the inputs and sequence shown above, here’s the expected full output:

```
Enter values to insert into BST (end with -1): 15 10 20 8 12 16 25 -1

Level Order Traversal:
15
10 20
8 12 16 25

In-Order Traversal: 8 10 12 15 16 20 25
Pre-Order Traversal: 15 10 8 12 20 16 25
Post-Order Traversal: 8 12 10 16 25 20 15

Searching for value 16 in BST:
Value is Present

Minimum value in BST:
Minimum Value is : 8
Maximum value in BST:
Maximum Value is : 25

In-Order Predecessor of 10: 8
In-Order Successor of 10: 12

Deleting value 10 from BST:
Level Order Traversal after deletion:
15
12 20
8 16 25
```

This example output demonstrates the basic operations of the BST. Each function manipulates or traverses the tree according to the BST rules and outputs the corresponding results.
