class Solution {
public:
    int total_count(int n, int x, vector<int>& nums){
        int count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] >= x){
                count++;
            }
        }
    return count;
    }
    int specialArray(vector<int>& nums) {
       int n = nums.size();

       for(int x = 0; x <= n; x++){
        int cnt = total_count(n, x, nums);

        if(cnt == x){
            return x;
        }
    }

    return - 1;
    }
};
