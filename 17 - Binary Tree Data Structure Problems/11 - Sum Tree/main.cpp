class Solution {
  private:
    pair<int, int> fastSumTree(Node* root){
        if(root == NULL) return {true, 0};
        if(root -> left == NULL && root -> right == NULL) return {true, root->data};
        
        
        pair<bool, int> leftAns = fastSumTree(root -> left);
        pair<bool, int> rightAns = fastSumTree(root -> right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        bool condition = root -> data == leftAns.second + rightAns.second;
        
        pair<int, int> ans;
        if(left && right && condition){
            ans.first = true;
            ans.second = 2 * root -> data;
        }else{
            ans.first = false;
        }
        
        
        return ans;
    }
  public:
    bool isSumTree(Node* root) {
        return fastSumTree(root).first;
    }
};
