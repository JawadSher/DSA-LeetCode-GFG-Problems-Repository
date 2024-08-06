#include <iostream>
using namespace std;

int main() {
  int N;
  
  cout << "Enter a value for N: ";
  cin >> N;

  int row = 1; 
  int num = 1;

  while (row <= N) {
    int col = 1;
    while (col <= N + N) {
      cout << num << " ";
      col++;
      num++;
    }
    cout << endl;
    row++;
  }
  
  return 0;
}
