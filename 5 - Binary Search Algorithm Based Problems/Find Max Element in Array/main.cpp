#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

bool is_max(int mid, int nums[], int n){
   for(int i = 0; i < n; i++){
       if(nums[i] > mid){
           return false;
       }
   }
   return true;
}

int max_element(int nums[], int n){
    int left = nums[0];
    int right = nums[0];
    
    for(int i = 1; i < n; i++){
        if(nums[i] < left) left = nums[i];
        if(nums[i] > right) right = nums[i];
    }
    
    while(left < right){
        int mid = left + (right - left)/2;
        
        if(is_max(mid, nums, n)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return right;
}

int main() {
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    
    int w_length = sizeof(nums) / sizeof(nums[0]);
    int max_value = max_element(nums, w_length);
    cout<<"Max Value is : "<<max_value;
    
    return 0;
}
