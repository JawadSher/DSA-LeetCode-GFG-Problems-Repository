class Solution {
  private: 
     int height(Node* root) {
        // base case
        if(root == NULL) return 0;
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        return max(left, right) + 1;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // base case
        if(root == NULL) return 0;
        
        int opt1 = diameter(root -> left);
        int opt2 = diameter(root -> right);
        int opt3 = height(root->left) + height(root -> right) + 1;
        
        
        return max(opt1, max(opt2, opt3));
    }
};
