class Solution{
private:
    void insertAtBottom(stack<int> &st, int num){
        if(st.empty()){
            st.push(num);
            return;
        }
        
        int preserveNum = st.top();
        st.pop();
        
        insertAtBottom(st, num);
        
        st.push(preserveNum);
        
    }
public:
    void Reverse(stack<int> &st){
        // base case
        if(st.empty()){
            return;
        }
        
        int preserveNum = st.top();
        st.pop();
        
        Reverse(st);
        
        insertAtBottom(st, preserveNum);
    }
};
