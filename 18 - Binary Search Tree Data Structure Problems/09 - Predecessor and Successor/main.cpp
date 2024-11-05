class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {   
        pre = NULL;
        suc = NULL;
        
        // find key
        Node* temp = root;
        while(temp != NULL){
            if(temp -> key == key) break;
            
            if(temp -> key > key){
                suc = temp;
                temp = temp -> left;
            }else{
                pre = temp;
                temp = temp -> right;
            }
        }
        
        if(temp == NULL) return;
        
        Node* leftTree = temp -> left;
        while(leftTree != NULL){
            pre = leftTree;
            leftTree = leftTree -> right;
        }
        
        Node* rightTree = temp -> right;
        while(rightTree != NULL){
            suc = rightTree;
            rightTree = rightTree -> left;
        }
        
    }
};
