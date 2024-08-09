class Solution {
public:
    vector<vector<int>> imageMatrix;
    int total_rows, total_cols;

    // Calculates the sum of values in the 3x3 grid centered at (row, col)
    int calculate3X3sum(int row, int col) {
        int total_sum = 0;

        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                if (i >= 0 && i < total_rows && j >= 0 && j < total_cols) {
                    total_sum += imageMatrix[i][j];
                }
            }
        }

        return total_sum;
    }

    // Calculates the average value for border cells, considering valid neighbors
    int calculateBorderAvg(int row, int col) {
        int sum = 0;
        int count = 0;

        for (int i = max(row - 1, 0); i <= min(row + 1, total_rows - 1); ++i) {
            for (int j = max(col - 1, 0); j <= min(col + 1, total_cols - 1); ++j) {
                sum += imageMatrix[i][j];
                count++;
            }
        }

        return sum / count;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        imageMatrix = img;
        total_rows = img.size();
        total_cols = img[0].size();

        vector<vector<int>> smoothedImage(total_rows, vector<int>(total_cols));

        for (int row = 0; row < total_rows; ++row) {
            for (int col = 0; col < total_cols; ++col) {
                if (row > 0 && row < total_rows - 1 && col > 0 && col < total_cols - 1) {
                    smoothedImage[row][col] = calculate3X3sum(row, col) / 9;
                } else {
                    smoothedImage[row][col] = calculateBorderAvg(row, col);
                }
            }
        }

        return smoothedImage;
    }
    
};
