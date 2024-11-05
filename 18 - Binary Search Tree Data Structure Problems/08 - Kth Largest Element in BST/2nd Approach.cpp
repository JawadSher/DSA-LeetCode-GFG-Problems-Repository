class Solution {
  public:
    int kthLargest(Node *root, int k) {
        Node* current = root;
        int count = 0;
        int element = -1;
        
        while(current != NULL){
            if(current -> right == NULL){
                count++;
                if(count == k) element = current -> data;
                current = current -> left;
            }else{
                Node* predecessor = current -> right;
                while(predecessor -> left != NULL && predecessor -> left != current){
                    predecessor = predecessor -> left;
                }
                
                if(predecessor -> left == NULL){
                    predecessor -> left = current;
                    current = current -> right;
                }else{
                    predecessor -> left = NULL;
                    count++;
                    if(count == k) element = current -> data;
                    current = current -> left;
                }
            }
            if(element != -1) break;
        }
        return element;
    }
};
