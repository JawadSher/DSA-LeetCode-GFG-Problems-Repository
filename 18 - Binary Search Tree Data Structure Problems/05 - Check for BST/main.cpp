class Solution {
  public:
    bool isBST(Node* root, Node* & prev){
        if(root == NULL) return true;
        
        if(!isBST(root -> left, prev)) return false;
        
        if(prev != NULL && root -> data <= prev -> data) return false;
        
        prev = root;
        
        return isBST(root -> right, prev);
        
    }
    
    bool isBST(Node* root) {
        Node* prev = NULL;
        return isBST(root, prev);
    }
};
