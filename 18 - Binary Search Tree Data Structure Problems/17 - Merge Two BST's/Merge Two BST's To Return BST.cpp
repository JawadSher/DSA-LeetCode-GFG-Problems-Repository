class Solution {
  public:
    // Helper function to perform in-order traversal and store the result in 'bst'
    void inOrder(Node* root, vector<int> &bst){
        // Base case: If the current node is NULL, return
        if(root == NULL) return;
        
        // Traverse the left subtree
        inOrder(root -> left, bst);
        
        // Store the current node's data in 'bst'
        bst.push_back(root -> data);
        
        // Traverse the right subtree
        inOrder(root -> right, bst);
    }
    
    // Helper function to convert a sorted array into a balanced BST
    Node* inorderToBST(int start, int end, vector<int> &merged){
        // Base case: If the start index is greater than the end, return NULL (no subtree)
        if(start > end) return NULL;
        
        // Calculate the middle element to maintain balance in the BST
        int mid = start + (end - start) / 2;
        
        // Create a new node with the middle element
        Node* root = new Node(merged[mid]);
        
        // Recursively build the left subtree using the left half of the array
        root -> left = inorderToBST(start, mid - 1, merged);
        
        // Recursively build the right subtree using the right half of the array
        root -> right = inorderToBST(mid + 1, end, merged);
        
        // Return the root of the constructed subtree
        return root;
    }
    
    // Main function to merge two BSTs into a single balanced BST
    Node* merge(Node *root1, Node *root2) {
        vector<int> bst1, bst2;
        
        // Perform in-order traversal of both trees and store the results in 'bst1' and 'bst2'
        inOrder(root1, bst1);
        inOrder(root2, bst2);
        
        // Merge the two sorted arrays into a single sorted array 'merged'
        vector<int> merged;
        
        int i = 0, j = 0;
        
        // Merge the two sorted arrays while there are elements in both
        while(i < bst1.size() && j < bst2.size()){
            // Compare the current elements from both arrays and add the smaller one to 'merged'
            if(bst1[i] < bst2[j]){
                merged.push_back(bst1[i++]); // Increment i after adding the element
            }else{
                merged.push_back(bst2[j++]); // Increment j after adding the element
            }
        }
        
        // If there are remaining elements in bst1, add them to 'merged'
        while(i < bst1.size()){
            merged.push_back(bst1[i++]);
        }
        
        // If there are remaining elements in bst2, add them to 'merged'
        while(j < bst2.size()){
            merged.push_back(bst2[j++]);
        }
        
        // Convert the sorted array 'merged' into a balanced BST and return the root
        return inorderToBST(0, merged.size()-1, merged);
    }
};
