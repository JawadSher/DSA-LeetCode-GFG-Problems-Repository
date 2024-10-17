class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> ans(n);

        st.push(0);

        for(int i = n-1; i >= 0; i--){
            int current = prices[i];

            while(!st.empty() && st.top() > current){
                st.pop();
            }

            ans[i] = prices[i] - st.top();
            st.push(current);
        }

        return ans;
    }
};
