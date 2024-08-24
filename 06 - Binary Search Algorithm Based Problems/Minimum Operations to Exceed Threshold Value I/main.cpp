class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int index = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
        
        if(index > -1){
            return index;
        }

        return -1;
    }
};
