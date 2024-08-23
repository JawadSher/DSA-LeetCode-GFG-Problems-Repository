#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertion_sort(vector<int>& nums){
  for(int i = 1; i < nums.size(); i++){
    int key = nums[i];
    
    int j = i-1;
    for(; j >= 0; j--){
      if(nums[j] > key){
        nums[j+1] = nums[j];
      }else{
        break;
      }
    }
    nums[j+1] = key;
  }
}

int main() {
  vector<int> nums = {10, 2, 3, 8, 5, 1, 4, 7, 9, 6};
  insertion_sort(nums);

  for(int i : nums){
    cout<<i<<" ";
  }
  return 0;
}
