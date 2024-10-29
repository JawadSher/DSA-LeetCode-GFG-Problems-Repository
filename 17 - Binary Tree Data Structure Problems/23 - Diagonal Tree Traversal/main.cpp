void solve(Node* root, int d, map<int, vector<int>> & diagonalMap){
    if(root == NULL) return;
    
    diagonalMap[d].push_back(root -> data);
    
    solve(root -> left, d + 1, diagonalMap);
    solve(root -> right, d, diagonalMap);
}
vector<int> diagonal(Node *root)
{
   map<int, vector<int>> diagonalMap;
   vector<int> result;
   
   solve(root, 0, diagonalMap);
   
   
   for(auto i : diagonalMap){
       result.insert(result.end(), i.second.begin(), i.second.end());
   }
   
   
   return result;
}
