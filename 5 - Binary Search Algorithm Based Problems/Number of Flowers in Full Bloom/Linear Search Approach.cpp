#include <iostream>
#include <vector>
using namespace std;

void fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people){

  int m = flowers.size();
  int n = people.size();
  vector<int> result(n);

  for(int i = 0; i < n; i++){
    int person_time = people[i];

    int bloomed_flowers = 0;

    for(int j = 0; j < m; j++){

      int bloomed_time = flowers[j][0];
      int died_time = flowers[j][1];

      if(person_time >= bloomed_time && person_time <= died_time){
        bloomed_flowers++;
      }

    }

    result[i] = bloomed_flowers;
  }

  for(int i = 0; i < result.size(); i++){
    cout<<result[i]<<" ";
  }
}

int main() {
  vector<vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
  vector<int> people = {2, 3, 7, 11};


  fullBloomFlowers(flowers, people);

  return 0;
}
