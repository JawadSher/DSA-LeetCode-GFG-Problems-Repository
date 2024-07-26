class Solution {
public:
    typedef long long ll;

    bool isPossible(int len, const vector<int>& nums, const vector<ll>& prefix, ll k, int n) {
        int s = 0;
        int e = len-1;

        while(e < n){
            ll target_idx = s + (e - s)/2;
            ll target_num = nums[target_idx];

            ll operation_left = 0;
            ll operation_right = 0;

            if(target_idx == 0){
                operation_left = 0;
            }else{
                operation_left = ((target_idx - s) * target_num) - (prefix[target_idx - 1] - (s > 0 ? prefix[s - 1] : 0));
            }

            operation_right = (prefix[e] - prefix[target_idx]) - ((e - target_idx) * target_num);

            if(operation_right + operation_left <= k){
                return true;
            }
            s++;
            e++;
        }
        return false;    
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<ll> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int min_score = 1;
        int max_score = n;
        int result = 0;

        while(min_score <= max_score){
            int win_size = min_score + (max_score - min_score) / 2;
            if(isPossible(win_size, nums, prefix, k, n)){
                result = win_size;
                min_score = win_size + 1;
            }else{
                max_score = win_size - 1;
            }
        }

        return result;
    }
};
