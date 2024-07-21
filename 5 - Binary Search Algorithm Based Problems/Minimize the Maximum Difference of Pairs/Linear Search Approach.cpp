#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int min_difference(vector<int>& nums, int p){
  int n = nums.size();

  vector<int> differences;
  sort(nums.begin(), nums.end());

  for(int i = 0; i + 1 < n; i++){
    differences.push_back(nums[i + 1] - nums[i]);
  }

  sort(differences.begin(), differences.end());

  int result = INT_MAX;
  for(int i = 0; i + p - 1 < differences.size(); i++){
    result = min(result, differences[i + p - 1]);
  }
  return result;
}

int main() {
  vector<int> nums {10,1,2,7,1,3};
  int p = 2;

  int output = min_difference(nums, p);
  cout<<"Minimize the maximum difference pairs is : "<<output;
  return 0;
}
