#include <iostream>
using namespace std;

int main() {
  int N;
  cout << "Enter the value of N: ";
  cin >> N;

  int row = 1;
  char ch = 'A';
  while (row <= N) {
    int col = 1;
    while (col <= row) {
      cout<< ch <<" ";
      col++;
      ch++;
    }
    cout << endl;
    row++;
  }

  return 0;
}
