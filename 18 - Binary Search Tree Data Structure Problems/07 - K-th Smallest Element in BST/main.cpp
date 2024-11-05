class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        Node* current = root;
        int count = 0;
        int element = -1;
        
        while(current != NULL){
            if(current -> left == NULL){
                count++;
                if(count == k) element = current -> data;
                current = current -> right;
            }else{
                Node* predecessor = current -> left;
                while(predecessor -> right != NULL && predecessor -> right != current){
                    predecessor = predecessor -> right;
                }
                
                if(predecessor -> right == NULL){
                    predecessor -> right = current;
                    current = current -> left;
                }else{
                    predecessor -> right = NULL;
                    count++;
                    if(count == k) element = current -> data;
                    current = current -> right;
                }
            }
            if(element != -1) break;
        }
        
        
        return element;
    }
};
