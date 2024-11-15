class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> ptr(k, 0);

        int minRange = INT_MAX;
        int start = -1;
        int end = -1;

        while(true){
            int mini = INT_MAX;
            int maxi = INT_MIN;
            int minRow = -1;

            for(int i = 0; i < k; i++){
                int value = nums[i][ptr[i]];

                if(value < mini){
                    mini = value;
                    minRow = i;
                }
                maxi = max(maxi, value);
            }

            if(maxi - mini < minRange){
                minRange = maxi - mini;
                start = mini;
                end = maxi;
            }

            ptr[minRow]++;
            if(ptr[minRow] == nums[minRow].size()) break;
        }

        return {start, end};
    }
};
