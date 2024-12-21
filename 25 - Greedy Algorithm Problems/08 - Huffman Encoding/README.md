<h1 align="center">Huffman - Encoding</h1>

## Problem Statement

**Problem URL :** [Huffman Encoding](https://www.geeksforgeeks.org/problems/huffman-encoding3345/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/fa5a66db-b5ba-4ca7-8ae5-fefd1bf398c7)

### Problem Explanation
The problem at hand is to implement **Huffman encoding**, which is a lossless data compression algorithm. The goal is to generate a binary tree (called a **Huffman tree**) that represents the most efficient way to encode characters based on their frequencies. Characters that appear more frequently should have shorter codes, while those that appear less frequently should have longer codes.

### Steps Involved:

1. **Create Nodes for Each Character**: For each character, create a node with its frequency.
2. **Build a Min-Heap**: Build a **min-heap** (priority queue) where the nodes with the smallest frequencies are at the top.
3. **Build the Huffman Tree**: Combine the two nodes with the smallest frequencies into a new node, and push this new node back into the heap. Repeat this process until there is only one node left in the heap (the root of the Huffman tree).
4. **Generate Codes**: Traverse the Huffman tree, assigning binary codes ('0' for left and '1' for right) to each character.

## Problem Solution
```cpp
// Define a Node class to represent each node in the Huffman tree
class Node {
    public:
        int data;      // The frequency of the character (or combined frequencies)
        Node* right;   // Pointer to the right child node
        Node* left;    // Pointer to the left child node
        
        // Constructor to initialize a node with a given frequency
        Node(int d) {
            this -> data = d;  // Set the frequency (data) of the node
            left = NULL;        // Initialize the left child as NULL
            right = NULL;       // Initialize the right child as NULL
        }
};

// Comparator class for the priority queue to create a min-heap
class cmp {
    public:
        bool operator()(Node* a, Node* b) {
            // Return true if the frequency of 'a' is greater than 'b', 
            // which helps in maintaining a min-heap (lowest frequency at top)
            return a -> data > b -> data;
        }
};

// Solution class that contains the logic for building Huffman codes
class Solution {
    public:
        // Helper function to traverse the Huffman tree and store codes
        void traverse(Node* root, vector<string>& ans, string temp) {
            // Base case: If it's a leaf node, add the generated code to the answer
            if(root -> left == NULL && root -> right == NULL) {
                ans.push_back(temp);
                return;
            }
            
            // Recursively traverse the left subtree and append '0' to the code
            traverse(root -> left, ans, temp + "0");
            
            // Recursively traverse the right subtree and append '1' to the code
            traverse(root -> right, ans, temp + "1");    
        }
        
        // Main function to build Huffman codes
        vector<string> huffmanCodes(string S, vector<int> f, int N) {
            // Priority queue to store nodes of the Huffman tree; min-heap based on frequency
            priority_queue<Node*, vector<Node*>, cmp> pq;
            
            // Step 1: Insert all the nodes into the priority queue (based on frequency)
            for(int i = 0; i < N; i++) {
                Node* temp = new Node(f[i]);  // Create a new node with frequency f[i]
                pq.push(temp);  // Push the node into the priority queue
            }
            
            // Step 2: Build the Huffman tree by combining the two nodes with the smallest frequencies
            while(pq.size() > 1) {
                // Extract the two nodes with the smallest frequencies
                Node* left = pq.top();
                pq.pop();
                
                Node* right = pq.top();
                pq.pop();
                
                // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies
                Node* newNode = new Node(left -> data + right -> data);
                
                // Set the left and right children of the new node
                newNode -> left = left;
                newNode -> right = right;
                
                // Push the new node back into the priority queue
                pq.push(newNode);
            }
            
            // The final node in the priority queue is the root of the Huffman tree
            Node* root = pq.top();
            
            // Step 3: Traverse the Huffman tree to generate the Huffman codes
            vector<string> ans;  // This will store the final Huffman codes
            string temp = "";     // Temporary string to build the code for each character
            
            // Call the helper function to traverse the tree and build the codes
            traverse(root, ans, temp);
            
            // Return the final Huffman codes
            return ans;
        }
};

```

## Problem Solution Explanation

```cpp
// Define a Node class to represent each node in the Huffman tree
class Node {
    public:
        int data;      // The frequency of the character (or combined frequencies)
        Node* right;   // Pointer to the right child node
        Node* left;    // Pointer to the left child node
        
        // Constructor to initialize a node with a given frequency
        Node(int d) {
            this -> data = d;  // Set the frequency (data) of the node
            left = NULL;        // Initialize the left child as NULL
            right = NULL;       // Initialize the right child as NULL
        }
};
```

- **Node Class**: Each node in the tree holds a frequency (`data`), and pointers to the left and right child nodes. The constructor initializes the node's frequency and sets the left and right children to `NULL`.

```cpp
// Comparator class for the priority queue to create a min-heap
class cmp {
    public:
        bool operator()(Node* a, Node* b) {
            // Return true if the frequency of 'a' is greater than 'b', 
            // which helps in maintaining a min-heap (lowest frequency at top)
            return a -> data > b -> data;
        }
};
```

- **Comparator Class**: The `cmp` class defines a comparison function to be used in the priority queue. The function compares two nodes by their frequency (`data`). If the frequency of node `a` is greater than node `b`, the function returns `true`, ensuring that the min-heap property is maintained, with the node having the lowest frequency at the top of the priority queue.

```cpp
// Solution class that contains the logic for building Huffman codes
class Solution {
    public:
        // Helper function to traverse the Huffman tree and store codes
        void traverse(Node* root, vector<string>& ans, string temp) {
            // Base case: If it's a leaf node, add the generated code to the answer
            if(root -> left == NULL && root -> right == NULL) {
                ans.push_back(temp);
                return;
            }
            
            // Recursively traverse the left subtree and append '0' to the code
            traverse(root -> left, ans, temp + "0");
            
            // Recursively traverse the right subtree and append '1' to the code
            traverse(root -> right, ans, temp + "1");    
        }
```

- **`traverse` Function**: This function recursively traverses the Huffman tree and generates the binary codes for the characters.
  - **Base case**: When a leaf node is reached (a node without children), the current string (`temp`) representing the path from the root is added to the result (`ans`).
  - **Recursive case**: For each internal node, the function calls itself recursively on the left child (appending '0' to the path) and the right child (appending '1' to the path).

```cpp
        // Main function to build Huffman codes
        vector<string> huffmanCodes(string S, vector<int> f, int N) {
            // Priority queue to store nodes of the Huffman tree; min-heap based on frequency
            priority_queue<Node*, vector<Node*>, cmp> pq;
            
            // Step 1: Insert all the nodes into the priority queue (based on frequency)
            for(int i = 0; i < N; i++) {
                Node* temp = new Node(f[i]);  // Create a new node with frequency f[i]
                pq.push(temp);  // Push the node into the priority queue
            }
```

- **`huffmanCodes` Function**: This function is responsible for constructing the Huffman tree and generating the Huffman codes.
  - **Priority Queue**: A priority queue (min-heap) `pq` is created to store the nodes of the Huffman tree. The comparator class `cmp` ensures that the node with the smallest frequency is at the top.
  - **Step 1**: Nodes are created for each frequency in the array `f[]` and pushed into the priority queue.

```cpp
            // Step 2: Build the Huffman tree by combining the two nodes with the smallest frequencies
            while(pq.size() > 1) {
                // Extract the two nodes with the smallest frequencies
                Node* left = pq.top();
                pq.pop();
                
                Node* right = pq.top();
                pq.pop();
                
                // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies
                Node* newNode = new Node(left -> data + right -> data);
                
                // Set the left and right children of the new node
                newNode -> left = left;
                newNode -> right = right;
                
                // Push the new node back into the priority queue
                pq.push(newNode);
            }
```

- **Step 2**: **Build the Huffman Tree**
  - The two nodes with the smallest frequencies are extracted from the priority queue.
  - A new internal node is created with a frequency equal to the sum of the two smallest nodes' frequencies.
  - The two smallest nodes become the left and right children of the new internal node.
  - This new node is then pushed back into the priority queue.
  - This process continues until there is only one node left in the priority queue, which is the root of the Huffman tree.

```cpp
            // The final node in the priority queue is the root of the Huffman tree
            Node* root = pq.top();
            
            // Step 3: Traverse the Huffman tree to generate the Huffman codes
            vector<string> ans;  // This will store the final Huffman codes
            string temp = "";     // Temporary string to build the code for each character
            
            // Call the helper function to traverse the tree and build the codes
            traverse(root, ans, temp);
            
            // Return the final Huffman codes
            return ans;
        }
};
```

- **Step 3**: **Generate the Huffman Codes**
  - The root node of the Huffman tree is retrieved.
  - The `traverse` function is called to generate the binary codes by traversing the tree, starting from the root.
  - The final Huffman codes are stored in the vector `ans`, and they are returned.


### Example:

Consider the string `S = "abc"` with frequencies `f = [5, 9, 12]`.

1. **Create Nodes**:
   - Node 'a' with frequency 5.
   - Node 'b' with frequency 9.
   - Node 'c' with frequency 12.

2. **Priority Queue**:
   - Initially: `[5, 9, 12]` (ordered by frequency).
   - Extract two smallest nodes: 'a' (5) and 'b' (9).
   - Create a new internal node with frequency `5 + 9 = 14`. Push it back into the priority queue.
   - Now the queue contains: `[12, 14]`.

3. **Repeat the Process**:
   - Extract the two smallest nodes: 'c' (12) and the new internal node (14).
   - Create a new internal node with frequency `12 + 14 = 26` and push it into the priority queue.
   - The queue now contains: `[26]` (root node).

4. **Generate Huffman Codes**:
   - The final Huffman tree is built, and the codes are generated as follows:
     - 'a': `00`
     - 'b': `01`
     - 'c': `1`

### Time and Space Complexity:

**Time Complexity**:
- **Building the Priority Queue**: Pushing N nodes into a priority queue takes (O(N log N)).
- **Building the Huffman Tree**: Each iteration removes two nodes and inserts one node, which takes (O(log N)) per operation. This is done (N - 1) times, resulting in (O(N log N)) time.
- **Traversing the Tree**: The tree has N nodes, and traversal takes (O(N)).
  
  **Total Time Complexity**: (O(N log N))

**Space Complexity**:
- **Priority Queue**: The priority queue stores N nodes, so it takes (O(N)) space.
- **Huffman Tree**: The tree also contains N nodes, which take (O(N)) space.

  **Total Space Complexity**: (O(N))
