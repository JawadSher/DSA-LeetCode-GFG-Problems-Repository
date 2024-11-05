class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            if(root == NULL) return NULL;
            
            while(root != NULL){
                if(root -> data < n1 && root -> data < n2){
                    root = root -> right;
                }
                
                else if(root -> data > n1 && root -> data > n2){
                    root = root -> left;
                }        
                else return root;
            }
        }
};
