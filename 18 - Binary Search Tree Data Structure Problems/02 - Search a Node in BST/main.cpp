bool present(Node* root, int value){
    if(root == NULL) return false;
    
    if(root -> data == value) return true;
    
    
    if(root -> data < value) return present(root -> right, value);
    else return present(root -> left, value);
    
    
    return false;
}
bool search(Node* root, int x) {
    return present(root, x);
}
