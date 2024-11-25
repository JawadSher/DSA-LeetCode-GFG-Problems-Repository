class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int value){
        char ch = value + '0';

        for(int i = 0; i < board[0].size(); i++){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board[0].size();

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(board[row][col] == '.'){
                    for(int val = 1; val <= 9; val++){
                        if(isSafe(row, col, board, val)){
                            char ch = val + '0';
                            board[row][col] = ch;
                            if(solve(board)) return true;
                            board[row][col] = '.';
                        }

                    }

                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
