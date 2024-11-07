#include <iostream>
using namespace std;

class Node {
public:
    int data;           // Data value of the node
    Node* left;         // Pointer to the left child
    Node* right;        // Pointer to the right child

    // Constructor to initialize a node with given value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node into a Binary Search Tree (BST)
Node* insertBST(Node* root, int val) {
    if (root == nullptr) // If the tree/subtree is empty, create a new node
        return new Node(val);
    if (val < root->data) // If value is less, insert in the left subtree
        root->left = insertBST(root->left, val);
    else                  // Otherwise, insert in the right subtree
        root->right = insertBST(root->right, val);
    return root;
}

// Convert a BST to a sorted doubly linked list
void convertIntoSortedDLL(Node* root, Node* &head) {
    if (root == nullptr) return;  // Base case for recursion

    convertIntoSortedDLL(root->right, head); // Process the right subtree first

    root->right = head;  // Link current node's right to head of sorted DLL
    if (head != nullptr) head->left = root; // Set head's left to current node

    head = root;          // Update head to current node

    convertIntoSortedDLL(root->left, head); // Process the left subtree
}

// Merge two sorted doubly linked lists into a single sorted list
Node* mergeLinkedList(Node* head1, Node* head2) {
    Node* head = nullptr; // Head of the merged list
    Node* tail = nullptr; // Tail of the merged list

    // Merge nodes from both lists until one list is exhausted
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) { // Add node from head1 if it has smaller data
            if (head == nullptr) {       // First node in merged list
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {                     // Subsequent nodes
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {                         // Add node from head2 otherwise
            if (head == nullptr) {       // First node in merged list
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {                     // Subsequent nodes
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    // Append remaining nodes of head1
    while (head1 != nullptr) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    // Append remaining nodes of head2
    while (head2 != nullptr) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head; // Return the head of merged list
}

// Count the number of nodes in a doubly linked list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) { // Traverse the list to count nodes
        count++;
        temp = temp->right;
    }
    return count;
}

// Convert sorted doubly linked list to a balanced BST
Node* sortedLLToBST(Node* &head, int n) {
    if (n <= 0 || head == nullptr) return nullptr; // Base case for recursion

    Node* left = sortedLLToBST(head, n / 2); // Recursively create left subtree

    Node* root = head;       // Current node becomes root
    root->left = left;       // Connect left subtree

    head = head->right;      // Move head to the next node

    root->right = sortedLLToBST(head, n - n / 2 - 1); // Recursively create right subtree

    return root;
}

// Print the BST in in-order traversal (for verification)
void printInOrder(Node* root) {
    if (root == nullptr) return;

    printInOrder(root->left);   // Visit left subtree
    cout << root->data << " ";  // Print root node
    printInOrder(root->right);  // Visit right subtree
}

int main() {
    // Create first BST
    Node* root1 = nullptr;
    root1 = insertBST(root1, 3);
    root1 = insertBST(root1, 1);
    root1 = insertBST(root1, 5);

    // Create second BST
    Node* root2 = nullptr;
    root2 = insertBST(root2, 4);
    root2 = insertBST(root2, 2);
    root2 = insertBST(root2, 6);
    
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Convert BSTs to sorted doubly linked lists
    convertIntoSortedDLL(root1, head1);
    head1->left = nullptr;  // Set left of the head to null

    convertIntoSortedDLL(root2, head2);
    head2->left = nullptr;  // Set left of the head to null

    // Merge the two sorted doubly linked lists
    Node* mergedHead = mergeLinkedList(head1, head2);

    // Convert merged sorted linked list back to a balanced BST
    Node* mergedBST = sortedLLToBST(mergedHead, countNodes(mergedHead));

    // Print the in-order traversal of the merged BST
    cout << "In-order traversal of merged BST: ";
    printInOrder(mergedBST);
    cout << endl;

    return 0;
}
