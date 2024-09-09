#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<vector<int>> temp(cols, vector<int>(rows));
    
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        temp[j][rows - i - 1] = matrix[i][j];
      }
    }
    
    for (const auto& row : temp) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
