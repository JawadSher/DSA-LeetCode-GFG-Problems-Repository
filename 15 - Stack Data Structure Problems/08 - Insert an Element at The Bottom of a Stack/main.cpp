class Solution{
public:
    stack<int> insertAtBottom(stack<int>& st,int x){
        // base case
        if(st.empty()){
            st.push(x);
            return st;
        }
        
        int preserveNum = st.top();
        st.pop();
        
        insertAtBottom(st, x);
        
        st.push(preserveNum);
        
        return st;
    }
};
