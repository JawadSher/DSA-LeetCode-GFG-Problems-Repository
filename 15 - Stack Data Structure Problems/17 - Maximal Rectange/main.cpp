class Solution {
private:
    vector<int> nextSmallerElementIndexes(vector<int> arr, int n){
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);

        for(int i = n-1; i >= 0; i--){
            int current = arr[i];

            while(st.top() != -1 && arr[st.top()] >= current){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    vector<int> prevSmallerElementIndexes(vector<int> arr, int n){
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);

        for(int i = 0; i < n; i++){
            int current = arr[i];

            while(st.top() != -1 && arr[st.top()] >= current){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int> heights, int n) {

        vector<int> next = nextSmallerElementIndexes(heights, n);

        vector<int> prev = prevSmallerElementIndexes(heights, n);

        int area = 0;

        for(int i = 0; i < n; i++){
            int height = heights[i];

            if(next[i] == -1) next[i] = n;

            int width = next[i] - prev[i] - 1;
            
            int newArea = height * width;
            area = max(area, newArea);
        }

        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();

        if(n == 0) return 0;

        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }

            int area = largestRectangleArea(heights, m);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }

};
