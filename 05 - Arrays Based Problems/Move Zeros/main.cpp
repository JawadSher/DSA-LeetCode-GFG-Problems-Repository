class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastnonZeroIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[lastnonZeroIndex++] = nums[i];
            }
        }

        for(int i = lastnonZeroIndex; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};
