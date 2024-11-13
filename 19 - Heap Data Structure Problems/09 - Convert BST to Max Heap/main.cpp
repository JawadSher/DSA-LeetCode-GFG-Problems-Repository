#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node in the Binary Tree
class Node {
public:
    int data;      // Value of the node
    Node* left;    // Left child
    Node* right;   // Right child

    // Constructor to create a new node with a given value
    Node(int val) {
        this->data = val;
        this->left = NULL;  // Initially, left child is NULL
        this->right = NULL; // Initially, right child is NULL
    }
};

// Function to perform in-order traversal of the BST
// This will store the values of the tree nodes in an array
void inOrder(Node* root, vector<int> &nodes) {
    if (root == NULL) return;  // Base case: if node is NULL, return

    inOrder(root->left, nodes);  // Recur on the left child
    nodes.push_back(root->data); // Store the current node's data
    inOrder(root->right, nodes); // Recur on the right child
}

// Function to convert the BST to a Max Heap
// It uses the in-order traversal values stored in 'nodes' and sets the tree
// values in a way that satisfies the Max Heap property
void inOrderToMaxHeap(Node* root, vector<int>& nodes, int &index) {
    if (root == NULL) return;  // Base case: if node is NULL, return

    // Assign the current node's data from the largest remaining value
    root->data = nodes[index--];  // Decrement index after assigning to ensure we take the largest value first

    // Recur on the left and right subtrees
    inOrderToMaxHeap(root->left, nodes, index);
    inOrderToMaxHeap(root->right, nodes, index);
}

// Function to convert the entire BST to Max Heap
void BST_to_MaxHeap(Node* root) {
    if (root == NULL) return;  // Base case: if root is NULL, return

    vector<int> nodes;        // Vector to store the node values in in-order
    inOrder(root, nodes);     // Perform in-order traversal and store node values in 'nodes'

    int index = nodes.size() - 1;  // Initialize the index to the last element (largest value)
    inOrderToMaxHeap(root, nodes, index); // Assign values from largest to smallest to the tree nodes
}

// Function to print the tree in preorder (root, left, right) to check the Max Heap property
void print(Node* root) {
    if (root == NULL) return;  // Base case: if node is NULL, return

    cout << root->data << " ";  // Print the current node's data
    print(root->left);          // Recursively print the left subtree
    print(root->right);         // Recursively print the right subtree
}

int main() {
    // Constructing a simple BST
    Node* root = new Node(4);          // Root node with value 4
    root->left = new Node(2);          // Left child of root with value 2
    root->right = new Node(6);         // Right child of root with value 6
    root->left->left = new Node(1);    // Left child of node 2 with value 1
    root->left->right = new Node(3);   // Right child of node 2 with value 3
    root->right->left = new Node(5);   // Left child of node 6 with value 5
    root->right->right = new Node(7);  // Right child of node 6 with value 7

    // Convert BST to Max Heap
    BST_to_MaxHeap(root);

    // Print the tree in preorder to verify the Max Heap property
    cout << "Preorder of Max Heap: ";
    print(root);  // Print the tree's preorder traversal (should satisfy Max Heap property)
    cout << endl;

    return 0;
}
