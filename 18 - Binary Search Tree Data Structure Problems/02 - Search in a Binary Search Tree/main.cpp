class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int value) {
        if(root == NULL) return NULL;

        if(root -> val == value) return root;

        if(root -> val < value) return searchBST(root -> right, value);
        else return searchBST(root -> left, value);

        return root;
    }
};
