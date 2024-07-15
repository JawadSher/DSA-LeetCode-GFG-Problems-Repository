#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int min_cost(vector<int>& nums, vector<int>& cost){
  long long answer = LLONG_MAX;
  int n = nums.size();

  for(int i = 0; i < n; i++){
    int num = nums[i];
    long long t_cost = 0;
    for(int j = 0; j < nums.size(); j++){
      t_cost += (long long) abs((nums[j] - num) * cost[j]);
    }
    if(t_cost < answer){
      answer = t_cost;
    }
  }
  return (answer == INT_MAX) ? 0 : answer;
}

int main() {
  vector<int> nums = {1,3,5,2};
  vector<int> cost = {2,3,1,14};

  long long answer = min_cost(nums, cost);
  cout<<"Minimum Cost to Make Array Equal is : "<<answer;

  return 0;
}
