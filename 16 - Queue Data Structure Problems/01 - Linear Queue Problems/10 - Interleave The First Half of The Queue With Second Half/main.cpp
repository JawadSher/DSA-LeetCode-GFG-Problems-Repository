class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        stack<int> st;
        vector<int> v;
        
        int n = q.size() / 2;
        
        for(int i = 0; i < n; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
            
        }
        
        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();
        }
        
        for(int i = 0; i < n; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
        
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        
        return v;
    }
};
