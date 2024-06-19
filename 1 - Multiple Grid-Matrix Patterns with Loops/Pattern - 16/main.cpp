#include <iostream>
using namespace std;

int main() {
  int N;

  cout << "Enter the number of rows: ";
  cin >> N;
  
  int row = 1;
  while (row <= N) {
    int space = 1;
    while (space <= N-row+1) {
      cout << "_"<<" ";
      space++;
    }

    int col = 1;
    while(col <= row){
      cout<<"*"<<" ";
      col = col + 1;
    }
    cout << endl;
    row++;
  }

  return 0;
}
