class Solution {
public:
    int Counter(vector<int>& nums, int target){
        int count = 0;

        for(int num : nums){
            if(num >= target){
                count++;
            }
        }

        return count;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());

        while(start < end){
            int mid = start + (end - start + 1)/2;

            int count = Counter(nums, mid);

            if(count >= k){
                start = mid;
            }else{
                end = mid - 1;
            }
        }
    return start;
    }
};
