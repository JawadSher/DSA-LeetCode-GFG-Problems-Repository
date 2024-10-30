class Solution{
    public:
    
    void createMapping(int in[], map<int, int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
        
    }
    
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
        if(index >= n || inOrderStart > inOrderEnd) return NULL;
        
        int element = pre[index++];
        Node* root = new Node(element);
        
        int position = nodeToIndex[element];
        
        root->left = solve(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
       int preOrderIndex = 0;
       map<int, int> nodeToIndex;
       createMapping(in, nodeToIndex, n);
       
       return solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
       
    }
};
