#include <iostream>
using namespace std;

int main() {
  int N;
  cout << "Enter the value of N: ";
  cin >> N;

  int row = 1;
  while (row <= N) {
    int col = 1;
    while (col <= N-row+1) {
      cout << col << " ";
      col++;
    }
    int space = 2*row-1;
    while (space > 1) {
      cout << "*" << " ";
      space--;
    }
    int col2 = N-row+1;
    while (col2 >= 1) {
      cout << col2 << " ";
      col2--;
    }
    cout << endl;
    row++;
  }

  return 0;
}
