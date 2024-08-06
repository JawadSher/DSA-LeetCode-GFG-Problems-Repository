class Solution {
public:
    bool isValid(vector<int>& nums, int exp_mid, int n){
        vector<long long> arr(nums.begin(), nums.end());

        for(int i = n - 1; i > 0; i--){
            if(arr[i] > exp_mid){
                long long buffer = arr[i] - exp_mid;
                arr[i] = exp_mid;
                arr[i - 1] += buffer;
            }
        }

        return arr[0] <= exp_mid;

    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        int max_s = 0;
        int max_e = *max_element(nums.begin(), nums.end());

        int result = 0;

        while(max_s <= max_e){
            int max_mid = max_s + (max_e - max_s)/2;

            if(isValid(nums, max_mid, n)){
                result = max_mid;
                max_e = max_mid - 1;
            }else{
                max_s = max_mid + 1;
            }
        }
        
        return result;
    }
};
