class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(n);
        
        for(int i = n-1; i >= 0; i--){
            int current = arr[i];
            
            while(st.top() >= current){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(current);
        }
        
        return ans;
    } 
};
