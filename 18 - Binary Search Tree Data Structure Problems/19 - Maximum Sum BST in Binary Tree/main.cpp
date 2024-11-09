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

class nodeInfo{
    public:
        int mini;
        int maxi;
        bool isBST;
        int size;
        int sum;
};
class Solution {
public:
    nodeInfo getLargestBSTSize(TreeNode* root, int &ans){
        if(root == NULL) return nodeInfo{INT_MAX, INT_MIN, true, 0, 0};

        nodeInfo left = getLargestBSTSize(root -> left, ans);
        nodeInfo right = getLargestBSTSize(root -> right, ans);

        nodeInfo currentNode;
        currentNode.size = left.size + right.size + 1;
        currentNode.sum = left.sum + right.sum + root -> val;
        currentNode.mini = min(root -> val, left.mini);
        currentNode.maxi = max(root -> val, right.maxi);

        if(left.isBST && right.isBST && (root -> val > left.maxi && root -> val < right.mini)){
            currentNode.isBST = true;
            ans = max(ans, currentNode.sum);
        }else{
            currentNode.isBST = false;
        }
        
        return currentNode;
    }

    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        getLargestBSTSize(root, max_sum);
        return max_sum;
    }
};
