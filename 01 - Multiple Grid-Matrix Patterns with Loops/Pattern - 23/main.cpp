#include <iostream>
using namespace std;

int main() {
  int N;
  cout << "Enter the value of N: ";
  cin >> N;

  int row = 1;
  while (row <= N) {
    int space = 1;
    while (space < N-row+1) {
      cout << "-" << " ";
      space++;
    }
    int col = 1;
    while (col <= row) {
      cout << col << " ";
      col++;
    }
    int col2 = 1;
    while (col2 < row) {
      cout << row-col2 << " ";
      col2++;
    }
    int space2 = 1;
    while (space2 <= N-row+1) {
      cout << "-" << " ";
      space2++;
    }

    
    cout << endl;
    row++;
  }

  return 0;
}
