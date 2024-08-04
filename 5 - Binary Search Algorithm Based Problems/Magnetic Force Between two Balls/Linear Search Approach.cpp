#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimum_maximum_position(vector<int>& position, int m){
  
  // sort positions
  for(int i = 0; i < position.size()-1; i++){
    for(int k = i+1; k < position.size(); k++){
      if(position[k] < position[i]){
        int temp = position[i];
        position[i] = position[k];
        position[k] = temp;
      }
    }
  }

  int n = position.size();
  int max_dist = 0;

  for(int d = 1; d <= position[n-1] - position[0]; d++){
    int balls = 1;
    int last_position = position[0];

    for(int i = 1; i < n; i++){
      if(position[i] - last_position >= d){
        balls++;
        last_position = position[i];

        if(balls == m){
          break;
        }
      }
    }
    
    if(balls >= m){
      max_dist = d;
    }
  }
 return max_dist;
}
int main() {

  vector<int> position = {1,2,3,4,7};
  int m = 3;
  // output = 3

  int minimum = minimum_maximum_position(position, m);
  cout<<"The maximum of position of minimum is : "<<minimum<<endl;
  return 0;
}
