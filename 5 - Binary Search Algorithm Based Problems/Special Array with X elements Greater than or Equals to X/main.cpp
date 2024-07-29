class Solution {
public:
   
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> frequency(n+1);

        for(int i = 0; i < n; i++){
            frequency[min(n, nums[i])]++;
        }

        int cum_sum = 0;

        for(int x = n; x >= 0; x--){
            cum_sum += frequency[x];

            if(cum_sum == x){
                return cum_sum;
            }
        }
    return -1;
    }
};
