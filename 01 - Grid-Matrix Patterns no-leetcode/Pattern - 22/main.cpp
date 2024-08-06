#include <iostream>
using namespace std;

int main() {
  int N;
  cout << "Enter the value of N: ";
  cin >> N;

  int row = 1;
  int num = 1;
  while (row <= N) {
    int space = 1;
    while (space < N-row+1) {
      cout << "-" << " ";
      space++;
    }
    int col = 1;
    while (col <= row) {
      cout << num << " ";
      col++;
      num++;
    }
    cout << endl;
    row++;
  }

  return 0;
}

