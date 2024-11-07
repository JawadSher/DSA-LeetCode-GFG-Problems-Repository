class Solution {
  public:
    void inOrder(Node* root, vector<int> &bst){
        if(root == NULL) return;
        
        inOrder(root -> left, bst);
        bst.push_back(root -> data);
        inOrder(root -> right, bst);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> bst1, bst2;
        
        inOrder(root1, bst1);
        inOrder(root2, bst2);
        
        vector<int> merged;
        
        int i = 0;
        int j = 0;
        while(i < bst1.size() && j < bst2.size()){
            if(bst1[i] < bst2[j]){
                merged.push_back(bst1[i++]);
            }else{
                merged.push_back(bst2[j++]);
            }
        }
        
        while(i < bst1.size()){
            merged.push_back(bst1[i++]);
        }
        
        while(j < bst2.size()){
            merged.push_back(bst2[j++]);
        }
        
        return merged;
    }
};
