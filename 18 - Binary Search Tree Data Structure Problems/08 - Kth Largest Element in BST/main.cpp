class Solution {
  public:
     int solve(Node* root, int &i, int k){
        if(root == NULL) return -1;

        int right = solve(root -> right, i, k);
        if(right != -1) return right;

        i++;
        if(i == k) return root -> data;

        return solve(root -> left, i, k);
    }
    
    int kthLargest(Node *root, int k) {
        int i = 0;
        int ans = solve(root, i, k);

        return ans;
    }
};
