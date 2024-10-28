class Solution{
    public:
    int heights(Node* root){
        if(root == NULL) return 0;
        
        int left = heights(root -> left);
        if(left == -1) return -1;
        
        int right = heights(root -> right);
        if(right == -1) return -1;
        
        if(abs(left - right) > 1) return -1;
        
        return max(left, right) + 1;
    }
    bool isBalanced(Node *root)
    {
        return heights(root) != -1;

    }
};
