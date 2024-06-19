#include <iostream>
using namespace std;

int main() {
  int N;
  cout << "Enter the value of N: ";
  cin >> N;

  int row = 1;
  while (row <= N) {
    int space = 1;
    while (space < row) {
      cout << "-" << " ";
      space++;
    }
    int col = 1;
    int num = row;
    while (col <= N-row+1) {
      cout << num << " ";
      col++;
      num++;
    }
    cout << endl;
    row++;
  }

  return 0;
}
