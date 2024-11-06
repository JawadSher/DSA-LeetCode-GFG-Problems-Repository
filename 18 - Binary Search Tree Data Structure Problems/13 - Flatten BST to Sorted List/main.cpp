class Solution
{
public:
    void inOrder(Node* root, vector<Node*> &nodes){
        if(root == NULL) return;
        
        inOrder(root -> left, nodes);
        nodes.push_back(root);
        inOrder(root -> right, nodes);
    }
    Node *flattenBST(Node *root)
    {
        if(root == NULL) return NULL;
        
        vector<Node*> nodes;
        inOrder(root, nodes);
        
        Node* newRoot = nodes[0];
        Node* current = newRoot;
        
        for(int i = 1; i < nodes.size(); i++){
            current -> left = NULL;
            current -> right = nodes[i];
            current = nodes[i];
        }
        
        current -> left = NULL;
        current -> right = NULL;
        
        return newRoot;
    }
};
