#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

void sorted(int potions[], int m){
  for (int i = 0; i < m-1; i++){
    for(int j = i+1; j<m; j++){

      if(potions[j] < potions[i]){
        int temp = potions[i];
        potions[i] = potions[j];
        potions[j] = temp;
      }
    }
  }
}

void successful_pairs(int potions[], int m, int spells[], int n, int success){
  sorted(potions, m);
  vector <int> answer(n, 0);
  
  for(int i = 0; i < n; i++){
    int spell = spells[i];

    for(int k = 0; k<m; k++){
      if((spell * potions[k]) >= success){
        answer[i] = m-k;
        break;
      }
    }
  }

  for(int x : answer){
    cout<<x<<" ";
  }
}


int main() {
    int potions[] = {8,5,8};
    int spells[] = {3,1,2};
    int success = 16;

    int m = sizeof(potions) / sizeof(potions[0]);
    int n = sizeof(spells) / sizeof(spells[0]);

    successful_pairs(potions, m, spells, n, success);
  return 0;
}
