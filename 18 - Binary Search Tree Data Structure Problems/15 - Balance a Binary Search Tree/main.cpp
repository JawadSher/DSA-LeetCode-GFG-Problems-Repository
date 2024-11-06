/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root, vector<TreeNode*> &inOrderValues){
        if(root == NULL) return;

        inOrder(root -> left, inOrderValues);
        inOrderValues.push_back(root);
        inOrder(root -> right, inOrderValues);
    }

    TreeNode* inorderToBST(int start, int end, vector<TreeNode*> &inOrderValues){
        if(start > end) return NULL;

        int mid = start + (end - start) / 2;

        TreeNode* root = inOrderValues[mid];

        root -> left = inorderToBST(start, mid-1, inOrderValues);
        root -> right = inorderToBST(mid + 1, end, inOrderValues);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inOrderValues;
        inOrder(root, inOrderValues);

        return inorderToBST(0, inOrderValues.size()-1, inOrderValues);
    }
};
