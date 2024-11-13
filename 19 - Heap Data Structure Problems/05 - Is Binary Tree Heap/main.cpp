class Solution {
  public:
    int countNodes(struct Node* root){
        if(root == NULL) return 0;
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    bool isCBT(struct Node* root, int index, int count){
        if(root == NULL) return true;
        
        if(index >= count) return false;
        
        else {
            bool left = isCBT(root -> left, 2 * index + 1, count);
            bool right = isCBT(root -> right, 2 * index + 2, count);
            
            return left && right;
        }
    }
    
    bool isMaxOrder(struct Node* root){
        if(root -> left == NULL && root -> right == NULL) return true;
        
        if(root -> right == NULL) return (root -> data > root -> left -> data);
        else {
            bool left = isMaxOrder(root -> left);
            bool right = isMaxOrder(root -> right);
            
            return (left && right && 
            (root -> data > root -> left -> data && root -> data > root -> right -> data));
        }
    }
    bool isHeap(struct Node* root) {
        int index = 0;
        int totalCount = countNodes(root);
        
        if(isCBT(root, index, totalCount) && isMaxOrder(root)) return true;
        
        return false;
    }
};
