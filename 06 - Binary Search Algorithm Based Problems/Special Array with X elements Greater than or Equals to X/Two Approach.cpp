class Solution {
public:
    int binary_search(vector<int>& nums, int x){
        int start = 0;
        int end = nums.size() - 1;

        int mid = start + (end - start)/2;
        while(start <= end){
            if(nums[mid] >= x){
                end = mid - 1;
            }else{
                start = mid +1;
            }
        }
        
        return start;
    }
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int x = 0; x <= n; x++){
            int idx = binary_search(nums, x);
            int count = n - idx;
            if(count == x){
                return x;
            }
        }
    return -1;
    }
};
