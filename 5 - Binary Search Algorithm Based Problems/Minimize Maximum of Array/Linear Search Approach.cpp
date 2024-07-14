#include <iostream>
#include <vector>
using namespace std;

int minimizeArrayValue(vector<int> nums){
  long long sum = 0;
  int max_value = 0;

  for(int i = 0; i < nums.size(); i++){
    sum += nums[i];

    int average = (sum + i) / (i + 1);
    max_value = max(max_value, average);
  }

  return max_value;
}
int main() {
    vector<int> nums = {3, 7, 1, 6};
    cout<<"Minimum Max Value is : "<<minimizeArrayValue(nums);
    return 0;
}
