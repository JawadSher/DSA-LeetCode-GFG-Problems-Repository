#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int total_profit(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
  int worker_id = 0;
  int profit_index = 0;
  int difficulty_id = 0;

  int m = difficulty.size();
  int n = profit.size();
  int t_profit = 0;

  for(int i = 0; i < worker.size(); i++){
    vector<int> profits(n);
    int worker_id = worker[i];

    for(int k = 0; k < m; k++){
      difficulty_id = difficulty[k];
      
      if(difficulty_id <= worker_id){
        profit_index = k;
        int profit_id = profit[profit_index];
        profits.push_back(profit_id);
      }
    }
    
    // Best Way to get max Element
    // t_profit += *max_element(profits.begin(), profits.end());

    int max_value = 0;
    for(int i = 0; i < profits.size(); i++){

      if(max_value < profits[i]){
        max_value = profits[i];
      }
    }
    t_profit += max_value;
  }
  
  return t_profit;
}


int main() {
  
  vector<int> difficulty = {2,4,6,8,10};
  vector<int> profit = {10,20,30,40,50};
  vector<int> worker = {4,5,6,7};

  int max_profit = total_profit(difficulty, profit, worker);
  cout<<"Maximum Profit is : "<<max_profit<<endl;
  return 0;
}
