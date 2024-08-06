#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDays(vector<int>& bloomDays, int m, int k){
  int max_days = 0;

  for(int i = 0; i < bloomDays.size(); i++){
    if(max_days < bloomDays[i]){
      max_days = bloomDays[i];
    }
  }

  for(int days = 1; days <= max_days; days++){
    int flowers_count = 0;
    int bouquets = 0;

    for(int i = 0; i < bloomDays.size(); i++){

      if(bloomDays[i] <= days){
        flowers_count++;
      }else{
        flowers_count = 0;
      }

      if(flowers_count == k){
        bouquets++;
        flowers_count = 0;
      }

    }

    if(bouquets >= m){
      return days;
    }

  }
  return -1;
}


int main() {
  vector<int> bloomDays = {1,10,3,10,2};
  int m = 3;
  int k = 1;

  int min_days = minDays(bloomDays, m, k);
  cout<<"Minimum Number of Days wait to make bouquets : "<<min_days<<endl;
  return 0;
}
