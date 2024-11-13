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
    int totalCount(TreeNode* root){
        if(root == NULL) return 0;

        return 1 + totalCount(root -> left) + totalCount(root -> right);
    }
    int isCBT(TreeNode* root, int index, int count){
        if(root == NULL) return true;
        if(index >= count) return false;

        bool left = isCBT(root -> left, 2 * index + 1, count);
        bool right = isCBT(root -> right, 2 * index + 2, count);

        return left && right;
    }
    bool isCompleteTree(TreeNode* root) {
        int index = 0;
        int count = totalCount(root);
        return isCBT(root, index, count);
    }
};
