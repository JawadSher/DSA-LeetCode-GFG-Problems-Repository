class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    
        vector<int> result;
        if(root == NULL) return result;
        
        bool LTR = true;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);
            
            for(int i = 0; i < size; i++){
                Node* frontNode = q.front();
                q.pop();
                
                int index = LTR ? i : size - i - 1;
                ans[index] = frontNode -> data;
                
                if(frontNode -> left) q.push(frontNode -> left);
                if(frontNode -> right) q.push(frontNode -> right);
                
            }
            
            LTR = !LTR;
            
            for(auto i : ans){
                result.push_back(i);
            }
            
        }
        
        return result;
    	
    }
};
