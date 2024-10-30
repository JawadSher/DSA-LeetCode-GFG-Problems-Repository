class Solution {
  public:
    void createMapping(vector<int> &in, map<int, int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
        
    }
    
    Node* solve(vector<int>&in , vector<int> postorder, int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
        if(index < 0 || inOrderStart > inOrderEnd) return NULL;
        
        int element = postorder[index--];
        Node* root = new Node(element);
        
        int position = nodeToIndex[element];
        
        root->right = solve(in, postorder, index, position + 1, inOrderEnd, n, nodeToIndex);
        root->left = solve(in, postorder, index, inOrderStart, position - 1, n, nodeToIndex);
        
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> &postorder) {
        int n = postorder.size();
        
        int postOrderIndex = n-1;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
       
        return solve(inorder, postorder, postOrderIndex, 0, n-1, n, nodeToIndex);
    }
};
