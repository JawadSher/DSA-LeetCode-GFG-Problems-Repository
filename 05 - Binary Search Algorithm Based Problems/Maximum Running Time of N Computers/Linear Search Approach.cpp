#include <iostream>
using namespace std;

int max_time(int battries[], int n, int c){
  int max_minutes = 0;
  int max_power = 0;

  for(int i = 0; i < n; i++){
    max_power += battries[i];
  }

  for(int t = 1; t <= max_power; t++){
    int power_needed = t * c;
    int power_available = 0;

    for(int i = 0; i < n; i++){
      power_available += min(battries[i], t);
    }

    if(power_available >= power_needed){
      max_minutes = t;
    }else{
      break;
    }

  }

  return max_minutes;
}

int main() {
  int battries[] = {1,1,1,1};
  int size = sizeof(battries) / sizeof(battries[0]);
  int computers = 2;

  int m_minutes = max_time(battries, size, computers);
  cout<<"Maximum runing time of c Computers is : "<<m_minutes;
  return 0;
}
