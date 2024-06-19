#include <iostream>
using namespace std;

int main() {
  int N;
  cout << "Enter the value of N: ";
  cin >> N;

  int row = 1;
  while (row <= N) {
    int col = 1;
    while (col <= row) {
      cout <<row+col-1<< " ";
      col++;
    }
    cout << endl;
    row++;
  }

  return 0;
}
