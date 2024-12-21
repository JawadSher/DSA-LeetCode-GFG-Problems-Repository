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
