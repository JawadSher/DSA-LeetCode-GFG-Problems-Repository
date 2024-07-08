#include<iostream>
#include<algorithm>
using namespace std;

bool is_min(int mid, int nums[], int n){
    for(int i = 0; i < n; i++){
        if(nums[i] > mid){
            return false;
        }
    }
    return true;
}

int min_element(int nums[], int n){
   int start = nums[0];
   int end = nums[n-1];
   
   while(start < end){
       int mid = start + (end - start)/2;
       if(is_min(mid, nums, n)){
           start = mid;
       }else{
           end = mid - 1;
       }
   }
   return end;
}

int main() {
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    
    int w_length = sizeof(nums) / sizeof(nums[0]);
    int min_value = min_element(nums, w_length);
    cout << "Min Value is: " << min_value;
    
    return 0;
}
