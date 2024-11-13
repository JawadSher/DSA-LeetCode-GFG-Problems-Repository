#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node in the Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
  
    // Constructor to create a new node with given value
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to perform inorder traversal on the BST
// This collects all node values in sorted order
void inOrder(Node* root, vector<int>& nodes) {
    if (root == NULL) return; // Base case for recursion

    inOrder(root->left, nodes);      // Traverse left subtree
    nodes.push_back(root->data);     // Visit node and add its value to the vector
    inOrder(root->right, nodes);     // Traverse right subtree
}

// Function to transform the BST to a Min Heap using preorder traversal
// It assigns values from the sorted list to each node
void inOrderToMinHeap(Node* root, vector<int>& nodes, int& index) {
    if (root == NULL) return; // Base case for recursion

    // Assign the current node with the next value in sorted order
    root->data = nodes[index++];

    // Continue assigning values to left and right children
    inOrderToMinHeap(root->left, nodes, index);
    inOrderToMinHeap(root->right, nodes, index);
}

// Main function to convert BST to Min Heap
void BST_to_MinHeap(Node* root) {
    if (root == NULL) { // Check for an empty tree
        cout << "Empty Tree" << endl;
        return;
    }

    vector<int> nodes; // Vector to store nodes in sorted order

    // Step 1: Store elements of BST in sorted order
    inOrder(root, nodes);

    int index = 0;
    // Step 2: Assign values from sorted list to nodes in preorder traversal
    inOrderToMinHeap(root, nodes, index);
}

// Function to print the tree in preorder to check Min Heap property
void print(Node* root) {
    if (root == NULL) return; // Base case for recursion

    cout << root->data << " "; // Print current node
    print(root->left);         // Print left subtree
    print(root->right);        // Print right subtree
}

int main() {
    // Constructing a simple BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Convert BST to Min Heap
    BST_to_MinHeap(root);
    
    // Print the tree in preorder to verify Min Heap property
    cout << "Preorder of Min Heap : ";
    print(root);
    cout << endl;
    
    return 0;
}
