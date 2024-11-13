class Solution{
  public:
    void inOrder(Node* root, vector<int> &nodes){
        if(root == NULL) return;
        
        inOrder(root -> left, nodes);
        nodes.push_back(root -> data);
        inOrder(root -> right, nodes);
    }
    
    void inOrderToHeap(Node* root, vector<int> &nodes, int & index){
        if(root == NULL) return;
        
        inOrderToHeap(root -> left, nodes, index);
        inOrderToHeap(root -> right, nodes, index);
        
        root -> data = nodes[index++];
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> nodes;
        inOrder(root, nodes);
        
        int index = 0;
        inOrderToHeap(root, nodes, index);
    }    
};
