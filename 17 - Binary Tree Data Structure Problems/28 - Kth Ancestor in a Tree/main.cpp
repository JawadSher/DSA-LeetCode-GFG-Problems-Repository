Node* solve(Node* root, int& k, int node){
    if(root == NULL) return NULL;
    
    if(root -> data == node) return root;
    
    Node* leftAns = solve(root -> left, k, node);
    Node* rightAns = solve(root -> right, k, node);
    
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return root;
        }
        
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return root;
        }
        
        return rightAns;
    }
    
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ancestor = solve(root, k, node);
    if(ancestor == NULL || ancestor -> data == node) return -1;
    
    return ancestor->data;
}
