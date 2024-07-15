#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minimum_speed(vector<int>& dist, double hour){
  int n = dist.size();
  int speed = 1;

  while(true){
    double time = 0.0;

    for(int i = 0; i < n-1; i++){
      time += ceil(1.0 * dist[i]/speed); 
    }

    time += 1.0 * dist[n-1]/speed;

    if(time <= hour){
      return speed;
    }
    
    speed++;
    if (speed > 1e7) break;
  }

  return -1;
}

int main() {
    vector<int> dist = {1,3,2};
    double hour = 6;

    int min_speed = minimum_speed(dist, hour);
    cout<<"Minimum Speed to reach Office is : "<<min_speed;
    return 0;
}
