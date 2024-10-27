<h1 align='center'>Binary - Tree - Example</h1>

## What is a Binary Tree?

A **binary tree** is a tree data structure in which each node has at most two children, referred to as the left child and the right child. The topmost node is called the **root**, and nodes with no children are called **leaf nodes**. 

#### Properties of Binary Trees:
- Each node contains a data field and pointers to its left and right child nodes.
- The depth of a node is the number of edges from the root to that node.
- The height of a binary tree is the maximum depth of any node in the tree.

### Example of a Binary Tree

Consider the following binary tree:

```
        10
       /  \
      5   15
     / \    \
    3   7   20
```

- **Root**: 10
- **Leaf Nodes**: 3, 7, 20
- **Height**: 2 (the longest path from root to leaf)

## Source Code
```cpp
#include <iostream>
using namespace std;
#include <queue>
#include <stack>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    
    if(data == -1) return NULL;
    
    cout << "Enter data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);
    
    cout << "Enter data for inserting in the right of "<< data << endl;
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Separator
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            // previous level completed
            cout << endl;
            if(!q.empty()){
                // Queue has still some child nodes
                q.push(NULL);
            }
        }else{
            cout << temp -> data << " ";
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
}

void reverseLevelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    stack<Node*> st;

    // Push the root to the queue and a NULL to mark the end of the level
    q.push(root);
    q.push(NULL); // NULL acts as a level separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of current level
            st.push(NULL); // Push NULL to the stack to mark level boundary

            if (!q.empty()) {
                q.push(NULL); // Add separator for the next level
            }
        } else {
            // Push the node data into the stack
            st.push(temp);

            // Enqueue right child first, then left child to maintain reverse level order
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
    }

    // Print nodes from the stack in reverse level order with levels separated
    while (!st.empty()) {
        Node* node = st.top();
        st.pop();

        if (node == NULL) {
            cout << endl; // Newline after each level
        } else {
            cout << node->data << " ";
        }
    }
    cout << endl;
}

void inOrderTraversal(Node* root){
    if(root == NULL) return;
    
    inOrderTraversal(root->left);
    cout<< root -> data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if(root == NULL) return;
    
    cout<< root -> data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root -> data << " ";
}

void buildFromLevelOrder(Node* &root){
    queue<Node *> q;
    cout << "Enter data for root " << endl;
    int data;
    cin >> data ;
    root = new Node(data);
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        cout << "Enter left Node for : " << temp -> data <<endl;
        int leftData;
        cin>> leftData;
        
        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }
        
        cout << "Enter right Node for : " << temp -> data <<endl;
        int rightData;
        cin>> rightData;
        
        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL;
    
    // Creating buildTree
    root = buildTree(root);
    
    // // data : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    // // level order Traversal
    // cout << "Printing the level order traversal output " <<endl;
    // levelOrderTraversal(root);
    
    // Reverse Level Order Traversal
    cout << "Printing the reverse order traversal output " << endl;
    reverseLevelOrderTraversal(root);
    
    // cout << "Inorder Taversal is : ";
    // inOrderTraversal(root);
    
    // cout << endl;
    
    // cout << "Preorder Traversal is : ";
    // preOrderTraversal(root);
    
    // cout << endl;
    
    // cout << "Postorder Traversal is : ";
    // postOrderTraversal(root);
    
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // Create from level order
    // buildFromLevelOrder(root);
    
    // // // level order
    // cout << "Printing the level order traversal output " <<endl;
    // levelOrderTraversal(root);

    return 0;
}
```


## Source Code Explanation

```cpp
#include <iostream>
using namespace std;
#include <queue>
#include <stack>
```
Here, we include the necessary headers for input-output and data structures like queues and stacks.

#### Node Class

```cpp
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
```

- **Purpose**: Defines a node of the binary tree.
- **Attributes**:
  - `data`: Stores the integer value.
  - `left`: Pointer to the left child.
  - `right`: Pointer to the right child.
- **Constructor**: Initializes the node with a given value and sets the left and right pointers to `NULL`.

#### 1. **buildTree Function**

```cpp
Node* buildTree(Node* root){
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    
    if(data == -1) return NULL;
    
    cout << "Enter data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);
    
    cout << "Enter data for inserting in the right of "<< data << endl;
    root->right = buildTree(root->right);
    
    return root;
}
```

- **Purpose**: Recursively builds a binary tree from user input.
- **How It Works**:
  1. Prompts the user to enter data for the current node.
  2. If the input is `-1`, it returns `NULL`, indicating no child.
  3. Recursively calls itself to build the left and right subtrees.
  
- **Example Usage**:
  - If the input sequence is: `1 2 -1 -1 3 -1 -1`, the tree will look like:
  
```
    1
   /
  2
   \
    3
```

#### 2. **levelOrderTraversal Function**

```cpp
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Separator
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            // previous level completed
            cout << endl;
            if(!q.empty()){
                // Queue has still some child nodes
                q.push(NULL);
            }
        }else{
            cout << temp -> data << " ";
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
}
```

- **Purpose**: Performs level-order traversal (breadth-first) of the binary tree.
- **How It Works**:
  1. Uses a queue to traverse nodes level by level.
  2. Adds a `NULL` marker to indicate the end of each level.
  3. Prints nodes from left to right for each level.

- **Example**:
  For the tree:
```
        10
       /  \
      5   15
```
- **Output**:
```
10
5 15
```

#### 3. **reverseLevelOrderTraversal Function**

```cpp
void reverseLevelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    stack<Node*> st;

    q.push(root);
    q.push(NULL); // NULL acts as a level separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            st.push(NULL); // Push NULL to the stack to mark level boundary

            if (!q.empty()) {
                q.push(NULL); // Add separator for the next level
            }
        } else {
            st.push(temp);

            // Enqueue right child first, then left child to maintain reverse level order
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
    }

    // Print nodes from the stack in reverse level order with levels separated
    while (!st.empty()) {
        Node* node = st.top();
        st.pop();

        if (node == NULL) {
            cout << endl; // Newline after each level
        } else {
            cout << node->data << " ";
        }
    }
    cout << endl;
}
```

- **Purpose**: Performs reverse level-order traversal of the binary tree.
- **How It Works**:
  1. Uses a queue to explore the tree while storing nodes in a stack.
  2. Nodes are added to the stack in normal order but are printed in reverse order.
  3. Levels are separated by `NULL` markers.

- **Example**:
  For the same tree:
```
        10
       /  \
      5   15
```
- **Output**:
```
5 15
10
```

#### 4. **inOrderTraversal Function**

```cpp
void inOrderTraversal(Node* root){
    if(root == NULL) return;
    
    inOrderTraversal(root->left);
    cout << root -> data << " ";
    inOrderTraversal(root->right);
}
```

- **Purpose**: Performs in-order traversal of the binary tree (left, root, right).
- **How It Works**:
  1. Recursively visits the left subtree.
  2. Prints the current node's data.
  3. Recursively visits the right subtree.

- **Example**:
  For the tree:
```
        10
       /  \
      5   15
```
- **Output**:
```
5 10 15
```

#### 5. **preOrderTraversal Function**

```cpp
void preOrderTraversal(Node* root){
    if(root == NULL) return;
    
    cout << root -> data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
```

- **Purpose**: Performs pre-order traversal of the binary tree (root, left, right).
- **How It Works**:
  1. Prints the current node's data.
  2. Recursively visits the left subtree.
  3. Recursively visits the right subtree.

- **Example**:
  For the tree:
```
        10
       /  \
      5   15
```
- **Output**:
```
10 5 15
```

#### 6. **postOrderTraversal Function**

```cpp
void postOrderTraversal(Node* root){
    if(root == NULL) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root -> data << " ";
}
```

- **Purpose**: Performs post-order traversal of the binary tree (left, right, root).
- **How It Works**:
  1. Recursively visits the left subtree.
  2. Recursively visits the right subtree.
  3. Prints the current node's data.

- **Example**:
  For the tree:
```
        10
       /  \
      5   15
```
- **Output**:
```
5 15 10
```

#### 7. **buildFromLevelOrder Function**

```cpp
void buildFromLevelOrder(Node* &root){
    queue<Node *> q;
    cout << "Enter data for root " << endl;
    int data;
    cin >> data ;
    root = new Node(data);
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        cout << "Enter left Node for : " << temp -> data <<endl;
        int leftData;
        cin >> leftData;
        
        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }
        
        cout << "Enter right Node for : " << root -> data <<endl;
        int rightData;
        cin >> rightData;
        
        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
```

- **Purpose**: Builds a binary tree from level-order input.
- **How It Works**:
  1. Prompts the user for the root data

.
  2. Uses a queue to keep track of nodes for which children are being added.
  3. Iteratively prompts for left and right children data until the queue is empty.

- **Example Usage**:
  If the input sequence is `1 2 3 -1 -1 4 -1 -1`, the tree will look like:
```
    1
   / \
  2   3
       \
        4
```

### Main Function

```cpp
int main() {
    Node* root = NULL;
    buildTree(root);
    
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    
    cout << "Reverse Level Order Traversal: " << endl;
    reverseLevelOrderTraversal(root);
    
    cout << "In Order Traversal: " << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre Order Traversal: " << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << "Post Order Traversal: " << endl;
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
```

- **Purpose**: The entry point of the program.
- **How It Works**:
  1. Initializes the root of the tree.
  2. Calls the `buildTree` function to construct the tree from user input.
  3. Calls the various traversal functions to display the tree in different orders.

### Conclusion

The provided code effectively builds a binary tree from user input and demonstrates various tree traversal techniques. Each function is designed for specific operations, showcasing the versatility of binary trees in handling hierarchical data structures. 

If you have any further questions or need clarifications on any part of the code, feel free to ask!
