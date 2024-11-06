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
    void inOrder(TreeNode* root, vector<int> &inOrderVal){
        if(root == NULL) return;

        inOrder(root -> left, inOrderVal);
        inOrderVal.push_back(root -> val);
        inOrder(root -> right, inOrderVal);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrderVal;   
        
        inOrder(root, inOrderVal);

        int i = 0;
        int j = inOrderVal.size() -1;

        while(i < j){
            int sum = inOrderVal[i] + inOrderVal[j];

            if(sum == k) return true;
            else if(sum > k) j--;
            else i++;
        } 

        return false;
    }
};
