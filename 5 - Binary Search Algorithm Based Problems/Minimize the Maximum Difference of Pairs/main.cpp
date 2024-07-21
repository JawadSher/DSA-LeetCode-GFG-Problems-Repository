class Solution {
public:

    bool canFormPairs(vector<int>& nums, int p, int max_diff){
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] <= max_diff){
                ++count;
                ++i;
            }
        }
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.back() - nums.front();
        int result = right;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(canFormPairs(nums, p, mid)){
                result = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
    return result;
    }
};
