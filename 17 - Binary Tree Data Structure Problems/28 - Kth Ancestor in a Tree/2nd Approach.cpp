bool solve(Node* root, int k, int node, vector<int> &ans){
    if(root == NULL) return false;
    
    ans.push_back(root -> data);
    
    if(root -> data == node) return true;
    
    
    if(solve(root -> left, k, node, ans) || solve(root -> right, k, node, ans)) return true;
    
    ans.pop_back();
    
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> ans;
    if(!solve(root, k, node, ans)) return -1;
    
    int ancestorIndex = ans.size() - k - 1;
    if(ancestorIndex < 0) return -1;
    
    return ans[ancestorIndex];
}
