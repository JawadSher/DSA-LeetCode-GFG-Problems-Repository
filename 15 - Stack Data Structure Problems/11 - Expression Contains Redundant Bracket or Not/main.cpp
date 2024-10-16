class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '*' || ch == '+' || ch == '-' || ch == '/'){
                st.push(ch);
            }else if(ch == ')'){
                
                bool isRedundant = true;
                
                while(!st.empty() && st.top() != '('){
                    char top = st.top();
                    st.pop();
                    
                    if (top == '*' || top == '+' || top == '-' || top == '/') {
                        isRedundant = false;
                    }
                }
                
                if(!st.empty()) st.pop();
                
                if(isRedundant) return 1;
            }
        }
        
        return 0;
    }
};
