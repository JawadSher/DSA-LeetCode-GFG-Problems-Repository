#include <iostream>
using namespace std;

void waveIteration(int array_2d[][5], int row, int col){
  for(int j = 0; j < col; j++){
    if(j&1){
      for(int i = row-1; i>=0; i--){
        cout<<array_2d[i][j] << " ";
      }
      cout<<endl;
    }else{
      for(int i = 0; i<=row-1; i++){
        cout<<array_2d[i][j]<< " ";
      }
      cout<<endl;
    }
  }
}

int main() {
  int array_2d[3][5] = {{1, 2, 3, 4, 5}, 
                  {11, 12, 13, 14, 15}, 
                  {21, 22, 23, 24, 25}};

  waveIteration(array_2d, 3, 5);
  return 0;
}
