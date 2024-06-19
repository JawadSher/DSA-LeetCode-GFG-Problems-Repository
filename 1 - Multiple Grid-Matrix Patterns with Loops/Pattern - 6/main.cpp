#include <iostream>
using namespace std;

int main() {
  int N;

  cout << "Enter the value of N: ";
  cin >> N;

  int row = 1;
  int num = row;

  while (row <= N) {
    int col = 1;
    while (col <= row) {
      cout << num << " ";
      col++;
      num++;
    }
    cout << end l;
    row++;
  }

  return 0;
}
