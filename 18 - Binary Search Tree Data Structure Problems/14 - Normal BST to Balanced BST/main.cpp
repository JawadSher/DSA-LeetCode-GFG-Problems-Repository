class Solution{
    
    public:
    void inOrder(Node* root, vector<Node*> &in_nodes){
        if(root == NULL) return;
        
        inOrder(root -> left, in_nodes);
        in_nodes.push_back(root);
        inOrder(root -> right, in_nodes);
    }
    
    Node* inOrderToBST(int start, int end, vector<Node*> &in_nodes){
        if(start > end) return NULL;
        
        int mid = start + (end - start) / 2;
        Node* root = in_nodes[mid];
        
        root -> left = inOrderToBST(start, mid-1, in_nodes);
        root -> right = inOrderToBST(mid+1, end, in_nodes);
        
        return root;
    }
    
    
    
    Node* buildBalancedTree(Node* root)
    {
    	vector<Node*> in_nodes;
    	inOrder(root, in_nodes);
    	return inOrderToBST(0, in_nodes.size()-1, in_nodes);
    }
};
