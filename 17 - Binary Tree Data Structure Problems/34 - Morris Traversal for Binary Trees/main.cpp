#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void morrisInorderTraversal(TreeNode* root) {
    TreeNode* current = root;
    
    while (current != nullptr) {
        if (current->left == nullptr) {
            // If no left child, visit current and move to the right
            cout << current->val << " ";
            current = current->right;
        } else {
            // Find the in-order predecessor of current
            TreeNode* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            
            if (predecessor->right == nullptr) {
                // Establish temporary link from predecessor's right to current
                predecessor->right = current;
                current = current->left;
            } else {
                // Remove temporary link and visit current
                predecessor->right = nullptr;
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
}

int main() {
    // Example tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Morris In-order Traversal: ";
    morrisInorderTraversal(root);  // Expected Output: 4 2 5 1 3
    return 0;
}
