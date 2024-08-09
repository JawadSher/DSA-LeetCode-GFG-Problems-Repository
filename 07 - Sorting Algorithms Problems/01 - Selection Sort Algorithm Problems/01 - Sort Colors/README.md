<h1 align='center'>Sort - Colors</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/01c427de-71b2-414c-874a-a624b1ff767d)


## Problem Explanation

## Problem Solution 
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }

        }
    }
};
```

## Problem Solution Explanation
