class Solution {
public:
   int index(vector<int>& nums, int x_mid){
    int start = 0;
    int end = nums.size();

    while(start < end){
        int mid = start + (end - start)/2;

        if(nums[mid] >= x_mid){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    return start;
   }
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int x_start = 0;
        int x_end = n;

        while(x_start <= x_end){
            int x_mid = x_start + (x_end - x_start)/2;
            int idx = index(nums, x_mid);
            int count = n - idx;
            if(x_mid > count){
                x_end = x_mid - 1;
            }else if(x_mid < count){
                x_start = x_mid + 1;
            }else{
                return x_mid;
            }
        }
    return -1;
    }
};
