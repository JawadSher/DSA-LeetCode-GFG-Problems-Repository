class Solution {
    // Function to find the index of the next smaller element for each element in the array
    private:
        vector<int> nextSmallerElementIndexes(vector<int> arr, int n){
            stack<int> st;  // Stack to store indices
            vector<int> ans(n);  // Vector to store the result
    
            st.push(-1);  // Push -1 as the base value for comparison
    
            for(int i = n-1; i >= 0; i--){  // Traverse the array from right to left
                int current = arr[i];  // Current element
                
                // Pop elements from the stack until a smaller element is found
                while(st.top() != -1 && arr[st.top()] >= current){
                    st.pop();
                }
    
                ans[i] = st.top();  // Store the index of the next smaller element
                st.push(i);  // Push current index to the stack
            }
    
            return ans;
        }
        
        // Function to find the index of the previous smaller element for each element in the array
        vector<int> prevSmallerElementIndexes(vector<int> arr, int n){
            stack<int> st;  // Stack to store indices
            vector<int> ans(n);  // Vector to store the result
    
            st.push(-1);  // Push -1 as the base value for comparison
    
            for(int i = 0; i < n; i++){  // Traverse the array from left to right
                int current = arr[i];  // Current element
    
                // Pop elements from the stack until a smaller element is found
                while(st.top() != -1 && arr[st.top()] >= current){
                    st.pop();
                }
    
                ans[i] = st.top();  // Store the index of the previous smaller element
                st.push(i);  // Push current index to the stack
            }
    
            return ans;
        }
        
        // Function to calculate the largest rectangular area that can be formed from the histogram
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();  // Get the number of bars in the histogram
        
            // Get the next smaller element indexes for each bar
            vector<int> next(n);
            next = nextSmallerElementIndexes(heights, n);
        
            // Get the previous smaller element indexes for each bar
            vector<int> prev(n);
            prev = prevSmallerElementIndexes(heights, n);
        
            int area = INT_MIN;  // Initialize area to the minimum possible value
        
            for(int i = 0; i < n; i++){
                int l = heights[i];  // Height of the current bar
        
                // If no next smaller element exists, set it to n (end of the histogram)
                if(next[i] == -1) next[i] = n;
        
                // Width is the distance between the previous and next smaller elements
                int b = next[i] - prev[i] - 1;
                
                // Calculate the area for the current bar and update the maximum area
                int newArea = l * b;
                area = max(area, newArea);
            }
        
            return area;  // Return the maximum area found
        }
        
    public:
        // Function to calculate the maximum area of a rectangle in a 2D matrix
        int maxArea(vector<vector<int>> &mat) {
            vector<int> height(mat[0].size(), 0);  // Initialize height array with 0s (one for each column)
            int maxi = INT_MIN;  // Variable to store the maximum area
        
            for(int i = 0; i < mat.size(); i++){  // Traverse each row of the matrix
                for(int j = 0; j < height.size(); j++){  // Traverse each column in the row
                    if(mat[i][j] == 1) height[j]++;  // If the element is 1, increment the height
                    else height[j] = 0;  // If the element is 0, reset the height
                }
                
                // Calculate the maximum area for the current row using the histogram approach
                maxi = max(maxi, largestRectangleArea(height));
            }
            
            return maxi;  // Return the maximum area found
        }
};
